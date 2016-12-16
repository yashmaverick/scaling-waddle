#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int ht,val,ln,rn;
        struct node *l,*r;
}node;
int height(node * x)
{
        if( x==NULL)
                return 0;
        return x->ht;
}
int max(int a, int b)
{
        return (a>b)?a:b;
}
node* RR(node *y)
{
        node *x=y->l;
        node *t2=x->r;
        (x->rn)+=(1+ y->rn );
        (y->ln)-=(1+ x->ln );
        y->l=t2;
        x->r=y;
        y->ht=max(height(y->l),height(y->r)) + 1;
        x->ht=max(height(x->l),height(x->r)) + 1;
        return x;
}
node *RL(node *x)
{
        node *y=x->r;
        node* t2=y->l;
        (x->rn)-=(1+ y->rn );
        (y->ln)+=(1+ x->ln );
        y->l=x;
        x->r=t2;
        y->ht=max(height(y->l),height(y->r)) + 1;
        x->ht=max(height(x->l),height(x->r)) + 1;
        return y;
}
node* newNode(int val)
{
        node *temp=(node*)malloc(sizeof(node));
        temp->val = val;
        temp->ht=1;
        temp->l = NULL;
        temp->r = NULL;
        temp->ln=0;
        temp->rn=0;
        return temp;
}
node* addNode(node* root, node* new)
{
        if(root == NULL)
                root = new;
        else if(root->val >= new->val)
        {
                root->ln++;
                root->l=addNode(root->l, new);
        }
        else
        {
                root->rn++;
                root->r=addNode(root->r, new);
        }
        root->ht=max(height(root->l),height(root->r))+1;
        int diff = height(root->l)-height(root->r);
        if(diff < -1 )
        {
              //  printf("AAAAAAAAAAA 1\n");
                int diffr = height(root->r->l)-height(root->r->r);
                //printf("AAAAAAAAAAA 2\n");
                if(diffr<0)
                        return RL(root);
                  //              printf("a");
                root->r=RR(root->r);
                return RL(root);
        }
        else if(diff>1)
        {
             //   printf("BBBBBBBBBBBB 1\n");
                int diffl = height(root->l->l)-height(root->l->r);
               // printf("BBBBBBBBBBBB 2\n");
                //              printf("b");
                if(diffl>0)
                        return RR(root);
                //              printf("c");
                root->l=RL(root->l);
                return RR(root);
                //          printf("d");
        }
        return root;
}
int fl=0;
void search(node *root, int x)
{
        if(root == NULL)
                return;
        if(root->val == x)
                fl=1;
        else if(root->val < x)
                search(root->r,x);
        else
                search(root->l,x);
}               
void print(int x,node *root)
{
        node *t=root;
        while(t!=NULL)
        {
                if((t->ln)+1 == x)
                {
                        x-=(t->ln + 1);
                        printf("%d\n",t->val);
                        break;
                }
                else if((t->ln)+1 > x)
                        t=t->l;
                else
                {
                        x-=(t->ln + 1);
                        t=t->r;
                }
        }
}
int sm=0;
void RB(int x,node *root)
{
        node *t=root;
        while(t!=NULL)
        {
                if(x==t->val)
                {
                        sm+=t->ln;
                        break;
                }
                else if(x > t->val)
                {
                        sm+=(t->ln + 1);
                        t=t->r;
                }
                else
                        t=t->l;
        }
}
void pt(node *root)
{
        if(root==NULL)
                return;
        int A=0,B=0;
        if(root->l!=NULL)
                A=root->l->val;
        if(root->r!=NULL)
                B=root->r->val;
        if(A==0 && B==0)
                return;
        printf("%d(%d)-> %d %d\n",root->val,root->ht,A,B);
        pt(root->l);
        pt(root->r);
}
int main()
{
        int X;
        node *root=NULL;
        char q[20];
        int count=0;
        //                      printf("x:%d\n",count++);
        scanf("%s",q);
        while(q[0]!='Q')
        {
                if(q[0]=='S')
                {
                        //                    printf("x:%d\n",count++);
                        scanf("%d",&X);
                        node *t=newNode(X);
                        root=addNode(root,t);
                }
                else if(q[0]=='C')
                {
                        //                  printf("x:%d\n",count++);
                        fl=0;
                        scanf("%d",&X);
                        search(root,X);
                        if(fl==1)
                        {
                                fl=0;
                                printf("YES\n");
                        }
                        else
                                printf("NO\n");
                }
                else if(q[0]=='H')
                {
                        //                printf("x:%d\n",count++);
                        scanf("%d",&X);
                        if(root == NULL ||  X > (1+ root->rn + root->ln))
                                printf("NONE\n");
                        else
                                print(X,root);
                }
                else if(q[0]=='R')
                {
                        //              printf("x:%d\n",count++);
                        sm=0;
                        scanf("%d",&X);
                        RB(X,root);
                        printf("%d\n",sm);
                }
                //                pt(root);
                scanf("%s",q);
        }
        return 0;
}
