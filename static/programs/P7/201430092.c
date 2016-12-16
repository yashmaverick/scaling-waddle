#include<stdio.h>
void merge(long long int L[],long long int R[],long long int A[],long long int nL,long long int nR)
{
    long long int i,j,k;
    i=0;j=0;k=0;
    while(i<nL&&j<nR)
    {
	if(L[i]<=R[j])
	{
	    A[k]=L[i];
	    i++;
	}
	else
	{
	    A[k]=R[j];
	    j++;
	}
	k++;
    }
    while(i<nL)
    {
	A[k]=L[i];
	k++;
	i++;
    }
    while(j<nR)
    {
	A[k]=R[j];
	k++;
	j++;
    }
    return;
}

void mergesort(long long int A[],long long int n)
{
    long long int i,mid,L[1000000],R[1000000],nL,nR;
    if(n<2)
    {return;}
    else
    {
	mid=n/2;
	for(i=0;i<mid;i++)
	{
	    L[i]=A[i];
	}
	for(i=mid;i<n;i++)
	{
	    R[i-mid]=A[i];
	}
	nL=mid;
	nR=n-mid;
	//    printf("%d %d\n",nL,nR);
	mergesort(L,nL);
	mergesort(R,nR);
	merge(L,R,A,nL,nR);
    }
}

int main()
{
    long long int N;
    scanf("%lld",&N);
    while(N--)
    {
	long long int n,i=0,A[1000001];
	scanf("%lld",&n);
	while(i<n)
	{
	    scanf("%lld",&A[i]);
	    i++;
	}
	mergesort(A,n);
//	qsort(A,n,sizeof(long long int),f);
	//	for(i=0;i<n;i++)
	//	    printf("%lld ",A[i]);
	long long int p=0,j,count,m;
	m=A[0];
	count=1;
	for(i=1;i<n;i++)
	{  
	    if(m==A[i])
		count++;	
	    else
	    {	m=A[i];
		p=p+count*(count-1)/2;
		count=1;
		//		printf("%lld\n",p);
	    }
	}
	p=p+count*(count-1)/2;
	printf("%lld\n",p);
    }
    return 0;
}
