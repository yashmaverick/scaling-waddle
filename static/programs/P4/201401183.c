#include<stdio.h>
char a[100002];
int c[100002],cum[100002];
void merge(int low,int mid,int high)
{
	int l,i,j;
	for(i=low,j=mid+1,l=low;i<=mid&&j<=high;l++)
	{
		if(cum[i]<cum[j])
		{
			c[l]=cum[i];
			i++;
		}
		else
		{
			c[l]=cum[j];
			j++;
		}
	}
	if(l<=high)
	{
		while(i<=mid)
		{
			c[l]=cum[i];
			l++;
			i++;
		}
		while(j<=high)
		{
			c[l]=cum[j];
			l++;
			j++;
		}
	}
	for(i=low;i<=high;i++)
		cum[i]=c[i];
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
	char c;
	int t,i,j,n,count;
	scanf("%d",&t);
	while(t--)
	{	
	c=getchar();	
	scanf("%s",a);
		count=0;
		if(a[0]=='J')
			cum[0]=-100002;
		else if(a[0]=='M')
			cum[0]=1;
		else if(a[0]=='R')
			cum[0]=100001;
		for(i=1;a[i]!='\0';i++)
		{
			if(a[i]=='J')
				cum[i]=cum[i-1]-100002;
			else if(a[i]=='M')
				cum[i]=cum[i-1]+1;
			else if(a[i]=='R')
				cum[i]=cum[i-1]+100001;
		}
		n=i;
		mergesort(0,n-1);
		for(i=0;i<n;i++)
		{
			j=i;
			while(cum[j]==cum[j+1]&&j!=n-1)
			{
				j++;
			}
			count+=((j-i+1)*(j-i))/2;
			if(cum[j]==0)
				count+=j-i+1;
			i=j;
		}
		printf("%d\n",count);
	}
		return 0;
}
