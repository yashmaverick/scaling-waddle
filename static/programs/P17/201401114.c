#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct node
{
        ll val;
        struct node*left, *right;
}node;

ll pre[100001], in[100001], pre_index; //initialised to 1
node*root=NULL;
node* build_tree(ll start, ll end)
{
        if(start>end)
                return NULL;

        node*ptr=malloc(sizeof(node));
        ptr->val=pre[pre_index++];
        ptr->left=ptr->right=NULL;

        if(start==end)
                return ptr;
        
        ll i, index;
        for(i=start; i<=end; i++)
                if(in[i]==ptr->val)
                {
                        index=i;
                        break;
                }

        ptr->left=build_tree(start, index-1);
        ptr->right=build_tree(index+1, end);
        return ptr;
}
void inorder(node*root)
{
        if(root==NULL)
                return;
        else
        {
                inorder(root->left);
                printf("%lld ", root->val);
                inorder(root->right);
        }
}

node* lca(node*ptr, ll n1, ll n2)
{
        if(ptr==NULL)
                return NULL;

        if(ptr->val==n1 || ptr->val==n2)
                return ptr;

        node*left=lca(ptr->left, n1, n2);
        node*right=lca(ptr->right, n1, n2);

        if (left==NULL)
                return right;
        if(right==NULL)
                return left;
        if (left != NULL && right != NULL)
                return ptr;
}
int main()
{
        ll N, i;
        pre_index=0;
        scanf("%lld", &N);

        //printf("Enter preorder: ");
        for(i=0; i<N; i++)
                scanf("%lld", &pre[i]);
        //printf("Enter inorder: ");
        for(i=0; i<N; i++)
                scanf("%lld", &in[i]);

        /*node*ptr=malloc(sizeof(node));
        ptr->val=pre[0];
        ptr->left=NULL;
        ptr->right=NULL;
        root=ptr;*/

        root=build_tree(0, N-1);
        //inorder(root);

        ll t, pos_JS, pos_WW;
        scanf("%lld", &t);
        while(t--)
        {
                scanf("%lld %lld", &pos_JS,&pos_WW);
                node* ans=lca(root, pos_JS, pos_WW);
                printf("%lld\n", ans->val);
        }
                

        return 0;
}




        
