#include<stdio.h>
int bsmi(int a[],int num,int start,int end,int n);
int main()
{
	int t,p,q,r,a[100000],b[100000],c[100000],i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		int l;
		if(p<q)
			l=q;
		else
			l=p;
		for(i=0;i<l;i++)
		{
			if(i<p)
				a[i]=bsmi(b,a[i],i,q-1,q-1);
			if(i<q)
				b[i]=r-bsmi(c,b[i],i,r-1,r-1);
		}
		int ans=0;
		for(i=0;i<p;i++)
		{
			for(j=a[i];j<q;j++)
				ans=ans+b[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}



int bsmi(int a[],int num,int start,int end,int n)
{
	int ans,state=1;
	while(start<=end)
	{
//		printf(" %d%d ",start,end);
		if(a[(start+end)/2]==num)
		{
			if((start+end)/2==n-1)
				ans=(start+end)/2;
			else
				ans=(start+end)/2+1;
			state=0;
			break;
		}
		if(a[(start+end)/2]<num)
			start=(start+end)/2+1;
		else
			end=(start+end)/2-1;
	}
	if(state==1)
	{	
		if(a[start]<num && start<n-1)
			ans=start+1;
		else
			ans=start;
	}
	return ans;
}



