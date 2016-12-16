#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag=0;
typedef struct tr
{
        struct tr *a[10];
        int end;
        int leaf;
}tr;
tr* createNode()
{
        int i;
        tr *t=(tr*)malloc(sizeof(tr));
        for(i=0;i<10;i++)
                t->a[i]=NULL;
        t->end=0;
        t->leaf=1;
        return t;
}
tr* insert(char *no, tr *root)
{
        tr *c=root;
        int i,l=strlen(no);
        for(i=0;i<l;i++)
        {
                int x=no[i]-'0';
                if(c->a[x]==NULL)
                {
                        if(c->leaf==1)
                                c->leaf=0;
                        c->a[x]=createNode();
                }
                else
                {
                        if(  i==( l-1 ) )
                                flag=1;
                }
                if(c->end==1)
                        flag=1;
                c=c->a[x];
        }
        c->end=1;
        return root;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                tr *root=createNode();
                int k;
                scanf("%d",&k);
                while(k--)
                {
                        char a[10];
                        scanf("%s",a);
                        root=insert(a,root);
                }
                if(flag!=1)
                        printf("YES\n");
                else
                {
                        flag=0;
                        printf("NO\n");
                }
                free(root);
        }
        return 0;
}
