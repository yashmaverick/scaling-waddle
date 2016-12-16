#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
	int w,x,xx,y,yy;
	long long int z;
	int g,h;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&nn);
		int a[nn];
		mm=0;
		int b[1000000]={0};
		x=10000000;
		while(mm<nn)
		{
			scanf("%d",&a[mm]);
			if(a[mm]<x)
			{
				x=a[mm];
			}
			mm++;
		}
		g=0;
		/*while(g<nn)
		{
			if(a[g]<x)
			{
				x=a[g];
			}
			g++;
		}*/
		h=0;
		while(h<nn)
		{
			a[h]=a[h]-x;
			h++;
		}
		y=0;
		while(y<nn)
		{
			xx=a[y];
			b[xx]++;
			y++;
		}
		yy=0;
		z=0;
		//printf("%d %d\n",b[0],b[1]);
		while(yy<1000000)
		{
			z=z+(((long long)b[yy]*(b[yy]-1))/2);
			yy++;
		}
		printf("%lld\n",z);
		m++;
	}
	return 0;
}
