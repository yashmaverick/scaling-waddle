#include<stdio.h>
void Merge(long long int arr[],long long int left,long long int mid,long long int right)
{
        long long int tempArr[right-left+1];
        long long int pos=0,lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right)
        {
                if(arr[lpos] < arr[rpos])
                {
                        tempArr[pos++] = arr[lpos++];
                }
                else
                {
                        tempArr[pos++] = arr[rpos++];
                }
        }
        while(lpos <= mid)  tempArr[pos++] = arr[lpos++];
        while(rpos <= right)tempArr[pos++] = arr[rpos++];
        long long int iter;
        for(iter = 0;iter < pos; iter++)
        {
                arr[iter+left] = tempArr[iter];
        }
        return;
}

void MergeSort(long long int arr[],long long int left,long long int right)
{
        long long int mid = (left+right)/2;
        if(left<right)
        {
                MergeSort(arr,left,mid);
                MergeSort(arr,mid+1,right);
                Merge(arr,left,mid,right);
        }
}

long long int nc2(long long int n)
{
        return (n*(n-1))/2;
}


int main()
{

        int t;
        scanf("%d",&t);
        long long int size,i,arr[1000007],count;
        while(t--)
        {
                scanf("%lld", &size);
                for(i = 0;i < size;i++)
                {
                        scanf("%lld",&arr[i]);
                }
                MergeSort(arr,0,size-1); 
                long long int count = 1,sum =0;
                for(i=1;i<size;i++)
                {
                        if(arr[i]==arr[i-1])
                                count++;
                        else
                        {
                                sum += nc2(count);
                                count = 1;
                        }
                }
                if(count>1)
                        sum += nc2(count);
                printf("%lld\n", sum);
                
        }

        return 0;
}