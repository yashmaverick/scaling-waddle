#include<stdio.h>

#include<string.h>
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
    long long int i,mid,L[100000],R[100000],nL,nR;
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
    return ;
}
int main()
{
    long long int t,x,i,j,k,l,n,m,A[100000];
    char y[100000];
    scanf("%lld",&t);
    while(t--)
    {
	scanf("%s",y);
	x=strlen(y);
	if(y[0]=='R')
	    A[0]=1;
	else if(y[0]=='J')
	    A[0]=100000;
	else
	    A[0]=-1000001;
	for(i=1;i<x;i++)
	{
	    if(y[i]=='R')
		A[i]=A[i-1]+1;
	    else if(y[i]=='J')
		A[i]=A[i-1]+100000;
	    else
		A[i]=A[i-1]-100001;
	}
	mergesort(A,x);
	long long int gain=1;
	long long int prt=0;
	for(i=0;i<x;i++)
	{
	    if(A[i]==0)
		prt=prt+1;
	    if(A[i]==A[i+1])
	    {
		gain++;
		if(i==n-1)
		{
		    if(A[i]==A[i+1])
			gain--;
		    prt=prt+((gain)*(gain-1))/2;
		}
	    }
	    else
	    {
		prt=prt+((gain)*(gain-1))/2;
		gain=1;
	    }
	}
	printf("%lld\n",prt);
    }
    return 0;
}
