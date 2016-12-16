#include<stdio.h>
#include<stdlib.h>

int arr[100005];         // Initial values are much bigger
int store=1;
int ans[100006],count=0;
int visited[1000006]={0};
struct node* v[100006];
struct node* v_transpose[100006];


void insert_in_heap(int data);

struct node{
    int ver;
    struct node *next;
};

int min(int A, int B)
{
    return (A<B)?A:B;
}

struct node* insert(struct node *root, int data)
{
    if (root==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->ver=data;
        new->next=NULL;
        return new;
    }
    else
    {
        //if(root->ver < data)
        {
            root->next=insert(root->next,data);
            return root;
        }
        //else
        // {
        //     struct node *nr=(struct node*)malloc(sizeof(struct node));
        //     nr->ver=data;
        //     nr->next=root;
        //     return nr;
        // }
    }
}


struct node* delete_node(struct node* head, int value)
{
    struct node *newnode=head;
    if (head==NULL)
    {
        //printf("ERROR: Key not found\n");
        return NULL;
    }
    else if (head->ver==value)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    else
    {
        head->next=delete_node(head->next,value);
        return head;
    }
}


void delete_inedges_and_push(int vertex)
{
    struct node *temp=v[vertex];
    v[vertex]=NULL;

    while(temp!=NULL)
    {
        struct node *temp2=v_transpose[temp->ver];
        v_transpose[temp->ver]=temp2=delete_node(temp2,vertex);
        if(temp2==NULL)
        {
            insert_in_heap(temp->ver);
            visited[temp->ver]=1;
        }

        temp2=temp;
        temp=temp->next;
        free(temp2);
    }

}

void push_with_no_inedges(int n)
{
    int i;
    for(i=1;i<=n;i++)
        if(v_transpose[i]==NULL)
        {
            insert_in_heap(i);
            visited[i]=1;
        }
}


void insert_in_heap(int data)
{
    arr[store]=data;
    int check=store;
    while (arr[(check/2)] > arr[check] && check!=1)
    {
        int temp=arr[check];
        arr[check]=arr[check/2];
        arr[check/2]=temp;
        check/=2;
    }
    store++;
}

void deletemin()
{
    arr[1]=arr[store-1];
    int check=1;
    while (min(arr[check*2],arr[check*2 + 1]) < arr[check])
    {
        int MIN = (arr[check*2]<arr[check*2 + 1])?(check*2):(check*2+1);
        if (MIN>=store)
            break;
        int temp=arr[MIN];
        arr[MIN]=arr[MIN/2];
        arr[MIN/2]=temp;
        check=MIN;
    }
    store--;
}
/*
   void print_heap()
   {
   int f=0;
   for(f=0;f<10;f++)
   printf("%d ",arr[f]);
   printf("\n");
   }

   void print_linked_list(int n)
   {
   int i=0;
   printf("V ======\n");
   for(i=1;i<=n;i++)
   {
   struct node *temp=v[i];
   printf("%d : ",i);
   while(temp!=NULL)
   {
   printf("-> %d ",temp->ver);
   temp=temp->next;
   }
   printf("\n");
   }

   printf("V_Transpose =====\n");
   for(i=1;i<=n;i++)
   {
   struct node *temp=v_transpose[i];
   printf("%d : ",i);
   while(temp!=NULL)
   {
   printf("-> %d ",temp->ver);
   temp=temp->next;
   }
   printf("\n");
   }
   }
   */

int main()
{
    int n,m,d,i;
    scanf("%d %d",&n ,&m);

    for(d=0;d<=n;d++)
        v_transpose[d]=v[d]=NULL;

    for(i=0;i<m;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1 ,&t2);
        v[t1]=insert(v[t1],t2);
        v_transpose[t2]=insert(v_transpose[t2],t1);
    }

    push_with_no_inedges(n);
    //    print_heap();
    while(store!=1)
    {
        int MIN=arr[1];
        ans[count++]=MIN;
        deletemin();
        //push_children(MIN,v);
        delete_inedges_and_push(MIN);
        //        print_heap();
        //        print_linked_list(n);
        //push_with_no_inedges();
    }
    count--;

    for(i=0;i<count;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[count]);

    return 0;
}
