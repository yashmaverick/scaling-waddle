#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,k;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		int i,j;
		int l1,l2,l3;
		int *a1;
		int *a2;
		int *a3;
		scanf("%d",&l1);
		a1=(int*)malloc(sizeof(long long int)*l1);
		for(j=0;j<l1;j++)
		{
			scanf("%lld",&a1[j]);
		}
		scanf("%d",&l2);
		a2=(int*)malloc(sizeof(long long int)*l2);
		for(j=0;j<l2;j++)
		{
			scanf("%lld",&a2[j]);
		}
		scanf("%d",&l3);
		a3=(int*)malloc(sizeof(long long int)*l3);
		for(j=0;j<l3;j++)
		{
			scanf("%lld",&a3[j]);
		}
		int* a4;
		a4=(int*)malloc(sizeof(long long int)*l2);
		j=i=0;
		while(j<l2)
		{
			while(i<=j && a1[i]<=a2[j] && i<l1)
			{i++;
				
			}
			a4[j]=i;
			j++;
		}
//		for(i=0;i<l2;i++)
//			printf("%lld ",a4[i]);
		free(a1);
		j=i=0;
		int *a5;
		a5=(int*)malloc(sizeof(long long int)*l3);
		long long int total=0,sum=0;
		while(j<l3)
		{
			while(i<=j && a3[j]>=a2[i] && i<l2)
			{sum=sum+a4[i];
				i++;
		
			}
			total=total+sum;
			j++;
		}
		free(a2);
		printf("%lld\n",total);
		free(a3);
		free(a4);
		free(a5);
	}
	return 0;
}




