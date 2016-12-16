#include<stdio.h>
#include<stdlib.h>
#define INF 2000000000
struct node{
	int data;
	struct node*next;
};
int u=0,uu=0;
int v,vv;
void ord(int a[])
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	w=2;
	a[1]=0;
	while(w<=100)
	{
		ww=2;
		while(w*ww<=10001)
		{
			a[w*ww]=0;
			ww++;
		}
		w++;
		if(w%2==0)
		{
			w++;
		}
	}
	return ;
}
int ch(int x,int y)
{
	int m,mm,n,nn;
	int a[5];
	int b[5];
	mm=0;
	m=1000;
	while(mm<=3)
	{
		a[mm]=x/m;
		x=x%m;
		m=m/10;
		mm++;
	}
	nn=0;
	n=1000;
	while(nn<=3)
	{
		b[nn]=y/n;
		y=y%n;
		n=n/10;
		nn++;
	}
	m=0;
	mm=0;
	while(m<=3)
	{
			if(a[m]==b[m])
			{
				a[m]=-1;
				mm++;
			}
		m++;
	}
	if(mm==3)
	{
		return 1;
	}
	return 0;
}
struct node* gnn(int y)
{
	struct node *nnode=(struct node*)malloc(sizeof(struct node));
	nnode->data=y;
	nnode->next=0;
	return nnode;
}
void ins(struct node*b[],int x,int y)
{
	struct node*cnode;
	cnode=b[x];
	if(cnode==0)
	{
		b[x]=gnn(y);
	}
	else
	{
		while(cnode->next!=0)
		{
			cnode=cnode->next;
		}
		cnode->next=gnn(y);
	}
	return ;
}
void pp(int a[],struct node*b[])
{
	int x,y;
	x=1009;
	while(x<=9999)
	{
		if(a[x]==1)
		{
			/*y=x+1;
			while(y<=9999)
			{
				if(a[y]==1&&ch(x,y))
				{
					ins(b,x,y);
					ins(b,y,x);
				}
				y++;
			}*/
			/*if(x==1009)
			{
				printf("YES\n");
			}*/
			int c[5];
			int m,n,mm,nn;
			mm=0;
			m=1000;
			n=x;
			while(mm<=3)
			{
				c[mm]=n/m;
				n=n%m;
				m=m/10;
				mm++;
			}
			/*if(x==1009)
			{
				printf("%d %d %d %d\n",c[0],c[1],c[2],c[3]);
			}*/
			int w,ww;
			int g,h;
			w=1;
			g=c[0];
			while(w<=8)
			{
				c[0]++;
				if(c[0]>=10)
				{
					c[0]=1;
				}
				ww=1000*c[0]+100*c[1]+10*c[2]+c[3];
				if(a[ww]==1)
				{
					ins(b,x,ww);
				}
				w++;
			}
			c[0]=g;
			g=c[1];
			w=1;
			while(w<=9)
			{
				c[1]++;
				if(c[1]>=10)
				{
					c[1]=0;
				}
				ww=1000*c[0]+100*c[1]+10*c[2]+c[3];
				/*if(x==1009)
				{
					printf("%d\n",ww);
				}*/
				if(a[ww]==1)
				{
					ins(b,x,ww);
				}
				w++;
			}
			c[1]=g;
			g=c[2];
			w=1;
			while(w<=9)
			{
				c[2]++;
				if(c[2]>=10)
				{
					c[2]=0;
				}
				ww=1000*c[0]+100*c[1]+10*c[2]+c[3];
				/*if(x==1009)
				{
					printf("%d\n",ww);
				}*/
				if(a[ww]==1)
				{
					ins(b,x,ww);
				}
				w++;
			}
			c[2]=g;
			g=c[3];
			w=1;
			while(w<=9)
			{
				c[3]++;
				if(c[3]>=10)
				{
					c[3]=0;
				}
				ww=1000*c[0]+100*c[1]+10*c[2]+c[3];
				if(a[ww]==1)
				{
					ins(b,x,ww);
				}
				w++;
			}
		}
		x++;
	}
	return ;
}
int bfs(struct node*b[],int distance[],int mark[],int queue[],int x,int y)
{
	distance[x]=1;
	u++;
	queue[u]=x;
	mark[x]=1;
	while(u!=uu)
	{
		struct node*cnode;
		int w;
		w=queue[uu+1];
		cnode=b[w];
		uu++;
		while(cnode!=0)
		{
			if(mark[cnode->data]==0)
			{
				distance[cnode->data]=distance[w]+1;
				u++;
				queue[u]=cnode->data;
				mark[cnode->data]=1;
			}
			cnode=cnode->next;
		}
	}
	return ;
}
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int a[10002]={1};
	ww=1;
	while(ww<10002)
	{
		a[ww]=1;
		ww++;
	}
	scanf("%d",&n);
	struct node*b[10002]={0};
	ord(a);
	pp(a,b);
	m=0;
	//int distance[10002]={0};
	//int mark[10002]={0};
	int queue[200002]={0};
	while(m<n)
	{
		scanf("%d%d",&x,&y);
		//ww=0;
		//while(ww<10002)
		//{
			int distance[10002]={0};
			int mark[10002]={0};
			//ww++;
		//}
		//printf("%d\n",distance[10]);
		u=0;
		uu=0;
		bfs(b,distance,mark,queue,x,y);
		if(distance[y]==0)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n",distance[y]-1);
		}
		m++;
	}
	return 0;
}
