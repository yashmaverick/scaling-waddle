#include<stdio.h>
#include<malloc.h>

typedef enum node_color {red,black} node_color;

typedef struct tree_node tree_node;

struct tree_node
{
	int key;
	tree_node *left;
	tree_node *right;
	tree_node *parent;
	node_color color;
	int size;
};

tree_node *root;
tree_node *nil;

void init_red_black_tree()
{
	nil=(tree_node *)malloc(sizeof(tree_node));
	nil->key=-1;
	nil->left=nil->right=nil->parent=NULL;
	nil->color=black;
	nil->size=0;
	root=nil;
}

tree_node *createtree_node(int key)
{
	tree_node *new_node;
	new_node=(tree_node *)malloc(sizeof(tree_node));
	new_node->key=key;
	new_node->left=new_node->right=new_node->parent=NULL;
	new_node->color=red;
	new_node->size=1;
	return new_node;
}

void left_rotate(tree_node *xnode)
{
	tree_node *ynode;
	ynode=xnode->right;
	xnode->right=ynode->left;
	if(ynode->left!=nil)
		ynode->left->parent=xnode;
	ynode->parent=xnode->parent;
	if(xnode->parent==nil)
		root=ynode;
	else if(xnode==xnode->parent->left)
		xnode->parent->left=ynode;
	else
		xnode->parent->right=ynode;
	ynode->left=xnode;
	xnode->parent=ynode;
	ynode->size=xnode->size;
	xnode->size=xnode->left->size+xnode->right->size+1;
}

void right_rotate(tree_node *ynode)
{
	tree_node *xnode;
	xnode=ynode->left;
	ynode->left=xnode->right;
	if(xnode->right!=nil)
		xnode->right->parent=ynode;
	xnode->parent=ynode->parent;
	if(ynode->parent==nil)
		root=xnode;
	else if(ynode==ynode->parent->left)
		ynode->parent->left=xnode;
	else
		ynode->parent->right=xnode;
	xnode->right=ynode;
	ynode->parent=xnode;
	xnode->size=ynode->size;
	ynode->size=ynode->left->size+ynode->right->size+1;
}

void insert_fixup(tree_node *znode)
{
	tree_node *ynode;
	while(znode->parent->color==red)
	{
		if(znode->parent==znode->parent->parent->left)
		{
			ynode=znode->parent->parent->right;
			if(ynode->color==red)
			{
				znode->parent->color=black;
				ynode->color=black;
				znode->parent->parent->color=red;
				znode=znode->parent->parent;
			}
			else
			{
				if(znode==znode->parent->right)
				{
					znode=znode->parent;
					left_rotate(znode);
				}
				znode->parent->color=black;
				znode->parent->parent->color=red;
				right_rotate(znode->parent->parent);
			}
		}
		else
		{
			ynode=znode->parent->parent->left;
			if(ynode->color==red)
			{
				znode->parent->color=black;
				ynode->color=black;
				znode->parent->parent->color=red;
				znode=znode->parent->parent;
			}
			else
			{
				if(znode==znode->parent->left)
				{
					znode=znode->parent;
					right_rotate(znode);
				}
				znode->parent->color=black;
				znode->parent->parent->color=red;
				left_rotate(znode->parent->parent);
			}
		}
	}
	root->color=black;
}

void insert_node(tree_node *znode)
{
	tree_node *xnode;
	tree_node *ynode;
	ynode=nil;
	xnode=root;
	while(xnode!=nil)
	{
		xnode->size++;
		ynode=xnode;
		if(znode->key<xnode->key)
			xnode=xnode->left;
		else
			xnode=xnode->right;
	}
	znode->parent=ynode;
	if(ynode==nil)
		root=znode;
	else if(znode->key<ynode->key)
		ynode->left=znode;
	else
		ynode->right=znode;
	znode->left=nil;
	znode->right=nil;
	znode->color=red;
	insert_fixup(znode);
}

tree_node *minimum(tree_node *xnode)
{
	while(xnode->left!=nil)
		xnode=xnode->left;
	return xnode;
}

tree_node *search_node(int key)
{
	tree_node *xnode;
	xnode=root;
	while(xnode!=nil)
	{
		if(key<xnode->key)
			xnode=xnode->left;
		else if(key>xnode->key)
			xnode=xnode->right;
		else
			return xnode;
	}
	return NULL;
}

tree_node *select_node(int rank)
{
	tree_node *xnode;
	xnode=root;
	while(rank!=xnode->left->size+1)
	{
		if(rank<xnode->left->size+1)
			xnode=xnode->left;
		else
		{
			rank-=xnode->left->size+1;
			xnode=xnode->right;
		}
	}
	return xnode;
}

int rank_node(int key)
{
	int rank;
	tree_node *xnode;
	rank=0;
	xnode=root;
	while(xnode!=nil)
	{
		if(key<xnode->key)
			xnode=xnode->left;
		else if(key==xnode->key)
		{
			rank+=xnode->left->size;
			break;
		}
		else
		{
			rank+=xnode->left->size+1;
			xnode=xnode->right;
		}
	}
	return rank;
}

void transplant(tree_node *unode,tree_node *vnode)
{
	if(unode->parent==nil)
		root=vnode;
	else if(unode==unode->parent->left)
		unode->parent->left=vnode;
	else
		unode->parent->right=vnode;
	vnode->parent=unode->parent;
}

void delete_fixup(tree_node *xnode)
{
	tree_node *wnode;
	while((xnode!=root) && (xnode->color==black))
	{
		if(xnode==xnode->parent->left)
		{
			wnode=xnode->parent->right;
			if(wnode->color==red)
			{
				wnode->color=black;
				xnode->parent->color=red;
				left_rotate(xnode->parent);
				wnode=xnode->parent->right;
			}
			if((wnode->left->color==black) && (wnode->right->color==black))
			{
				wnode->color=red;
				xnode=xnode->parent;
			}
			else
			{
				if(wnode->right->color==black)
				{
					wnode->left->color=black;
					wnode->color=red;
					right_rotate(wnode);
					wnode=xnode->parent->right;
				}
				wnode->color=xnode->parent->color;
				xnode->parent->color=black;
				wnode->right->color=black;
				left_rotate(xnode->parent);
				xnode=root;
			}
		}
		else
		{
			wnode=xnode->parent->left;
			if(wnode->color==red)
			{
				wnode->color=black;
				xnode->parent->color=red;
				right_rotate(xnode->parent);
				wnode=xnode->parent->left;
			}
			if((wnode->right->color==black) && (wnode->left->color==black))
			{
				wnode->color=red;
				xnode=xnode->parent;
			}
			else
			{
				if(wnode->left->color==black)
				{
					wnode->right->color=black;
					wnode->color=red;
					left_rotate(wnode);
					wnode=xnode->parent->left;
				}
				wnode->color=xnode->parent->color;
				xnode->parent->color=black;
				wnode->left->color=black;
				right_rotate(xnode->parent);
				xnode=root;
			}
		}
	}
	xnode->color=black;
}

void delete_node(tree_node *znode)
{
	node_color ynode_original_color;
	tree_node *xnode;
	tree_node *ynode;
	tree_node *pnode;
	ynode=znode;
	ynode_original_color=ynode->color;
	if(znode->left==nil)
	{
		pnode=znode->parent;
		xnode=znode->right;
		transplant(znode,znode->right);
	}
	else if(znode->right==nil)
	{
		pnode=znode->parent;
		xnode=znode->left;
		transplant(znode,znode->left);
	}
	else
	{
		ynode=minimum(znode->right);
		ynode_original_color=ynode->color;
		xnode=ynode->right;
		if(ynode->parent==znode)
		{
			pnode=znode->parent;
			xnode->parent=ynode;
		}
		else
		{
			pnode=ynode->parent;
			transplant(ynode,ynode->right);
			ynode->right=znode->right;
			ynode->right->parent=ynode;
		}
		transplant(znode,ynode);
		ynode->left=znode->left;
		ynode->left->parent=ynode;
		ynode->color=znode->color;
	}
	while((pnode!=nil) && (pnode!=root))
	{
		pnode->size--;
		pnode=pnode->parent;
	}
	if(ynode!=nil)
		ynode->size=ynode->left->size+ynode->right->size+1;
	if(pnode!=nil)
		pnode->size=pnode->left->size+pnode->right->size+1;
	if(ynode_original_color==black)
		delete_fixup(xnode);
	free(znode);
}

void delete_tree(tree_node *xnode)
{
	if(xnode==nil)
		return;
	delete_tree(xnode->left);
	delete_tree(xnode->right);
	free(xnode);
}

void delete_red_black_tree()
{
	delete_tree(root);
	free(nil);
}

int main()
{
	char op[100];
	int count,k,Q,x;
	init_red_black_tree();
	tree_node *node;
	count=0;
	scanf("%s",op);
	while(op[0]!='Q')
	{
		//scanf("%s",op);
		switch(op[0])
		{
		case 'S':
			scanf("%d",&x);
			if(search_node(x)==NULL)
			{
				insert_node(createtree_node(x));
				count++;
			}
			break;

		case 'C':
			scanf("%d",&x);
			if((node=search_node(x))!=NULL)
				puts("YES");
			else
				puts("NO");
			break;

		case 'H':
			scanf("%d",&k);
			if(k>count)
				printf("NONE\n");
			else
				printf("%d\n",select_node(k)->key);
			break;

		case 'R':
			scanf("%d",&x);
			printf("%d\n",rank_node(x));
			break;
		}
		scanf("%s",op);
	}
	delete_red_black_tree();
	return 0;
}
