#include<stdio.h>
int main()
{
	int n,arr[10000],a,b,min,i1,c[10000],k,i=0,k1,s,d,f=0;
	scanf("%d",&d);
	for(s=0;s<d;s++)
	{
		i1=1;
		scanf("%d%d",&n,&k);
		for(a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
		}
		k1=1;
		min=arr[1];
		for(b=1;b<=n&&b<=n-k+1;b++,k1++,i1++)
		{
			if(b>1 && min!=arr[b-1] && min>arr[k1+k-1])
			{
				min=arr[k1+k-1];	
			}
			else if(b==1 || (b>1 && min==arr[b-1]))
			{
				min=arr[b];
				for(a=k1;a<=k1+k-1;a++)
				{
					if(arr[a]<min)
					{
						min=arr[a];
					}
				}
			}
			c[i1]=min;
		}
		for(a=1;a<n-k+1;a++)
		{

			printf("%d ",c[a]);
		}
		printf("%d",c[a]);
		printf("\n");
	}
	return 0;
}

