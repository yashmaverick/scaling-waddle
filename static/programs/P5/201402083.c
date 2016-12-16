#include<stdio.h>
#include<stdlib.h>
int arr[100001];
int luck(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int flag;
void search(int arr[],int k,int start,int end);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,find;
		scanf("%d %d",&n,&find);
	//	printf("$$$$$%d$$$$$$\n",find);
		int i;
		char str[1000];
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),luck);
	//	for(i=0;i<n;i++)
	//		printf(" %d ",arr[i]);
	//	printf("\n");

		int j;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				
				int temp=find-arr[j]-arr[i];
			//	printf("%d-find %d-temp %d-arr[j] %d-arr[i]\n",find,temp,arr[j],arr[i]);
				if(temp>arr[n-1])
				       continue;
				if( temp<arr[j])
					break;
				search(arr,temp,j+1,n-1);
				if(flag==1)
				{
					printf("YES\n");
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag==1)
			flag=0;
		else
			printf("NO\n");
	}
	return 0;
}

void search(int arr[],int k,int start,int end)
{
	if(start>=end)
	{
		if(start==end)
			if(arr[start]==k)
				flag=1;
		return ;
	}
	int mid=(start+end)/2;
	//printf("$$$$$%d$$$$$$$%d$$$$$$%d$\n",arr[mid],flag,k);
	if(arr[mid]==k)
	{
		flag=1;
		return;
	}
	else if(arr[mid]>k)
		search(arr,k,start,mid);
	else
		search(arr,k,mid+1,end);
}



