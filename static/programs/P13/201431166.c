#include<stdio.h>
#define MAX 100000

int max,value;

int function(int *a,int *b,int root,int depth,int *p)
{
	if ( p[root]==1 )
		return;
	else
		p[root]=1;
	depth++;
	if (depth==max && a[root]<=value )
	{
		value=a[root];
	}
	else if (depth>max)
	{
		max=depth;
		value=a[root];
	}
	if (root==0)
		return;
	else
	{
		if ( b[root]>=0 )
		function(a,b,b[root],depth,p);
		if ( b[root] != root-1 )
		function(a,b,root-1,depth,p);
		return;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);	max=-1;
		int a[n],i,j,k,b[n],p[n];
		for(i=0;i<n;i++)
		{	
			scanf("%d",&a[i]);
			p[i]=0;
		}
		b[0]=-1;
		if(a[1]>a[0])
			b[1]=0;
		else 
			b[1]=-1;
		for(i=2;i<n;i++)
		{
			j=i-1;
			k=i;
			while(k--)
			{
				if(a[j]<a[i])
				{	
					b[i]=j;
					break;
				}
				else
				{ 
					j=b[j];
					if(j==-1)
					{	b[i]=j;
						break;
					}
				}

			}
		}
//		for (i=0;i<n;i++)
//			printf("i = %d, %d\n",i,b[i]);
		function(a,b,n-1,-1,p);
		printf ("%d %d\n",value,max);
	}
		return 0;
}
