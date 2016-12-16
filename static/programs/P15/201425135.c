#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,j,g;
		scanf("%d %d",&n,&k);
		int a[n+1],wholemin,min1,q;
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i==1)
				wholemin=a[1];
			else
			{
				if(wholemin>a[i])
					wholemin=a[i];
			}
		}
		j=n-k+1;
		for(i=1;i<=j;i++)
		{
			if(i==1)
			{
				min1=a[i];
				for(g=i;g<=i+k-1;g++)
				{
					if(a[g]<=min1)
					{
						q=g;
						min1=a[g];
					}

				}
				if(i!=j)
					printf("%d ",min1);
				else
					printf("%d",min1);
			}
			else
			{
				if(a[i+k-1]==wholemin)
				{
					q=i+k-1;
					min1=a[i+k-1];
					if(i==j)
						printf("%d",min1);
					if(i!=j)
						printf("%d ",min1);
				}
				else
				{
					if(q!=i-1)
					{
						if(a[i+k-1]>min1)
						{
							if(i!=j)
								printf("%d ",min1);
							else
								printf("%d",min1);
						}

						else if(a[i+k-1]<=min1)
						{
							q=i+k-1;
							min1=a[i+k-1];
							if(i!=j)
								printf("%d ",min1);
							else
								printf("%d",min1);
						}

					}
					else if(q==i-1)
					{
						min1=a[i];
						for(g=i;g<=i+k-1;g++)
						{
							if(a[g]<=min1)
							{
								q=g;
								min1=a[g];
							}
						}
						if(i!=j)
							printf("%d ",min1);
						else
							printf("%d",min1);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}

