#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int prec=0;
int *b,n,*a,*par,*dep;
int find(int);
typedef struct  node
{
    struct node* left;
    struct node* right;
    int val;
}node;

node * newnode(int d)
{
    node *a;
    a=(node *)malloc(sizeof(node));
    a->val=d;
    a->left=NULL;
    a->right=NULL;
    return a;
}
node * ins(int i,int j)
{
    if(i==j)
        return newnode(a[prec++]);
    if(i>j)
        return NULL;
    else
    {
        node *r;
        r=newnode(a[prec++]);
        int pos;
        pos=find(r->val);
        r->left=ins(i,pos-1);
        r->right=ins(pos+1,j);
        return r;
    }
}
void dfs(node *head,int depth,int parent)
{
    if(head==NULL)
        return;
    a[head->val]=parent;
    b[head->val]=depth;
    dfs(head->left,depth+1,head->val);
    dfs(head->right,depth+1,head->val);

}
int lca(int x,int y)
{
    while(x!=y)
    {
        if(b[x]>b[y])
            x=a[x];
        else {
            y=a[y];
        }
    }
    return x;
}
int find(int q)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(q==b[i])
            return i;
    }
}
void inorder(node *top)
{
    if(top!=NULL)
    {
        inorder(top->left);
        printf("%d ",top->val);
        inorder(top->right);
    }
}

int main()
{
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    b=(int *)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int pre=0;int pos=0;
    node *head=ins(0,n-1);
   // inorder(head);//checking the insertion code
    dfs(head,0,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,ans;
        scanf("%d%d",&x,&y);
        ans=lca(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
