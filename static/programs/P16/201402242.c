#include<stdio.h>
long long int yy;
long long int decl(long long int g)
{
	int m,n;
	int mm,nn;
	long long int w,x,xx,y,z;
	xx=2;
	yy=2;
	w=1;
	x=g;
	while(yy<=x)
	{
		yy=yy*xx;
		w++;
	}
	return w-1;

}
int main()
{
	int m,n;
	int mm,nn;
	long long int w,ww,x,xx,y,z,zz;
	long long int g,h;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%lld",&g);
		zz=decl(g);
		//printf("zz:%d %d\n",zz,yy);
		if(g<=yy-1&&g>=yy-(yy/4))
		{
			z=zz*2;
		}
		else
		{
			z=zz*2-1;
		}
		if(g==1)
		{
			z=0;
		}
		printf("%lld\n",z);
		m++;
	}
	return 0;
}

