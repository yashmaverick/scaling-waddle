#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
typedef struct node
{
    int val,w,c;
    struct node *l,*r;
}node;

int child(node *head)
{
    if(head==NULL)
        return 0;
    else {
        return head->c;
    }
}
void calc(node *head)
{
    head->c=child(head->l)+child(head->r)+1;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
node *newnode(int val)
{
    node*a=(node*)malloc(sizeof(node));
    a->val=val;
    a->w=1;
    a->l=NULL;
    a->r=NULL;
    a->c=1;
    return a;
}

int h(node *head)
{
    if(head==NULL)
        return 0;
    else {
        return head->w;
    }
}

void height(node *x)
{
    x->w=max(h(x->l),h(x->r))+1;
}

node* leftrot(node *z)
{
    node *y=z->r;
    node *t=y->l;
    z->r=t;
    y->l=z;
    height(z);
    height(y);
    calc(z);
    calc(y);
    return y;

}

node * rightrot(node *z)
{

    node* y=z->l;
    node* t=y->r;
    z->l=t;
    y->r=z;
    height(z);
    height(y);
    calc(z);
    calc(y);
    return y;
}
int balance(node *head)
{
    if(head==NULL)
        return 0;
    else {
        return (h(head->l)-h(head->r));
    }
}
node* insert(node *top,int val)
{
    if(top==NULL)
        return newnode(val);
     else if(top->val>val)
        top->l=insert(top->l,val);
    else
       top->r= insert(top->r,val);

    height(top);
    calc(top);
    int bal;
    bal=balance(top);
    //printf("balance at %d is %d\n",top->val,bal);
    if(bal<2&&bal>-2)
    return top;
    else
    {
        if(bal>=2)       //left cases
        {
            //left left case
            if(top->l->val>val)
            {
        //        printf("left left case\n");
                top=rightrot(top);
            }
            else        //left right case
            {
        //        printf("left right case\n");
                top->l=leftrot(top->l);
                top=rightrot(top);
            }
        }
        else if(bal<=-2)
        {
            //right right case
            if(top->r->val<=val)
            {
        //        printf("right right case\n");
                top=leftrot(top);
            }
            else
            {
        //        printf("right left case\n");
                top->r=rightrot(top->r);
                top=leftrot(top);
            }
        }
    }

    return top;
}

node *find(node *head,int x)
{
    if(head==NULL)
        return NULL;
    else if(head->val==x)
        return head;
    else if(x<head->val)
        return find(head->l,x);
    else {
        return find(head->r,x);
    }
}

int count=1;
void inorder(node *head,int n)
{
    if(head!=NULL)
    {
        if(head->val<n)
           {
               count+=child(head->l)+1;
                inorder(head->r,n);
           }
        else {
            inorder(head->l,n);
        }
    }

}
void xorder(node *head,int n)
{
    if(head==NULL)
        printf("NONE\n");
    else if(child(head->l)+1==n)
        printf("%d\n",head->val);
    else if(n>child(head->l))
    {
        xorder(head->r,n-child(head->l)-1);
    }
    else {
        xorder(head->l,n);
    }
}
void zorder(node *head)
{
    if(head!=NULL)
    {
        zorder(head->l);
        printf("%d:%d:%d ",head->val,head->w,head->c);
        zorder(head->r);
    }
}
int main()
{
    node*head=NULL;
    char s[100]="hello";
    while(s[0]!='Q')
    {
        scanf("%s",s);
        if(s[0]=='C')
        {
            int x;
            scanf("%d",&x);
            node *a=find(head,x);
            if(a==NULL)
                printf("NO\n");
            else {
                printf("YES\n");
            }

        }
        else if(s[0]=='S')
        {
            int x;
            scanf("%d",&x);
            head=insert(head,x);
        //    zorder(head);
        //    printf("\n");
        }
        if(s[0]=='H')
        {
            count=1;
            int x;
            scanf("%d",&x);
            xorder(head,x);
        }
        if(s[0]=='R')
        {
            count=0;
            int x;
            scanf("%d",&x);
            inorder(head,x);
            printf("%d\n",count);
        }



    }

    return 0;
}
