#include<stdio.h>
#include<stdlib.h>
void merge(int *a[],int l1,int r1,int l2,int r2)
{
	int x,xx,y,yy;
	int k,kk;
	int *b[(r1+r2)-(l1+l2)+2];
	x=l1;
	y=l2;
	k=0;
	while(x<=r1&&y<=r2)
	{
		if(*a[x]<=*a[y])
		{
			b[k]=a[x];
			x++;
			k++;
		}
		else
		{
			b[k]=a[y];
			y++;
			k++;
		}
	}
	while(x<=r1)
	{
		b[k]=a[x];
		x++;
		k++;
	}
	while(y<=r2)
	{
		b[k]=a[y];
		y++;
		k++;
	}
	kk=0;
	xx=l1;
	while(kk<k)
	{
		a[xx]=b[kk];
		//printf("aaaaaaa %d aaaaaa ",*a[xx]);
		xx++;
		kk++;
	}
	//printf("l1:%d r1:%d l1:%d r2:%d\n",l1,r1,l2,r2);
	return ;
}
void mergesort(int *a[],int l,int r)
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
	int w,ww,x,xx,y,yy,z,zz;
	int u,uu,v,vv;
	int mod;
	//scanf("%d",&n);
	//m=0;
	//while(m<n)
	//{
		scanf("%d%d",&nn,&mod);
		int *a[nn];
		mm=0;
		while(mm<nn)
		{
			scanf("%d",&yy);
			//printf("YES\n");
			a[mm]=(int *)malloc((yy+2)*sizeof(int));
			//printf("YES1\n");
			xx=2;
			u=0;
			while(xx<yy+2)
			{
				scanf("%d",&uu);
				a[mm][xx]=uu;
				u=(u%mod+uu%mod)%mod;
				xx++;
			}
			a[mm][0]=u;
			a[mm][1]=yy;
			mm++;
		}
		//printf("YES2\n");
		ww=0;
		/*while(ww<nn)
		{
			zz=0;
			while(zz<a[ww][1]+2)
			{
				printf("%d ",a[ww][zz]);
				zz++;
			}
			printf("\n");
			ww++;
		}*/
		mergesort(a,0,nn-1);
		//printf("YES3\n");
		/*ww=0;
		while(ww<nn)
		{
			zz=0;
			while(zz<a[ww][1]+2)
			{
				printf("%d ",a[ww][zz]);
				zz++;
			}
			printf("\n");
			ww++;
		}*/
		ww=0;
		while(ww<nn)
		{
			zz=0;
			printf("%d\n",*a[ww]);
			while(zz<a[ww][1])
			{
				printf("%d\n",a[ww][zz+2]);
				zz++;
			}
			printf("\n");
			ww++;
		}
		//m++;
	//}
	return 0;
}
