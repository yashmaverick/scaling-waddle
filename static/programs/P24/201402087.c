#include<stdio.h>
#include<stdlib.h>

typedef struct t
{
		int d;
		int h;
		int el;
		int er;
		struct t* right;
		struct t* left;
}t;

int lelements(t* head)
{
		if(head==NULL)
				return 0;
		return head->el;
}

int relements(t* head)
{
		if(head==NULL)
				return 0;
		return head->er;
}

int height(t* head)
{
		if(head==NULL)
				return 0;
		return head->h;
}

int max(int a,int b)
{
		if(a>b)
				return a;
		return b;
}

void postorder(t* head)
{
		printf("%d h=%d el=%d er=%d\n",head->d,height(head),lelements(head),relements(head));
		if(head->left!=NULL)
				postorder(head->left);
		if(head->right!=NULL)
				postorder(head->right);
}

int hb(t* head)
{
		if(head==NULL)
				return 0;//
		else
				return (height(head->left) - height(head->right));
}

t* rights(t* head)
{
		//t* temp1=head;
		t* temp2=head->left;
		t* temp=temp2->right;
		
		temp2->right=head;
		head->left=temp;
		//head=temp1->left;
		
		
		head->h=1+max(height(head->left),height(head->right));
		if( head->left == NULL)
				head->el=lelements(head->left)+relements(head->left);
		else		
				head->el=1+lelements(head->left)+relements(head->left);
		temp2->h=1+max(height(temp2->left),height(temp2->right));
		if(temp2->right == NULL)
				temp2->er=lelements(temp2->right)+relements(temp2->right);
		else
				temp2->er=1+lelements(temp2->right)+relements(temp2->right);
		return temp2;
}

t* lefts(t* head)
{
	//	t* temp1=head;
		t* temp2=head->right;
		t* temp=temp2->left;
				
		temp2->left=head;
		head->right=temp;
		//head=temp1->right;

	//	printf("before d=%d er=%d yol=%d yor=%d\n",head->d,head->er,lelements(head->right),relements(head->right));
		head->h=1+max(height(head->left),height(head->right));
		if(head->right==NULL)
				head->er=lelements(head->right)+relements(head->right);
		else
				head->er=1+lelements(head->right)+relements(head->right);
	//	printf("after d=%d er=%d\n",head->d,head->er);

		temp2->h=1+max(height(temp2->left),height(temp2->right));
	    if( temp2->left == NULL)
				temp2->el=lelements(temp2->left)+relements(temp2->left);	
		else
				temp2->el=1+lelements(temp2->left)+relements(temp2->left);	
		return temp2;
}

t* insert(int num,t* head)
{
		if(head==NULL)
		{
				head=(t*)malloc(sizeof(t));
				head->d=num;
				head->left=NULL;
				head->right=NULL;
				head->h=1;
				head->el=0;
				head->er=0;
				return head;
		}
		else if(num<(head->d))
		{
				head->left=insert(num,head->left);
				head->el=lelements(head)+1;
		}
		else if(num>(head->d))
		{
				head->right=insert(num,head->right);
				head->er=relements(head)+1;
		}

		//head->el=1+lelements(head->left)+relements(head->left);
		//head->er=1+lelements(head->right)+relements(head->right);
		head->h=1+max(height(head->left),height(head->right));
	    //printf("head->h=%d\n",head->h);	
		
		int diff=hb(head);   
		
		if(diff>1)//left
		{
				//int diffc=hb(head->left);
				
				if(num<head->left->d)//left-left
						return rights(head);
				else
				{
						head->left=lefts(head->left);
						return rights(head);
				}
		}
		else if(diff <-1)//right
		{
				//int diffc=hb(head->right);
				
				if(num>head->right->d)//right-right
				{
					//	printf("right right\n");
						return lefts(head);
				}
				else
				{
						head->right=rights(head->right);
						return lefts(head);
				}
		}
		return head;
}

int search( int num , t* head )
{
		if(head==NULL)
				return 0;
		else if( head->d == num )
				return 1;
		else if( num < head->d )
				return search(num,head->left);
		else if( num > head->d )
				return search(num,head->right);
}

int count;
int flag;
void rotten( int num,t* head)
{
		if(head==NULL)
				return;
		else if(head->d==num)
				count+=lelements(head);
		else if( head->d > num)
		{
				rotten(num,head->left);
		}
		else if( head->d < num )
		{
				count+=lelements(head)+1;
				rotten(num,head->right);
		}
}
int node;
void healthy(int num,t* head)
{
	//	printf("%d\n",lelements(head)+count);
		if( head==NULL )
				return;
		else if(lelements(head)+count == num-1)
		{
	//			printf("==\n");
				flag=1;
				node=head->d;
				return;
		}
		else if(lelements(head)+count>=num)
		{
	//			printf("yo\n");
				healthy(num,head->left);
		}
		else
		{
	//			printf("else\n");
				count+=lelements(head)+1;
				healthy(num,head->right);
		}
}

int main()
{
		char query[100];
		scanf("%s",query);
		t* root =NULL;
		while(query[0]!='Q')
		{
				count=0;
				flag=0;
				node=0;
				if( query[0] == 'S' )
				{
						int n;
						scanf("%d",&n);
						int yo = search(n,root);
						if(yo==1)
								;
						else
								root = insert(n,root);
					//	postorder(root);
					//	printf("\n");
				}
				else if ( query[0] == 'C' )
				{
						int n;
						scanf("%d",&n);
						int yo = 0;
						yo = search(n,root);
						if(yo==1)
								printf("YES\n");
						else
								printf("NO\n");
				}
				else if( query[0] == 'H' )
				{
						int n;
						scanf("%d",&n);
						flag=count=0;
						healthy(n,root);
						if(flag!=1)
								printf("NONE\n");
						else
								printf("%d\n",node);
				}
				else if ( query[0] == 'R' )
				{
						int n;
						scanf("%d",&n);
						flag=count=0;
						rotten(n,root);
						printf("%d\n",count);
				}
				else if( query[0] == 'P')
				{
						postorder(root);
						printf("\n");
				}
				scanf("%s",query);
		}
		return 0;
}
