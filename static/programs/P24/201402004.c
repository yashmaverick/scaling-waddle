#include <stdio.h>
#include<stdlib.h>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

struct node
{
	int val;
	struct node* left;
	struct node* right;
	struct node* parent;
	int nodes_lesser;
	int nodes_greater;
	int depth;
};

int depval;

int depth(struct node* head)
{
	if(head==NULL)
		return 0;
	else
		return head->depth;
}
void set_nodes(struct node* head)
{
    if(head==NULL)return;
    if(head->left!=NULL&&head->right!=NULL)
    {
        head->nodes_lesser=(head->left->nodes_lesser+head->left->nodes_greater+1);
        head->nodes_greater=(head->right->nodes_lesser+head->right->nodes_greater+1);
    }
    else if(head->left==NULL&&head->right!=NULL)
    {
        head->nodes_lesser=0;
        head->nodes_greater=(head->right->nodes_lesser+head->right->nodes_greater+1);
    }
    else if(head->left!=NULL&&head->right==NULL)
    {
        head->nodes_lesser=(head->left->nodes_lesser+head->left->nodes_greater+1);
        head->nodes_greater=0;
    }
    else
    {
        head->nodes_lesser=0;
        head->nodes_greater=0;
    }
}

int diff_height(struct node* head)
{
	if(head==NULL)
		return 0;
	else if(head->left!=NULL)
		if(head->right!=NULL)
			return (head->left->depth)-(head->right->depth);
		else
			return head->left->depth;
	else
		if(head->right==NULL)
			return 0;
		else
			return -1*head->right->depth;
}

struct node* right_rotate(struct node* z)
{
	struct node* y;
	struct node* t3;	
	y=z->left;
	t3=y->right;
	y->parent=z->parent;
	y->right=z;
	z->parent=y;
	z->left=t3;
	if(t3!=NULL)
	t3->parent=z;
	z->depth=max(depth(z->left)+1, depth(z->right)+1);
    y->depth=max(depth(y->left)+1, depth(y->right)+1);
    set_nodes(y);
    set_nodes(z);
    set_nodes(t3);
    return y;
}
struct node* left_rotate(struct node* z)
{
	struct node* y;
	struct node* t2;
	y=z->right;
	t2=y->left;
	y->parent=z->parent;
	y->left=z;
	z->right=t2;
	if(t2!=NULL)
	t2->parent=z;
	z->parent=y;
	z->depth=max(depth(z->left)+1,depth(z->right)+1);
    y->depth=max(depth(y->left)+1,depth(y->right)+1);
    set_nodes(y);
    set_nodes(z);
    set_nodes(t2);
    return y;
}


struct node* balance(struct  node* head)
{
	int bal_val=diff_height(head);
	//printf("The difference in depth of childrn of %d is %d\n",head->val,bal_val);
	if(bal_val>1)
	{
		if(diff_height(head->left)>0)
			head=right_rotate(head);
		else
		{
			head->left=left_rotate(head->left);
			head=right_rotate(head);
		}
	}
	else if(bal_val<-1)
	{
		if(diff_height(head->right)>0)
		{
			head->right=right_rotate(head->right);
        	head=left_rotate(head);
		}
		else
			head=left_rotate(head);
	}
	return head;
}

int rotten_before(struct node* head, int val, int ans)
{
    if(head==NULL)return ans;
    if(head->val>val)
    {
        return rotten_before(head->left,val,ans);
    }
    else if(head->val<val)
    {
        ans+=head->nodes_lesser+1;
        return rotten_before(head->right,val,ans);
    }
    else if(head->val==val)
    {
        return ans+head->nodes_lesser;
    }
    else
    {
        return ans;
    }

}

struct node* insert(struct node* parent,struct node* head, int val)
{
	if(head==NULL) 
	{
        head=(struct node*)(malloc(sizeof(struct node)));
        head->val=val;
        head->left=NULL;
        head->right=NULL;
        head->parent=parent;
        head->depth=1;
        set_nodes(head);
        //printf("New node %d inserted\n",head->val);
        return head;
    }
    else if(val<head->val)
    {
    	head->left=insert(head,head->left,val);
    	head->depth=max(depth(head->left)+1,depth(head->right)+1);
    	set_nodes(head);
//    	printf("The depth of the %d is %d and it is left child\n",head->val,head->depth);
    	head=balance(head);
    	set_nodes(head);
    }
    else if(val>head->val)
    {
    	head->right=insert(head,head->right,val);
    	head->depth=max(depth(head->left)+1,depth(head->right)+1);
    	set_nodes(head);
  //  	printf("The depth of the %d is %d and it is the right child\n",head->val,head->depth);
    	head=balance(head);
    	set_nodes(head);
    }
    
    return head;
}

struct node* search(struct node* head,int val)
{
    if(head==NULL)return NULL;
    if(val<head->val){depval*=2;return search(head->left,val);}
    if(val==head->val)return head;
    if(val>head->val){depval*=2;depval+=1;return search(head->right,val);}
}

int healthy(struct node* head, int val, int ans)
{
    if(head==NULL)
        return -1;
    //printf("The node is %d and %d is the size of left subtree and %d of right tree.\n",head->val,head->nodes_lesser,head->nodes_greater);
    if(val==ans+1)
    {
        //printf("The current node is %d\n",head->val);
        return head->val;
    }
    if(val<ans+head->nodes_lesser+1)
    {
        return healthy(head->left,val,ans);
    }
    else if(val>ans+head->nodes_lesser+1)
    {
        ans=ans+head->nodes_lesser+1;
        //printf("The ans is %d and the next node is %d\n",ans,head->right->val);
        return healthy(head->right,val,ans);
    }
}

void clear(struct node* head)
{
    if(head!=NULL)
    {
        clear(head->left);
        clear(head->right);
        free(head);
    }
}

void preorder(struct node* head)
{
    //head->depth=max(depth(head->left)+1,depth(head->right)+1);
    //printf("The node is %d and its depth is %d and left child depth is %d and right child depth is %d and max is %d\n",head->val,head->depth,depth(head->left),depth(head->right),max(depth(head->left),depth(head->right)));
    //printf("The node is %d and its depth is %d\n",head->val,head->depth);
    //printf("In %d node, The size of left tree is %d and right tree is %d and size of \n",head->val,head->nodes_lesser,head->nodes_greater);
    if(head->left!=NULL){preorder(head->left);}
    if(head->right!=NULL){preorder(head->right);}
    return;
}

int main(void) {
	struct node *root = NULL;
	struct node* ans;
	char s[1000];
	int v,out;
	scanf("%s",s);
	while(s[0]!='Q')
	{
	    scanf("%d",&v);
	    //printf("%d\n",v);
        if(s[0]=='S')
        { 
            //printf("Entered SetHealthy\n");    
            root=insert(NULL,root,v);
            //preorder(root);
        } 
        else if(s[0]=='C')
        {
         //   scanf("%d",&v);
            ans=search(root,v);
            if(ans==NULL)printf("NO\n");
            else
            printf("YES\n");
        } 
        else if(s[0]=='H')  
        {
           //scanf("%d",&v);
           out=healthy(root,v,0);
           if(out==-1)printf("NONE\n");
           else
           printf("%d\n",out);
        }
        else if(s[0]=='R')
        {
            //scanf("%d",&v);
            out=rotten_before(root,v,0);          
            printf("%d\n",out);
        }  
        else
        {
 //           printf("Wrong input\n");
        }  
    	scanf("%s",s);
    }	
  	free(root);
	return 0;
}
