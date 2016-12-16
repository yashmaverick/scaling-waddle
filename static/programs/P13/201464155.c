#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max=0;
int small=100001;
int flag=0;
int arr[100001];
int bst(int a[],int depth,int start,int end)
{
	//printf("small=%d  and depth=%d\n",small,depth);
	if(depth>max)
		max=depth;
	/*if(start>end)
		return 100001;*/
	if(start>=end)
		return a[start];
	else{
	int value=a[end];
	int left=binary(a,start,end-1,value);
		/*printf("left is %d\n",a[left]);
		printf("bst for %d to %d\n",a[start],a[left]);
		printf("left is %d\n",a[left]);*/
	int l=bst(a,depth+1,start,left);
	if((max==depth+1))
	{
		if(arr[max]==0)
			small=l;
		else if(arr[max]!=0&&l<small){
				small=l;
		}
		arr[max]++;
	}
		//printf("left is %d\n",a[left]);
		//printf("bst for %d to %d\n",a[left+1],a[end-1]);
	int r=bst(a,depth+1,left+1,end-1);
	if((max==depth+1))
	{
		if(arr[max]==0)
			small=r;
		else if(arr[max]!=0&&r<small)
			small=r;
		arr[max]++;
	}
	}
return a[start];
}

/*int bst1(int a[],int depth,int start,int end)
{
	if(depth==max&&a[start]<small)
	{	small= a[start];
		return 1;
	}
	if(start>end)
		return 100001;
	if(start==end&&depth==max&&small>a[start])
	{small=a[start];
	return 1;}
	int value=a[end];
	int left=binary(a,start,end-1,value);
	int l=bst(a,depth+1,start,left);
	int r=bst(a,depth+1,left+1,end-1);
}*/

int binary(int a[],int s,int e,int v)
{
	//printf("s=%d\n",s);
	if(e<s || a[s]>v)
	{
		return s-1;
	}
	int low=s,high=e,mid;
	while(low<high && a[high]>v)
	{
		mid=low+(high-low+1)/2;
		if(a[mid]>v)
		{
			high=mid-1;
		}
		else
		{
			low=mid;
		}
	}
	return high;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	int n,i,io;
	max=0;
	small=100001;
	flag=0;
	for(io=0;io<100001;io++)
		arr[io]=0;
	scanf("%d",&n);
	int a[n];
	//memset(arr,0,sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int re=bst(a,0,0,n-1);
	//int rep=bst1(a,0,0,n-1);
	if(small==100001)
		small=a[0];
	printf("%d %d\n",small,max);
	}
	return 0;
}
