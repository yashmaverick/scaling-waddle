#include<stdio.h>
#include<stdlib.h>
void quicksort(int sum[],int **a,int first,int last)
{
	int pivot,j,temp,i;
	int *te;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(sum[i]<=sum[pivot]&&i<last)
				i++;
			while(sum[j]>sum[pivot])
				j--;
			if(i<j){
				temp=sum[i];
				sum[i]=sum[j];
				sum[j]=temp;
				if(sum[i]!=sum[j])
				{
					te=*(a+i);
					*(a+i)=*(a+j);
					*(a+j)=te;
				}
			}
		}
		if(sum[pivot]!=sum[j])
		{
			te=*(a+pivot);
			*(a+pivot)=*(a+j);
			*(a+j)=te;
		}
		temp=sum[pivot];
		sum[pivot]=sum[j];
		sum[j]=temp;
		quicksort(sum,a,first,j-1);
		quicksort(sum,a,j+1,last);

	}
}
int main()
{
	int i,j,n,temp,temp1;
	int sum[1002]={0};
	int mod;
	scanf("%d%d",&n,&mod);
	int *a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		*(a+i)=(int*)malloc((temp+1)*sizeof(int));
		for(j=0;j<temp;j++)
		{
			scanf("%d",(*(a+i)+j));
//			printf("val:%d\n",a[i][j]);
			sum[i]=(sum[i]%mod+(*(*(a+i)+j))%mod)%mod;
		}
		*(*(a+i)+j)=-1;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d\n",sum[i]);
		for(j=0;*(*(a+i)+j)!=-1;j++)
			printf("%d\n",*(*(a+i)+j));
		printf("\n");
	}*/
	//printf("abcdsomething:%d\n",a[2][6]);
	quicksort(sum,a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",sum[i]);
		for(j=0;*(*(a+i)+j)!=-1;j++)
			printf("%d\n",*(*(a+i)+j));
		printf("\n");
	}
	return 0;
}
