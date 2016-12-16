#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int a[1000001],b[1000001],c[1000001],d[1000001];
int main()
{
	int i,j,k,l,m,o,p,gg,jj,kk,pp,ll,mm,nn;
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		scanf("%d",&a[j]);
		d[a[j]]=j;
	}
	for(j=0;j<i;j++)
		scanf("%d",&b[j]);
//	for(j=0;j<i;j++)
//		printf("%d ",a[j]);
//		printf("\n");
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&o,&p);
		m=0;
		while(b[m]!=o && b[m]!=p)
		{
//			printf("b[m]:%d ",b[m]);
			m++;
		}
//		printf("\n");
//		printf("m:%dend",m);
		if(b[m]==o)
		{
			jj=0;
//			printf("gg");
			while(m<i && b[m]!=p)
			{
				c[jj]=b[m];
				jj++;
				m++;
			}
			c[jj]=b[m];
		}
		else
		{
			jj=0;
			while(m<i && b[m]!=o)
			{
				c[jj]=b[m];
				jj++;
				m++;
			}
			c[jj]=b[m];
		}
	//	for(kk=0;kk<=jj;kk++)
	//	printf("%d ",c[kk]);
	//	printf("\n");
	//	for(kk=0;kk<i;kk++)
	//	{
	//		pp=kk;
	//		ll=0;
	//		while(ll<=jj && a[pp]!=c[ll])
	//		{ ll++;
	//		}
	//		if(ll<=jj)
	//		{
	//			printf("%d\n",c[ll]);
	//			break;
	//		}
	//	}
		ll=10000001;
		for(kk=0;kk<=jj;kk++)
		{
			if(d[c[kk]]<ll)
			{
				ll=d[c[kk]];
				nn=c[kk];
			}
		}
		printf("%d\n",nn);

	}
return 0;
}
