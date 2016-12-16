#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
	int w,x,xx,y,yy,z;
	int g1,g2,g3;
	int h1,h2,h3;
	int mid,midd;
	int l,r,ll,rr;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&h1);
		int a[h1];
		g1=0;
		while(g1<h1)
			scanf("%d",&a[g1++]);
		scanf("%d",&h2);
		int b[h2];
		g2=0;
		while(g2<h2)
			scanf("%d",&b[g2++]);
		scanf("%d",&h3);
		int c[h3];
		g3=0;
		while(g3<h3)
			scanf("%d",&c[g3++]);
		x=0;
		z=0;
		while(x<h1)
		{
			if(b[x]>=a[x])
				xx=x;
			else if(b[h2-1]<a[x])
				xx=h2;
			else
			{
				l=x;
				r=h2-1;
				while(l<=r)
				{
					mid=(l+r)/2;	
					if(b[mid]<a[x]&&b[mid+1]>=a[x])
					{
						xx=mid+1;
						break;
					}
					else if(b[mid]>=a[x]&&b[mid-1]<a[x])
					{

						xx=mid;
						break ;
					}//return mid+!;	
					else if(b[mid]>a[x]&&b[mid-1]>a[x])
						r=mid-1;
					else if(b[mid]<a[x]&&b[mid+1]<a[x])
						l=mid+1;
						/*if(b[mid]>=a[x])
						{
							xx=mid;
							break;
						}
						else
						{	
							mid++;
							xx=mid;
							break;
						}*/
				}
			}
			while(xx<h2)
			{
				if(c[xx]>=b[xx])
					yy=xx;
				else if(c[h3-1]<b[xx])
					yy=h3;
				else
				{
					ll=xx;
					rr=h3-1;
					while(ll<=rr)
					{
						midd=(ll+rr)/2;
						if(c[midd]>b[xx]&&c[midd-1]>b[xx])
							rr=midd-1;
						if(c[midd]<b[xx]&&c[midd+1]<b[xx])
							ll=midd+1;
						else
						{
							if(c[midd]>=b[xx])
							{
								yy=midd;
								break;
							}
							else
							{
								midd++;
								yy=midd;
								break;
							}
						}
					}

				}
				z=z+(h3-yy);
				xx++;
			}
			x++;
		}
		printf("%d\n",z);
		m++;
	}
	return 0;
}
