#include<stdio.h>
void merge(int a[],int l1,int r1,int l2,int r2)
{
	int w,x,xx,y,yy,z;
	int k,kk;
	int b[(r1+r2)-(l1+l2)+2];
	x=l1;
	y=l2;
	k=0;
	while(x<=r1&&y<=r2)
	{
		if(a[x]<a[y])
		{
			b[k]=a[x];
			k++;
			x++;
		}
		else
		{
			b[k]=a[y];
			k++;
			y++;
		}
	}
	while(x<=r1)
	{
		b[k]=a[x];
		k++;
		x++;
	}
	while(y<=r2)
	{
		b[k]=a[y];
		k++;
		y++;
	}
	kk=l1;
	w=0;
	while(kk<r2+1)
	{
		a[kk]=b[w];
		kk++;
		w++;
	}
	return ;
}
void mergesort(int a[],int l,int r)
{
	int mid;
	mid=(l+r+1)/2;
	if(l>=r)
	{
		return ;
	}
	else
	{
		mergesort(a,l,mid-1);
		mergesort(a,mid,r);
		merge(a,l,mid-1,mid,r);
	}
	return ;
}
int main()
{
	int m,n;
	int mm,nn;
	int x,xx,y,yy,z;
	int w;
	int k;
	char c;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d%d",&nn,&k);
		int a[100000];
		mm=0;
		while(mm<nn)
		{
			while((c=getchar())!=' ')
			{
			}
			scanf("%d",&a[mm]);
			mm++;
		}
		mergesort(a,0,nn-1);
		//z=0;
		//while(z<nn)
		//{
			//printf("%lld\n",a[z]);
			//z++;
		//}
		x=0;
		xx=0;
		y=0;
		w=-1;
		int flag=0;
		while(x<nn-2)
		{
			xx=x+1;
			y=nn-1;
			while(xx<y)
			{
				if(a[x]+a[xx]+a[y]==k)
				{
					flag=1;
					break;
				}
				else if(a[x]+a[xx]+a[y]<k)
				{
					xx++;
				}
				else
				{
					y--;
				}
			}
			if(flag==1)
			{
				break;
			}
			x++;		
			
		}
		if(flag==0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		m++;
	}
	return 0;
}
