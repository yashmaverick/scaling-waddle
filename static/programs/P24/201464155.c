#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct c
{  	int data,height,leftnode,rightnode;
	struct c *left,*right;
}node;

int count=0,flag=0,re=0;

int sort(node *T,int v)
{
	if(v==T->leftnode+1)
		return T->data;
	else if(v>T->leftnode+1)
		sort(T->right,v-T->leftnode-1);
	else
		sort(T->left,v);
}

void less(node *T,int val)
{
	if(T!=NULL)
	{
		if(T->data<val)
		{
			re=re+T->leftnode+1;
			less(T->right,val);
		}
		else if(T->data>val)
			less(T->left,val);
		else
			re=re+T->leftnode;	
	}
	else
		return;
	return;
}

void find(node *T,int val)
{
	if(T!=NULL)
	{
		//printf("Finding %d at %d with flag=%d\n",val,T->data,flag);
		if(T->data==val)
		{
			flag=1;
			//printf("Changing flag\n");
			return;
		}
		else if(T->data>val)
			find(T->left,val);
		else
			find(T->right,val);
	}
	else
		return;
	return;
}	

node* heightnode(node *T)
{
	int l,r;
	if(T==NULL)
		return 0;
	
	if(T->right==NULL)
	{
		r=0;
		T->rightnode=0;
	}
	else
	{
		r=1+T->right->height;
		T->rightnode=T->right->leftnode+T->right->rightnode+1;
	}
	if(T->left==NULL)
	{
		l=0;
		T->leftnode=0;
	}
	else
	{
		l=1+T->left->height;
		T->leftnode=T->left->leftnode+T->left->rightnode+1;
	}
	if(r>l)
		T->height=r;
	else
		T->height=l;
	return T;
}
node* rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x=heightnode(x);
	y=heightnode(y);
	return y;
}
node* rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x=heightnode(x);
	y=heightnode(y);
	return y;
}

node* leftleft(node *T)
{
	T=rotateright(T);
	return T;
}
node* leftright(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return T;
}
node* rightleft(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return T;
}
node* rightright(node *T)
{
	T=rotateleft(T);
	return T;
}
int diff(node *T)
{
	int l,r;
	if(T==NULL)
		return 0;
	if(T->left==NULL)
		l=0;
	else
		l=1+T->left->height;
	if(T->right==NULL)
		r=0;
	else
		r=1+T->right->height;
	return(l-r);
}

node* insertnode(node *T,int x)
{
	if(T==NULL)
	{
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
		T->leftnode=0;
		T->rightnode=0;
	}
	else
		if(x>T->data)                // insert in right subtree
		{
			T->right=insertnode(T->right,x);
			if(diff(T)==-2)
				if(x>T->right->data)
					T=rightright(T);
				else
					T=rightleft(T);
		}
		else
			if(x<T->data)
			{
				T->left=insertnode(T->left,x);
				if(diff(T)==2)
					if(x < T->left->data)
						T=leftleft(T);
					else
						T=leftright(T);
			}
	T=heightnode(T);
	return T;
}

int main()
{
	node *root=NULL;
	int x,n,i,o;
	char select[20];
	scanf("%s",select);
	if(strcmp(select,"Quit")==0)
		return 0;
	scanf("%d",&x);
	//printf("%s %d\n",select,x);
	while(1)
	{
		flag=0;
		re=0;
		int r;
		if(strcmp(select,"SetHealthy")==0)
			o=1;
		else if(strcmp(select,"CheckHealthy")==0)
			o=2;
		else if(strcmp(select,"Healthy")==0)
			o=3;
		else if(strcmp(select,"RottenBefore")==0)
			o=4;
		//printf("O=%d\n",o);
		switch(o)
		{
			case 1:
				root=insertnode(root,x);
				count++;
				//printf("Root is %d and Leftnode: %d and Righeightnode: %d\n",root->data,root->leftnode,root->rightnode);
				break;
			case 2:find(root,x);
			       if(flag==1)
				       printf("YES\n");
			       else
				       printf("NO\n");
			       break;
			case 3: //printf("Count : %d\n",count);
			       if(x<=count)
			       {	r=sort(root,x);
				       printf("%d\n",r);
			       }
			       else
				       printf("NONE\n");
			       break;
			case 4:	less(root,x);
				printf("%d\n",re);
				break;
		}

		scanf("%s",select);
		if(strcmp(select,"Quit")==0)
			break;
		scanf("%d",&x);

	}
return 0;
}

