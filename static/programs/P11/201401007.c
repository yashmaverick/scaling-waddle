#include<stdio.h>
long long int l[100005];
long long int r[100005];
long long int A[100005];
long long int B[100005];
void func1(long long int first,long long int size)
{
    B[0]=-1;
    long long int last=1,m=B[last-1],i;
    B[last]=first;
    last++;
    l[first]=m;
    for(i=1;i<size;i++)
    {
	m=B[last-1];
	if(A[i]>A[m])
	{
	    l[i]=m;
	    B[last]=i;
	    last++;
	}
	else
	{
	    while(A[i]<=A[m]&&last>1)
	    {
		last--;
		m=B[last-1];
	    }
	    m=B[last-1];
	    B[last]=i;
	    last++;
	    l[i]=m;
	}
    }
/*    for(i=0;i<size;i++)
    {
	printf("%lld ",l[i]);
    }
    printf("\n");*/
}
void func2(long long int first,long long int size)
{
    B[0]=size;
    long long int last=1,m=B[last-1],i;
    B[last]=first;
    last++;
    r[first]=m;
    for(i=first-1;i>=0;i--)
    {
	m=B[last-1];
	if(A[i]>A[m])
	{
	    r[i]=m;
	    B[last]=i;
	    last++;
	}
	else
	{
	    while(A[i]<=A[m]&&last>1)
	    {
		last--;
		m=B[last-1];
	    }
	    m=B[last-1];
	    B[last]=i;
	    last++;
	    r[i]=m;
	}
    }
/*    for(i=0;i<size;i++)
    {
	printf("%lld ",r[i]);
    }
    printf("\n");*/
}
int main()
{
    long long int area,max;
    long long int i,n;
    scanf("%lld",&n);
    while(n)
    {
	max=0;
	for(i=0;i<n;i++)
	{
	    scanf("%lld",&A[i]);
	}
	func1(0,n);
	func2(n-1,n);
	for(i=0;i<n;i++)
	{
	    area=A[i]*((i-l[i]-1)+(r[i]-i-1)+1);
//	    printf("%lld\n",area);
	    if(area>max)
	    {
		max=area;
	    }
	}
	printf("%lld\n",max);
	scanf("%lld",&n);
    }
    return 0;
}
