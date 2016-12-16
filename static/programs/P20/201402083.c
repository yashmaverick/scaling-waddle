/*
   _____________________________________________
   PROBLEM STATEMENT: You have to find the diameter of a given tree . 

COMMENTS:   Here , we are considering that we are storing the tree as an adjacency list and are directly finding diameter from 
there without building the tree. 
We first apply dfs from any arbitrary node in order to find the farthest node(k) from this node .
Now , we'll apply dfs from k to find the farthest node from k and the gap between these two nodes will be the
diameter.

SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node node;

struct node 
{
    int nodename;
    //int data;
    node* next;
};

node *tree[1000001];
int flag[1000001];
int max_length;
int length;
int k;
void dfs(int a);
void print (int n);
int main()
{
    int n,i,t;                //n=number of edges ....... no. of nodes will be n+1 (because it's a tree)
    // printf("enter no. of edges in the tree\n");
    scanf("%d",&t);
    while(t--)
    {
        k=0;
        max_length=0;
        length=0;
        for(i=0;i<1000001;i++) flag[i]=0;
        for(i=0;i<1000001;i++) tree[i]=NULL;
        scanf("%d",&n);
        for(i=0;i<n-1;i++)                                              //scanning the tree in the same manner as we scan a 
        {                                                             //  general graph
            int a,b;
      //      printf("enter the vertices of the edge\n");
            scanf("%d %d",&a,&b);
            node *temp=(node *)malloc(sizeof(node));
            temp->nodename=a;
            temp->next=tree[b];
            tree[b]=temp;
            node *temp2=(node *)malloc(sizeof(node));
            temp2->nodename=b;
            temp2->next=tree[a];
            tree[a]=temp2;
        }
        //    print(n+2);             // to print adjacency list
        max_length=length=0;
        dfs(1);
        max_length=length=0;
        for(i=0;i<1000001;i++) flag[i]=0;
        dfs(k);
        printf("%d\n",max_length);
    }
    return 0;
}

void print(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        node *temp=tree[i];
        while(temp!=NULL)
        { printf("%d  ",temp->nodename); temp=temp->next;}
        printf("\n");
    }
}
void dfs(int a)
{
    int i;
    flag[a]=1;
    length++;
    if(length>max_length)
    {
        max_length=length;
        k=a;
    }
    node *temp=tree[a];
    while(temp!=NULL)
    {
        if(flag[temp->nodename]==0)
        {
            dfs(temp->nodename);
        }
        temp=temp->next;
    }
    length--;
}


