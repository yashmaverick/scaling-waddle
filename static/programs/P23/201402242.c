#include<stdio.h>
#include<stdlib.h>
int u,uu;
struct node{
	int data;
	struct node*next;
};
struct node* gnn(int y)
{
	struct node*nnode=(struct node*)malloc(sizeof(struct node));
	nnode->data=y;
	nnode->next=0;
	return nnode;
}
void in(struct node* a[],int x,int y)
{
	struct node*cnode;
	cnode=a[x];
	if(cnode==0)
	{
		a[x]=gnn(y);
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
void dfs(struct node* a[],int b[],int c[],int nn,int y)
{
	int m,n;
	/*if(uu==0)
	{
		printf("%d\n",y);
		uu=1;
	}*/
	b[y]=1;
	//printf("do:%d\n",y);
	struct node* cnode;
	cnode=a[y];
	while(cnode!=NULL)
	{
		m=cnode->data;
		if(b[m]==0)
		{
			dfs(a,b,c,nn,m);
		}
		cnode=cnode->next;
	}
	c[u]=y;
	u++;
}
void print(int c[])
{
	int x,y;
	x=u;
	x=x-1;
	while(x>=0)
	{
		printf("%d%c",c[x],(x!=0)?' ':'\n');
		x--;
	}
	return ;
}
void lexib(struct node* a[],int nn)
{
	int x,y;
	int b[100005]={0};
	int c[100005]={0};
	x=0;
	y=nn;
	u=0;
	while(y>=1)
	{
		if(b[y]==0)
		{
			uu=0;
			dfs(a,b,c,nn,y);
			//printf("YES\n");
		}
		y--;
	}
	print(c);
	return ;
}
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	//scanf("%d",&n);
	//m=0;
	//while(m<n)
	//{
		scanf("%d%d",&yy,&nn);
		struct node* a[yy+1];
		xx=0;
		while(xx<=yy)
		{
			a[xx]=0;
			xx++;
		}
		mm=0;
		while(mm<nn)
		{
			scanf("%d%d",&x,&y);
			in(a,x,y);
			mm++;
		}
		/*xx=1;
		while(xx<=yy)
		{
			struct node*cnode;
			printf("%d--",xx);
			cnode=a[xx];
			while(cnode!=NULL)
			{
				printf("%d ",cnode->data);
				cnode=cnode->next;
			}
			printf("\n");
			xx++;
		}*/
		lexib(a,yy);
		//m++;
	//}
	return 0;
}
