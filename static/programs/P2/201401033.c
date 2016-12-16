#include<stdio.h>
#define MAX 100010
long long int binary(long long int C[],long long int x,long long int low,long long int high,long long int len)
{
	long long int mid,var=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x<C[mid])
		{
			high=mid-1;
		}
		else if(x>C[mid])
		{
			low=mid+1;
		}
		else
		{
			var=mid;
			high=mid-1;
		}
	}
	if(var!=-1)
		return var;
	else
	{
		if(C[mid]<x && C[mid+1]>x)
			return mid+1;
		if(C[mid]>x)
			return mid;
		else
			return len;
	}
}
int main()
{
	long long int A[MAX],B[MAX],C[MAX],D[MAX];
	long long int tc,a,b,c,i,j,k,cnt,temp;
	scanf("%lld",&tc);
	while(tc--)
	{
		cnt=0;
		scanf("%lld",&a);
		for(i=0;i<a;i++)
			scanf("%lld",&A[i]);
		scanf("%lld",&b);
		for(i=0;i<b;i++)
			scanf("%lld",&B[i]);

		scanf("%lld",&c);
		for(i=0;i<c;i++)
			scanf("%lld",&C[i]);
		for(i=0;i<b;i++)
		{
			temp=binary(C,B[i],i,c-1,c);
			D[i]=c-temp;
			//printf("%lld ",D[i]);
		}
	//	printf("\n\n");
		for(i=b-2;i>=0;i--)
			D[i]=D[i]+D[i+1];
		for(i=0;i<a;i++)
		{
			temp=binary(B,A[i],i,b-1,b);
			cnt+=D[temp];
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
