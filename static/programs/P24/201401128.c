#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int d,h,child_count;
    struct node *l,*r;
};
typedef struct node ELEMENT;
typedef ELEMENT *LINK;
LINK head;

void set_height(LINK root)
{
    int ht_l=0,ht_r=0;
    if(root->l!=NULL)
        ht_l=root->l->h;
    if(root->r!=NULL)
        ht_r=root->r->h;
    root->h=(ht_l>=ht_r)?ht_l+1:ht_r+1;
}

int unbalance(LINK root)
{
    int ht_l=0,ht_r=0;
    if(root->l!=NULL)
        ht_l=root->l->h;
    if(root->r!=NULL)
        ht_r=root->r->h;
    return ht_l-ht_r;
}

void update_count(LINK root)
{
    if(root==NULL)
        return;
    root->child_count=(root->l!=NULL?root->l->child_count:0)+(root->r!=NULL?root->r->child_count:0)+1;
}

LINK LL(LINK z)
{
    LINK y=z->l;
    LINK temp=y->r;
    y->r=z;
    z->l=temp;

    set_height(z);
    set_height(y);
    update_count(z);
    update_count(y);
    return y;
}

LINK RR(LINK z)
{
    LINK y=z->r;
    LINK temp=y->l;
    y->l=z;
    z->r=temp;

    set_height(z);
    set_height(y);
    update_count(z);
    update_count(y);
    return y;
}

LINK LR(LINK z)
{
    z->l=RR(z->l);
    return LL(z);
}

LINK RL(LINK z)
{
    z->r=LL(z->r);
    return RR(z);
}


LINK balance(LINK z)
{
     int bf_z;     //balance factor
     bf_z=unbalance(z);
     
     if(bf_z==2)
     {
         if(unbalance(z->l)==1)
             return LL(z);
         else
             return LR(z);
     }
     else
     {
         if(unbalance(z->r)==1)
             return RL(z);
         else
             return RR(z);
     }

}   

LINK insert(LINK root,int x)
{
    if(root==NULL)
    {
        LINK temp;
        temp=(LINK)malloc(sizeof(ELEMENT));
        temp->d=x;
        temp->h=1;
        temp->child_count=1;
        temp->l=temp->r=NULL; 
        return temp;
    }   

    if(x>=root->d)
    {
        root->r=insert(root->r,x);
        root->child_count++;
        set_height(root);
        if(unbalance(root)==2 || unbalance(root)==-2)
            root=balance(root);
    }
    else
    {
        root->l=insert(root->l,x);
        root->child_count++;
        set_height(root);
        if(unbalance(root)==2 || unbalance(root)==-2)
            root=balance(root);
    }
    return root;
}

int children(LINK root)
{
    if(root==NULL)
        return 0;
    else
        return root->child_count;
}

int Healthy(LINK root,int x,int prev)
{
    if(root==NULL || root->child_count<x-prev)
        return -1;
    if(children(root->l)==x-1-prev)
        return root->d;
    else if(children(root->l)>x-1-prev)
        return Healthy(root->l,x,prev);
    else return Healthy(root->r,x,prev+children(root->l)+1);
}

int check(LINK root,int x)
{
    if(root==NULL)
        return 0;
    if(x>root->d)
        return check(root->r,x);
    else if(x<root->d)
        return check(root->l,x);
    else
        return 1;
}

int count_lt(LINK root,int x,int ans)       //counts number of nodes less than x
{   
    if(root==NULL)
        return ans;
    if(root->d==x)
        return ans+children(root->l);
    else if(root->d>x)
        return count_lt(root->l,x,ans);
    else if(root->d<x)
        return count_lt(root->r,x,ans+children(root->l)+1);
}

/*void in(LINK root)
{
    if(root==NULL)
        return;
    in(root->l);
    printf("%d %d\n",root->d,root->child_count);
    in(root->r);
}
*/
int main()
{
    head=NULL;
    char cmd[15];
    int x,temp;
    while(1)
    {
        scanf("%s",cmd);
        if(cmd[0]=='Q')
            return 0;
        else
        {
            scanf("%d",&x);
            getchar();
        }

        switch(cmd[0])
        {
            case 'C':
                    if(check(head,x))
                         printf("YES\n");
                     else
                         printf("NO\n");
                     break;
            case 'S':
                     if(head!=NULL)
                         head->child_count++;
                     head=insert(head,x);break;
  //                   printf("printing tree\n");in(head);break;
            case 'H':
                     if((temp=Healthy(head,x,0))!=-1)
                         printf("%d\n",temp);
                     else
                         printf("NONE\n");
                     break;
            case 'R':
                     printf("%d\n",count_lt(head,x,0));
                     break;
        }

    }

return 0;
}
