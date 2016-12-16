#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
	int d;
	int h;
	int e;
	struct avl *left;
	struct avl *right;
}avl;


//avl functions
avl *left_shift(avl *temp);
avl *right_shift(avl *right);
avl *insert(avl *temp,int x);
int height(avl *temp);
//void in_order(avl *temp);
//void in_order2(int x,avl *temp);

//required functions
avl *insert_sack(int x,avl *temp);
avl *search_sack(int x,avl *temp);
void xth_sack(int x,avl *temp);
//void lessthanx(int x,avl *temp);
int elements(avl *temp)
{
	if(temp!=NULL)
		return temp->e;
	else if(temp==NULL) 
		return 0;
}

//global variables
int count;
int flag;
//main()
int main()
{
	char s[100];
	int x;
	avl *root = NULL;
	avl *temp=NULL;

	while(1)
	{
		count=0;
		flag=0;
		//inputing
		scanf("%s",s);
		if(s[0]=='Q')
			break;
		scanf("%d",&x);

		char c=s[0];
		switch(c)
		{
			case 'S':
				temp=search_sack(x,root);
				if(temp!=NULL)
					break;
				root=insert_sack(x,root);
				break;
			case 'C':
				temp=search_sack(x,root);
				if(temp!=NULL)
					printf("YES\n");
				else if(temp==NULL)
					printf("NO\n");
				break;
			case 'H':
				if(x>elements(root))
					printf("NONE\n");
				else
					xth_sack(x,root);


				break;
			case 'R':

				temp=search_sack(x,root);
				if(temp==NULL && count==0)
					printf("0\n");
				else
					printf("%d\n",count);
				break;
			default:
				break;
		}


	}
	return 0;
}

avl *insert(avl *temp,int x)
{
	if(temp==NULL)
	{
		temp=(avl *)malloc(sizeof(avl));
		temp->h=1;
		temp->d=x;
		temp->left=NULL;
		temp->right=NULL;
		temp->e=1;
		return temp;
	}

	if(temp->d<x)
	{   

		temp->right=insert(temp->right,x);
		temp->e=temp->e+1;

	}
	else
	{   
		temp->left=insert(temp->left,x);

		temp->e=temp->e+1;
	}
	//incrementing height

	int hl=height(temp->left);
	int hr=height(temp->right);
	temp->h=(hl>hr?hl:hr)+1;

	int diff=hl-hr;



	if(diff<0 && temp->right!=NULL)
	{
		//right-right case or right-left case
		if(diff < -1 && x>temp->right->d)//right-right case
			return left_shift(temp);
		else if(diff < -1 && x<temp->right->d) //right-left case
		{
			temp->right=right_shift(temp->right);
			return left_shift(temp);
		}
	}
	else if(diff>0 && temp->left!=NULL) 
	{
		//left-left case or left-right case
		if(diff>1 && x<temp->left->d)//left-left case
			return right_shift(temp);
		else if(diff>1 && x>temp->left->d) //left-right case
		{
			temp->left=left_shift(temp->left);
			return right_shift(temp);
		}
	}

	return temp;
	//end of insert
}
avl *right_shift(avl *a)
{
	avl *b=a->left;
	avl *c=b->right;

	int nl=elements(b->left);
	int nr=elements(b->right);

	b->right=a;
	a->left=c;

	a->e=a->e-b->e+nr;
	b->e=a->e+nl+1;


	int hl=height(a->left);
	int hr=height(a->right);

	a->h=(hl>hr?hl:hr)+1;
	hl=height(b->left);
	hr=height(b->right);
	b->h=(hl>hr?hl:hr)+1;


	return b;
}
avl *left_shift(avl *a)
{
	avl *b=a->right;
	avl *c=b->left;

	int nl=elements(b->left);
	int nr=elements(b->right);

	b->left=a;
	a->right=c;

	a->e=a->e-b->e+nl;
	b->e=a->e+nr+1;


	int hl=height(a->left);
	int hr=height(a->right);
	a->h=(hl>hr?hl:hr)+1;
	hl=height(b->left);
	hr=height(b->right);
	b->h=(hl>hr?hl:hr)+1;


	return b;
}
int height(avl *temp)
{
	if(temp!=NULL)
		return temp->h;
	else
		return 0;
}
avl *insert_sack(int x,avl *temp)
{
	return insert(temp,x);
}
avl *search_sack(int x,avl *temp)//search
{
	while(temp!=NULL)
	{    
		if(temp->d==x)
		{   count+=elements(temp->left);
			return temp;
		}
		else if(temp->d>x)
			temp=temp->left;
		else if(temp->d<x)
		{   count+=elements(temp->left)+1;
			temp=temp->right;
		}
	}    
	return NULL;
}
void xth_sack(int x,avl *temp)
{



	if((elements(temp->left)+1)==x)
	{
		printf("%d\n",temp->d);
		return;
	}
	else if(elements(temp->left)>=x)
		xth_sack(x,temp->left);
	else if(elements(temp->left)<x)
		xth_sack(x-elements(temp->left)-1,temp->right);
}

/*void in_order(avl *temp)//in order
  {
  if(temp!=NULL)
  {

  in_order(temp->left);


  printf("%d %d\n",temp->d,temp->e);

  in_order(temp->right);
  }
  }
  void in_order2(int x,avl *temp)//in order
  {
  if(temp!=NULL)
  {
  count++;
  in_order2(x,temp->left);
  if(temp->d==x)
  {
  flag=1;
  printf("%d\n",(count-1));
  }
  in_order2(x,temp->right);
  }
  }*/
