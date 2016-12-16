# include <stdio.h>

long long int compare (const void * a, const void * b)
{
    return ( *(long long int*)a - *(long long int*)b );
}

long long int find3Numbers(long long int A[], long long int arr_size, long long int sum)
{
    long long int l,r,i,flag=0;

    for (i=0;i<arr_size-2;i++)
    {
        l=i+1; /* index of the first element in the remaining elements */
        r=arr_size-1; /* index of the last element */
        while(l<r)
        {
            if(A[i]+A[l]+A[r]==sum){
                flag=1;
                return 1;
            }
            else if(A[i]+A[l]+A[r]<sum)
                l++;
            else /* A[i] + A[l] + A[r] > sum */
                r--;
        }
    }
    if(flag==0)
        return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,k,data[1001],i;
        char arr[100];

        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%s %lld",arr,&data[i]);
        qsort(data,n,sizeof(long long int),compare);

        if(find3Numbers(data,n,k))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
