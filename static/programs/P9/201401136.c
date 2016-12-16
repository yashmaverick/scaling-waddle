#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    int sum;
    int *arr;
    struct node *next;
}node;
void print(node *t)
{
    while(t!=NULL)
    {
        int j;
        printf("%d\n",t->sum);
        for(j=0;j<t->num;j++)
        {
            printf("%d\n",t->arr[j]);
        }
        printf("\n");
        t=t->next;
    }
}
int main()
{
    int n;
    int mod;
    scanf("%d%d",&n,&mod);
    int i,m;
    node *p;
    node *q;
    p=NULL;
    for(i=0;i<n;i++)
    {
        int j;
        if(p==NULL)
        {
            p=(node *)malloc(sizeof(node));
            scanf("%d",&p->num);
            p->next=NULL;
            p->sum=0;
            p->arr=(int *)malloc((p->num)*sizeof(int));
            for(j=0;j<p->num;j++)
            {
                scanf("%d",&p->arr[j]);
                p->sum=((p->sum%mod)+(p->arr[j]%mod))%mod;
            }
        }
        else
        {

            node *q;
            q=(node *)malloc(sizeof(node));
            scanf("%d",&q->num);
            q->next=NULL;
            q->sum=0;
            q->arr=(int *)malloc((q->num)*sizeof(int));
            for(j=0;j<q->num;j++)
            {
                scanf("%d",&q->arr[j]);
                q->sum=((q->sum%mod)+(q->arr[j]%mod))%mod;
            }
            node *temp;
            temp=p;
            if(temp->sum>q->sum)
            {
                q->next=temp;
                p=q;
            }
            else
            {
            while(temp->next!=NULL&&temp->next->sum<q->sum)
                temp=temp->next;
            q->next=temp->next;
            temp->next=q;
            }
        }
    }
    node *t;
    t=p;
    print(t);
    /* node *a;
       node *previous;
       node *successor;
       while(t!=NULL)
       {
       a=p;
       while(a->next!=NULL)
       {
       if(a->sum>a->next->sum)
       {
       if(a==p)
       {
       node *temp2;
       temp2=a->next->next;
       a->next->next=a;
       a->next=temp2;
       p=a;
       }
       else
       {
       previous->next=a->next;
       a->next=a->next->next;
       previous->next->next=a;
       }    
       }
       previous=a;
       a=a->next;
       printf("a->next is %d\n",a->sum);
       print(p);
       }
       t=t->next;
       }*/
    return 0;
}
