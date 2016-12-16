#include<stdio.h>
void quickSort( int[], int, int);
int partition( int[], int, int);
void quickSort( int a[], int l, int r)
{
	int j;

	if( l < r )
	{
		// divide and conquer
		j = partition( a, l, r);
			quickSort( a, l, j-1);
			quickSort( a, j+1, r);
	}

}
int partition( int a[], int l, int r) {
	int pivot, i, j, t;
	pivot = a[l];
	i = l; j = r+1;

	while( 1)
	{
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
		if( i >= j ) break;
		t = a[i]; a[i] = a[j]; a[j] = t;
	}
	t = a[l]; a[l] = a[j]; a[j] = t;
	return j;
}
int main()
{
	int t,a[100005],i,n,k,start,end,flag,sum;
	char s[100005];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&a[i]);
		}
		quickSort(a,0,n-1);
		for(i=0;i<n-2;i++)
		{
			start=i+1;
			end=n-1;
			while(start<end)
			{
				sum=a[i]+a[start]+a[end];
				if(sum==k)
				{
					flag=1;
					break;
				}
				if(sum<k)
					start++;
				if(sum>k)
					end--;
			}
			if(flag==1)
			{
				printf("YES\n");
				break;
			}

		}
		if(flag==0)
			printf("NO\n");

	}
	return 0;
}
