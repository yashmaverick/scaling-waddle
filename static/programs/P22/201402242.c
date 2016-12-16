#include<stdio.h>
int a[2000005]={0};
int b[2000005]={0};
void mnh(int a[],int x,int mm)
{
	int m,n;
	int w,ww,xx,y,yy,z,zz;
	a[mm]=x;
	int sw;
	while(mm>1&&a[mm/2]>a[mm])
	{

		sw=a[mm];
		a[mm]=a[mm/2];
		a[mm/2]=sw;
		mm=mm/2;
	}
	return ;
}
void mxh(int a[],int x,int mm)
{
	int m,n;
	int w,ww,xx,y,yy,z,zz;
	a[mm]=x;
	//printf("xxxxxxx:%d %d %d\n",a[1],x,mm);
	while(mm>1&&a[mm/2]<a[mm])
	{
		int sw;
		sw=a[mm];
		a[mm]=a[mm/2];
		a[mm/2]=sw;
		mm=mm/2;
	}
	return ;
}
void dmnhp(int a[],int mm)
{
	int m,n;
	int w,ww,x,xx,y,yy,z,zz;
	a[1]=a[mm];
	mm=mm-1;
	w=1;
	while(2*w<=mm)
	{
		int sw;
		if(2*w==mm&&a[2*w]<a[w])
		{
			sw=a[2*w];
			a[2*w]=a[w];
			a[w]=sw;
		}
		else if((a[w]>a[2*w]||a[w]>a[2*w+1])&&a[2*w]<=a[2*w+1])
		{
			sw=a[2*w];
			a[2*w]=a[w];
			a[w]=sw;
			w=2*w;
		}
		else if((a[w]>a[2*w]||a[w]>a[2*w+1])&&a[2*w+1]<=a[2*w])
		{
			sw=a[2*w+1];
			a[2*w+1]=a[w];
			a[w]=sw;
			w=2*w+1;
		}
		else
		{
			break ;
		}
	}
	return ;
}
void dmxhp(int a[],int mm)
{
	int m,n;
	int w,ww,x,xx,y,yy,z,zz;
	a[1]=a[mm];
	mm=mm-1;
	w=1;
	while(2*w<=mm)
	{
		int sw;
		if(2*w==mm&&a[2*w]>a[w])
		{
			sw=a[2*w];
			a[2*w]=a[w];
			a[w]=sw;
		}
		else if((a[2*w]>a[w]||a[2*w+1]>a[w])&&a[2*w]>=a[2*w+1])
		{
			sw=a[2*w];
			a[2*w]=a[w];
			a[w]=sw;
			w=2*w;
		}
		else if((a[2*w]>a[w]||a[2*w+1]>a[w])&&a[2*w+1]>=a[2*w])
		{
			sw=a[2*w+1];
			a[2*w+1]=a[w];
			a[w]=sw;
			w=2*w+1;
		}
		else
		{
			break ;
		}
	}
	return ;
}   
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	long long int u,uu,v,vv;
	int k,kk;
	long long int g,gg,h,hh;
	int MOD;
	MOD=1000000007;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%lld%lld%lld%d",&g,&gg,&h,&nn);
		mm=1;
		xx=1;
		yy=1;
		w=1;
		uu=0;
		if(nn==1)
		{
			mm++;
			w=1;
			printf("%d\n",1);
		}
		else
		{
			k=1;
			kk=(((g%MOD)*1+((gg%MOD)*2)%MOD)%MOD+(h%MOD))%MOD;
			if(k>=kk)
			{
				mnh(a,k,xx);
				xx++;
				mxh(b,kk,yy);
				yy++;
				w=kk;
			}
			else
			{
				mnh(a,kk,xx);
				xx++;
				mxh(b,k,yy);
				yy++;
				w=k;
			}
			uu=uu+1+kk;
			//printf("1: 1\n2: %d\n",kk);
			mm++;
			mm++;
			while(mm<=nn)
			{
				x=((((g%MOD)*((long long)w%MOD))%MOD+((gg%MOD)*((long long)mm%MOD))%MOD)%MOD+(h%MOD))%MOD;
				//printf("%d: %d\n",mm,x);
				uu=uu+x;
				if(x>=w)
				{
					if(xx==yy+1)
					{
						u=a[1];
						xx--;
						dmnhp(a,xx);
						mxh(b,u,yy);
						yy++;
					}
					mnh(a,x,xx);
					xx++;
				}
				else
				{
					if(yy==xx+1)
					{
						v=b[1];
						yy--;
						dmxhp(b,yy);
						mnh(a,v,xx);
						xx++;
					}
					mxh(b,x,yy);
					yy++;
				}
				/*int j;
				j=1;
				while(j<xx)
				{
					printf("%d ",a[j]);
					j++;
				}
				printf("\n");
				j=1;
				while(j<yy)
				{
					printf("%d ",b[j]);
					j++;
				}
				printf("\n");*/
				if(yy>xx)
				{
					w=b[1];
				}
				else if(xx>yy)
				{
					w=a[1];
				}
				else if(a[1]<=b[1])
				{
					w=a[1];
				}
				else
				{
					w=b[1];
				}
				mm++;
			}
			printf("%lld\n",uu);
		}
		m++;
	}
	return 0;
}
