#include<stdio.h>
#include<stdlib.h>
int *a;
int wall(int start,int pivot)
{
	int wall=start;
	int i;
	int temp;
	int value=a[pivot];
	for(i=start;i<pivot;i++)
	{
		if(a[i] < value)
		{
			temp=a[wall];
			a[wall]=a[i];
			a[i]=temp;
			wall++;
		}
	}
	temp=a[pivot];
	a[pivot]=a[wall];
	a[wall]=temp;
	return wall;
}
void quicksort(int low,int high)
{
	if(low<high)
	{
		int pivot=wall(low,high);
		quicksort(low,pivot-1);
		quicksort(pivot+1,high);
	}
	return ;
}
int main()
{
	int N,ll;
	scanf("%d",&N);
	for(ll=1;ll<=N;ll++)
	{	
		int n;
		int i;
		int k;
		scanf("%d%d",&n,&k);
		a=malloc(n*sizeof(int));
		char string[1000];
		for(i=0;i<n;i++)
		{
			scanf("%s%d",string,&a[i]);
		}
		quicksort(0,n-1);int flag;
		for(i=0;i<n-2;i++)
		{flag=0;
			int l=i+1;
			int r=n-1;
			while(l<r)
			{
				if(a[i]+a[l]+a[r]==k)
				{	
					printf("YES\n");
					flag=1;	
				}
				else if(a[i]+a[l]+a[r]<k)
					l++;
				else
					r--;
				if(flag==1)
					break;
			}
				if(flag==1)
					break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}
