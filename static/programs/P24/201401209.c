#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct node
{
    ll val;
    ll height;
    ll lc;
    ll rc;
    struct node* left;
    struct node* right;
}node;
ll max(ll a,ll b)
{
    if(a>=b) return a;
    else return b;
}
ll height(node* root)
{
    if(root==NULL) return 0;
//    printf("in height root-> %lld height->%lld\n",root->val,root->height);
    return root->height;
}
ll calch(node* root)
{
    if(root==NULL) return 0;
    else return max(height(root->left),height(root->right))+1;
}
node* left_rotate(node* root)
{
    node* temp=root->left;
    root->lc=temp->rc;
    root->height=calch(root);
    root->left=temp->right;
    root->height=calch(root);
    temp->right=root;
    temp->height=calch(temp);
    temp->rc=root->lc+root->rc+1;
    temp->height=calch(temp);
    return temp;
}
node* right_rotate(node* root)
{
    //printf("hi %lld\n",root->val);
    node* temp=root->right;
    root->rc=temp->lc;
    root->height=calch(root);
    root->right=temp->left;
    root->height=calch(root);
    temp->lc=root->lc+root->rc+1;
    temp->height=calch(temp);
    temp->left=root;
    temp->height=calch(temp);
    return temp;
}
void udfs(node* root)
{
    if(root==NULL) return;
    udfs(root->left);
    udfs(root->right);
    printf("root -> %lld lc-> %lld rc-> %lld  height->%lld\n",root->val,root->lc,root->rc,root->height);
}
node* insert(node* root,ll x)
{
    if(root==NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->val=x;
        temp->lc=0;
        temp->rc=0;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=1;
        return temp;
    }
    else
    {
        if(x>root->val)  {  root->rc++;  root->right=insert(root->right,x);}
        else  {  root->lc++;  root->left=insert(root->left,x); } 
    }
   // printf("trace back %lld %lld %lld->left %lld %lld->right %lld\n",root->val,height(root),root->val,height(root->left),root->val,height(root->right));
    root->height=calch(root);
   // printf("trace back %lld %lld %lld->left %lld %lld->right %lld\n",root->val,height(root),root->val,height(root->left),root->val,height(root->right));
    if(height(root->left)-height(root->right)>=2)
    {
     //        printf("r -> %lld %lld\n",height(root->left),height(root->right));
       //    printf("%lld %lld\n",height(root->left->left),height(root->left->right));
        if(height(root->left->left)>height(root->left->right))
        {
         //              printf("rotate ll");
            root=left_rotate(root);
        }
        else if(height(root->left->left)<height(root->left->right))
        {
         //             printf("rotate lr\n");
            root->left=right_rotate(root->left);
            root=left_rotate(root);
        }
    }
    else if(height(root->right)-height(root->left)>=2)
    {
        if(height(root->right->right)>height(root->right->left))
        {
           //             printf("rotate rr");
            root=right_rotate(root);
        }
        else if(height(root->right->left)>height(root->right->right))
        {
             //         printf("rotate rl");
            root->right=left_rotate(root->right);
            root=right_rotate(root);
        }
    }
  //  udfs(root);
    return root;
}
void find(node* root,ll temp)
{
    if(root==NULL) { printf("NO\n"); return; }
    if(root->val==temp) { printf("YES\n");  return; }
    else if(temp<=root->val) {  find(root->left,temp); return;   }
    else find(root->right,temp);
}
ll dfsc=0;
ll dfs(node* root,ll x)
{
    if(root==NULL) return;
   // printf("%lld %lld\n",root->val,x);
    if(root->lc+1==x) { return root->val;  }
    else if(root->lc+1>x) {  return dfs(root->left,x);  }
    else if(root->lc+1<x) { return dfs(root->right,x-root->lc-1); }
}
void dfs2(node* root,ll x)
{
    if(root==NULL) return;
//    printf("dfs2 -> %lld %lld\n",root->val,x);
    if(root->val==x) { dfsc+=root->lc; return ;}
    else if(root->val<x) {  dfsc+=root->lc;dfsc++; dfs2(root->right,x);  }
    else if(root->val>x) { dfs2(root->left,x);   }
}

int main()
{
    node* root=NULL;
    ll size=0;
    while(1)
    {
        char a[100];
        scanf("%s",a);
        if(a[0]=='Q') break;
        else
        {
            ll temp;
            scanf("%lld",&temp);
            if(a[0]=='C') find(root,temp);
            else if(a[0]=='S') { root=insert(root,temp); size++;}
            else if(a[0]=='H')
            {
                if(temp>size) printf("NONE\n");
                else{ temp=dfs(root,temp);
                printf("%lld\n",temp);}
            }
            else { dfsc=0; dfs2(root,temp);  printf("%lld\n",dfsc); dfsc=0; }
        }
    }

    return 0;
}
