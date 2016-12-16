//arr[i] = (int *)malloc(m+1)*sizeof(int));
#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[],int left,int mid,int right)
{
        int tempArr[right-left+1];
        int pos=0,lpos = left,rpos = mid + 1;
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
        int iter;
        for(iter = 0;iter < pos; iter++)
        {
                arr[iter+left] = tempArr[iter];
        }
        return;
}

void MergeSort(int arr[],int left,int right)
{
        int mid = (left+right)/2;
        if(left<right)
        {
                MergeSort(arr,left,mid);
                MergeSort(arr,mid+1,right);
                Merge(arr,left,mid,right);
        }
}


int main()
{
	int total, mod,total1,i,j,k,num,weight;
	scanf("%d", &total);
	scanf("%d", &mod);
	int *arr[total+1];
	int num_weights[total+1],sum_weights[total+1];
	for(i=0;i<total;i++)
	{
		scanf("%d", &num_weights[i]);
		num = num_weights[i] + 1;
		arr[i] = (int *)malloc((num) * sizeof(int));
		arr[i][0] = 0;
		for(j=1;j<=num_weights[i];j++)
		{
			scanf("%d", &weight);
			arr[i][j] = weight;
			arr[i][0] = arr[i][0]%mod;
			arr[i][0] =(arr[i][0]%mod+weight%mod)%mod;
		}
	}
	for(i=0;i<total;i++)
	{
		sum_weights[i]= arr[i][0];
	}
	MergeSort(sum_weights,0,total-1);
	for(i=0;i<total;i++)
	{	
		int row;
		for(j=0;j<total;j++)
		{
			if(sum_weights[i]==arr[j][0])
			{
				row = j;
				break;
				
			}
		}
		printf("%d\n", arr[row][0]);
		arr[row][0] = -1;
		for(k=1;k<=num_weights[row];k++)
		{
			printf("%d\n",arr[row][k]);
		}
		printf("\n");
		
	}
return 0;

}
