#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;

    struct node *next;
}node;
int visited[1000002]={0};
node * head;
node ver[1000002];
int dfs(int * queue,int index,int max)
{
    if (index==-1)
    {
        index++;
        queue[index]=head->val;
        visited[1]=head->val;
    }
    int k;
    //printf("hey\n");
    //printf("%d\n",ver[queue[index]].val);
    node * temp=ver[queue[index]].next;
    while(temp!=NULL)
    {
        int a=temp->val;
        if(visited[a]!=1)
        {
            visited[a]=1;
            queue[index+1]=a;
            if(index+2>max)
            {
                max=index+2;
                head=temp;
            }
            max=dfs(queue,index+1,max);
        }
        temp=temp->next;


    }
    if(temp==NULL)
        return max ;




}


int main()
{
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        

        int n;
        ver[1].val=1;
        scanf("%d",&n);
        // node * ver=(node *)malloc(sizeof(node)*(n+1));

        int j;
        for(j=1;j<=n;j++)
        {
            ver[j].next=NULL;

        }
        for(j=1;j<=n;j++)
            visited[j]=0;
        for(j=0;j<n-1;j++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            node * temp=(node *)malloc(sizeof(node));
            temp->val=v;
            temp->next=ver[u].next;
            ver[u].next=temp;

            node * t=(node *)malloc(sizeof(node));
            t->val=u;
            t->next=ver[v].next;
            ver[v].next=t;
        }

        int * queue=(int *)malloc(sizeof(int)*(n+1));
        head=&ver[1];
      //  printf("%d %d\n",head->val,ver[1].val);
        if(n==1)
            printf("1\n");
        else
        {
        //    printf("i entered else\n");
            int dist=dfs(queue,-1,0);
          //  printf("%d %d\n",dist,head->val);

            int * queue2=(int*)malloc(sizeof(int)*(n+1));
            int q;
            for(q=1;q<=n;q++)
            {
                visited[q]=0;
            }


            dist=dfs(queue2,-1,0);
            
            printf("%d\n",dist);


            /*for(j=1;j<=n;j++)
              {
              printf("%d -> ",j);
              node * temp=ver[j].next;
              while(temp!=NULL)
              {
              printf("%d ",temp->val);
              temp=temp->next;
              }
              printf("\n");
              }*/
        }
    }


    return 0;
}

