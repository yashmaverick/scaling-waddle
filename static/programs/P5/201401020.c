#include<stdio.h>
int a[10005];
void merge(int l,int mid,int r)
{
	int b[10005];
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
	int n,k,l,j,i,t;
	scanf("%d",&t);
	while(t--)
	{
		char c[1000];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&a[i]);
		}
		mergesort(0,n-1);
		int x,y,z;
		
		int flag=0;
		for(x=0;x<n;x++)
		{
			y=x+1;
			z=n-1;
			while(z>y)
			{
				if(a[x]+a[y]+a[z]<k)
					y++;
				else if(a[x]+a[y]+a[z]>k)
					z--;
				else
				{
					flag=1;
					printf("YES\n");
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

