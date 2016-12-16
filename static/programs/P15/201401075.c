#include<stdio.h>
int main()
{
	int t,n,k,i,j,min,ar[10007];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		for(i=0;i+k-1<n;i++)
		{
			if(i==0)
			{
				min=ar[0];
				for(j=1;j<k;j++)
				{
					if(ar[j]<min)
						min=ar[j];
				}
			}
			else
			{
				if(ar[i-1]<=min)
				{
					min=ar[i];
					for(j=i;j<i+k;j++)
					{
						if(ar[j]<min)
							min=ar[j];
					}
				}
				else
				{
					if(ar[i+k-1]<min)
						min=ar[i+k-1];
				}
			}
			printf("%d%s",min,(i+k-1==n-1)?"\n":" ");
		}
	}
	return 0;
}
					

