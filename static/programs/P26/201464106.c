#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#define N 1229
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct heap_node
{
    int v;
    long long int d;
}heap_node;

void insert(node *list[],int u,int v)
{
    node *temp=malloc(sizeof(node));
    temp->data=v;
    temp->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=malloc(sizeof(node));
        list[u]=temp;
    }
    else
    {
        temp->next=list[u]->next;
        list[u]->next=temp;
    }
}

int a[10000];

void erat()
{
    int i,j;
    for(i=0;i<=9999;i++)
        a[i]=1;
    for(i=2;i*i<=9999;i++)
    {
        if(a[i]==1)
        {
            for(j=i*i;j<=9999;j=j+i)
                a[j]=0;
        }
    }
}


long long int sz=0; 
heap_node heap[100001];

void swap(heap_node *p,heap_node *q)
{
    heap_node hold=*p;
    *p=*q;
    *q=hold;
}

void ins_heap(heap_node x)
{
    sz++;
    heap[sz]=x;
    int i=sz;
    while(heap[i/2].d > heap[i].d)
    {
        swap(&heap[i/2],&heap[i]);
        i=i/2;
    }
}

heap_node del_heap(int n)
{
    int i=1;
    heap_node min;
    min=heap[1];
    heap[1]=heap[sz];
    heap[sz].d='\0';
    sz--;
    while(i<=sz/2)
    {
        if((heap[i].d>heap[2*i+1].d) && (heap[i].d>heap[2*i].d) && (heap[2*i].d!='\0') && (heap[2*i+1].d!='\0'))
        {
            if(heap[2*i].d > heap[2*i+1].d)
            {
                swap(&heap[i],&heap[2*i+1]);
                i=2*i+1;
            }
            else
            {
                swap(&heap[i],&heap[2*i]);
                i=2*i;
            }
        }
        else if((heap[i].d>heap[2*i+1].d) && (heap[2*i+1].d!='\0'))
        {
            swap(&heap[i],&heap[2*i+1]);
            i=2*i+1;
        }
        else if((heap[i].d>heap[2*i].d) && (heap[2*i].d!='\0'))
        {
            swap(&heap[i],&heap[2*i]);
            i=2*i;
        }
        else
            break;
    }
    return min;
}

void dij(node *list[],int u,int t,int n)
{
    int vis[n+1],flag=0;
    long long int dis[n+1];
    int i;
    for(i=1000;i<=n;++i)
    {
        vis[i]=0;
        dis[i]=INT_MAX;
    }
    heap_node temp;
    dis[u]=0;
    int cur_dis;
    temp.d=0;
    temp.v=u;    
    ins_heap(temp);
    while(sz)
    {
        heap_node min=del_heap(n);
        vis[min.v]=1;
        if(min.v==t)
        {
            flag=1;
            break;
        }
        node *y=list[min.v];
        while(y!=NULL)
        {
            temp.v=y->data;
            cur_dis = 1 + dis[min.v];
            temp.d=cur_dis;
            if(vis[temp.v]!=1 && cur_dis <= dis[temp.v])
            {
                ins_heap(temp);
                dis[temp.v]=cur_dis;
                if(temp.v==t)
                {
                    flag=2;
                    printf("%lld\n",dis[temp.v]);
                    break;
                }
            }
            y=y->next;
        }
        if(flag==2)break;
    }
    if(flag!=2)
    {
        if(vis[t]==1)
            printf("%lld\n",dis[t]);
        else
            printf("Impossible\n");
    }
}


int main()
{
    erat();
    node *list[10001]={NULL};
    int t,i,l;
    int j,k,pos;
    for(i=1000;i<=10000;i++)
    {
        if(a[i]==1)
        {
            int x=i;
            pos=i;
            /* while(x!=0)
               {
               digit[j]=x%10;
               x=x/10;
               j--;
               }
               int temp;
               for(k=0;k<4;k++)
               {
               temp=digit[k];
               for(l=0;l<=9;l++)
               {
               digit[k]=l;                    
               if(a[num(digit)]==1 && num(digit)!=i && (num(digit)/1000)!=0)
               {
               insert(list,pos,num(digit));
               }
               }
            // digit[k]=temp;
            }*/
            int y;
            for(j=0;j<=9;j++)
            {
                y=j*1000+x%1000;
                if(a[y]==1 && y/1000!=0 && y!=x)
                    insert(list,pos,y);
                y=(x/1000)*1000+j*100+x%100;
                if(a[y]==1 && y!=x)
                    insert(list,pos,y);
                y=(x/100)*100+j*10+x%10;
                if(a[y]==1 && y!=x)
                    insert(list,pos,y);
                y=(x/10)*10+j;
                if(a[y]==1 && y!=x)
                    insert(list,pos,y);
            }
        }
    }
    /*  for(i=8779;i<=8779;i++)
        {
        printf("%d--->",i);
        node *temp=list[i];
        while(temp!=NULL)
        {
        printf("%d ",temp->data);
        temp=temp->next;
        }
        printf("\n");
        }*/
    for(scanf("%d",&t);t--;)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        dij(list,n,m,10000);
        sz=0;
    }
    return 0;
}



