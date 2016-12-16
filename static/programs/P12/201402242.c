#include<stdio.h>
int a[500050]={0};
int main()
{
	int m,n;
	long long int mm,nn;
	long long int w,ww,x,xx,y,yy,z,zz;
	//scanf("%d",&n);
	//m=0;
	//while(m<n)
	//{
	while(1)
	{
		scanf("%lld",&nn);
		if(nn==0)
		{
			break;
		}
		mm=0;
		xx=0;
		zz=0;
		z=0;
		while(mm<nn)
		{
			scanf("%lld",&x);
			if(xx==0||a[xx-1]>=x)
			{
				a[xx]=x;
				xx++;
			}
			else
			{
				yy=0;
				while(xx>=1&&a[xx-1]<x)
				{
					ww=0;
					while(xx>=3&&a[xx-1]==a[xx-2])
					{
						a[xx-1]=0;
						ww++;
						yy++;
						xx--;
					}
					if(xx>=2&&a[xx-1]!=a[xx-2])
					{
						z=z+(ww+1)*(xx-2);
						//printf("z:%d\n",z);
					}
					//a[xx-1]=0;
					//yy++;
					//xx--;
					a[xx-1]=0;
					yy++;
					xx--;
				}
				z=z+yy*((nn-1)-mm);
				//printf("%d %lld\n",mm,z);
				a[xx]=x;
				xx++;
			}
			mm++;
		}
		//printf("%lld\n",z);
		while(xx>=2)
		{
			//printf("%d %d\n",a[xx-1],a[xx-2]);
			ww=0;
			w=xx;
			while(xx>=3&&a[xx-1]==a[xx-2])
			{
				ww++;
				a[xx-1]=0;
				xx--;
			}
			if(a[xx-1]!=a[xx-2])
			{
				z=z+(ww+1)*(xx-2);
				//printf("z:%d\n",z);
			}
			xx--;
		}
		printf("%lld\n",z);
		//m++;
	//}
	}
	return 0;
}
