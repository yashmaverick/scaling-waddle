#include<stdio.h>
#include<stdlib.h>
int t,n,i,j;
int a,b;
int maxlevel=0;
int final=0;
typedef struct node
{
        int data;
        struct node* next;
}node;
node *head;
int visited[1000001];
void dfs(int v, int level)
{
        if(visited[v]==1)
              return;
        if (maxlevel < level)
        {       
                maxlevel=level;
                final=v;
        }
               
        node *z=&head[v];
         visited[v]=1;
        z=z->next;
        while(z!=NULL)
        { //      printf("z->data=%d ",z->data);
                if(visited[z->data]!=1)
                {
                        //visited[v]=1;
                        dfs(z->data,level+1);          
                }
                z=z->next;
        }
         
}
int main()
{
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                maxlevel=0;
                final=0;
               
                scanf("%d",&n);
                //visited=(int *)malloc(sizeof(int)*(n+1));
                head=malloc(sizeof(node)*(n+1));
                for(j=0;j<=n;j++)
                        visited[j]=0;
                for(j=1;j<=n;j++)
                        head[j].data=j;
                for(j=1;j<=n-1;j++)
                {
                        scanf("%d%d",&a,&b);
                        {
                                node *p=&head[a];
                                node *q=&head[b];
                                while(p->next!=NULL)
                                        p=p->next;
                                node *m=malloc(sizeof(node));
                                m->data=b;
                                p->next=m;

                                while(q->next!=NULL)
                                        q=q->next;
                                node *l=malloc(sizeof(node));
                                l->data=a;
                                q->next=l;
                        }
                }
                /*for(j=1;j<=n;j++)
                  {
                  node *k=&head[j];
                  k=k->next;
                  while(k->next!=NULL)
                  {
                  printf("%d ",k->data);
                  k=k->next;
                  }

                  printf("%d\n",k->data);
                  }*/
                for(j=1;j<=n;j++)
                        visited[j]=0;
                dfs(a,0);
                //printf("%d\n",maxlevel);
                maxlevel=0;
                // printf("%d",final);
                for(j=1;j<=n;j++)
                        visited[j]=0;
                dfs(final,0);
                printf("%d\n",maxlevel+1);
        }
        return 0;
}




