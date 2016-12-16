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
    while(a<=heap[temp>>1]&&temp>>1>0)
    {
        if(a==heap[temp>>1])
        {
            if(nod[temp]<nod[temp>>1])
                swap(temp,temp>>1);
        }
        else
        {
            swap(temp,temp>>1);
        }
        temp=temp>>1;
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
            else if(heap[child+1]==heap[child]&&nod[child+1]<nod[child])
                child++;
        }
        if(heap[ind]>heap[child])
        {
            swap(ind,child);
            ind=child;
        }
        else if (heap[ind]==heap[child]&&nod[ind]>nod[child])
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
    while(a<=heap[temp>>1]&&temp>>1>0)
    {
        if(a==heap[temp>>1])
        {
            if(nod[temp]<nod[temp>>1])
                swap(temp,temp>>1);
        }
        else
        {
            swap(temp,temp>>1);
        }
        temp=temp>>1;
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
typedef struct node
{
    int  val;
    struct node*next;

}node;

node * newnode(int  s)
{
    node *a=(node*)malloc(sizeof(node));
    a->val=s;
    a->next=NULL;
    return a;
}
void insert(node *a[],int  x,int y)
{
    node*head=a[x];
    node *old=head->next;
    head->next=newnode(y);
    head->next->next=old;
}
void topolex(node *g[],int *a,int n)
{
    int i,src;
    int b[n+1];
    int top=-1;
    for(i=1;i<=n;i++)
    {
        if(a[i]==0)
            push(i,0);
    }
    int count=0;
    int temp;

       // print();
        while(hsize)
        {
            temp=pop();
            if(count++<n-1)
                printf("%d ",temp);
            node *head=g[temp];
            while(head->next!=NULL)
            {
                head=head->next;
                a[head->val]-=1;
                if(a[head->val]==0)
                    push(head->val,0);

            }
        }
    printf("%d\n",temp);

}
int main()
{
    int n;
    scanf("%d",&n);
    int *a;
    a=(int *)malloc(sizeof(int)*(n+1));
    node *graph[n+1];
    int i;
    for(i=0;i<=n;i++)
        graph[i]=newnode(i);
    memset(a,0,sizeof(a));
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        insert(graph,x,y);
        a[y]+=1;
    }
    topolex(graph,a,n);

return 0;
}
