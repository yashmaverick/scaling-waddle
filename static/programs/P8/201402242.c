#include<stdio.h>
int main()
{
	int m,n;
	unsigned long long int mm,nn;
	unsigned long long int w,x,xx,y,yy;
	unsigned long long int z,zz;
	unsigned long long int g,h;
	unsigned long long int u,d,dd;
	unsigned long long int a,b,c;
	unsigned long long int k,kk,kkk;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%llu%llu%llu%llu",&u,&d,&mm,&nn);
		w=0;
		z=0;
    		while(w<nn&&w<=u)
		{
			x=0;
			dd=d;
			h=w%nn;
			a=1;
			while(dd>0)
			{
				if(dd%2==1)
				{
					a=(a*h%nn)%nn;
				}
				dd=dd/2;
				h=((h%nn)*(h)%nn)%nn;
			}
			if(d==0)
			{
				a=1;
			}
			while(x<nn&&x<=u)
			{
				y=0;
				dd=d;
				h=x%nn;
				b=1;
				while(dd>0)
				{
					if(dd%2==1)
					{
						b=(b*h%nn)%nn;
					}
					dd=dd/2;
					h=((h%nn)*(h%nn))%nn;
				}		
				if(d==0)
				{
					b=1;
				}
				while(y<nn&&y<=u)
				{
					dd=d;
					h=y%nn;
					c=1;
					while(dd>0)
					{
						if(dd%2==1)
						{
							c=((c%nn)*(h%nn))%nn;
						}
						dd=dd/2;
						h=(h*h)%nn;
					}
					if(d==0)
					{
						c=1;
					}
					zz=0;
					if((a+b+c)%nn==mm)
					{
						//printf("%llu %llu %llu\n",w,x,y);
						k=0;kk=0;kkk=0;
						if(w<=u%nn)
						{
							k=1;
						}
						if(x<=u%nn)
						{
							kk=1;
						}
						if(y<=u%nn)
						{
							kkk=1;
						}
						zz=(((((u/nn)%1000000007+k)*((u/nn)%1000000007+kk))%1000000007)*((u/nn)%1000000007+kkk))%1000000007;
						//printf("%llu %llu %llu %llu %llu\n",zz,k,kk,kkk,u/nn);
						z=(z+zz)%1000000007;
					}
					y++;
				}
				x++;
			}
			w++;
		}
		printf("%llu\n",z);
		m++;
	}
	return 0;
}
