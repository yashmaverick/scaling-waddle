#include<stdio.h>
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int u,uu,v,vv;
	char cc,dd;
	//scanf("%d",&n);
	//m=0;
	//while(m<n)
	//{
	scanf("%d",&nn);
	//printf("YY\n");
	char *a[nn];
	char b[nn][105];
	x=0;
	y=0;
	mm=0;
	while(mm<nn)
	{
		a[mm]=NULL;
		mm++;
	}
	while(1)
	{
		getchar();
		scanf("%c",&cc);
		//printf("%c\n",cc);
		if(cc=='A')
		{
			scanf("%d",&yy);
			xx=0;
			while(xx<yy)
			{
				//printf("Y1\n");
				scanf("%s",b[y]);
				//printf("%s\n",b[y]);
				//printf("Y2\n");
				a[y]=&b[y][0];
				//printf("%s\n",a[y]);
				y++;
				if(y==nn)
				{
					y=0;
				}
				xx++;
			}
			//printf("y%d\n",y);
			if(a[y]!=NULL)
			{
				x=y;
			}
			//printf("YES1\n");
		}
		else if(cc=='R')
		{
			scanf("%d",&zz);
			ww=0;
			while(ww<zz)
			{
				a[x]=NULL;
				x++;
				if(x==nn)
				{
					x=0;
				}
				ww++;
			}
			//printf("YES2\n");
		}
		else if(cc=='L')
		{
			w=x;
			//printf("%d %d\n",w,y);
			if(nn>0)
			{
				while(a[w]!=NULL)
				{
					printf("%s\n",a[w]);
					w++;
					if(w==nn)
					{
						w=0;
					}
					if(w==y)
					{
						break;
					}
				}
			}
			//printf("YES3\n");
		}
		else if(cc=='Q')
		{
			//printf("YES4\n");
			break;
		}
	}
	//m++;
	//}
	return 0;
}

