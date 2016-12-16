#include<stdio.h>
#include<math.h>
long long int A[100001],B[100001],C[100001],D[100001],E[100001];
long long int  search(long long int K[],long long int low ,long long int high,long long int s)
{
	long long int mid;
	mid=(low+high)/2;
	if(low<0) return 0;
	if(low>=high)
	{
		if(s<=K[low])
			return low;
		return low+1;
	}
	else if(s>K[mid])
		return  search(K,mid+1,high,s);
	else
		return search(K,low,mid,s);
}
long long int search1(long long int K[],long long int low,long long int high,long long int i )
{
	long long int mid;
	mid=(low+high)/2;
	if(low<0) return 0;
	if(low>=high)
	{

		if(K[low]<=B[i])
			return low+1;
		return low;
	}
	else if(B[i]>K[mid])
		return search1(K,mid+1,high,i);
	else
		return search1(K,low,mid,i);
}
int main()
{
	long long int i,j,l,t,u,c,p,q,r;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		l=0;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&A[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&B[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&C[i]);
		for(i=0;i<100001;i++)
			D[i]=E[i]=0;
		for(i=0;i<q;i++)
		{
			if(i<r)	
			{
			  //printf("%lld\n",r);
			D[i]=r-search(C,i,r-1,B[i]);
			}
		}
		for(i=0;i<q;i++)
		{
			if(i>=p && A[p-1]<=B[i])
				E[i]=p;
			else if(A[i]<=B[i] && i<p)
				E[i]=i+1;
			else if(A[0] > B[i])
				E[i]=0;
			else
				E[i]=search1(A,0,p-1,i);
		}
		//printf("Printing D[i]:\n"); for(i=0;i<q;i++)printf("%lld ",D[i]); printf("\n");
		//printf("Printing E[i]:\n"); for(i=0;i<q;i++)printf("%lld ",E[i]); printf("\n");
		for(i=0;i<fmin(q,r);i++)
		{
			c=(D[i]*E[i]);
			l=l+c;
		}
		printf("%lld\n",l);
	}
	return 0;
}
