#include <stdio.h>
#include<stdlib.h>

int vis[1000000], a[1000000], b[1000000], n,i;

struct node
{
	struct node* left;
	struct node* right;
	struct node* parent;
	int val;
	int depth;
};

struct node* build(int start, int end, int depth, struct node* head, struct node* parent)
{
	int j;
	
	if(start>end||start<0||end>n)return NULL;
	head=(struct node*)(malloc(sizeof(struct node)));
	if(parent!=NULL)
	head->parent=parent;
	head->depth=depth;
	//printf("%d %d %d %d\n",start,end,i,depth);
	for(j=start;j<=end;j++)
	{
		if(a[j]==b[i])
		{
			vis[i]=1;
			head->val=a[j];
			i++;
			//printf("%d\n",a[j]);
			head->left=build(start,j-1,depth+1,head->left,head);
			if(head->left!=NULL);
			//printf("The left child of %d is %d\n ",head->val,head->left->val);
			for(i=start;vis[i]==1;i++);
			
			head->right=build(j+1,end,depth+1,head->right,head);
			if(head->right!=NULL);
			//printf("The right child of %d is %d\n",head->val,head->right->val);
			return head;
		}
	}
}

struct node* find(int val, struct node* head)
{
    struct node* temp;
    if(head->val==val)return head;
    else
    {
        if(head->left!=NULL)
        {
            //printf("Finding in left child of %d\n",head->val);
            temp=find(val,head->left);
            if(temp!=NULL)
            {
                //printf("The value was found in the left branch of %d\n",head->val);
                return temp;
            }   
        }
        if(head->right!=NULL)
        {
            //printf("Finding in right child of %d\n",head->val);
            temp=find(val,head->right);
            if(temp!=NULL)
            {
                //printf("The value was found in the right branch of %d\n",head->val);
                return temp;
            }     
        }
            return NULL;
    }
}

struct node* root=NULL;

int main(void) {
	int i,x,y;
	scanf("%d",&n);
	n--;
	for(i=0;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	root=build(0,n,0,root,NULL);
	scanf("%d",&n);
	//printf("The bnumber of inputs are %d",n);
	for(i=0;i<n;i++)
	{
        scanf("%d %d",&x,&y);
        //printf("The entered numbers are %d %d\n",x,y);
        struct node* n1=find(x,root);
        struct node* n2=find(y,root);
        if(n1->depth<n2->depth)
        {
            struct node* tmp;
            tmp=n1;
            n1=n2;
            n2=tmp;
        }
        while(n1->depth>n2->depth)
        {
            n1=n1->parent;
        }
        while(n1->val!=n2->val)
        {
            n1=n1->parent;
            n2=n2->parent;
        }
        printf("%d\n",n1->val);	    
	}
	return 0;
}

