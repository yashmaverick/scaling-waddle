#include<stdio.h>
int u,v,vv;
int bins(int a[],int l,int r)
{
	int w,x,y,z;
	w=a[r];
	int mid;
	r--;
	mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]>w)
		{
			r=mid-1;
		}
		if(a[mid]<w)
		{
			l=mid+1;
		}
	}
	if(mid==r&&a[mid]<w)
	{
		mid=mid+1;
	}
	//printf("%d\n",mid);
	return mid;
}
void post(int a[],int l,int r,int uu)
{
	int w,ww,x,xx,y,yy,z,zz;
	if(l>r)
	{
		return ;
	}
	if(l==r)
	{
		if(uu>u)
		{
			u=uu;
			v=a[l];
		}
		return ;
	}
	xx=l;
/*	while(a[xx]<a[r])
	{
		xx++;
	}*/
	xx=bins(a,l,r);
	uu++;
	post(a,l,xx-1,uu);
	post(a,xx,r-1,uu);
	return ;
}

int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int uu;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&nn);
		int a[nn];
		mm=0;
		while(mm<nn)
		{
			scanf("%d",&a[mm]);
			mm++;
		}
		u=0;
		uu=0;
		post(a,0,nn-1,uu);
		if(nn==1)
		{
			zz=0;
			z=a[0];
		}
		else
		{
			zz=u;
			z=v;
		}
		printf("%d %d\n",z,zz);
		m++;
	}
	return 0;
}
