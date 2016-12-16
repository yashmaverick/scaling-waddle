#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        int L[n1], R[n2];

        for(i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for(j = 0; j < n2; j++)
                R[j] = arr[m + 1+ j];

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

        while (i < n1)
        {
                arr[k] = L[i];
                i++;
                k++;
        }

        while (j < n2)
        {
                arr[k] = R[j];
                j++;
                k++;
        }
}

void mergeSort(int arr[], int l, int r)
{
        if (l < r)
        {
                int m = l+(r-l)/2; 
                mergeSort(arr, l, m);
                mergeSort(arr, m+1, r);
                merge(arr, l, m, r);
        }
}

int binsrch(int k,int a[],int l,int h)
{
        int mid;

        while(l<=h)
        {
                mid=(l+h)/2;

                if(k==a[mid])
                        return 1;
                else if(k<a[mid])
                {
                        h=mid-1;                
                }
                else
                {
                        l=mid+1;
                }
        }

        return 0;
}

int main()
{
        int t,T,i,j,n,k,a[1000],rem,res;
        char str[1000000];

        scanf("%d",&T);

        for(t=1;t<=T;t++)
        {
                scanf("%d %d",&n,&k);

                for(i=0;i<n;i++)
                {
                        scanf("%s %d",str,&a[i]);
                }

/*                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                if(a[i]>a[j])
                                {
                                        a[i]=a[i]+a[j];
                                        a[j]=a[i]-a[j];
                                        a[j]=a[i]-a[j];
                                }
                        }
                }*/

                mergeSort(a,0,n-1);
                res=0;

                for(i=0;i<n-2;i++)
                {
                        for(j=i+1;j<n-1;j++)
                        {
                                rem=k-a[i]-a[j];
                                res=binsrch(rem,a,j+1,n-1);
                                if(res==1)
                                        break;
                        }

                        if(res==1)
                                break;
                }

                if(res==1)
                        printf("YES\n");
                if(res==0)
                        printf("NO\n");

        }

        return 0;
}
