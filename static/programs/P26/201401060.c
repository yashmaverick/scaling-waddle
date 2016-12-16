#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    int dist;
    struct node * next;
}node;
int array[1002]={0};
int visited[10002]={0};
int prime[10002]={0};
int flag=-1;
int prime2[2000];
int position=0;
int start=-1;
int insert=0;
void bfs(int u,int v,node * ver)
{
    if(start==insert || array[start]==v)
        return;
    if(start==-1)
    {
        start++;
        array[start]=u;
        //start++;
        insert++;
        visited[u]=1;
        ver[u].dist=0;
    }
    node *temp=ver[array[start]].next;
    while(temp!=NULL)
    {
        int a=temp->val;
        if(visited[a]!=1)
        {
            visited[a]=1;
            ver[a].dist=ver[array[start]].dist+1;
            array[insert]=a;
            insert++;
        }
        if(a==v)
            return;
        temp=temp->next;
    }
    start++;
    bfs(u,v,ver);
}





int main()
{
    int t;
    scanf("%d",&t);
    int k=0;
    prime[0]=-1;
    prime[1]=-1;
    prime[2]=0;
    int c=0;
    int i,j;
    for (i=2;i<=10000;i++)
    {
        if(prime[i]==0)
        {
            prime2[position]=i;
            position++;
            for(j=2*i;j<=10000;j+=i)
                prime[j]=1;
        }
    }
    /*for(i=1000;i<10000;i++)
      {
      if(prime[i]==0)
      printf("%d\n",i);
      }*/
    //  printf("i am here 2\n");
    node *ver=(node*)malloc(sizeof(node)*10002);
    for(i=0;i<10002;i++)
        ver[i].next=NULL;
    int count=0;
    //printf("i am here 3\n");
    for(i=1000;i<10000;i++)
    {

        if(prime[i]==0)
        {
            for(j=i+1;j<10000;j++)
            {
                count =0;
                if(prime[j]==0)
                {
                    if(j%10==i%10)
                        count++;

                    if((j%100)/10==(i%100)/10)
                        count++;

                    if((j%1000)/100==(i%1000)/100)
                        count++;


                    if((j%10000)/1000==(i%10000)/1000)
                        count++;

                    if(count+1==4)
                    {
                        //              printf("i am here 4\n");
                        node *temp=(node *)malloc(sizeof(node));
                        temp->next=ver[i].next;
                        temp->val=j;
                        temp->dist=-1;
                        ver[i].dist=-1;
                        ver[i].next=temp;
                        node *t=(node*)malloc(sizeof(node));
                        t->next=ver[j].next;
                        t->dist=-1;
                        t->val=i;
                        ver[j].dist=-1;
                        ver[j].next=t;
                        //            printf("i am here 5\n");
                    }
                }
            }
        }
    }
   /* for(i=1000;i<10000;i++)
    {
        if(prime[i]==0)
        {
            printf("%d -> ",i);
            node * temp=ver[i].next;
            while(temp!=NULL)
            {
                printf("%d ",temp->val);
                temp=temp->next;
            }
            printf("\n");
        }
    }
    */



    for(k=0;k<t;k++)
    {
        flag=-1;
        start=-1;
        insert=0;
        for(i=0;i<10000;i++)
        {
            array[i]=0;
            visited[i]=0;
            ver[i].dist=-1;
        }

        int u,v;
        scanf("%d%d",&u,&v);
        if(u==v)
        {
            printf("0\n");
            continue;
        }
        //dfs(u,v,ver,-1);
       // array[0]=u;
        //int start=0;
        //visited[u]=1;
        //int front=0;
        bfs(u,v,ver);
                      
            

        if(ver[v].dist!=-1)
            printf("%d\n",ver[v].dist);
        else
            printf("Impossible\n");
    }





    return 0;
}


