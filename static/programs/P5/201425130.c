#include<stdio.h>
//void quicksort(int A[100000],int low,int high);
int findsum(int A[100000],int size,int sum)
{
	int l,r,i;
	quicksort(A,0,size-1);
	for( i=0;i<size-2;i++)
	{
		l=i+1;
		r=size-1;
		while(l<r)
		{
			if((A[i]+A[l]+A[r])==sum)
				return 1;
			else
				if((A[i]+A[l]+A[r])<sum)
					l++;
				else
					r--;
		}
	}
	return -1;

}
int main()
{

	int test,k,r,l,i,j,fl,n;
	int A[100000];
	char	B[100000];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s %d",B,&A[i]);
		}
		fl=findsum(A,n,k);
		if(fl==1)
			printf("YES\n");
		if(fl==-1)
			printf("NO\n");
	}
	return 0;
}
int quicksort(int *A,int low,int high)
{
	int pivot;
	if(high>=low)
	{
		pivot=partition(A,low,high);
		quicksort(A,low,pivot-1);
		quicksort(A,pivot+1,high);
	}
	return ;
}
int partition( int A[], int l, int r)
{
	int pivot, i, j, t;
	pivot = A[l];
	i = l; j = r+1;
	while(i<=r)
	{
		do ++i;
		while( A[i] <= pivot);
		do --j;
		while( A[j] > pivot );
		if( i >= j )
			break;
		swap(&A[i],&A[j]);
	}
	swap(&A[l],&A[j]);
	return j;
}
int swap(int *l,int *r)
{
	int temp;
	temp=*l;
	*l=*r;
	*r=temp;
}






















































































