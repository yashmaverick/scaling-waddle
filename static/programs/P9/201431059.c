#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_SIZE 1001

int bags[1001];
long long weights[1001];
int numItems[1001];
int* items[1001];

void merge(int A[MAX_SIZE], int p, int q, int r)
{
	int L[MAX_SIZE],R[MAX_SIZE],i=0,j=0,n1,n2,k;
	n1=q-p+1;
	n2=r-q;
	for(;i<n1;i++)
		L[i]=A[p+i];
	for(;j<n2;j++)
		R[j]= A[q+1+j];
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	i=0;
	j=0;

	for(k=p;k<=r;k++)
	{
		if(i<n1 && j<n2)
		{
		if(weights[L[i]]<=weights[R[j]])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		}
		else if(i==n1)
		{
			A[k] = R[j++];
		}
		else if(j == n2)
		{
			A[k]=L[i++];
		}
	}
}

void mergesort(int A[MAX_SIZE],int p,int r)
{
	if(p<r)
	{
		int q;
		q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}



int main()
{
	int n,MOD;
	int i,j;
	scanf("%d %d",&n,&MOD);
	for(i=0;i<n;i++)
	{
		scanf("%d",numItems+i);
		items[i] = (int*)malloc(sizeof(int)*numItems[i]);
		weights[i]=0;
		bags[i]=i;
		for(j=0;j<numItems[i];j++)
		{
			scanf("%d",&items[i][j]);
			weights[i] = (weights[i] + items[i][j])%MOD;
		}

	}
	mergesort(bags,0,n-1);

	for(i=0;i<n;i++)
	{
		printf("%lld\n",weights[bags[i]]);
		for(j=0;j<numItems[bags[i]];j++)
			printf("%d\n",items[bags[i]][j]);
		printf("\n");
	}

	return 0;
}
