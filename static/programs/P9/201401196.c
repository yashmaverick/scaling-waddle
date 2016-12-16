#include <stdio.h>
#include<stdlib.h>

struct Weight
{
	int *item;
	int w;
	int no;
};

void merge(int arr[][2],int low,int mid,int high)
{
	int i,j,k,x,temp[100009][2];
	i=low;
	j=low;
	k=mid+1;
	while((i<=mid)&&(k<=high))
	{
		if(arr[i][0]<=arr[k][0])
		{
			temp[j][0]=arr[i][0];
			temp[j][1]=arr[i][1];
			i++;
		}
		else
		{
			temp[j][0]=arr[k][0];
			temp[j][1]=arr[k][1];
			k++;
		}
		j++;
	}
	if(i>mid)
	{
		for(x=k;x<=high;x++,j++)
		{
			temp[j][0]=arr[x][0];
			temp[j][1]=arr[x][1];
		}
	}
	else
	{
		for(x=i;x<=mid;x++,j++)
		{
			temp[j][0]=arr[x][0];
			temp[j][1]=arr[x][1];
		}
	}
	for(x=low;x<=high;x++)
	{
		arr[x][0]=temp[x][0];
		arr[x][1]=temp[x][1];
	}
}


void partition(int arr[][2],int low,int high)
{
	if(low>=high)
		return;
	int mid=(low+high)/2;
	partition(arr,low,mid);
	partition(arr,mid+1,high);
	merge(arr,low,mid,high);
}


int main()
{
	int i,j,k,n;
	int mod,num;
	scanf("%d %d",&n,&mod);
	struct Weight bag[n];
	int arr[n][2];
	for(i=0;i<n;i++)
	{
		scanf("%d",&bag[i].no);
		bag[i].w=0;
		bag[i].item=(int *)malloc(sizeof(int)*(bag[i].no));
		for(j=0;j<bag[i].no;j++)
		{
			scanf("%d",&bag[i].item[j]);
		//	printf("**%d**\n",bag[i].item[j]);
			bag[i].w=(bag[i].w+bag[i].item[j])%mod;

		}
		arr[i][0]=bag[i].w;
		arr[i][1]=i;
	}
//	for(i=0;i<n;i++)
//		printf("%d ",arr[i][0]);
//	printf("\n");
	partition(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i][0]);
		for(j=0;j<bag[arr[i][1]].no;j++)
			printf("%d\n",bag[arr[i][1]].item[j]);
		printf("\n");
	}
	return 0;

}

