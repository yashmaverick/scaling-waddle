#include<stdio.h>
int el,p=0,depth=0;
int b[100002];
void stak(int a[],int n)
{
	int c[100002],i,j;
	i=n-1;
	j=-1;
	while(i>=0)
	{
		if(j==-1||a[i]>a[c[j]])
		{
			j++;
			c[j]=i;
			i--;
		}
		else
		{
			while(a[i]<a[c[j]]&&j!=-1)
			{
				b[c[j]]=i;
				j--;
			}
			j++;
			c[j]=i;
			i--;
		}
	}
}
void post_order(int a[],int s,int e)
{
	int l,temp;
	if(s==e&&p>depth)
	{
		depth=p;
		el=a[s];
	}
	if(s==e&&p==depth)
	{
		if(el>a[s])
			el=a[s];
	}
	if(s<e)
	{
		p++;
		temp=p;
		if(b[e]+1<=e)
			post_order(a,b[e]+1,e-1);
		p=temp;
		if(b[e]>=s)
			post_order(a,s,b[e]);
	}
}
int main()
{
	int i,j,n,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a[100002];
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		stak(a,n);
		post_order(a,0,n-1);
		printf("%d %d\n",el,depth);
		p=0;
		depth=0;
	}
	return 0;
}
