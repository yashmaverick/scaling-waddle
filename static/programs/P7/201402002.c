#include<stdio.h>


long long int cmp(const void *a, const void *b)
{
    return (*(long long int*)a) - (*(long long int*)b);
}

void swap(long long int *arr, long long int A, long long int B)
{
    long long int temp;
    temp=arr[B];
    arr[B]=arr[A];
    arr[A]=temp;
}

void quicksort(long long int *arr, long long int l, long long int h)
{
    long long int wall=l;

    if (l>=h)
        return;

    long long int i=l;
    long long int pivot=h;

    while(i<h)
    {
        if(arr[i]<arr[pivot])
        {
            swap(arr,i,wall);
            wall++;
        }

        i++;
    }

    swap(arr,wall,h);

    quicksort(arr,l,wall-1);
    quicksort(arr,wall+1,h);

}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;

    /* create temp arrays */
    long long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
 *   of arr to be sorted */
void mergesort(long long int arr[], long long int l, long long int r)
{
    if (l < r)
    {
        long long int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    long long int t,i;
    scanf("%lld",&t);

    for(i=0;i<t;i++)
    {
        long long int j,n,num,min=10000001;
        scanf("%lld",&n);

        long long int arr[n];

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
            if (arr[j]<min)
                min=arr[j];
        }

        if (n==1)
            printf("0\n");
        else
        {
            //   quicksort(arr,0,n-1);
            mergesort(arr,0,n-1);

//            for(j=0;j<n;j++)
//            printf("Elem is %lld\n",arr[j]);

                long long int ans=0;
            for(j=0;j<n-1;j++)
            {
                long long int dup=1;
                while(arr[j]==arr[j+1])
                {
                    j++;
                    dup++;
                }
                ans+=(dup)*(dup-1)/2;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
