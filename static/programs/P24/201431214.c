#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    int v;
    struct node* left;
    struct node* right;
    int height;
    int count;
}node;
//int a[100001];
int ind=0,flag1=0,flag=0,cnt=0,f2=0;
int counter(node* l)
{
    if(l==NULL)
    {
        return 0;
    }
    else
    {
        return l->count;
    }
}
node* singlerotationwithleft(node* l)
{
    node* temp;
    int h1,h2,h3,h4;
    temp=l->left;
    l->left=temp->right;
    temp->right=l;
    if(l->left==NULL)
    {
        h2=-1;
    }
    else
    {
        h2=l->left->height;
    }
    if(l->right==NULL)
    {
        h1=-1;
    }
    else
    {
        h1=l->right->height;
    }
    if(temp->left==NULL)
    {
        h4=-1;
    }
    else
    {
        h4=temp->left->height;
    }
    if(temp->right==NULL)
    {
        h3=-1;
    }
    else
    {
        h3=temp->right->height;
    }
    l->count=counter(l->left)+counter(l->right)+1;
    temp->count=counter(temp->left)+counter(temp->right)+1;
    if(h2>h1)
    {
        l->height=h2+1;
    }
    else
    {
        l->height=h1+1;
    }
    if(h3>h4)
    {
        temp->height=h3+1;
    }
    else
    {
        temp->height=h4+1;
    }
    return temp;
}
node* singlerotationwithright(node* l)
{
    int h1,h2,h3,h4;
    node* temp;
    temp=l->right;
    l->right=temp->left;
    temp->left=l;
    if(l->left==NULL)
    {
        h2=-1;
    }
    else
    {
        h2=l->left->height;
    }
    if(l->right==NULL)
    {
        h1=-1;
    }
    else
    {
        h1=l->right->height;
    }
    if(temp->left==NULL)
    {
        h4=-1;
    }
    else
    {
        h4=temp->left->height;
    }
    if(temp->right==NULL)
    {
        h3=-1;
    }
    else
    {
        h3=temp->right->height;
    }
    l->count=counter(l->left)+counter(l->right)+1;
    temp->count=counter(temp->left)+counter(temp->right)+1;
    if(h2>h1)
    {
        l->height=h2+1;
    }
    else
    {
        l->height=h1+1;
    }
    if(h3>h4)
    {
        temp->height=h3+1;
    }
    else
    {
        temp->height=h4+1;
    }
    return temp;
}
node* insert(int num,node* t)
{
    int h1,h2,h3,h4,h5,h6;
    if(t==NULL)
    {
       // printf("num=%d\n",num);
        t=(node*)malloc(sizeof(node));
        t->v=num;
        t->left=NULL;
        t->right=NULL;
        t->height=0;
        t->count=1;
        return t;
    }
    else if(num<=t->v)
    {
        t->left=insert(num,t->left);
        if(t->left==NULL)
        {
            h1=-1;
        }
        else
        {
            h1=t->left->height;
        }
        if(t->right==NULL)
        {
            h2=-1;
        }
        else
        {
            h2=t->right->height;
        }
        if((h1-h2>=2) && num<=t->left->v)
        {
            t=singlerotationwithleft(t);
        }
        else if((h1-h2>=2) && num>t->left->v)
        {
            t->left=singlerotationwithright(t->left);
            t=singlerotationwithleft(t);
        }
    }
    else if(num>t->v)
    {
        t->right=insert(num,t->right);
        if(t->right==NULL)
        {
            h3=-1;
        }
        else
        {
            h3=t->right->height;
        }
        if(t->left==NULL)
        {
            h4=-1;
        }
        else
        {
            h4=t->left->height;
        }
        if((h3-h4>=2)&& num>t->right->v)
        {
            t=singlerotationwithright(t);
        }
        else if((h3-h4>=2) && num<=t->right->v)
        {
            t->right=singlerotationwithleft(t->right);
            t=singlerotationwithright(t);
        }
    }
    if(t->left==NULL)
    {
        h5=-1;
    }
    else
    {
        h5=t->left->height;
    }
    if(t->right==NULL)
    {
        h6=-1;
    }
    else
    {
        h6=t->right->height;
    }
    if(h5>h6)
    {
        t->height=h5+1;
    }
    else
    {
        t->height=h6+1;
    }
    t->count=counter(t->left)+counter(t->right)+1;
    return t;
}
void searchtree(node* t,int num)
{
    if((num>t->v) && (t->right!=NULL))
    {
        searchtree(t->right,num);
    }
   /* else if(num==t->v && t->right==NULL)
    {
        flag=1;
        return;
    }*/
    else if((num<t->v) && (t->left!=NULL))
    {
        searchtree(t->left,num);
    }
    else if((num==t->v) )
    {
        flag=1;
        return;
    }
}
int healthy(int k,node* t)
{
    if(t!=NULL)
    {
        if(counter(t->left)+1==k)
        {
            return t->v;
        }
        else if(k>counter(t->left))
        {
            healthy(k-counter(t->left)-1,t->right);
        }
        else 
        {
            healthy(k,t->left);
        }
    }
}
int rotten(int num,node* t)
{
    int f1,noofval=0,c1,c2,z;
    f1=2;
    c1=0,c2=0,z=0;
    //    printf("ctl=%d\n",counter(t->left));
    while(t->right!=NULL || t->left!=NULL)
    {
        if(t->v==num)
        {
            c2=c2+counter(t->left);
            z=1;
        }
        else if(t->v>num)
        {
            // printf("tl\n");
            if(t->left!=NULL)
            {
                t=t->left;
            }
            else if(t->left==NULL && t->right!=NULL)
            {
                z=1;
            }
        }
        else if(t->v<num)
        {
            c2=c2+counter(t->left)+1;
            if(t->right!=NULL)
            {
                t=t->right;
            }
            else if(t->right==NULL && t->left!=NULL)
            {
                z=1;
            }
        }
        if(z==1)
        {
            break;
        }
        if(t->right==NULL && t->left==NULL)
        {
            if(t->v<num)
            {
                c2=c2+counter(t->left)+1;
            }
            break;
        }
    }
    return c2;
}
int inorder(int num,node* l)
{
    if(l->left!=NULL && f2==0)
    {
        inorder(num,l->left);
    }
    if(l->v<num && f2==0)
    {
        cnt++;
    }
    else if(l->v>=num)
    {
        f2=1;
        return cnt;
    }
    if(l->right!=NULL && f2==0)
    {   inorder(num,l->right);}
}
int main()
{
    char s[25];
    node* tree;
    tree=NULL;
    while(1)
    {
        int x,ANS,no,yy;
        scanf("%s",s);
     if(strcmp("SetHealthy",s)==0)
        {
            scanf("%d",&x);
            tree=insert(x,tree);
        }
        else if(strcmp("CheckHealthy",s)==0)
        {
            flag=0;
            scanf("%d",&x);
            if(tree==NULL)
            {
                printf("NO\n");
            }
            else if(tree!=NULL && tree->v==x)
            {
                printf("YES\n");
            }
            else if(tree!=NULL)
            {
               // preorder(tree);
                searchtree(tree,x);
                if(flag==1)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            flag=0;
        }
        else if(strcmp("Healthy",s)==0)
        {
            flag1=0;
            scanf("%d",&x);
            if(tree==NULL ||x>tree->count||x==0)
            {
                printf("NONE\n");
            }
            else if(tree!=NULL && x<=tree->count)
            {
                ANS=healthy(x,tree);
                printf("%d\n",ANS);
            }
        }
        else if(strcmp("RottenBefore",s)==0)
        {
            flag=0;
            yy=0;
            scanf("%d",&x);
            if(tree==NULL)
            {
                printf("0\n");
            }
            else if(tree!=NULL)
            {
                if(tree->count==1)
                {
                    if(x>tree->v)
                    {
                        cnt=1;
                    }
                    else
                    {
                        cnt=0;
                    }
                    yy=1;
                }
                searchtree(tree,x);
                if(flag==1 && yy==0)
                {
                    cnt=inorder(x,tree);
                }
                else if(flag==0 && yy==0)
                {
                    cnt= rotten(x,tree);
                }
                printf("%d\n",cnt);
            }
            flag=0;
            cnt=0;
            f2=0;
        }
        else if(strcmp("Quit",s)==0)
        {
            break;
        }
    }
    return 0;
}
