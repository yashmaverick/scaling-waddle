#include<stdio.h>
long long int n,A[1000000],i,count=1,sum=0;
void swap(long long int A[], long long int x, long long int y)
{
	/*A[x]=A[x]+A[y];
	A[y]=A[x]-A[y];
	A[x]=A[x]-A[y];*/
	int t=A[x];
	    A[x]=A[y];
	    A[y]=t;
}
void sort(long long int A[], long long int f, long long int l)
{
	if(f<l-1)
	{
		long long int mid,pivot,p,q;
		mid=(f+l)/2;
		swap(A,mid,l-1);
		pivot=A[l-1];
		p=f;q=l-2;
		while(p<=q)
		{
			while(A[p]<pivot)
				p++;
			while(A[q]>pivot)
				q--;
			if(p<q)
				swap(A,p,q);
			if(A[p]==pivot && A[q]==pivot)
			{
				p++;q--;
			}
		}
		swap(A,p,l-1);
		sort(A,f,p);
		sort(A,p+1,l);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//long long int n,A[1000000],
		long long int i,count=1,sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		sort(A,0,n);
	/*	for(i=0;i<n;i++)
			printf("%lld ",A[i]);
		printf("\n");*/
		for(i=0;i<n-1;i++)
		{
			if(A[i]==A[i+1])
				count++;
			
			if(A[i]!=A[i+1] && A[i]==A[i-1])
			{	
				sum+=(count*(count-1))/2; //printf("for num(%lld) freq=%lld dup=%lld\n",A[i],count,(count*(count-1))/2);
				count=1;
			}	
		}
		if(count>1)
			sum+=(count*(count-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}	

