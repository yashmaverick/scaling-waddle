#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
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
		long long int a[nn+1];
		long long int b[nn+1];
		ww=0;
		while(ww<nn)
		{
			scanf("%lld",&a[ww]);
			b[ww]=0;
			ww++;
		}
		mm=0;
		xx=-1;
		w=0;
		y=0;
		z=0;
		yy=0;
		while(mm<nn)
		{
			if(xx==-1||a[b[xx]]<=a[mm])
			{
				xx++;
				b[xx]=mm;
				//xx++;
				mm++;
			}
			else
			{
				yy=b[xx];
				b[xx]=0;
				xx--;
				y=a[yy]*((xx==-1)?mm:mm-b[xx]-1);
				if(y>z)
				{
					z=y;
//					printf("z%d\n",z);
				}
			}
		}
//		printf("%d %d %d %d\n",b[0],b[1],b[2],b[3]);
//		printf("YES1\n");
		while(xx>-1)
		{
			yy=b[xx];
			b[xx]=0;
			xx--;
			y=a[yy]*((xx==-1)?mm:(mm-b[xx]-1));
			if(y>z)
			{
				z=y;
//				printf("zz%d\n",z);
			}	
		}
		printf("%lld\n",z);
	}
	//m++;
	//}
	return 0;
}
