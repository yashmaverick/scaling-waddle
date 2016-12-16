#include<stdio.h>
void quicksort(int a[1000],int low,int high);
int find3num(int a[1000],int arr_size,int sum)
{
	int l,r,i;
	quicksort(a,0,arr_size-1);
	for( i=0;i<arr_size-2;i++)
	{
		l=i+1;
		r=arr_size-1;
		while(l<r)
		{
			if((a[i]+a[l]+a[r])==sum)
				return 1;
			else
				if((a[i]+a[l]+a[r])<sum)
					l++;
				else
					r--;
		}
	}
	return 9;
}
void quicksort(int a[1000],int low,int high)
{
	int pivot;
	if(high>low)
	{
		pivot=partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}
int partition(int a[1000],int low,int high)
{
	int left,right,temp;
	int pivot_item;
	pivot_item=a[low];
	left=low;
	right=high;
	while(left<right)
	{
		while(a[left]<=pivot_item)
		{
			left++;
		}
		while(a[right]>pivot_item)right--;
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}

	}
	a[low]=a[right];
	a[right]=pivot_item;
	return right;
}

int main()
{
	int t,n,k,r,l,m;
	int a[1000];
	int b[100000];
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(m=0;m<n;m++)
		{
			scanf("%s",b);
			scanf("%d",&a[m]);
		}
		r=find3num(a,n,k);
		if(r==1)
			printf("YES\n");
		if(r==9)
			printf("NO\n");

	}
	return 0;
}
