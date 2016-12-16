#include<stdio.h>

int min,depth;

void finddepth(int a[100000],int b[100000],int f,int l,int d)
{
	if(l==f)
		return;
	if(d>depth)
	{
		depth=d;
		min=a[l-1];
	}
	if((l-f)==1)
	{
		if(a[l-1]<min&&d==depth)
			min=a[l-1];
		return;
	}
	else
	{
		finddepth(a,b,f,b[l-1]+1,d+1);
		finddepth(a,b,b[l-1]+1,l-1,d+1);
		return;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,a[100000],b[100000];
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=-1;
		for(i=1;i<n;i++)
		{
			j=i-1;
			while(a[j]>=a[i])
			{
				j=b[j];
				if(j==-1)
					break;
			}
			b[i]=j;
		}
//		for(i=0;i<n;i++) printf("%d ",b[i]);printf("\n");
		if(n==0)
			min=0;
		else
			min=a[n-1];
		depth=0;
		finddepth(a,b,0,n,0);
		printf("%d %d\n",min,depth);
	}
	return 0;
}
