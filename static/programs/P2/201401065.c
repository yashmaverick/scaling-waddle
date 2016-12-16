#include<stdio.h>
int binsearch(int a[100000],int k,int f,int l);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,pn,qn,rn,p[100000],q[100000],r[100000];
		scanf("%d",&pn);
		for(i=0;i<pn;i++)
			scanf("%d",&p[i]);
		scanf("%d",&qn);
		for(i=0;i<qn;i++)
			scanf("%d",&q[i]);
		scanf("%d",&rn);
		for(i=0;i<rn;i++)
			scanf("%d",&r[i]);
		int j,c1[100000]={0},tmp;
		for(i=0;i<qn;i++)
		{
			c1[i]=rn-(binsearch(r,q[i],i,rn-1));
			if(c1[i]>rn)
			{c1[i]=0;}
		}
		for(i=qn-2;i>=0;i--)
			c1[i]+=c1[i+1];
	/*	for(i=0;i<qn;i++)
			printf("%d ",c1[i]);printf("\n");*/
		int cnt=0;
		for(i=0;i<pn;i++)
		{
			tmp=binsearch(q,p[i],i,qn-1);
			if(tmp!=-1&&c1[tmp]!=0)
				cnt+=c1[tmp];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
int binsearch(int a[100000],int k,int f,int l)
{
	int m;
	if(k>a[l]||f>l)
		return -1;
	else if(f==l&&k>a[f])
		return -1;
	while(f<l)
	{
		m=(f+l)/2;
		if(k==a[m])
			return m;
		else if(k>a[m])
			f=m+1;
		else if(k<a[m])
			l=m-1;
	}
	return f;
}
