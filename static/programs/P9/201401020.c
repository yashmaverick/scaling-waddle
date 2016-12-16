#include<stdio.h>
int c[1000][2];
void merge(int l,int mid,int r)
{
	int b[1000],d[1000];
	int i;
	int x,y;
	x=l;
	y=mid+1;
	for(i=l;i<=r;i++)
	{
		if(x<=mid && y<=r)
		{
			if(c[x][0]<=c[y][0])
			{
				b[i]=c[x][0];
				d[i]=c[x][1];
				x++;
			}
			else
			{
				b[i]=c[y][0];
				d[i]=c[y][1];
				y++;
			}
		}
		else if(x>mid)
		{
			b[i]=c[y][0];
			d[i]=c[y][1];
			y++;    
		}
		else
		{
			b[i]=c[x][0];
			d[i]=c[x][1];
			x++;
		}
	}
	for(i=l;i<=r;i++)
	{
		c[i][0]=b[i];
		c[i][1]=d[i];
	}
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
	int l,k,j,i,f;
	int a[1000][1005];
	int n,mod;
	scanf("%d",&n);
	scanf("%d",&mod);
	for(i=0;i<n;i++)
	{
		int sum=0;
		scanf("%d",&a[i][0]);
		for(j=1;j<=a[i][0];j++)
		{
			scanf("%d",&a[i][j]);
			sum=sum+a[i][j];
		}
		sum=sum%mod;
		c[i][0]=sum;
		c[i][1]=i;
	}
	mergesort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",c[i][0]);
		l=c[i][1];
		for(j=1;j<=a[l][0];j++)
		{
			printf("%d\n",a[l][j]);
		}
		printf("\n");
	}
	return 0;
}

