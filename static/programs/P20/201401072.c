#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//#define din(n) scanf("%d",&n);
//#define forn(k,n) {int i;for(i=k;i<n;i++)};
int maxd=-1,maxn=-1,n;
int *b;
typedef struct node
{
    int val;
    struct node *next;
    struct node* tail;
}node;

node * newnode(int ins)//initalises a new node with the given value;
{
    node *a=(node *)malloc(sizeof(node));
    a->val=ins;
    a->next=NULL;
    a->tail=NULL;
    return a;
}

void insert(node *a[],int y,int x)
{
    node *head=a[y];
    node *old=head->next;
    head->next=newnode(x);
    head->next->next=old;
}

void dfs(node*a[],int y,int d)
{
    b[y]=1;
  //  printf("dfs for %d and sum is %d\n",y,sum);
    node*head=a[y];
    if(maxd<d)
    {
        maxd=d;
        maxn=y;
    }
    while(head->next!=NULL)
    {
        head=head->next;
        if(b[head->val]==0)
        {
            dfs(a,head->val,d+1);
        }

    }


}

void printlist(node* a[])             //utility function to print the adjacency list
{
    int j;
    printf("insider print list\n");
    for(j=1;j<=n;j++)
    {
        node*head=a[j];
        printf("%d :",head->val);

        while(head->next!=NULL)
        {
            head=head->next;
            printf("%d ",head->val);
        }
        printf("\n");
    }
}

/*void rev_dfs(int v,node*a[])
{

    d[v]=1;
    count++;
    node*head=a[v];
    while(head->next!=NULL)
    {
        head=head->next;
        if(d[head->val]!=1)
        {
            rev_dfs(head->val,a);
        }

    }
}*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      // printf("%d %d\n",maxn,maxd);
        scanf("%d",&n);
        int m=n;
        node *a[n+1];
        b=(int *)malloc(sizeof(int)*(n+1));
        int i;

        for(i=1;i<=n;i++)
        {
            a[i]=newnode(i);    //function to initialize the adjacency list pointers
        }
        m=n-1;
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            insert(a,x,y);
            insert(a,y,x);
        }
       // printlist(a);
        for(i=0;i<=n;i++)
            b[i]=0;
        dfs(a,x,0);
        maxd=-1;
        memset(b,0,sizeof(int)*(n+1));
        dfs(a,maxn,0);
        printf("%d\n",maxd+1);
        maxn=-1,maxd=-1;
        for(i=1;i<=n;i++)
        free(a[i]);
        }
return 0;
}

