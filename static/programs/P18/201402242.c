#include<stdio.h>
#include<stdlib.h>
int uu,vv;
int g,h;
int gg,hh;
//int d,dd;
/*void redfs(int a[][1002],int mk[],int y,int nn,int v,int check[])
{
	int m,n;
	v++;
	if(check[y]==1)
	{
		hh=1;
		return ;
	}
	mk[y]=1;
	m=1;
	while(m<=nn)
	{
		if(mk[m]==0&&a[y][m]==1)
		{
			if(check[y]==1)return ;
			redfs(a,mk,m,nn,v,check);
			if(check[y]==1)return ;
		}
		m++;
	}
	return ;
}*/
void dfs(int a[][1002],int mk[],int y,int nn,int v)
{
	int m,n;
	v++;
	uu++;
	h++;
	if(uu==nn)
	{
		vv=1;
	}
	mk[y]=1;
	m=1;
	while(m<=nn)
	{
		if(mk[m]==0&&a[y][m]==1)
		{
			dfs(a,mk,m,nn,v);
		}
		m++;
	}
	return ;
}
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int u,v;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&nn);
		int a[1002][1002]={0};
		mm=1;
		while(mm<=nn)
		{
			scanf("%d",&yy);
			xx=1;
			while(xx<=yy)
			{
				scanf("%d",&w);
				a[w][mm]=1;
				xx++;
			}
			mm++;
		}
		y=1;
		ww=0;
		h=0;
		//int check[1002]={0};
		while(y<=nn)
		{
			int mk[1002]={0};
			v=0;
			vv=0;
			uu=0;
			//dd=0;
			dfs(a,mk,y,nn,v);
		//	check[y]=1;
			//dd=y;
			if(vv==1)
			{
				ww=ww+1;
				//printf("y:%d\n",y);
				break;
			}
			y++;
		}
		int b[1002][1002];
		gg=1;
		while(gg<=nn)
		{
			hh=1;
			while(hh<=nn)
			{
				b[gg][hh]=a[hh][gg];
				/*if(b[hh][gg]==1)
				{
					b[hh][gg]=a[gg][hh];
				}*/
				hh++;
			}
			gg++;
		}
		/*while(y<=nn)
		{
			int mk[1002]={0};
			v=0;
			vv=0;
			hh=0;
			uu=0;
			redfs(a,mk,y,nn,v,check);
			if(hh==1)
			{
				//printf("%d\n",y);
				check[y]=1;
				ww=ww+1;
			}
			y++;
		}*/
		int mk[1002]={0};
		h=0;
		v=0;
		vv=0;
		uu=0;
		//dd=0;
		dfs(b,mk,y,nn,v);
		//printf("%d\n",h);
		ww=ww+(h-1);
		/*int mk[1002]={0};
		int b[1002][1002]={0};
		v=0;
		vv=0;
		gg=1;
		while(gg<=nn)
		{
			hh=1;
			while(hh<=nn)
			{
				if(a[gg][hh]==1)
				{
					b[hh][gg]=1;
				}
				hh++;
			}
			gg++;
		}
		printf("--%d\n",uu);
		h=0;
		dfs(b,mk,uu,nn,v);
		ww=ww+h;*/
		printf("%d\n",ww);
		m++;
	}
	return 0;
}
