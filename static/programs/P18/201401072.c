#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//#define din(n) scanf("%d",&n);
//#define forn(k,n) {int i;for(i=k;i<n;i++)};
int sum=0,count=0,n;
int *b,*d;
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
    if(head->next==NULL)
    {   
        head->next=newnode(x);
        head->tail=head->next;
    }
    else
    {   
        head->tail->next=newnode(x);
        head->tail=head->tail->next;
    }
}

int dfs(node*a[],int y)
{
    b[y]=1;
    sum++;
  //  printf("dfs for %d and sum is %d\n",y,sum);
    int flag=0;
    if(sum==n)
       { 
            count++;
            return 1;
        }
    node*head=a[y];
    while(sum<n&&head->next!=NULL)
    {
        head=head->next;    
        if(b[head->val]==0)
        {
            flag=dfs(a,head->val);
        }

    }
    return flag;

}

void printlist(node* a[])             //utility function to print the adjacency list
{
    int j;
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

void rev_dfs(int v,node*a[])
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
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int temp;
        temp=sum;
        node *a[n+1],*c[n+1];
        b=(int *)malloc(sizeof(int)*n+1);
        d=(int *)malloc(sizeof(int)*n+1);
        int i;

        for(i=1;i<=n;i++)
        {
            a[i]=newnode(i);    //function to initialize the adjacency list pointers 
            c[i]=newnode(i);
        }

        for(i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            while(x--)
            {
                int y;
                scanf("%d",&y);
                insert(a,y,i);
                insert(c,i,y);
            }
        }
        //   printlist(a);
        //    printlist(c);
        int flag=0;
        for(i=1;i<=n&&!flag;i++)
        {   
            sum=0;    
            memset(b,0,sizeof(int)*(n+3));
            flag=dfs(a,i);
            if(flag==1)
            break;
        }

        int v=i;
        memset(d,0,sizeof(int)*(n+1));
        if(flag)
        {
            rev_dfs(v,c); 
            count=count-1;
        }
        printf("%d\n",count);
        count=0;
        }
        return 0;

}

