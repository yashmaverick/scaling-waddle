#include<stdio.h>
#define ll long long int
void print(ll *a,ll n)
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%lld ",a[i]);
	printf("\n");
}
int main()
{
	long long int i,j,a,st[500008],sum,val,n,k;
	scanf("%lld",&n);
	while(n!=0)
	{
		j=0;sum=0;
		st[0]=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			val=j;
        while(j>0 && st[j]<a)
				{
					j--;
				}
		  k=j;
			while(k>0 && st[k]==a)
				k--;
			if(k!=0)
				val+=1;
			val-=k;
			sum+=val;
				j++;
				st[j]=a;
//				print(st,j+1);
	//			printf("sum :%lld\n",sum);
		}
		sum=((n*(n-1))/2)-sum;
		printf("%lld\n",sum);
//	printf("%lld",n);
	scanf("%lld",&n);
	}
	return 0;
}

