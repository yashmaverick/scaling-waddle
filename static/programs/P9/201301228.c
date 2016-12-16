#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
	long long int sum;
	long long int item;
	long long int *wet;
}bag;
int main()
{
//	printf("Main starts\n");
	bag vin[1001];
	long long int num,mod,tcase,a,i,j,k,l;
	bag temp;
//	printf("decleration done\n");
	scanf("%lld %lld",&num,&mod);
	j=0;
	k=0;
//	printf("Stage1\n");
	while(k++<num)
	{
		a=0;
		scanf("%lld",&vin[k].item);
		//		printf("scanning done done\n");
		l=vin[k].item;
		vin[k].wet=(long long int*)malloc(sizeof(long long int) * l);
		for(i=0;i<l;i++)
		{
			//			printf("loop done\n");
			scanf("%lld",&vin[k].wet[i]);
			a+=vin[k].wet[i];
		}
		a=a%mod;
		vin[k].sum=a;
	}
	for(i=1;i<=num;i++)
	{
		for (j=1;j<=num-i;j++)
		{
			if (vin[j].sum > vin[j+1].sum) /* For decreasing order use < */
			{
				temp = vin[j];
				vin[j] = vin[j+1];
				vin[j+1] = temp;
			}
		}
	}
	for(i=1;i<=num;i++)
	{
		printf("%lld\n",vin[i].sum);
		for(j=0;j<(vin[i].item);j++)
			printf("%lld\n",vin[i].wet[j]);
		printf("\n");
	}
	return 0;
}
