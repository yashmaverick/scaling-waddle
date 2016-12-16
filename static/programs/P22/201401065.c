#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ull unsigned long long
#define M 1000000007

ull lmin=1;
ull lmax=1;

void swap(ull *a,ull *b)
{
	ull t=*a;
	*a=*b;
	*b=t;
}

void iminh(ull h[],ull v)
{
	h[lmin]=v;
	ull l;
	l=lmin;
	while((l/2)>=1)
	{
		if(h[l/2]>h[l])
		{
			swap(&h[l/2],&h[l]);
			l=l/2;
		}
		else
			break;
	}
	lmin++;
}

void imaxh(ull h[],ull v)
{
	h[lmax]=v;
	ull l;
	l=lmax;
	while((l/2)>=1)
	{
		if(h[l/2]<h[l])
		{
			swap(&h[l/2],&h[l]);
			l=l/2;
		}
		else
			break;
	}
	lmax++;
}

ull rmin(ull h[])
{
	ull k,l;
	k=h[1];
	h[1]=h[lmin-1];
	l=1;lmin--;
	while(l<lmin)
	{
		if((2*l+1)<lmin)
		{
			ull p,q;
			p=(h[2*l+1]>h[2*l])?h[2*l]:h[2*l+1];
			q=(h[2*l+1]>h[2*l])?(2*l):(2*l+1);
			if(h[l]>p)
			{
				swap(&h[l],&h[q]);
				l=q;
				continue;
			}
		}
		else if(2*l<lmin)
		{
			if(h[l]>h[2*l])
			{
				swap(&h[l],&h[2*l]);
				l=2*l;
				continue;
			}
		}
		break;
	}
	return k;
}

ull rmax(ull h[])
{
	ull k,l;
	k=h[1];
	h[1]=h[lmax-1];
	l=1;lmax--;
	while(l<lmax)
	{
		if((2*l+1)<lmax)
		{
			ull p,q;
			p=(h[2*l+1]<h[2*l])?h[2*l]:h[2*l+1];
			q=(h[2*l+1]<h[2*l])?(2*l):(2*l+1);
			if(h[l]<p)
			{
				swap(&h[l],&h[q]);
				l=q;
				continue;
			}
		}
		else if(2*l<lmax)
		{
			if(h[l]<h[2*l])
			{
				swap(&h[l],&h[2*l]);
				l=2*l;
				continue;
			}
		}
		break;
	}
	return k;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull a,b,c,n,i;
		scanf("%llu %llu %llu %llu",&a,&b,&c,&n);
		ull *minh,*maxh;
		minh=(ull *)calloc(n+1,sizeof(ull));
		maxh=(ull *)calloc(n+1,sizeof(ull));
		lmin=1;lmax=1;
		ull fl,m,s,f;
		fl=1;m=1;s=1;
		iminh(minh,1);
		for(i=2;i<=n;i++)
		{
			f=(a*m+b*i+c)%M;
			s+=f;
			if(fl)
			{
				if(f>=m)
				{
					imaxh(maxh,rmin(minh));
					iminh(minh,f);
					m=maxh[1];
					fl=0;
				}
				else
				{
					imaxh(maxh,f);
					m=maxh[1];
					fl=0;
				}
			}
			else
			{
				if(f<=m)
				{
					iminh(minh,rmax(maxh));
					imaxh(maxh,f);
					m=minh[1];
					fl=1;
				}
				else
				{
					iminh(minh,f);
					m=minh[1];
					fl=1;
				}
			}
		}
		printf("%llu\n",s);
	}
	return 0;
}
