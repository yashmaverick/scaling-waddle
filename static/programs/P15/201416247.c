#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,m,t,k,j,b[100000];
	scanf("%d",&m);
	for(t=0;t<m;t++)
	{  int min=1000000;
		scanf("%d %d",&n,&k);
		int *a;
		a=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n-k+1;i++)
		{
			if(i==0)
			{
				for(j=i;j<i+k;j++)
					if(min>a[j])
						min=a[j];
				b[0]=min;
			//	printf("%d\n",min);
			}
			else
			{
				if(min!=a[i-1])
				{
			//		printf("%d\n",i-k+2);
					if(a[i-1+k]<min)
					{
	//					int a1=-2;
	//					printf("%d\n",a1);
						min=a[i-1+k];
						b[i]=min;
						//break;
					}
					else 
					{
						//printf("a");
						b[i]=min;
					//	break;
					}
				}
				else
				{
					min=1000000;
					for(j=i;j<i+k;j++)
						if(min>a[j])
							min=a[j];
					b[i]=min;

				}

			}
		}
		for(i=0;i<n-k;i++)
			printf("%d ",b[i]);
		printf("%d",b[n-k]);
		printf("\n");

	}
	return 0;
}
