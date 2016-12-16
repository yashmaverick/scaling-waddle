#include<stdio.h>
/*int mid_array(int a[],int low,int mid,int high)
{


	int left_max=-1000050000,sum,i,lmax_coordinate,rmax_coordinate;
	int right_max=-1000050000;
	sum=0;
	for(i=mid;i>=low;i--)
	{
		sum=sum+a[i];
		if(sum>left_max)
		{
			left_max=sum;
			lmax_coordinate=i;
		}
	}
	sum=0;
	for(i=mid+1;i<=high;i++)
	{
		sum=sum+a[i];
		if(sum>right_max)
		{
			right_max=sum;
			rmax_coordinate=i;
		}
	}
	return (left_max+right_max);
}
int max_sum(int a[],int low,int high)
{
	int mid,left_low,left_high,left_max,right_low,right_high,right_max,mid_low,mid_high,mid_max;
	if(low==high)
	{
		if(a[low]>0)
			return a[low];
		else
			return 0;
	}
	else
	{
		mid=(low+high)/2;
		left_max = max_sum(a,low,mid);
		right_max = max_sum(a,mid+1,high);
		mid_max = mid_array(a,low,mid,high);
		if(left_max>=right_max && left_max>=mid_max)
			return(left_max);
		else if(right_max>=left_max && right_max>=mid_max)
			return (right_max);
		else return (mid_max);
	}
}*/
int main()
{
	int t,n,i,a[100005],diff,stoch,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		stoch=a[n-1]-a[n-2];
		for(i=n-1;i>0;i--)
		{
			diff=a[i]-a[i-1];
			if(diff>0)
			{
				temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
			}
			if(diff>stoch)
				stoch=diff;
		}
		if(stoch<0)
			printf("0\n");
		else
			printf("%d\n",stoch);
	}
	return 0;
}
