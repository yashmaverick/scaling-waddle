#include <stdio.h>


long long int handleA(long long int A[],long long int bSret,long long int item)
{
	long long int i=bSret;
	if(A[i]==item)
		while(A[i+1]==A[i])
			i++;
	else if(A[i]>item && (A[i-1]<item || i==0))	
		i--;	

	return i;
}

long long int handleC(long long int A[],long long int bSret,long long int item,long long int n)
{
	long long int i=bSret;
	if(A[i]==item && i>0)
	{
		while(A[i-1]==A[i] && i>0)
			i--;
	}
	else if(A[i]<item && (i+1)==n)
		i=-1;
	else if(A[i]<item && A[i+1]>item)
		i++;

	return i;
}

long long int bS(long long int A[],long long int n,long long int item)
{
	long long int l=0,r=n,mid,found=0;
	while(l<r)
	{
		mid=(l+r)/2;
		if(A[mid]==item)
			break;
		else if(item<A[mid])
			r=mid;			
		else if(item>A[mid])
			l=mid+1;		
	}
	
	return mid;
}

void scanArr(long long int A[],long long int n)
{
	long long int i;
	for(i=0;i<n;i++)
		scanf("%lld",&A[i]);
}

int main()
{
	long long int t,i,p,q,r,j,sum,A[100000],B[100000],C[100000];
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		sum=0;
		scanf("%lld",&p);
		scanArr(A,p);
		scanf("%lld",&q);
		scanArr(B,q);
		scanf("%lld",&r);
		scanArr(C,r);
		for(j=0;j<q && j<r;j++)
		{
			long long int bSA=bS(A,p,B[j]),bSC=bS(C,r,B[j]);
			long long int a=handleA(A,bSA,B[j]),c=handleC(C,bSC,B[j],r);
			
			if(a>j)
				a=j;
			if(c<j && c>-1)
				c=j;
			if(a==-1 || c==-1)
				sum+=0;
			else
				sum+=(a+1)*(r-c);
		}
		printf("%lld\n",sum);
	}

	return 0;
}