//Author:Bhaktipriya Shridhar
//Date:26th Feb 2015

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
long long int ctr=0;
long long int n;
long long int inorder[MAX],preorder[MAX];
long long int path1[MAX],path2[MAX],ctr1,ctr2,ctr;
typedef struct node
{long long int val; struct node *left;struct node *right;}node;

long long int search(long long int key)
{
    long long int i;
    for(i=0;i<n;++i)
        if(inorder[i]==key)
            return i;
}
node* newnode(long long int v)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->left=ptr->right=0;
    ptr->val=v;
    return ptr;
}
node* partition(long long int beg,long long int end)
{
    if (beg>end)
        return NULL;

    node *root=newnode(preorder[ctr++]);
    if(beg==end)
    {//current node has no children
        return root;
    }
    else{
        //assign values to current node's children
        long long int rootptr=search(root->val);
        root->left=partition(beg,rootptr-1);
        root->right=partition(rootptr+1,end);
        return root;
    }
}

void ino (node *ptr)
{

    if(ptr->left!=NULL)
        ino(ptr->left);
    printf("%lld ",ptr->val);
    if(ptr->right!=NULL)
        ino(ptr->right);
}

void preo(node *ptr)
{
    printf("%lld ",ptr->val);
    if(ptr->left!=NULL)
        preo(ptr->left);
    if(ptr->right!=NULL)
        preo(ptr->right);

}

long long int tsearch(node *ptr,long long int el)
{
    if(ptr==NULL)
        return 0;
    if(ptr->val==el)
        return 1;
    else if(ptr->val<el)
    {return tsearch(ptr->right,el);}//look in right
    else if(ptr->val>el)
    {return tsearch(ptr->left,el);} //look in left

}

int dfs(node *root,long long int el,long long int path[MAX])
{
    if(root==NULL)
        return 0;
    if(root!=NULL)
    {
        path[ctr++]=root->val;
        if(root->val==el)
        {
            return 1;
        }

        if(root->left)
            if(dfs(root->left,el,path))
                return 1;
        if(root->right)
            if(dfs(root->right,el,path))
                return 1;
        ctr--;
        return 0;
    }
}
int main()

{

    long long int i,test,a,b,min;
    long long int beg,end;
    scanf("%lld",&n);

    for(i=0;i<n;++i)
        scanf("%lld",&preorder[i]);

    for(i=0;i<n;++i)
        scanf("%lld",&inorder[i]);

    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&a);
        scanf("%lld",&b);

        ctr1=ctr2=0;

        long long int pos2=search(a),pick,pos1;
        beg=0;
        end=n-1;
        for(i=0;i<n;++i)
        {
            pick=preorder[i];
            pos1=search(pick);
            if(pos1>=beg&&pos1<=end)
            {
  //              printf("%lld ",pick);
                path1[ctr1++]=pick;
                if(pos1<pos2)
                    beg=pos1;
                else if(pos1>pos2)
                    end=pos1;
                else
                    break;

            }
        }
//        printf("\n\n");

        pos2=search(b);
        beg=0;
        end=n-1;
        for(i=0;i<n;++i)
        {
            pick=preorder[i];
            pos1=search(pick);
            if(pos1>=beg&&pos1<=end)
            {

                path2[ctr2++]=pick;
    //            printf("%lld ",pick);
                if(pos1<pos2)
                    beg=pos1;
                else if(pos1>pos2)
                    end=pos1;
                else
                    break;

            }
        }
        long long int min=ctr1<ctr2?ctr1:ctr2;
        for(i=0;i<min;++i)
            if(path1[i]!=path2[i])
            {
                printf("%lld\n",path1[i-1]);
                break;
            }
        if(i==min)
            printf("%lld\n",path1[min-1]);

    }
    return 0;
}
