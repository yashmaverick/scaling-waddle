#include<stdio.h>
long long int D[100005];
long long int binary1(long long int k,long long int B[],long long int q,long long int i)
{
    long long int low=i,high=q,mid;
    if(low>high)
    {
	return 0;
    }
    while(low<high)
    {
	mid=(low+high)/2;
	if(B[mid]>=k)
	{
	    high=mid;
	}
	else if(B[mid]<k)
	{
	    low=mid+1;
	}
    }
    if(B[low]<k)
    {
	low++;
    }
    return low;
}
int main()
{
    long long int t,i;
    long long int A[100005];
    long long int B[100005];
    long long int C[100005];
    scanf("%lld",&t);
    while(t--)
    {
	long long int ans=0,tmp=0;
	D[0]=0;
	long long int p,q,r,a,k;
	scanf("%lld",&p);
	for(i=1;i<=p;i++)
	{
	    scanf("%lld",&A[i]);
	}
	scanf("%lld",&q);
	for(i=1;i<=q;i++)
	{
	    scanf("%lld",&B[i]);
	}
	scanf("%lld",&r);
	for(i=1;i<=r;i++)
	{
	    scanf("%lld",&C[i]);
	}
	if(q<=r)
	{
	    D[q+1]=0;
	}
	else
	{
	    D[r+1]=0;
	}
	for(i=q;i>=1;i--)
	{
	    k=B[i];
	    if(binary1(k,C,r,i)==0)
	    {
		D[i]=tmp+0;
		tmp=D[i];
	    }
	    else
	    {
		D[i]=tmp+(r-binary1(k,C,r,i)+1);
		tmp=D[i];
	    }
	}
	/*	for(i=1;i<=q;i++)
		{
		printf("%lld ",D[i]);
		}
		printf("\n");*/
	for(i=p;i>=1;i--)
	{
	    k=A[i];
	    a=binary1(k,B,q,i);
	    ans=ans+D[a];
	}
	printf("%lld\n",ans);
    }
    return 0;
}





