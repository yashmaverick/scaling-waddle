#include<stdio.h>
#include<stdlib.h>
int h;
int vv;
int v;
struct node{
	int data;
	struct node*next;
};
void dfs(struct node*a[],int enc[],int y,int uu)
{
	//printf("YES\n");
	uu++;
	if(vv<=uu)
	{
		v=y;
		vv=uu;
		//printf("DDDDD%d\n",vv);
	}
	if(h==0)
	{
		//printf("%d\n",y);
		h=1;
	}
	enc[y]=1;
	struct node*cnode=a[y];
	while(cnode!=NULL)
	{
		if(enc[cnode->data]!=1)
		{
			//printf("%d\n",cnode->data);
			dfs(a,enc,cnode->data,uu);
		}
		cnode=cnode->next;
	}
	return ;
}
struct node* gnn(int y)
{
	struct node* ret=(struct node*)malloc(sizeof(struct node));
	ret->data=y;
	ret->next=0;
	return ret;
}
void put(struct node*a[],int x,int y)
{
	int m,n;
	int mm,nn;
	int w,ww,xx,yy,z,zz;
	struct node* node=gnn(y);
	struct node* cnode=a[x];
	if(cnode==NULL)
	{
		a[x]=node;
	}
	else
	{
		while(cnode->next!=NULL)
		{
			cnode=cnode->next;
		}
		cnode->next=node;
	}
	return ;
}
int main()
{
	int m,n;
	int mm,nn;
	int w,ww,x,xx,y,yy,z,zz;
	int uu;
	scanf("%d",&n);
	m=0;
	while(m<n)
	{
		scanf("%d",&nn);
		struct node*a[nn+1];
		int enc[nn+1];
		w=0;
		while(w<nn+1)
		{
			a[w]=0;
			enc[w]=0;
			w++;
		}
		mm=0;
		while(mm<nn-1)
		{
			scanf("%d%d",&x,&y);
			put(a,x,y);
			put(a,y,x);
			mm++;
		}
		h=0;
		vv=0;
		uu=0;
		v=1;
		dfs(a,enc,1,uu);
		//printf("%d\n",vv);
		vv=0;
		ww=0;
		while(ww<nn+1)
		{
			enc[ww]=0;
			ww++;
		}
		h=0;
		uu=0;
		dfs(a,enc,v,uu);
		/*xx=1;
		while(xx<=nn)
		{
			struct node*cnode;
			cnode=a[xx];
			printf("%d--",xx);
			while(cnode!=NULL)
			{
				printf("%d ",cnode->data);
				cnode=cnode->next;
			}
			printf("\n");
			xx++;
		}*/
		printf("%d\n",vv);
		m++;
	}
	return 0;
}
