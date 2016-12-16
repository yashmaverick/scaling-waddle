#include<stdio.h>
#include<string.h>
#include<math.h>
int start,end;

#define MAX 10000
#define MAX1 1000000
#define MAX2 1000
int len,v[MAX], sp[MAX],front=-1,rear=-1,dist[MAX],queue[MAX1],adj[MAX][MAX2],deg[MAX],visit[MAX];

void Sieve(){
    int i,j;
    for (i = 2; i < MAX; i += 2)    sp[i] = 2;
    for (i = 3; i < MAX; i += 2){
        if (!v[i]){
            sp[i] = i;
            for (j = i; (j*i) < MAX; j += 2){
                if (!v[j*i])    v[j*i] = 1, sp[j*i] = i;
            }
        }
    }
}

void push(int i){if(front==-1)front=0;queue[++rear]=i;}
 int pop (     ){return queue[front++];}
 int size(     ){return rear-front+1;};

void getadj(int start)
{
    deg[start]=0;
    if(sp[start]!=start)return;
    int k = start,pow10=1;
    while(k!=0)
    {
        int mod = k%10;
        int ll = start - mod * pow10;
        int i;
        for(i=0;i<10;i++)
        {
            int v = ll + pow10*i;
            if ( v!=start && v>1000)
                adj[start][deg[start]++]=v;       
        }

        k=k/10;
        pow10=pow10*10;
    }
}

void bfs()
{
    int i;
    for(i=1000;i<MAX;i++){
        dist[i]=MAX1;
        visit[i]=0;
    }
    push(start);
    dist[start]=0;
    while(size()!=0)
    {
        int u = pop();
        visit[u]=1;
        getadj(u);
        for(i=0;i<deg[u];i++)
        {
            int v = adj[u][i];
            if (dist[v]==MAX1)
            {
                dist[v]=dist[u]+1;
                if(v==end)
                    return;
                if(visit[v]==0)
                push(v);
            }
        }
    }
}

int main()
{
    Sieve();
    int t;
    int i;
    for(i=1000;i<10000;i++)
        getadj(i);
    scanf("%d",&t);
    while(t--)
    {
        front =-1;
        rear=-1;
        scanf("%d %d",&start,&end);
        bfs();
        if (sp[start]!=start || sp[end]!=end || dist[end]==MAX1)
        {    
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",dist[end]);
        }

    }
    return 0;
}
