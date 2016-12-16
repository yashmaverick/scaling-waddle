#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
        int m;
        int *item;
        int sum;
        struct bag * next;
}bag;
void print(bag * head,int n)
{
        bag *t=head;
        int i,j;
        for(j=0;j<n;j++)
        {
                printf("%d\n",(t->sum));
                for(i=0;i<(t->m);i++)
                        printf("%d\n",(t->item[i]));
                printf("\n");
                t=t->next;
        }
}
int main()
{
        int n,m,i=0,j=0,mod,x;
        scanf("%d %d",&n,&mod);
        bag *head;
        for(i=0;i<n;i++)
        {
                bag *b=(bag *)malloc(sizeof(bag));
                b->sum=0;
                b->next=NULL;
                scanf("%d",&x);
                b->m=x;
                b->item=(int *)malloc(sizeof(int)*(b->m));
                for(j=0 ; j < (b->m) ; j++)
                {
                        scanf("%d",&x);
                        (b->item[j])=x;
                        (b->sum)+=(b->item[j]);
                        (b->sum)%=mod;
                }
                if(i==0)
                        head=b;
                else if(i==1)
                {
                        if((b->sum) >= (head->sum))
                                head->next=b;
                        else
                        {
                                (b->next)=head;
                                head=b;
                        }
                }
                else
                {
                        bag *t=head,*tt=(head->next);
                        while(1)
                        {
                                if((tt) == NULL)
                                {
                                        t->next=b;
                                        break;
                                }
                                else if(((tt->sum) > (b->sum)) && ((t->sum) <= (b->sum)))
                                {
                                        (t->next)=b;
                                        (b->next)=tt;
                                        break;
                                }
                                else if((head->sum) > (b->sum))
                                {
                                        b->next=head;
                                        head=b;
                                        break;
                                }
                                else
                                {
                                        t=tt;
                                        tt=(tt->next);
                                }
                        }
                }
        }
        print(head,n);
        return 0;
}
