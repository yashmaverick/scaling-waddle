#include<stdio.h>
int max,val;
int binSearch(int* arr,int l,int r)
{
	int mid,l1 = l,r1 = r;
	mid = l;
	while(l <= r)
	{
		mid = l+  ((r-l)/2);
		if(l==r)
		{
			if(arr[l] > arr[r1+1])
				return l;
			else if(arr[l]<arr[r1+1])
				return l+1;
		}
		if(arr[mid] < arr[r1+1])
			l = mid + 1;
		else
			r = mid - 1;
	}
	/*if(l == l1)
		return l1;
	if(r == r1)
		return r1;
	if(arr[mid] < arr[r+1])
		return r;
	else
		return l;*/
	return mid;
}
void find(int* arr,int l,int r,int depth)
{
	if(l > r)
		return;
	int i;
	if(depth > max)
	{
		max = depth;
		val = arr[r];
	}
	else if(depth == max)
		val = val < arr[r] ? val : arr[r];
	if(l==r)
		return;
	i = binSearch(arr,l,r-1);
	/*for(i=l;i<r;i++)
	{
		if(arr[i] > arr[r])
			break;
	}*/
	find(arr,l,i-1,depth+1);
	find(arr,i,r-1,depth+1);
	return;
}


int main()
{
	int t,n,i;
	int arr[100001];
	scanf("%d",&t);
	while(t--)
	{
		max=-1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",arr+i);
		val = arr[n];
		find(arr,1,n,0);
		printf("%d %d\n",val,max);
	}
	return 0;
}



