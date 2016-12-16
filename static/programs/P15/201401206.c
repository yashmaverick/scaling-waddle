#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,x;
		scanf("%d %d",&n,&k);
		int ind[n],arr[n];
		scanf("%d",&arr[0]);
		ind[0]=-1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&arr[i]);
			x=i-1;
			if(arr[i]>arr[x])
				ind[i]=x;
			else
			{
				do
				{
					x=ind[x];
					if(x==-1)
					{
						ind[i]=-1;
						break;
					}
					if(arr[i]>arr[x])
					{
						ind[i]=x;
						break;
					}
				}while(x!=-1);
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d ",ind[i]);
//		printf("\n");
		for(i=0,j=k-1;j<n;j++,i++)
		{
			x=j;
			while(x>=i)
			{
				if(ind[x]<i)
				{
				//	printf("**%d %d %d** ",ind[x],i,x);
					printf("%d",arr[x]);
					if(j!=n-1)
						printf(" ");
					break;
				}
				x=ind[x];
			}
		}
		printf("\n");
	}
	return 0;
}

