#include<stdio.h>
#include<stdlib.h>
#define INF 100000000
#define min(a,b) a<b?a:b

long long int i,j,k,l;
int val[1100];
int graph[1100][110];
int size[1100];

void genprime()
{
    int a[100100],prime[100100];
    for(i=0;i<100010;i++){if(i&01)a[i]=0;else a[i]=1;}
    
    prime[0]=2;
    j=1;
    for(i=3;i<100010;i+=2)
    {
        if(a[i]==0)
        {
            prime[j]=i;
            j++;
            for(k=i*i;k<100010;k+=i)a[k]=1;
        }
    }
    k=0;
    for(i=0;i<j;i++)
    {
        if(prime[i]>999&&prime[i]<10000){val[k]=prime[i];k++;}
        
    }
    for(i=0;i<1100;i++)size[i]=0;
}

int dist(int x,int y)
{
    int cnt=0,h;
    for(h=0;h<4;h++)
    {
        if(x%10==y%10)cnt++;
        x/=10;
        y/=10;
    }
    if(cnt==3)return 1;
    return 0;
}

int find(int value)
{
    int h;
    for(h=0;h<k;h++)if(value==val[h])return h;
}

int a[100000],vis[1100],start,end;

int pop(){return a[start++];}
void push(int val){a[end++]=val;}
 
int bfs(int val, int val2)
{
    int ans=0,i;
    int f=find(val2);
    int s=find(val);
    if(val==val2)return 0;
    for(i=0;i<1100;i++){a[i]=0;vis[i]=0;}
    start=end=0;
    ans++;
    for(i=0;i<size[s];i++){if(vis[graph[s][i]]==0){push(graph[s][i]);vis[graph[s][i]]=1;if(graph[s][i]==f)return vis[f];}} 
    while(start!=end)
    {
        s=pop();
        for(i=0;i<size[s];i++)
        {
            if(vis[graph[s][i]]==0)
            {
                push(graph[s][i]);
                vis[graph[s][i]]=vis[s]+1;
                if(graph[s][i]==f)return vis[f];
            }
        }    
    }   
    return -1;
    
}

int main()
{
    genprime();
    int t,inp1,inp2,fans;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
             if(dist(val[i],val[j])==1)
             {
                graph[i][size[i]]=j;
                graph[j][size[j]]=i;
                size[i]+=1;
                size[j]+=1;
             }      
        }
    }
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&inp1,&inp2);
        fans=bfs(inp1,inp2);
        if(fans!=-1)
        printf("%d\n",fans);
        else
        printf("Impossible\n");
    }
    //for(i=0;i<10;i++){for(j=0;j<10;j++){printf("%d ",graph[i][j]);}printf("\n");}
    
    return 0;
}

