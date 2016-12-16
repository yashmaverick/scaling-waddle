#include<stdio.h>
long long int D[100005];
long long int binary1(long long int A[],long long int B[],long long int q,long long int i)
{
    long long int low=i,high=q,mid,record=0;
    if(A[i]<=B[i])
    {
	return i;
    }
    else if(A[i]>B[q])
    {
	return 0;
    }
    else
    {
	while(low<=high)
	{
	    mid=(low+high)/2;
	    if(B[mid]>=A[i])
	    {
		record=mid;
		high=mid-1;
	    }
	    else if(B[mid]<A[i])
	    {
		low=mid+1;
	    }
	}
	return record;
    }
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
	long long int p,q,r,a;
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
    D[q+1]=0;
	scanf("%lld",&r);
	for(i=1;i<=r;i++)
	{
	    scanf("%lld",&C[i]);
	}
	if(q<=r)
	{
	    for(i=q;i>=1;i--)
	    {
		if(binary1(B,C,r,i)==0)
		{
		    D[i]=tmp+0;
		    tmp=D[i];
		}
		else
		{
		    D[i]=tmp+(r-binary1(B,C,r,i)+1);
		    tmp=D[i];
		}
	    }
	}
	else
	{
	    for(i=r;i>=1;i--)
	    {
		if(binary1(B,C,r,i)==0)
		{
		    D[i]=tmp+0;
		    tmp=D[i];
		}
		else
		{
		    D[i]=tmp+(r-binary1(B,C,r,i)+1);
		    tmp=D[i];
		}
	    }
	}
/*	for(i=1;i<=q;i++)
	{
	    printf("%lld ",D[i]);
	}
	printf("\n");*/
	if(p<=q)
	{
	    for(i=p;i>=1;i--)
	    {
		a=binary1(A,B,q,i);
		ans=ans+D[a];
	    }
	}
	else
	{
	    for(i=q;i>=1;i--)
	    {
		a=binary1(A,B,p,i);
		ans=ans+D[a];
	    }
	}
	printf("%lld\n",ans);
    }
    return 0;
}





