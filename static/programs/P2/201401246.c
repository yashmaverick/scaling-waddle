#include<stdio.h>
int f1(long long int k,long long int a[],int n)
{
	int i,count=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=k)
			count++;
	}
	return count;
}
long long int f2(long long int k,long long int b[],int B[],int n)
{
	int i;
	long long int count=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]<=k)
			count=count+B[i];
	}
	return count;
}
int main()
{
	int i,t,p,q,r,j,B[100000];
	long long int a[100000],b[100000],c[100000],C[100000],ans=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&p);
		for(j=1;j<=p;j++)
		{
			scanf("%lld",&a[j]);
		}
		scanf("%d",&q);
		for(j=1;j<=p;j++)
		{
			scanf("%lld",&b[j]);
		}
		scanf("%d",&r);
		for(j=1;j<=p;j++)
		{
			scanf("%lld",&c[j]);
		}
		for(j=1;j<=q;j++)
		{
			B[j]=f1(b[j],a,j);
/*			printf("B_%d\n",B[j]);		*/
		}
		for(j=1;j<=r;j++)
		{
			C[j]=f2(c[j],b,B,j);
/*			printf("C_%lld\n",C[j]); 	*/
			ans=ans+C[j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
