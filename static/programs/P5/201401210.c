#include<stdio.h>

// void merge(int A[] , int low , int mid , int high);
// void mergesort(int A[] , int low , int high)
// {
//     int mid;
//     if(low<high)
//     {
//         mid = (low+high)/2;
//         mergesort(A,low,mid);
//         mergesort(A,mid+1,high);
//         merge(A,low,mid,high);
//     }
// }
// void merge(int A[] , int low , int mid , int high)
// {
//     int i = low, j = mid+1 , k = low , l;
//     int temp[100005];
//     while((i<=mid)&&(j<=high))
//     {
//         if(A[i]<A[j])
//             temp[k++] = A[i++];
//         else
//             temp[k++] = A[j++];
//     }
//         
//     if(i>mid)
//         for(l=j;j<=high;j++)
//             temp[k++] = A[l];
//     else
//         for(l=i;l<mid+1;l++)
//             temp[k++] = A[l];
// //     for(i=low;i<high;i++)
// //     {
// //         printf("%d ",temp[i]);
// //     }
// //     printf("\n");
//     for(i=low;i<=high;i++)
//         A[i] = temp[i];
// }

int find(int A[] , int n , int x)
{
    int l , r , i;
    for(i=0;i<n-2;i++)
    {
        l = i + 1;
        r = n - 1;
        while(l<r)
        {
            if(A[i] + A[l] + A[r] == x)
            {
                return 1;
            }
            else if(A[i] + A[l] + A[r] < x)
                l++;
            else
                r--;
        }
    }
//     printf("NO\n");
    return 0;
}

int main()
{
    int i , z , X , n , sum, j;
//     int z, X;
//             printf("this is this rouihr %d\n",t);

    int A[1005];
    char s[100];
    
//         printf("this is this rouihr %d\n",t);
    scanf("%d",&X);
//     printf("%d\n",T);
//         fprintf(stderr,"this is this rouihr %d\n",z);
    for(z=0;z<X;z++)
    {
//         fprintf(stderr,"this is this rouihr %d\n",z);
        scanf("%d %d",&n,&sum);
//         printf("%d\n",t);
        for(i=0;i<n;i++)
        {
//             gets(s);
            scanf("%s %d",s,&A[i]);
        }
//         printf("%d\n",t);
//         mergesort(A,0,n-1);

        for(i=0;i<n-1;++i)
            for(j=0;j<n-1;++j)
            {
                if(A[j]>A[j+1])
                {
                    int t = A[j+1];
                    A[j+1] = A[j];
                    A[j] = t;
                }
            }
        
        int f = find(A,n,sum);
//         printf("%d\n",t);
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
//         printf("%d\n",t);
    }
    return 0 ;
}