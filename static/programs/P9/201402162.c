#include<stdio.h>
#include<stdlib.h>
typedef struct lashit
{
	int add;
	int index;
	int len;
}lashit;
int main()
{
	long long int n,mod;
	int i,m,j,sum,temp,in;
	scanf("%lld%lld",&n,&mod);
	int* arr[n],brr[n];
	lashit c[n];
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%d",&m);
		arr[i]=(int *)malloc((m+1)*sizeof(int));
		for(j=1;j<=m;j++)
		{
			scanf("%d",&arr[i][j]);
			sum=(sum+arr[i][j])%mod;
		}
		arr[i][0]=sum;
		c[i].add=sum;
		c[i].index=i;
		c[i].len=m+1;
	}
	for(i=0;i<n-1;i++)
	{
		//sorting takes place here  .. 
		for(j=0;j<n-1-i;j++)
		{
			if(c[j].add>c[j+1].add)
			{
				temp=c[j].add;
				c[j].add=c[j+1].add;
				c[j+1].add=temp;
				temp=c[j].index;
				c[j].index=c[j+1].index;
				c[j+1].index=temp;
				temp=c[j].len;
				c[j].len=c[j+1].len;
				c[j+1].len=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		//printf("%d\n",c[i].add);
		in=c[i].index;
		for(j=0;j<c[i].len;j++)
			printf("%d\n",arr[in][j]);
		printf("\n");
	}
	return 0;
}
