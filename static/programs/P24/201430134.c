#include<stdio.h>
#include<stdlib.h>
typedef struct avl{
	int data;
	int n;
	struct avl* l;
	struct avl* r;
	int ht;
}avl;
typedef avl* vl;
int ob,cnt,no,frb;
int height(vl p)
{
	if(p==NULL)
	{
		return -1;
	}
	else
	{
		return p->ht;
	}
}
int max(int x1,int x2)
{
	return x1>=x2?x1:x2;
}
int noc(vl p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return p->n;
	}
}
vl srwl(vl g2)
{
	vl g1;

	g1=g2->l;
	g2->l=g1->r;
	g1->r=g2;

	g2->ht=max(height(g2->l),height(g2->r))+1;
	g1->ht=max(height(g1->l),height(g1->r))+1;

	g2->n=noc(g2->l)+noc(g2->r)+1;

	g1->n=noc(g1->l)+noc(g1->r)+1;
	return g1;
}
vl srwr(vl g1)
{
	vl g2;
	g2=g1->r;
	g1->r=g2->l;
	g2->l=g1;

	g1->ht=max(height(g1->l),height(g1->r))+1;
	g2->ht=max(height(g2->l),height(g2->r))+1;

	g1->n=noc(g1->l)+noc(g1->r)+1;
	g2->n=noc(g2->l)+noc(g2->r)+1;

	return g2;
}
vl drwl(vl k3)
{
	k3->l=srwr(k3->l);
	return srwl(k3);
}
vl drwr(vl k3)
{
	k3->r=srwl(k3->r);
	return srwr(k3);
}
vl set(int x,vl atree)
{
	vl temp;
	if(atree==NULL)
	{
		atree=(vl)malloc(sizeof(avl));
		atree->data=x;
//		printf("%d\n",atree->data);
		atree->l=NULL;
		atree->r=NULL;
		atree->ht=0;
		atree->n=1;
	}
	else if(x<atree->data)
	{
		atree->l=set(x,atree->l);
		//atree->nl++;
		if(height(atree->l)-height(atree->r)==2)
		{
			if(x<atree->l->data)
			{
				atree=srwl(atree);
			}
			else
			{
				atree=drwl(atree);
			}
		}
	}
	else if(x>atree->data)
	{
		atree->r=set(x,atree->r);
		//atree->nr++;
		if(height(atree->r)-height(atree->l)==2)
		{
			if(x>atree->r->data)
			{
				atree=srwr(atree);
			}
			else
			{
				atree=drwr(atree);
			}
		}
	}
	else
	{
		;
	}
	atree->ht=max(height(atree->l),height(atree->r))+1;
	atree->n=noc(atree->l)+noc(atree->r)+1;
	//atree->nr=nol(atree->r)+nor(atree->r)+1;
	return atree;
}
void check(int x,vl atree)
{
	int flag=0;
	vl temp;
	temp=atree;
	while(temp!=NULL)
	{
		if(x>temp->data)
		{
			temp=temp->r;
		}
		else if(x<temp->data)
		{
			temp=temp->l;
		}
		else
		{
			printf("YES\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("NO\n");
	}
}
void count(vl head)
{
	if(head==NULL)
	{
		return;
	}
	count(head->l);
	no++;
	count(head->r);
}
void rb(int x,vl atree)
{
	vl temp;
	temp=atree;
	while(temp!=NULL)
	{
		if(x>temp->data)
		{
			no=no+noc(temp->l)+1;
			temp=temp->r;
		}
		else if(x==temp->data)
		{
			no=no+noc(temp->l);
			break;
		}
		else
		{
			temp=temp->l;
		}
	}
	printf("%d\n",no);
}
void healthy(int x,vl atree)
{
	vl temp;
	temp=atree;
	while(temp!=NULL)
	{
		if(noc(temp->l)+1==x)
		{
			printf("%d\n",temp->data);
			ob=1;
			break;
		}
		else if(noc(temp->l)+1<x)
		{
			x=x-(noc(temp->l)+1);
			temp=temp->r;
		}
		else
		{
			temp=temp->l;
		}
	}
}
void pri(vl atree)
{
	//vl aahl,aahr;
	if(atree==NULL)
	{
		return;
	}
	pri(atree->l);
	//aahl=atree->l;aahr=atree->r;
	printf("%d\n",atree->data);
	pri(atree->r);
}
int main()
{
	vl atree=NULL;
	char inst[40];int x;
	scanf("%s",inst);
	while(inst[0]!='Q')
	{
		scanf("%d",&x);
		if(inst[0]=='S')
		{
			atree=set(x,atree);
	//	pri(atree);
		}
		else if(inst[0]=='C')
		{
			check(x,atree);
		}
		else if(inst[0]=='H')
		{
			ob=0;cnt=0;
			healthy(x,atree);
			if(ob==0)
			{
				printf("NONE\n");
			}
		}
		else if(inst[0]=='R')
		{
			no=0;frb=0;
			rb(x,atree);
		}
		scanf("%s",inst);
	}
	return 0;
}
