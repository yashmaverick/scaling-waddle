#include<stdio.h>
#include<stdlib.h>
typedef struct heap
{
    int src;
    int des;
    int we;
}heap;
heap* array[1000001];
heap* q[1000001];
int top=0;
int parent[100001];
int rank[100001];
void insertheap(int n1,int n2,int n3)
{
    int j;
    heap* temp;
    heap* temp1;
    temp=(heap*)malloc(sizeof(heap));
    temp->src=n1;
    temp->des=n2;
    temp->we=n3;
    if(top==0)
    {
        top++;
        q[top]=temp;
    }
    else
    {
        top++;
        q[top]=temp;
        for(j=top;(j/2!=0 && (q[j]->we)<(q[j/2]->we));j=j/2)
        {
            temp1=q[j];
            q[j]=q[j/2];
            q[j/2]=temp1;
        }
    }
}
void deletemin()
{
    int i;
    heap* temp;
    q[1]=q[top];
    top--;
    int flag=0;
    i=1;
    while((2*i<=top && q[i]->we > q[2*i]->we ) || (2*i+1<=top && q[i]->we > q[2*i+1]->we)){
        if(q[2*i+1]->we < q[2*i]->we && 2*i+1<=top){
          //  te=hash[q[i]->src];
           // hash[q[i]->src]=hash[q[2*i+1]->src];
           // hash[q[2*i+1]->src]=te;
            temp=q[(2*i)+1];
            q[(2*i)+1]=q[i];
            q[i]=temp;
            i=(2*i)+1;
        }
        else{
           // te=hash[q[i]->src];
           // hash[q[i]->src]=hash[q[2*i]->src];
           // hash[q[2*i]->src]=te;
            temp=q[(2*i)];
            q[(2*i)]=q[i];
            q[i]=temp;
            i=(2*i);
        }
    }
    return ;
}
int uni(int x,int y)
{
	int px,py,p,q;
	p=parent[x];
        q=parent[y];
        while(p!=parent[p])
        {
            p=parent[p];
        }
        while(q!=parent[q])
        {
            q=parent[q];
        }
        px=p;
        py=q;
      //  printf("before ra[px]=%d ra[py]=%d\n",rank[px],rank[py]);
       // printf("px=%d py=%d\n",px,py);
        if(px==py)
        {
            return 0;
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
       //     printf("parent\n");
        }
        else if(rank[px]==rank[py])
        {
            parent[py]=px;
            rank[px]=rank[px]+1;
        }
       // printf("parent[px]=%d parent[py]=%d\n",parent[px],parent[py]);
       // printf("rank[px]=%d rank[py]=%d\n",rank[px],rank[py]);
return 1;
}
int main()
{
    int n,m,x,y,w,i,c;
    long long int ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
       // insert(x,y,w);
       // insert(y,x,w);
        if(y>x)
        {
            insertheap(x,y,w);
        }
        else if(x>y)
        {
            insertheap(y,x,w);
        }
    }
    for(i=0;(top!=0 && i<m);i++)
    {
        //   printf("we=%d\n",q[1]->we);
        array[i]=q[1];
        deletemin();
    }
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
   int  nodes=n;
    ans=0;
    for(i=0;i<m && nodes>1;i++)
    {
        if(uni(array[i]->src,array[i]->des)==1)
        {
           // printf("a[i]->src=%d\n",array[i]->src);
            nodes--;
            ans=ans+array[i]->we;
        }
    }
    if(nodes>1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%lld\n",ans);
    }
	    return 0;
}
