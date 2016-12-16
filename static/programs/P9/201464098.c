#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int luck(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
#define gi(x) scanf("%lld",&x);
int main()
{
	long long int n,mod;
	gi(n);
	gi(mod);
	long long int *arr[n];
	long long int i=0,g,a,b,k,j;
	long long int life[n];
	long long int max=0,lov;
	long long int sum[n];
	for(g=0;g<n;g++)
	{
		scanf("%lld",&life[g]);
		a=life[g]+2;
		arr[i]= (long long int *)malloc(a * sizeof(long long int));
		j=2;
		arr[i][0]=0;
		arr[i][1]=life[g];
		for(lov=0;lov<(a-2);lov++)
		{
			gi(b);
			arr[i][j]=b;
			arr[i][0]=(arr[i][0]+b)%mod;
			j++;
		}
		sum[i]=arr[i][0];
		i++;
	}
	/*for(i=0;i<n;i++)
	{
		a=life[i]+2;
		for(j=0;j<a;j++)
			printf("%lld ",arr[i][j]);
		printf("\n");
	}*/
	qsort(sum,n,sizeof(long long int),luck);
	/*for(i=0;i<n;i++)
		printf("%lld ",sum[i]);*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(sum[i]==arr[j][0] && arr[j][1]!=-2)
			{
				printf("%lld\n",sum[i]);
				for(k=1;k<=arr[j][1];k++)
					printf("%lld\n",arr[j][k+1]);
				printf("\n");
				arr[j][1]=-2;
			}
		}
	}
	return 0;
}
