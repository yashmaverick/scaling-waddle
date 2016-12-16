#include<stdio.h>
int binarysearch(int a[],int x,int y,int z);
void daq(int a[],int first,int last);
int Index(int a[],int first,int last);
int main()
{       int t;
	scanf("%d",&t);
	while(t--)
	{
		int a[100000],i,n,j,k,l,x=0;
		char z[10000];
		scanf("%d%d",&n,&l);
			for(i=0;i<n;i++)
			{
				scanf("%s%d",z,&a[i]);
			}
		daq(a,0,n-1);
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				x=binarysearch(a,l-(a[j]+a[k]),k+1,n-1);
				if(x==1)
				{
					printf("YES\n");		
					break;
				}

			}
			if(x==1)
				break;
		}
		if(x==0)
			printf("NO\n");
	}
	return 0;
}
void daq(int a[],int first,int last)
{      
	int pivoted;
	if(first<=last)
	{

		pivoted=Index(a,first,last);
		daq(a,first,pivoted-1);
		daq(a,pivoted+1,last);

	}
	return ;
}
int Index(int a[],int first,int last)
{
	int i,j,temp,pivot;
	pivot=first;
	i=first;
	j=last;
	while(i<j)
	{
		while(a[i]<=a[pivot] && i<last)
			i++;
		while(a[j]>a[pivot])
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
	return j;
}
int binarysearch(int a[],int search,int first,int last)
{
	int mid,flag=0;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(search>a[mid])
		{
			first=mid+1;
		}
		else if(search<a[mid])
		{
			last=mid-1;
		}
		else
		{       flag=1;
			break;
		}
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
