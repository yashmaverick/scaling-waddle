#include<stdio.h>
long long int a[1000005];
void merge1sort(int low,int high,long long int pre[])
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge1sort(low,mid,pre);
		merge1sort(mid+1,high,pre);
		int i1=low;
		int j1=mid;
		int i2=mid+1;
		int j2=high;
		long long int temp[high-low+1];
		int i=0;
		while(i1<=j1 && i2<=j2)
		{
			if(pre[i1]<pre[i2])
			{
				temp[i]=pre[i1];
				i++;
				i1++;
			}
			else
			{
				temp[i]=pre[i2];
				i++;
				i2++;
			}
		}
		while(i1<=j1)
		{
			temp[i]=pre[i1];
			i++;
			i1++;
		}
		while(i2<=j2)
		{
			temp[i]=pre[i2];
			i++;
			i2++;
		}
		i1=low;
		int k=0;
		for(;k<i;k++)
		{
			pre[i1]=temp[k];
			i1++;
		}
	}
}
/*void mergesort(long long int A[],int l,int r)
{
	if(l==r-1)
		return;
	int mid = l + (r-l)/2;
	mergesort(A,l,mid);
	mergesort(A,mid,r);
	int  n = r - l;
	long long int B[n+1];
	int len=0;
	int p1,p2;
	for(p1=l,p2=mid ; p1<mid && p2<r ; ) 
		if(A[p1]<=A[p2])
			B[len++]=A[p1++];
		else
			B[len++]=A[p2++];
	while(p1<mid)
		B[len++]=A[p1++];
	while(p2<r)
		B[len++]=A[p2++];
	int i;
	for(i=l;i<r;i++)
		A[i] = B[i-l];
}*/
long long int b[1000005];
int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i=0;
		int size1=0,size2=0;
		for(;i<n;i++)
		{
			long long int val;
			scanf("%lld",&val);
			b[size2]=val;
			size2++;
			while(val/10!=0)
			{
				a[size1]=val/10;
				size1++;
				val=val/10;
			}
		}
		merge1sort(0,size1-1,a);
		merge1sort(0,size2-1,b);
		int flag=0;
		for(i=1;i<size2;i++)
		{
			if(b[i]==b[i-1])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(i=0;i<size2;i++)
			{
				int low=0;
				int high=size1-1;
				while(low<=high)
				{
					int mid=(low+high)/2;
					if(a[mid]>b[i])
					{
						high=mid-1;
					}
					else if(a[mid]<b[i])
					{
						low=mid+1;
					}
					else
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else printf("YES\n");   

	}
	return 0;
}





















