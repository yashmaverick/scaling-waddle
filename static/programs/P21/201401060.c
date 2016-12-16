#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

    int val;
    int weight;
    struct node * next;
}node;
int end=1;
int visited[100005]={0};
int posarray[100005]={0};
int distarray[2][100005];
//memset(posarray,0,sizeof(posarray));
//memset(distarray,-1,sizeof(distarray));
int s,t;
int start=1;
void dfs(int index,node *in , node * out,int * queue)
{
    if (start==end+1 || distarray[1][start]==t)
        return ;
    if (index==0)
    {
        index++;
        end++;
        posarray[s]=index;
        distarray[0][index]=0;
        distarray[1][index]=s;
        visited[s]=1;
        queue[index]=s;
    }
    node *temp=out[distarray[1][start]].next;
    int parent=index;

    while(temp!=NULL)
    {
        int a=temp->val;
      //  printf(" a-> %d visited -> %d \n",a,visited[a]);
        //int a=temp->val;
        //if(visited[a]!=1)
        //{
        //visited[a]=1;
        int d=distarray[0][parent]+temp->weight;
        //if(distarray[0][posarray[a]]>d || distarray[0][posarray[a]]==-1)
        //{
        if(visited[a]!=1)
        {
            visited[a]=1;
            distarray[0][end]=d;
            distarray[1][end]=a;
            posarray[a]=end;
            end++;
        }
        else
        {
            if(distarray[0][posarray[a]]>d)
            {
        //        printf("entred else if %d %d ",distarray[0][posarray[a]],d);
                distarray[0][posarray[a]]=d;
            }
        }
        
        int pos1=posarray[a];
        int pos2=(pos1+index)/2;
        while(distarray[0][pos2]>distarray[0][pos1] && pos2>0)
        {
            int t=posarray[distarray[1][pos1]];
            posarray[distarray[1][pos1]]=posarray[distarray[1][pos2]];
            posarray[distarray[1][pos2]]=t;
            t=distarray[0][pos1];
            distarray[0][pos1]=distarray[0][pos2];
            distarray[0][pos2]=t;
            t=distarray[1][pos1];
            distarray[1][pos1]=distarray[1][pos2];
            distarray[1][pos2]=t;


            pos1=pos2;
            pos2=(pos1+index)/2;
        }
    
    
    temp=temp->next;
    }
    start++;
    dfs(index+1,in,out,queue);


}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    node * in =(node *)malloc(sizeof(node)*(n+1));
    node * out=(node *)malloc(sizeof(node)*(n+1));
    for(i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        node * temp=(node*)malloc(sizeof(node));
        temp->val=v;
        //    temp->exp=0
        temp->weight=w;
        temp->next=out[u].next;
        out[u].next=temp;
        node * t=(node*)malloc(sizeof(node));
        t->val=u;
        //  t->exp=0;
        t->weight=w;
        t->next=in[v].next;
        in[v].next=temp;
    }
    /*for(i=1;i<=m;i++)
    {
        printf("\n%d - > ",i);
        node *t=(node *)malloc(sizeof(node));
        t=out[i].next;
        while(t!=NULL)
        {
            printf("%d ",t->val);
            t=t->next;
        }
    }*/




    int * queue=(int *)malloc(sizeof(int)*(n+1));

    scanf("%d%d",&s,&t);
    for(i=1;i<=n;i++)
        distarray[0][i]=-1;
    dfs(0,in,out,queue);
    int flag=1;
    if(visited[t]==0)
        printf("NO\n");
    else
        printf("%d\n",distarray[0][posarray[t]]);



    return 0;
}
