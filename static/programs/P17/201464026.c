#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int k,iter=0;
typedef struct node
{
	int val;
	struct node *l;
	struct node *r;
}node;
node *create(int *inorder,int *preorder,int start,int end)
{
	if(start >= end)
		return NULL;
	if(start==end-1)
	{
		node *a = (node *)malloc(sizeof(node));
		a->val = preorder[k++];
		a->l = NULL;
		a->r = NULL;
		return a;
	}
	else
	{
		node *a = (node *)malloc(sizeof(node));
		a->val = preorder[k++];
		int i;
		for(i=start;i<end;i++)
		{
			if(inorder[i]==preorder[k-1])
				break;
		}
		a->l = create(inorder,preorder,start,i);
		a->r = create(inorder,preorder,i+1,end);
        return a;
	}
}
/*void print(node * root)
{
    if(root==NULL)
        return;
    print(root->l);
    printf("%d ",root->val);
    print(root->r);
}*/
int lca(node *root,int a,int b)
{
    //iter++;
    //printf("Debug : Call lca : root : %d,iteration: %d",root->val,iter);
    int ans;
	if(root == NULL)
        ans = INT_MIN;
    else if(root->val == a)
        ans = a;
    else if(root->val == b)
        ans = b;
	else
	{
		int l = lca(root->l,a,b);
		int r = lca(root->r,a,b);
		if(l!=INT_MIN && r!=INT_MIN)
            ans = root->val;
		else if(l == INT_MIN)
			ans = r;
		else
			ans = l;
	}
    return ans;
}
int main()
{
    int nodes,i,j;
    scanf("%d",&nodes);
    int *preorder,*inorder;
    preorder = (int *)malloc(4*nodes);
    inorder = (int *)malloc(4*nodes);
    for(i=0;i<nodes;i++)
        scanf("%d",&preorder[i]);
    for(i=0;i<nodes;i++)
        scanf("%d",&inorder[i]);
    k = 0;
    node * root = create(inorder,preorder,0,nodes);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        //print(root);
        //putchar('\n');
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(root,a,b));
    }
    free(inorder);
    free(preorder);
    free(root);
    return 0;
}
