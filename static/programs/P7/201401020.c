#include<stdio.h>
int a[1000005];
void merge(int l,int mid,int r)
{
	int b[1000005];
	int i;
	int x,y;
	x=l;
	y=mid+1;
	for(i=l;i<=r;i++)
	{
		if(x<=mid && y<=r)
		{
			if(a[x]<=a[y])
			{
				b[i]=a[x];
				x++;
			}
			else
			{
				b[i]=a[y];
				y++;
			}
		}
		else if(x>mid)
		{
			b[i]=a[y];
			y++;    
		}
		else
		{
			b[i]=a[x];
			x++;
		}
	}
	for(i=l;i<=r;i++)
		a[i]=b[i];
}

void mergesort(int l,int r)
{
	int mid=l+(r-l)/2;
	if(l==r)
		return ;
	else
	{
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}

int main()
{
	int n,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

		//int a[1005];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort (0,n-1);
		long long int num=0,j;
		int l,k;
		if(a[1]==a[0])
			j=1;
		else
			j=0;
		for(k=1;k<n;k++)
		{
			if(a[k]==a[k-1])
				j++;
			else
			{
				num=num+(j*(j-1))/2;
				j=1;
			}

		}
		num=num+(j*(j-1))/2;
		printf("%lld\n",num);
	}
	return 0;
}




















