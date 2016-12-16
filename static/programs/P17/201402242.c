#include<stdio.h>
int lca(int a[],int b[],int x,int y,int vv)
{
	int m,n;
	int mm,nn;
	int w,ww,xx,yy,z,zz;
	int u,uu,v;
	nn=vv;
	mm=0;
	v=0;
	while(mm<nn)
	{
		if(b[mm]==x)
		{
			xx=mm;
			v++;
		}
		if(b[mm]==y)
		{
			yy=mm;
			v++;
		}
		if(v==2)
		{
			break;
		}
		mm++;
	}
	if(xx>yy)
	{	
		uu=xx;
		xx=yy;
		yy=uu;
	}	
	w=0;
	while(w<nn)
	{
		u=0;
		ww=xx;
		while(ww<=yy)
		{
			if(b[ww]==a[w])
			{
				u=1;
				printf("%d\n",b[ww]);
				break;
			}
			ww++;
		}
		if(u==1)
		{
			break;
		}
		w++;
	}
	return 0;
}						
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int u,uu,v,vv;
	//scanf("%d",&n);
	//m=0;
	//while(m<n)
	//{
	scanf("%d",&vv);
	int a[vv];
	int b[vv];
	u=0;
	while(u<vv)
	{
		scanf("%d",&a[u]);
		u++;
	}
	v=0;
	while(v<vv)
	{
		scanf("%d",&b[v]);
		v++;
	}
	scanf("%d",&nn);
	mm=0;
	while(mm<nn)
	{
		scanf("%d%d",&x,&y);
		z=lca(a,b,x,y,vv);
		mm++;
	}
	//m++;
	//}
	return 0;
}
