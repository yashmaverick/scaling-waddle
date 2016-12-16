#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long int n,farthest,visited[1000005]={0},max_num=1,dist[1000005];
struct node
{        
        struct node* next;
        long long int adjv;
};
typedef struct node node;
node vertices[1000005];
void buttercup(long long int i)
{
        visited[i]=1;
        node* temp=vertices[i].next;
        while(temp!=NULL)
        {
                     //if(dist[temp->adjv]<dist[i]+1)
                       //        dist[temp->adjv]=dist[i]+1;
                //printf("%d ",dist[temp->adjv]);
                if(visited[temp->adjv]==0)
                {
//                        if(dist[temp->adjv]<dist[i]+1)
                                dist[temp->adjv]=dist[i]+1;
//printf("%d ",dist[temp->adjv]);
                        if(max_num<dist[temp->adjv]+1)
                        {
                                max_num++;
                                //dist[temp->adjv]=dist[i]+1;

                                farthest=temp->adjv;
                        }
  //                      printf("%d %d\n",max_num,farthest);
                        //farthest=temp->adjv;
                        buttercup(temp->adjv);
                }                        
                temp=temp->next;
        }        
}
int main()
{
        long long int i,v1,v2,w,v,u,t;
        scanf("%lld",&t);
        while(t--)
        {
                max_num=1;
                farthest=1;
                scanf("%lld",&n);
                for(i=1;i<=n;i++)
                {
                        vertices[i].next=NULL;
                        visited[i]=0;
                        dist[i]=0;
                }
                for(i=0;i<n-1;i++)
                {
                        scanf("%lld%lld",&v1,&v2);
                        node* temp=(node* )malloc(sizeof(node));    
                        temp->adjv=v2;
                        temp->next=vertices[v1].next;
                        vertices[v1].next=temp;
                        node* temp2=(node* )malloc(sizeof(node));
                        temp2->adjv=v1;
                        temp2->next=vertices[v2].next;
                        vertices[v2].next=temp2;

                } 
  /*              for(i=1;i<=n;i++)
                {
                        node* temp=vertices[i].next;
                        while(temp!=NULL)
                        {
                                printf("%d ",temp->adjv);
                                temp=temp->next;
                        }
                        printf("\n");
                        
                }
                        
                
*/
                buttercup(1);
                max_num=1;
                for(i=1;i<=n;i++)
                {
                        visited[i]=0;
                        dist[i]=0;
                }

                buttercup(farthest);
                printf("%lld\n",max_num);
        }
        return 0;
}
