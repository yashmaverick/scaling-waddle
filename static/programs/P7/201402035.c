#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
long long int sum,ct;
 int i,t,n,a[1000000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sum=0;
		ct=1;

		qsort(a,n,sizeof( int),compare);

		//for(i=0;i<n;i++)
		//	printf("%d ",a[i]);
	//	printf("\n");

		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				ct++;

			else
			{
				sum=sum+((ct)*(ct-1))/2;
				ct=1;
			}
		//	printf("vin\n");
		}
		sum=sum+((ct)*(ct-1))/2;
		
		printf("%lld\n",sum);
	}

	return 0;
}

