#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define INF 1000000000

int heap[100000],nod[100000],pos[100000],hsize=0;

//memset(pos,0,(sizeof(int)*1000));
void swap(int i,int j)
{
   // printf("swapping %d and %d \n",heap[i],heap[j]);
    int temp1=heap[i];
    int temp2=nod[i];
    int temp3=pos[nod[i]];
    heap[i]=heap[j];
    nod[i]=nod[j];
    heap[j]=temp1;
    nod[j]=temp2;
    pos[nod[i]]=i;
    pos[nod[j]]=j;

}

void push(int  b,int  a)
{
   // printf("in push\n");
    hsize++;
    heap[hsize]=a;
    nod[hsize]=b;
    pos[b]=hsize;
//    printf("%d and %d\n",b,a);
//    printf("at %d\n",hsize);
    int temp=hsize;
    while(a<heap[temp/2]&&temp/2>0)
    {
        swap(temp,temp/2);
        temp=temp/2;
    }
}

int  pop()
{
   // printf("in pop\n");
    swap(1,hsize);
    pos[nod[hsize]]=0;
    hsize--;
    int child;
    int  ind=1;
    while(ind*2<=hsize)
    {
        child=ind*2;
        if(child+1<=hsize)
        {
            if(heap[child+1]<heap[child])
                child++;

        }
        if(heap[ind]>heap[child])
        {
            swap(ind,child);
            ind=child;
        }
        else {
            break;
        }

    }
    return nod[hsize+1];
}
void heapify(int x)
{
   // printf("in heapify\n");
    int a=heap[x];
    int temp=x;
    while(a<heap[temp/2]&&temp/2>0)
    {
        swap(temp,temp/2);
        temp=temp/2;
    }
}

void print()
{
    int i;
    for(i=1;i<=hsize;i++)
    {
        printf("node:%d val:%d pos:%d\n",nod[i],heap[i],pos[nod[i]]);
    }
}

int dis[100000];
int vis[100000];
unsigned long long int w=0;
int count=0;
typedef struct node
{
    int  val,w;
    struct node*next;

}node;

node * newnode(int  s,int  w)
{
    node *a=(node*)malloc(sizeof(node));
    a->val=s;
    a->next=NULL;
    a->w=w;
    return a;
}
void disc(node **,int );
void djk(node *a[],int  src)
{
    dis[src]=0;
    push(src,0);
    while(hsize)
    {
        int  y=pop();
        if(!vis[y])
        {
            w+=dis[y];
            vis[y]=1;
            count++;
        }
        disc(a,y);
    }
}

void printpos(int x)
    {
        printf("%d\n",pos[x]);

    }
void disc(node *a[],int  x)
{
    //printf("discovering for node %lld\n",x);
    node *head=a[x];
    while(head->next!=NULL)
    {
        head=head->next;
    //    printf("%d+%d and %d\n",dis[x],head->w,dis[head->val]);
        if(head->w < dis[head->val])
        {
            dis[head->val]=head->w;
           // printpos(x);
            if(pos[head->val]>0)
            {
                heap[pos[head->val]]=dis[head->val];
                //printf("updating for %lld heap pos %lld and new value is%lld\n ",head->val,pos[head->val],heap[pos[head->val]]);
            //    print();
                heapify(pos[head->val]);
            //    print();
            }
            else
                push(head->val,dis[head->val]);
        }

    }
}

void insert(node *a[],int  x,int y,int  w)
{
    node*head=a[x];
    node *old=head->next;
    head->next=newnode(y,w);
    head->next->next=old;
}

void printdis(int  n)
{
    int  i;
    for(i=1;i<=n;i++)
    {
        if(dis[i]!=INF)
        printf("%lld:%lld\n",i,dis[i]);
    }
    printf("\n");
}

void printnode(int  n,node*a[])
{
 //   printf("in print fx with n= %d\n",n);
    int  i;
    for(i=1;i<=n;i++)
    {
        node *head=a[i];
        printf(" %lld-> ",head->val);
        while(head->next!=NULL)
        {
            head=head->next;
            printf("%lld:%lld ",head->val,head->w);
        }
        printf("\n");
    }
}

int main()
{
   // int t;
     // scanf("%d",&t);
      //  while(t--)
        {

            heap[0]=-1000000000;
            hsize=0;
            int n;
            scanf("%d",&n);
            int temp=n;
            node*a[n+1];
            int i;
            for(i=1;i<=n;i++)
            {
                a[i]=newnode(i,INF);
            }
      //      printnode(n,a);
            int e;
            scanf("%d",&e);
            while(e--)
            {
                n=temp;
          //      printf("in print fx with n= %d\n",n);
                int  x,y,w;
                scanf("%d%d%d",&x,&y,&w);
                insert(a,x,y,w);
                insert(a,y,x,w);
                //    printnode(n,a);
            }
    //        printnode(n,a);
            w=0;
            for(i=0;i<=n;i++)
            {  dis[i]=INF;
                pos[i]=0;
                vis[i]=0;
            }
            djk(a,1);

        //    printdis(n);
            if(count==n)
            printf("%llu\n",w);
            else {
                printf("-1\n");
            }
            for(i=1;i<=n;i++)
                free(a[i]);


        }

    return 0;
}

