#include<stdio.h>
#include<string.h>
int check(char x[],char y[])
{
	int m,n;
	int mm,nn;
	int w,ww,xx,yy,z,zz;
	xx=strlen(x);
	yy=strlen(y);
	w=0;
	while(w<xx&&w<yy&&x[w]==y[w])
	{
		w++;
	}
	if(w==xx||w==yy)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int lexib(char x[],char y[])
{
	int m,n;
	int mm,nn;
	int w,ww,xx,yy,z,zz;
	xx=strlen(x);
	yy=strlen(y);
	w=0;
	while(w<xx&&w<yy&&x[w]==y[w])
	{
		w++;
	}
	if(w==xx)
	{
		return 1;
	}
	else if(w==yy)
	{
		return 0;
	}
	else if(x[w]<=y[w])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void merge(char a[][11],int l1,int r1,int l2,int r2)
{

	int x,xx,y,yy;
	int k,kk;
	int w,ww;
	char b[(r1+r2)-(l1+l2)+2][11];
	x=l1;
	y=l2;
	k=0;
	while(x<=r1&&y<=r2)
	{
		if(lexib(a[x],a[y]))
		{
			w=0;
			while(w<11)
			{
				b[k][w]=a[x][w];
				w++;
			}
			x++;
			k++;
		}
		else
		{
			w=0;
			while(w<11)
			{
				b[k][w]=a[y][w];
				w++;
			}
			y++;
			k++;
		}
	}
	while(x<=r1)
	{
		w=0;
		while(w<11)
		{
			b[k][w]=a[x][w];
			w++;
		}
		x++;
		k++;
	}
	while(y<=r2)
	{
		w=0;
		while(w<11)
		{
			b[k][w]=a[y][w];
			w++;
		}
		y++;
		k++;
	}
	xx=l1;
	kk=0;
	while(kk<(r1+r2)-(l1+l2)+2)
	{
		w=0;
		while(w<11)
		{
			a[xx][w]=b[kk][w];
			w++;
		}
		xx++;
		kk++;
	}
	return ;
}
void mergesort(char a[][11],int l,int r)
{
	int mid=(l+r)/2;
	if(l>=r)
	{
		return ;
	}
	else
	{
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,mid+1,r);
	}
}
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&nn);
		char a[nn][11];
		mm=0;
		while(mm<nn)
		{
			scanf("%s",&a[mm]);
			mm++;
		}
		mergesort(a,0,nn-1);
		/*xx=0;
		while(xx<nn)
		{
			printf("%s\n",a[xx]);
			xx++;
		}*/
		w=0;
		while(w<nn-1)
		{
			ww=check(a[w],a[w+1]);
			if(ww==0)
			{
				printf("NO\n");
				break;
			}
			w++;
		}
		if(w==nn-1)
		{
			printf("YES\n");
		}
		m++;
	}
	return 0;
}
