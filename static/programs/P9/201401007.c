#include<stdio.h>
#include<stdlib.h>
#define MAX 1001
typedef struct array{
    int sum;
    int *head;
    int size;
}name;
void bs(name array[],int n)
{
    name swap;
    int c,d;
    for(c=0;c<(n-1);c++)
    {
	for(d=0;d<n-c-1;d++)
	{
	    if(array[d].sum>array[d+1].sum)
	    {
		swap=array[d];
		array[d]=array[d+1];
		array[d+1]=swap;
	    }
	}
    }
}
void mergeSort(name arr[],int low,int mid,int high);
void partition(name arr[],int low,int high);
void partition(name arr[],int low,int high){

    int mid;
    if(low<high){
	mid=(low+high)/2;
	partition(arr,low,mid);
	partition(arr,mid+1,high);
	mergeSort(arr,low,mid,high);
    }
}
void mergeSort(name arr[],int low,int mid,int high){

    int i,m,k,l;
    name temp[MAX];
    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

	if(arr[l].sum<=arr[m].sum){
	    temp[i].sum=arr[l].sum;
	    temp[i].head=arr[l].head;
	    temp[i].size=arr[l].size;
	    l++;
	}
	else{
	    temp[i].sum=arr[m].sum;
	    temp[i].head=arr[m].head;
	    temp[i].size=arr[m].size;
	    m++;
	}
	i++;
    }

    if(l>mid){
	for(k=m;k<=high;k++){
	    temp[i].sum=arr[k].sum;
	    temp[i].head=arr[k].head;
	    temp[i].size=arr[k].size;
	    i++;
	}
    }
    else{
	for(k=l;k<=mid;k++){
	    temp[i].sum=arr[k].sum;
	    temp[i].head=arr[k].head;
	    temp[i].size=arr[k].size;
	    i++;
	}
    }

    for(k=low;k<=high;k++){
	arr[k].sum=temp[k].sum;
	arr[k].head=temp[k].head;
	arr[k].size=temp[k].size;
    }
}
int main()
{
    int n,MOD,i,W,j,sum,m;
    name A[1001];
    scanf("%d %d",&n,&MOD);
    for(i=0;i<n;i++)
    {
	sum=0;
	scanf("%d",&m);
	A[i].size=m;
	A[i].head=(int*)malloc(m*sizeof(int));
	for(j=0;j<m;j++)
	{
	    scanf("%d",&W);
	    A[i].head[j]=W;
	    sum=(sum+W%MOD)%MOD;
	}
	A[i].sum=sum;
    }
    partition(A,0,n-1);
    for(i=0;i<n;i++)
    {
	printf("%d\n",A[i].sum);
	for(j=0;j<A[i].size;j++)
	{
	    printf("%d\n",A[i].head[j]);
	}
	printf("\n");
    }
    return 0;
}
