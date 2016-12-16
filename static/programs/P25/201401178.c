#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	long long int first;
	long long int last;
	long long int wgt;
}node;
void merge(node left[],node right[],node c[],long long int m,long long int u)
{
	long long int i=0,j=0,k=0;
	while(i<m && j<u)
	{
		if(left[i].wgt<right[j].wgt)
		{
			c[k++]=left[i++];
		}
		else if(left[i].wgt>right[j].wgt)
		{
			c[k++]=right[j++];
		}
		else
		{
			c[k++]=left[i++];
			c[k++]=right[j++];
		}
	}
	while(i<m)
	{
		c[k++]=left[i++];
	}
	while(j<u)
	{
		c[k++]=right[j++];
	}
}
long long int merge_sort(node a[],long long int n)
{

	long long int i;
	node left[n];
	node right[n];
	if(n<=1)
	{
		return;
	}
	for(i=0;i<n/2;i++)
	{
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{
		right[i-n/2]=a[i];
	}
	merge_sort(left,n/2);
	merge_sort(right,n-(n/2));
	merge(left,right,a,n/2,n-(n/2));
}
int main(){
	long long int nodes,edges;
	scanf("%lld%lld",&nodes,&edges);
	long long int z;
	node arr[edges];
	for(z=0;z<edges;z++){
		scanf("%lld%lld%lld",&arr[z].first,&arr[z].last,&arr[z].wgt);
	}
//	printf("-------------\n");
	merge_sort(arr,edges);
//	for(z=0;z<edges;z++)
//		printf("%lld %lld %lld\n",arr[z].first,arr[z].last,arr[z].wgt);
	long long int i;
	long long int count=0;
	long long int sum=0;
	long long int flag=0;
	long long int root[100001];
	long long int parent[100001]={0};
	for(i=1;i<=nodes;i++){
		root[i]=i;
//		printf("%lld ",root[i]);
	}
//	printf("\n");
	for(i=0;i<edges;i++){
		if(root[arr[i].first]!=root[arr[i].last]){
			sum=sum+arr[i].wgt;
			count++;
			long long int b,fix;
			fix=root[arr[i].last];
			for(b=1;b<=nodes;b++){
				if(root[b]==fix){
					root[b]=root[arr[i].first];
				}
			}
//			for(b=1;b<=nodes;b++){
//				printf("%lld ",root[b]);
//			}
//			printf("\n%lld %lld\n",sum,count);
			if(count==nodes-1)
				flag=1;
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
