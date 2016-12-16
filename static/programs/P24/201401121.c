#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int height;
	int lnumber;
	int rnumber;
	int data;
	struct node *l;
	struct node *r;
}node;
int ht(node * p)
{
	if(p==NULL)
		return 0;
	else
		return p->height;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int lnumber(node *p)
{
	if(p==NULL)
		return 0;
	return p->lnumber;
}
int rnumber(node *p)
{
	if(p==NULL)
		return 0;
	return p->rnumber;
}
int search(node *head,int data)
{
	if(head==NULL)
		return 0;
	else if(head->data > data)
		return search(head->l,data);
	else if(head->data < data)
		return search(head->r,data);
	else
		return 1;
}
int  healthy(node *head,int x)
{
	if(head==NULL)
		return 0;
	if(x == head->lnumber+1)
		return head->data;
	if(x>head->lnumber+1)
	{
		x-=head->lnumber+1;
		return healthy(head->r,x);
	}
	if(x<head->lnumber+1)
	{
		return healthy(head->l,x);
	}
}
int exist(node *x)
{
	if(x==NULL)
		return 0;
	return 1;
}
int rotcnt=0;
void rotten(node *head,int data) 
{
	if(head==NULL)
		return ;
	if(head->data<data)
	{
		rotcnt+=head->lnumber+1;
		rotten(head->r,data);
	}
	else rotten(head->l,data);
}
node * insert(node *head,int data)
{
	if(head==NULL)
	{
		head=malloc(sizeof(node));
		head->data=data;
		head->l=NULL;
		head->r=NULL;
		head->height=1;
		head->lnumber=0;
		head->rnumber=0;
		return head;
	}
	if(data > head->data)
	{

		head->r=insert(head->r,data);
		if(ht(head->r)-ht(head->l)<=1)
		{

			head->height=ht(head->	r)+1;
			head->rnumber=rnumber(head->r)+lnumber(head->r)+exist(head->r);;
			return head;
		}
		else
		{
			if(ht(head->r->r) > ht(head->r->l))
			{
				node *x=head->r;
				head->r=x->l;
				x->l=head;
				head->height=ht(x)-1;
				head->rnumber=lnumber(head->r)+rnumber(head->r)+exist(head->r);;
				x->lnumber=lnumber(x->l)+rnumber(x->l)+exist(x->l);
				return x;
			}
			else
			{
				node *x=head->r;
				head->r=x->l;
				node *y=x->l->r;
				x->l->r=x;
				x->l=y;
				x->lnumber=rnumber(x->l)+lnumber(x->l)+exist(x->l);
		//0		printf("\n\n %d lnumber is %d \n\n",x->data,x->lnumber);
				head->r->rnumber=rnumber(head->r->r)+lnumber(head->r->r)+exist(head->r->r);

		//		printf("\n\n %d rnumber is %d \n\n",head->r->data,head->r->rnumber);
				
				x=head->r;
				head->r=x->l;
				x->l=head;

		//		printf("\n\n %d lnumber is %d \n\n",x->data,x->lnumber);
				head->rnumber=lnumber(head->r)+rnumber(head->r)+exist(head->r);
				
		//		printf("\n\n %d lnumber is %d \n\n",head->data,he->lnumber);
				x->lnumber=lnumber(x->l)+rnumber(x->l)+exist(x->l);
				
//				printf("\n\n %d lnumber is %d \n\n",x->data,x->lnumber);
//				printf("\n\n %d rnumber is %d \n\n",x->data,x->lnumber);
				if(x!=NULL)
					x->height++;
				if(x->l!=NULL)
					x->l->height--;
				if(x->r!=NULL);
				x->r->height=ht(x)-1;
				return x;
			}
		}
	}
	else
	{

		head->l=insert(head->l,data);
		if(ht(head->l)-ht(head->r)<=1 )
		{
			head->height=ht(head->l)+1;
			head->lnumber=lnumber(head->l)+rnumber(head->l)+exist(head->l);
			return head;
		}
		else
		{
			if(ht(head->l->l) >ht(head->l->r))
			{
				node *x=head->l;
				head->l=x->r;
				x->r=head;
				head->height=ht(x)-1;
				head->lnumber=lnumber(head->l)+rnumber(head->l)+exist(head->l);
				x->rnumber=lnumber(x->r)+rnumber(x->r)+exist(x->r);
				return x;
			}
			else
			{
				node *x=head->l;
				head->l=x->r;
				node *y=x->r->l;
				x->r->l=x;
				x->r=y;
				x->rnumber=rnumber(x->r)+lnumber(x->r)+exist(x->r);
				head->l->lnumber=rnumber(head->l->l)+lnumber(head->l->l)+exist(head->l->l);
				x=head->l;
				head->l=x->r;
				x->r=head;
				head->lnumber=lnumber(head->l)+rnumber(head->l)+exist(head->l);
				x->rnumber=lnumber(x->r)+rnumber(x->r)+exist(x->r);
				if(x!=NULL)
					x->height++;
				if(x->l!=NULL)
					x->r->height--;
				if(x->l!=NULL);
				x->l->height=ht(x)-1;
				return x;
			}
		}
	}
}
void inorder(node *head)
{
	if(head==NULL)
		return ;
	inorder(head->l);

	printf("%d ",head->data);
	inorder(head->r);
}

void preorder(node *head)
{
	if(head==NULL)
		return ;

	printf("%d,%d ",head->data,head->lnumber);
	preorder(head->l);

	preorder(head->r);
}
void deletebst(node *head,int data, node *prev)
{
	if(data>head->data)
	{
		deletebst(head->r,data,head);

	}
	else if(data< head->data)
	{
		deletebst(head->l,data,head);
	}
	else
	{
		if(head->l=NULL)
		{
		if(prev->data >head->data)
			{
				prev->l=head->r;
			}
			else
			{
				prev->r=head->r;
			}
			return ;
		}
		if(head->r=NULL)
		{
			if(prev->data>head->data)
			{
				prev->l=head->l;
			}
			else
			{
				prev->r=head->r;
			}
			return ;
		}
		else
		{
			node *temp=head->l;
			node *pre=head;
			while(temp->r!=NULL)
			{
				pre=temp;
				temp=temp->r;
			}
			int swap=temp->data;
			temp->data=head->data;
			head->data=swap;
			if(pre==head)
				pre->l=temp->l;
			else
				pre->r=temp->l;


		}
	}
}
int main()
{
	node *head=NULL;
	char ar[100];
	int x;
	scanf("%s",ar);
	scanf("%d",&x);
	while(ar[0]!='Q')
	{
		if(ar[0]=='C')
		{
			if(search(head,x))
				printf("YES\n");
			else
				printf("NO\n");

		}
		else if(ar[0]=='S')
		{

//			printf("\nBefore insetion\n");
	//		preorder(head);
			head=insert(head,x);
	//		printf("\nAfter insertion\n");
	//		preorder(head);
		}
		else if(ar[0]=='H')
		{
	//		printf("\ninorder is \n");
		//	inorder(head);
		//	printf("\n");
		//	preorder(head);
			int t=healthy(head,x);
			if(t==0)
				printf("NONE\n");
			else
				printf("%d\n",t);
		}
		else 
		{
			rotten(head,x);
			printf("%d\n",rotcnt);
			rotcnt=0;
		}

		scanf("%s",ar);
		scanf("%d",&x);
	}

	return 0;
}



















