#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int d;
    int m;
    int *a;
    struct linklist *next;
}node;

int M;
int w;


void print(node *v)
{
    int i;

    while(v!=NULL)
    {
        printf("%d\n",v->d);
        for(i=0;i<(v->m);i++)
        {
            printf("%d\n",(v->a)[i]);
        }
        printf("\n");
        v=v->next;
    }
}


int main()
{
    int n,i,j;
    node *head=NULL;
    scanf("%d %d",&n,&M);
    for(i=0;i<n;i++)
    {
        node *p=(node *)malloc(sizeof(node));
        w=0;
        scanf("%d",&(p->m));
        p->a=(int *)malloc((p->m)*sizeof(int));
        for(j=0;j<(p->m);j++)
        {
            scanf("%d",&((p->a)[j]));
            w=(w%M+((p->a)[j])%M)%M;
        }
        p->d=w;
        if(head==NULL)
        {
            p->next=NULL;
            head=p;
        }
        else if(head->d>w)
        {
            p->next=head;
            head=p;
        }
        else
        {
            node *q=head;
            while(q->next!=NULL && (q->next)->d<w)
            {
                q=q->next;
            }
            p->next=q->next;
            q->next=p;
        }
       // print(head);
    }
    node *v=head;
    while(v!=NULL)
    {
        printf("%d\n",v->d);
        for(i=0;i<(v->m);i++)
        {
            printf("%d\n",(v->a)[i]);
        }
        printf("\n");
        v=v->next;
    }
    return 0;
}

