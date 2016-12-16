#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z;
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
		x=0;
		y=0;
		xx=0;
		yy=0;
		z=0;
		while(xx<nn)
		{
			if(a[xx]<a[x])
			{
				x=xx;
			}
			if(a[xx]-a[x]>z)
			{
				z=a[xx]-a[x];
			}
			xx++;
		}
		printf("%d\n",z);
		m++;
	}
	return 0;
}

			
