#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
typedef struct node{
	int val,height,lcount;
	struct node *left;
	struct node *right;
}node;

/*void print_n(node *t, int s){
	if(t==NULL)
		return;
	int i;
	for(i=0; i<s; i++){
		fprintf(stderr, " ");
	}
	fprintf(stderr, "%d\n", t->val);
	print_n(t->left, s+1);
	print_n(t->right, s+1);
}

void debug_tree(node *root){
	fprintf(stderr,"Tree\n");
	print_n(root, 0);
	fprintf(stderr, "\n");
}
*/
node *rotright(node* temp)
{
	node *a=temp->left;
	node *b=a->right;
	if(b==NULL)
		temp->lcount=0;
	else
		temp->lcount=temp->lcount-a->lcount-1;
	a->right=temp;
	temp->left=b;
	int lh,rh;
	if(temp->left==NULL)
		lh=0;
	else
		lh=temp->left->height;
	if(temp->right==NULL)
		rh=0;
	else
		rh=temp->right->height;
	if(lh>rh)
		temp->height=lh+1;
	else
		temp->height=rh+1;
	if(a->left==NULL)
		lh=0;
	else
		lh=a->left->height;
	if(a->right==NULL)
		rh=0;
	else
		rh=a->right->height;
	if(lh>rh)
		a->height=lh+1;
	else
		a->height=rh+1;

	return a;
}

node *leftrot(node* temp)
{
	node *a=temp->right;
	node *b=a->left;
	int lc;
	if(b==NULL)
		a->lcount=temp->lcount+1;
	else
		a->lcount=temp->lcount+a->lcount+1;
	a->left=temp;
	temp->right=b;
	int lh,rh;
	if(temp->left==NULL)
		lh=0;
	else
		lh=temp->left->height;
	if(temp->right==NULL)
		rh=0;
	else
		rh=temp->right->height;
	if(lh>rh)
		temp->height=lh+1;
	else
		temp->height=rh+1;
	if(a->left==NULL)
		lh=0;
	else
		lh=a->left->height;
	if(a->right==NULL)
		rh=0;
	else
		rh=a->right->height;
	if(lh>rh)
		a->height=lh+1;
	else
		a->height=rh+1;
	return a;
}

node *insert(node *temp,int x)
{
	if(temp==NULL)
	{
		node *tr=(node *)malloc(sizeof(node));
		tr->right=NULL;
		tr->val=x;
		tr->left=NULL;
		tr->height=1;
		tr->lcount=0;
		return tr;
	}
	
	else if(x>temp->val)
	{
		temp->right=insert(temp->right,x);
	}
	else if(x<=temp->val)
	{
		temp->left=insert(temp->left,x);
		temp->lcount++;
		//printf("tempvalue %d count %d\n",temp->val,temp->lcount);
	}
	int lh,rh,bal;
	if(temp->left==NULL)
		lh=0;
	else
		lh=temp->left->height;
	if(temp->right==NULL)
		rh=0;
	else
		rh=temp->right->height;
	if(lh>rh)
		temp->height=lh+1;
	else
		temp->height=rh+1;
	if(temp==NULL)
		bal=0;
	else
		bal=lh-rh;
	if(bal>1 && x< temp->left->val)
		return rotright(temp);

	if(bal>1 && x> temp->left->val)
	{
		temp->left= leftrot(temp->left);
			return rotright(temp);
	}


	if(bal<-1 && x> temp->right->val)
		return leftrot(temp);

	if(bal<-1 && x< temp->right->val)
	{

		temp->right= rotright(temp->right);
			return leftrot(temp);
	}
	return temp;

}

/*void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("val %d height %d lcount %d\n",temp->val,temp->height,temp->lcount);
		inorder(temp->right);
	}
	else return;
} 
*/
int el,count=0,crapflag=0;
int healthy(node *temp,int x)
{
	node *tr=temp;
	int ret =-10;
	while(tr)
	{
		if(tr->lcount+1==x)
		{
			crapflag=1;
			return tr->val;
		}
		else if(x>tr->lcount)
		{
			x=x-tr->lcount;
			x=x-1;
			tr=tr->right;
		}
		else
			tr=tr->left;
	}
	return ret;
} 

int flag=0;
void check(node *temp,int x)
{
	if(temp==NULL)
		return;
	if(temp->val==x)
	{
		flag=1;
		return;
	}
	else if(x<temp->val)
	{
		check(temp->left,x);
	}
	else 
		check(temp->right,x);

}
int anothercount=0;
void rot(node *temp,int x)
{
	if(temp==NULL)
		return;
	if(temp->val>=x)
		rot(temp->left,x);
	else
	
	{
		anothercount+=temp->lcount+1;
		rot(temp->right,x);
	}



}
int main()
{
	char c[100];
	int x;
	node *head=NULL;
	while(c[0]!='Q')
	{
		scanf("%s",c);
		if(c[0]!='Q')
			scanf("%d",&x);
		if(c[0]=='S')
		{
			head=insert(head,x);
			//inorder(head);
			//printf("\n");
		}
		if(c[0]=='C')
		{
			check(head,x);
			if(flag==1)
				printf("YES\n");
			else
				printf("NO\n");
			flag=0;
		}
		if(c[0]=='H')
		{
			el=healthy(head,x);
			if(crapflag==1)
				printf("%d\n",el);
			else
				printf("NONE\n");
			crapflag=0;
			count=0;
		}
		if(c[0]=='R')
		{
			rot(head,x);
			printf("%d\n",anothercount);
			anothercount=0;
		}
/*#ifdef DEBUG
		debug_tree(head);
#endif
*/
	}
	return 0;
}
