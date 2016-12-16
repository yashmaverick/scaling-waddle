#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define f(x) scanf("%d",&x)
#define s(s) scanf("%s",s)
typedef struct tree
{
    int make;
    struct tree *next[10];
}tree;
int def=0;
tree *insert(tree *head,char s[],int ind,int key)
{//printf("hhhd\n");
    tree *r,*p,*q;
    q=head;
    int i=0;
    for(i=0;i<ind;i++)
    {
        q=q->next[s[i]-48];
        if(q->make==-1)
            def=1;
    }
    if(q->next[s[i]-48]!=NULL)
    {
        if(q->make==-1 || key==-1)
        def=1;
    }
    else
    {//printf("%d\n",ind);
        p=malloc(sizeof(tree));
        p->make=key;
        for(i=0;i<10;i++)
            p->next[i]=NULL;
        q->next[s[ind]-48]=p;
    }
    return head;
}
int main()
{
    int i,k,l,j,t,n,b;
    f(t);
    char x[10];
    for(i=0;i<t;i++)
    {f(n);
        def=0;
        tree *h,*m;
        h=malloc(sizeof(tree));
        h->make=1;
        for(k=0;k<10;k++)
            h->next[k]=NULL;
        for(b=0;b<n;b++)
        {s(x);
            // printf("hdhdd\n")
            for(k=0;(k<(strlen(x)-1) && def==0);k++)
                h=insert(h,x,k,2);
            if(def!=1)
                h=insert(h,x,k,-1);
            m=h;
        }
        if(def==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
