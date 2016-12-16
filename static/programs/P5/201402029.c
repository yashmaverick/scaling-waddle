#include<stdio.h>
int main()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		int n,k,flag=0,j,p,q,temp,h;
		scanf("%d %d",&n,&k);
		int a[100000],b[n];
		for(j=0;j<n;j++)
		{
			scanf("%s %d",a,&b[j]);
		}
	//	for(j=0;j<n;j++)
	//	{
	//		printf("%d ",b[j]);
	//	}
		for(h=n-2;h>=0;h--)
		{
			for(j=0;j<=h;j++)
			{
				if(b[j]>b[j+1])
				{
					temp=b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}
			}
		}
		for(j=0;j<n-2;j++)
		{
			p=j+1;
			q=n-1;
			while(q>p)
			{
				if(b[j]+b[p]+b[q]==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				if(b[j]+b[p]+b[q]>k)
				{
					q--;
				}
				if(b[j]+b[p]+b[q]<k)
				{
					p++;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag!=1)
		{
			printf("NO\n");
		}
	}
	return 0;
}
