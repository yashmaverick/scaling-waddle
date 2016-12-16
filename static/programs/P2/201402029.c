#include<stdio.h>
/*int max(int a,int b,int c)
{
	if(a>b && a>c)
	{
		return a;
	}
	if(b>a && b>c)
	{
		return b;
	}
	if(c>a && c>b)
	{
		return c;
	}
}*/
//int compare(int x[],int a,int y[],int b,int z[],int c)
//{
//	int n=0;

//}
int main()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		int s,a,b,c,count=0,j,k,l;
		scanf("%d",&a);
		int x[a];
		for(j=0;j<a;j++)
		{
			scanf("%d",&x[j]);
		}
		scanf("%d",&b);
		int y[b];
		for(j=0;j<b;j++)
		{
			scanf("%d",&y[j]);
		}
		scanf("%d",&c);
		int z[c];
		for(j=0;j<c;j++)
		{
			scanf("%d",&z[j]);
		}
	//	s=max(a,b,c);
		for(j=0;j<a;j++)
		{
			for(k=0;k<b;k++)
			{
				for(l=0;l<c;l++)
				{
					if(x[j]<=y[k] && y[k]<=z[l] && j<=k && k<=l)
					{
						count++;
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
