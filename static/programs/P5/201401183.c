#include<stdio.h>
int a[100002],c[100002];
void merge(int low,int mid,int high)
{
	int l,i,j;
	for(i=low,j=mid+1,l=low;i<=mid&&j<=high;l++)
	{
		if(a[i]<a[j])
		{
			c[l]=a[i];
			i++;
		}
		else
		{
			c[l]=a[j];
			j++;
		}
	}
	if(l<=high)
	{
		while(i<=mid)
		{
			c[l]=a[i];
			l++;
			i++;
		}
		while(j<=high)
		{
			c[l]=a[j];
			l++;
			j++;
		}
	}
	for(i=low;i<=high;i++)
		a[i]=c[i];
}
void mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
	if(low==high)
		return;
}
int main()
{
  int flag,rem,start,end,sum,left,i,j,t,n,k;
	char x,y;
	scanf("%d",&t);
	while(t--)
	{	
		sum=0,left=0,flag=0;
		flag=0;
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		{	
		  x=y;
		  while(x!=' ')
		    x=getchar();
			scanf("%d",&a[i]);
		}
		mergesort(0,n-1);
		for(i=0;i<n-2;i++)
		  {
		    start=i+1;
		    end=n-1;
		    while(start<end)
		      {
			sum=a[start]+a[end];
			rem=k-sum;
			if(a[i]==rem)
			  {
			    printf("YES\n");
			    flag=1;
			    break;
			  }
			else if(a[i]<rem)
			  start++;
			else end--;
		      }
		    if(flag==1)break;
		  }
		if(flag!=1)
		  printf("NO\n");
	}
	return 0;
}
