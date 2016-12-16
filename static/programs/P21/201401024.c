#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100005
#define INF 100000000
typedef struct node
{
    struct node *next;
    int val;
    int w;
}node;
node *arr[MAX];
node *insert(node *root,int a,int b)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->val=a;
    temp->w=b;
    temp->next=root;
    return temp;
}
int size=-1;
int d[MAX];
int visited[MAX];
typedef struct pyque
{
    int val;
    int ind;
}pyque;
pyque a[MAX];
int back[MAX];
void swap(pyque *a,pyque *b)
{
    pyque temp=*a;
    *a=*b;
    *b=temp;
}
int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
void correct1(int n)
{
    if((n-1)/2>=0 && a[(n-1)/2].val>a[n].val)
    {
        back[a[n].ind]=(n-1)/2;
        back[a[(n-1)/2].ind]=n;
        swap(&a[n],&a[(n-1)/2]);
        correct1((n-1)/2);
    }
}
void correct2(int n)
{
    if(2*n+1>size)return;
    int x=2*n+1;
    if(a[x].val>a[2*n+2].val)
        x=2*n+2;
    if(a[x].val<a[n].val)
    {
        back[a[n].ind]=x;
        back[a[x].ind]=n;
        swap(&a[n],&a[x]);
        correct2(x);
    }
}
void heapinsert(int x,int y)
{
    size++;
    back[a[size].ind]=size;
    a[size].ind=x;
    a[size].val=y;
    correct1(size);
}
void heapupdate(int x,int y)
{
    int h=back[x];
    a[h].val=y;
    a[h].ind=x;
    correct1(h);
    correct2(h);
}
pyque getmin()
{
    pyque x=a[0];
    a[0]=a[size];
    size--;
    correct2(0);
    return x;
}
void dijkstra(int a){
    int i;
    for(i=0;i<MAX;i++)
        visited[i]=0;
    for(i=0;i<MAX;i++)
        d[i]=INF;
    d[a]=0;
    heapinsert(a,d[a]);
    while(size!=-1){
        pyque pp=getmin();
        int p=pp.ind;
        visited[p]=2;
        node *temp=arr[p];
        while(temp!=NULL){
            d[temp->val]=min(d[temp->val],d[p]+temp->w);
            if(visited[temp->val]==0){
                visited[temp->val]=1;
                heapinsert(temp->val,d[temp->val]);
            }
            else if(visited[temp->val]==1) 
                heapupdate(temp->val,d[temp->val]);
            temp=temp->next;
        }
    }
}
int main(){
    int n,m,u,v,i,w;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        arr[u]=insert(arr[u],v,w);
//        arr[v]=insert(arr[v],u,w);
    }
	int s,t;
	scanf("%d%d",&s,&t);    
	dijkstra(s);
    if(d[t]==INF)printf("NO\n");
    else printf("%d\n",d[t]);
    return 0;
}
