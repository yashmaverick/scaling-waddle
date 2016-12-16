#include<stdio.h>
#include<stdlib.h>

struct node
{
	int w;
	int *d;
	int n_d;
	struct node *left, *right;
};

typedef struct node node;

node* insert(int w, int *desc,int n_d, node* positon);
void print_inorder(node* root);

int main()
{
	int n,w=0,i,mod,n_items,j,w_item;
	scanf("%d%d",&n,&mod);
	int *desc;
	
	node *root = NULL;

	for(i = 0; i < n; i++)
	{
		w=0;
		scanf("%d",&n_items);
		desc = (int*) malloc( n_items * sizeof(int) );
		
		for( j = 0; j < n_items; j++)
		{
			scanf("%d",&w_item);
			w = ( w + w_item ) % mod ;
			desc[j] = w_item;

		}

		root = insert(w, desc, n_items, root);
	}

	print_inorder(root);
	
	return 0;
}

node* insert( int n, int *desc, int n_items, node* position)
{
	if( position == NULL )
	{
		position = (node*) malloc(sizeof(node)) ;
		position->w = n ;
		position->d = desc ;
		position->n_d = n_items ;
		position->left = position->right = NULL;
		return position;
	}
	else
	{
		if( n < position->w )
		{
			position->left = insert(n, desc, n_items, position->left);
			return position; 
		}
		else
		{
			position->right = insert(n, desc, n_items, position->right);
			return position;

		}
	}	
}

void print_inorder(node* position)
{
	int j;

	if( position == NULL )
	{
		return;
	}
	else
	{
		print_inorder(position->left);
		
		/* Print bag desc {.....*/
		printf("%d\n",position->w);

		for( j = 0; j < position->n_d; j++ )
		{
			printf("%d\n",( *((position->d) + j )) );
		}
		printf("\n");
		/* ...... }              */
		
		print_inorder(position->right);
		return;
	}
	
}
