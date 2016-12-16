#include<stdio.h>
int main()
{
	int i,j=0,t,a[10005],n,k,end,min,start;
	scanf("%d",&t);
	while(j<t)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<=n-k;i++)
		{
			end=i+k-1;
			if(i==0)
			{
				start=i;
				min=start;
				while(end>=start)
				{
					if(a[min]>a[end])
						min=end;
					end--;
				}
			}
			else 
			{
				if(min>=i)
				{
					if(a[end]<=a[min])
						min=end;
				}
				else
				{
					start=i;
					min=start;
					while(end>=start)
					{
						if(a[min]>=a[end])
							min=end;
						end--;
					}
				}
			}
			if(i!=n-k)
			        printf("%d ",a[min]);
			else
				printf("%d",a[min]);
		}
		printf("\n");
		j++;
	}
	return 0;
}

