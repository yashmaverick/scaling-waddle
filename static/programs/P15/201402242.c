#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int u,uu,v,vv;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d%d",&nn,&vv);
		int a[nn];
		mm=0;
		while(mm<nn)
		{
			/*if(mm*mm<=nn)
			  {
			  v=mm;
			  }*/
			scanf("%d",&a[mm]);
			mm++;
		}
		//int b[v+1];
		xx=0;
		yy=xx+vv-1;
		uu=-1;
		while(xx<nn-vv+1)
		{
			if(uu<xx)
			{
				u=xx;
				uu=xx;
				while(u<=xx+vv-1)
				{
					if(a[u]<=a[uu])
					{
						uu=u;
					}
					u++;
				}
			}
			//printf("uu%d",uu);
			if(a[xx+vv-1]<a[uu])
			{
				uu=xx+vv-1;
			}
			printf("%d%c",a[uu],(xx==nn-vv)?'\n':' ');
			xx++;
		}
		m++;
	}
	return 0;
}


