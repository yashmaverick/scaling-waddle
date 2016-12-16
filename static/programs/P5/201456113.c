# include <stdio.h>

// A utility function to sort an array using Quicksort
void quickSort(int *, int, int);

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triple
int find3Numbers(int A[], int arr_size, int sum)
{
	int l, r,i;

	/* Sort the elements */
	quickSort(A, 0, arr_size-1);

	/* Now fix the first element one by one and find the
	   other two elements */
	for (i = 0; i < arr_size - 2; i++)
	{

		// To find the other two elements, start two index variables
		// from two corners of the array and move them toward each
		// other
		l = i + 1; // index of the first element in the remaining elements
		r = arr_size-1; // index of the last element
		while (l < r)
		{
			if( A[i] + A[l] + A[r] == sum)
			{
				//printf("Triplet is %d, %d, %d", A[i], A[l], A[r]);
				return 1;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}

	// If we reach here, then no triplet was found
	return 4;
}

/* FOLLOWING 2 FUNCTIONS ARE ONLY FOR SORTING
   PURPOSE */
void exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}

int partition(int A[], int si, int ei)
{
	int x = A[ei];
	int i = (si - 1);
	int j;

	for (j = si; j <= ei - 1; j++)
	{
		if(A[j] <= x)
		{
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange (&A[i + 1], &A[ei]);
	return (i + 1);
}

/* Implementation of Quick Sort
   A[] --> Array to be sorted
   si  --> Starting index
   ei  --> Ending index
 */
void quickSort(int A[], int si, int ei)
{
	int pi;    /* Partitioning index */
	if(si < ei)
	{
		pi = partition(A, si, ei);
		quickSort(A, si, pi - 1);
		quickSort(A, pi + 1, ei);
	}
}

/* Driver program to test above function */
int main()
{
	int i,t;
	int j,n,k,s;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		int a[n];
		char st[100000];
		for(j=0;j<n;j++)
		{
			scanf("%s",st);
			scanf("%d",&a[j]);
		}

	s=find3Numbers(a,n,k);
	if(s==1)
		printf("YES\n");
	else if(s==4)
		printf("NO\n");
	}
	return 0;
}
