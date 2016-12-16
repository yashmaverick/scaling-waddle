#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;

    struct node *next;
}node;
int visited[1002]={0};
node * head;
int count =0;
node ver1[1002];
node ver2[1002];
int dfs(int * queue,int index,node ver[])
{
    if (index==-1)
    {
        index++;
        queue[index]=head->val;
        visited[head->val]=1;
    }
    int k;
    node * temp=ver[queue[index]].next;
    while(temp!=NULL)
    {
        int a=temp->val;
        if(visited[a]!=1)
        {
            visited[a]=1;
            queue[index+1]=a;
            count++;
            dfs(queue,index+1,ver);
        }
        temp=temp->next;
    }
    if(temp==NULL)
        return;
}


int main()
{
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {


        int n;
        ver1[1].val=1;
        ver2[1].val=1;
        scanf("%d",&n);
        int j;
        for(j=1;j<=n;j++)
        {
            ver1[j].next=NULL;
            ver2[j].next=NULL;

        }
        for(j=1;j<=n;j++)
            visited[j]=0;
        for(j=1;j<=n;j++)
        {
            int no;
            scanf("%d",&no);
            int u;
            int v;
            for(v=0;v<no;v++)
            {
            scanf("%d",&u);
            node * temp=(node *)malloc(sizeof(node));
            temp->val=j;
            temp->next=ver1[u].next;
            ver1[u].next=temp;

            node * t=(node *)malloc(sizeof(node));
            t->val=u;
            t->next=ver2[j].next;
            ver2[j].next=t;
            }
        }

        int * queue=(int *)malloc(sizeof(int)*(n+1));
        head=&ver1[1];
        if(n==1)
            printf("1\n");
        else
        {
            int z;
            int flag=0;
            for(z=1;z<=n;z++)
            {
                ver1[z].val=z;
                head=&ver1[z];
                count=0;
                dfs(queue,-1,ver1);
                if(count==n-1)
                {
                    flag=1;
                    break;
                }

                int q;
                for(q=1;q<=n;q++)
                {
                    visited[q]=0;
                }
            }
            int q;
            for(q=1;q<=n;q++)
                visited[q]=0;
        
            if(flag==1)
            {
                ver2[z].val=z;
                head=&ver2[z];
                count=1;
                dfs(queue,-1,ver2);


                printf("%d\n",count);
            }
            else
                printf("0\n");
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

