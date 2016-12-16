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

int check_2(long long int arr[], long long int size, long long int sum, long long int index)
{
	long long int left,right;
	left = 0;
	right = size - 1;
	while(left < right)
	{
		if(left==index)
			left++;
		else if(right==index)
			right--;
		else
		{
			if(arr[left]+arr[right]==sum)
				return 1;
			else if(arr[left]+arr[right] < sum)
				left++;
			else
				right--;
		}
	}
	return 0;
}

int check_3(long long int arr[], long long int size, long long int sum)
{
	long long int i,j,k;
	for(i=0; i<size; i++)
	{
		int flag = check_2(arr, size, sum - arr[i],i);
		if(flag == 1)
			return flag;
	}
	return 0;

}


int main()
{
        int t;
        scanf("%d",&t);
        char st[1000];
        long long int sum,i,size,arr[100007];
        while(t--)
        {
        	scanf("%lld %lld",&size, &sum);
        	for(i=0;i<size;i++)
        		scanf("%s %lld",st, &arr[i]);
        	MergeSort(arr,0,size-1);
        	int ans = check_3(arr,size,sum);
        	if(ans==1)
        		printf("YES\n");
        	else
        		printf("NO\n");
        }
        
        
        
        return 0;
}