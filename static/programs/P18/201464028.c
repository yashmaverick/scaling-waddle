#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define f(x) scanf("%d",&x)
typedef struct node
{
    int d;
    struct node *next;
}node;
node **head1,**head2;
int val,*visit;
node *insert(node *r,int p)
{
    if(r==NULL)
    {
        node *q;
        q=(node *)malloc(sizeof(node));
        q->d=p;
        q->next=NULL;
        r=q;
    }
    else
    {
        node *q;
        q=(node *)malloc(sizeof(node));
        q->d=p;
        q->next=r;
        r=q;
    }
    return r;
}
void dfs(int current)
{
//    if(visit[current]==1)
  //      return;
    visit[current]=1;
    node *q;
    val++;
    q=head1[current];
    while(q!=NULL)
    {
        if(visit[q->d]==0)
            dfs(q->d);
        q=q->next;
    }
}
void dfs2(int current)
{
    //if(visit[current]==1)
      //  return ;
    visit[current]=1;
    node *q;
    val++;
    //    printf("inc value for current=%d\n",current);
    q=head2[current];
    while(q!=NULL)
    {
        //      printf("entering while\n");
        if(visit[q->d]==0)
            dfs2(q->d);
        q=q->next;
    }
}
int main()
{
    int i,j,k,l,ty,n,a,b,t;
    scanf("%d",&ty);
    for(i=0;i<ty;i++)
    {
        f(n);
        head1=(node **)malloc(sizeof(node *)*(n+1));
        head2=(node **)malloc(sizeof(node *)*(n+1));
        visit=malloc(sizeof(int)*(n+1));
        for(k=1;k<=n;k++)
        {
            head1[k]=NULL;
            head2[k]=NULL;
            visit[k]=0;
        }
        for(t=1;t<=n;t++)
        {
            f(a);
            for(l=1;l<=a;l++)
            {
                f(b);
                head2[t]=insert(head2[t],b);
                head1[b]=insert(head1[b],t);
            }
        }
        for(l=1;l<=n;l++)
        {
            val=0;
            for(k=1;k<=n;k++){
                visit[k]=0;}
                 dfs(l);

            for(a=1;a<=n;a++)
            {//printf("%d: %d",l,visit[k]);
               if(visit[a]==0)
                    break;
            }
           // printf("\n");
            if(a>n)
                break;
        }
        for(k=1;k<=n;k++)
            visit[k]=0;
        val=0;
       //printf("%d ",l);
        dfs2(l);
        val=0;
        for(k=1;k<=n;k++)
        {if(visit[k]==1)
            val++;
        }

        printf("%d\n",val);
        //   free(head1);
        // free(head2);
     //   free(visit);
    }
    return 0;
}
