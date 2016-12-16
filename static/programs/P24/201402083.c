/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include<assert.h>
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define LL long long int 
#define NDEBUG
typedef struct node node;
struct node{
    int nodename;
    int countleft;
    int countright;
    int height;
    node *left;
    node *right;
};

void swap(int arr[],int i ,int j);
int max(int a,int b);
int min(int a,int b);
int heigh(node *head);
node *leftrotate(node *head);
node *rightrotate(node *head);
node *insert(node *head,int element);
int search(node *head,int element);
int find(node *head,int index);
int countbefore(node *head,int num);
int count_left(node *head);
print(node *head)
{
    if(head==NULL) return ;
    print(head->left);
    print(head->right);
    printf("(%d %d-cl) ",head->nodename,head->countleft);
}

int main()
{
    node *root=NULL;
    char q[100];
    int x;
    int count=0;

    while(1)
    {
        scanf("%s",q);
        if(strcmp(q,"SetHealthy")==0)
        {
            count++;
            scanf("%d",&x);
            root =insert(root , x);
        }
        else if(strcmp(q,"CheckHealthy")==0)
        {
            scanf("%d",&x);
            if(checkhealthy(root,x)==1) printf("YES\n");
            else printf("NO\n");
        }
        else if(strcmp(q,"Healthy")==0)
        {
            scanf("%d",&x);
            int ans=healthy(root,x);
            if(x>count) printf("NONE\n");
            else printf("%d\n",ans);
        }
        else if(strcmp(q,"RottenBefore")==0)
        {
            scanf("%d",&x);
            int ans=rottenbefore(root,x);
            printf("%d\n",ans);
        }
        else if(strcmp(q,"Quit")==0)
            break;
    }
//        print(root);
  //      printf("\n");
return 0;
}

int count_left(node *head)
{
    
    if(head==NULL) return 0;
    else {assert(head!=NULL);
        return head->countleft;
    }
}

int count_right(node *head)
{
    if(head==NULL) return 0;
    else return head->countright;
}

int rottenbefore(node *head,int num)
{
    if(head==NULL) return 0;
    else if(head->nodename < num ) return count_left(head) + 1 + rottenbefore(head->right,num);
    else if(head->nodename==num) return count_left(head) ;
    else if(head->nodename > num) return rottenbefore(head->left,num);
}

int healthy(node *head,int index)
{
    if(head==NULL) return -1;
    if(index> count_left(head)+1)
    {
        assert(head!=NULL);
        index=index - (count_left(head)+1);
        return healthy(head->right,index);
    }
    else if(index == count_left(head)+1) 
    {
        assert(head!=NULL);
        return head->nodename;
    }
    else 
    {
        assert(head!=NULL);
        return healthy(head->left,index);
    }
}

void swap(int arr[],int i,int j)              // swaps value at index i and j in arr[]
{
    if(i==j) return ;
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}

int max(int a , int b)                    // returns max of two numbers
{
    int c=a>b?a:b;
    return c;
}

int min(int a,int b)                     //returns min of two numbers
{
    int c=a<b?a:b;
    return c;
}
int heigh(node *head)
{
    if(head==NULL) return 0;
    else return head->height;
}

node *leftrotate(node *head)
{
    assert(head!=NULL);
    node *temp=head->right;
    node *temp2=temp->left;
    temp->left=head;
    head->right=temp2;
    head->height=max(heigh(head->left),heigh(head->right)) + 1;
    temp->height=max(heigh(temp->left),heigh(temp->right)) + 1;
    head->countright=count_left(temp);
    temp->countleft=count_left(head)+1 + count_left(temp);
    return temp;
}

node *rightrotate(node *head)
{
    assert(head!=NULL);
    node *temp=head->left;
    node *temp2=temp->right;
    temp->right=head;
    head->left=temp2;
    head->height=max(heigh(head->left),heigh(head->right)) + 1;
    temp->height=max(heigh(temp->left),heigh(temp->right)) + 1;
    head->countleft=count_right(temp) ;
    temp->countright=count_right(temp) + count_right(head)+1;
    return temp;
}

int balancefactor(node *head)
{
    if(head==NULL ) return 0;
    else return (heigh(head->left) - heigh(head->right));
}

node *insert(node *head,int element)
{
    if(head==NULL) 
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->nodename=element;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=1;
        temp->countleft=0;
        temp->countright=0;
        return temp;
    }
    if(element > head->nodename) {
        head->countright=(head->countright)+1;
        head->right=insert(head->right,element);
    }
    else {
        head->countleft=(head->countleft)+1;
        head->left=insert(head->left,element);
    }

    assert(head!=NULL);
    head->height=max(heigh(head->left),heigh(head->right)) + 1;
    int balance = balancefactor(head);
    if(balance > 1)
    {
        if(element < head->left->nodename) head=rightrotate(head);
        else
        {
            head->left=leftrotate(head->left);
            head=rightrotate(head);
        }
    }
    else if (balance < -1)
    {
        if(element > head->right->nodename) head=leftrotate(head);
        else
        {
            head->right=rightrotate(head->right);
            head=leftrotate(head);
        }
    }
    return head;
}
    
int checkhealthy(node *head,int element)
{
    if(head==NULL) return -1;
    if(head->nodename==element) return 1;
    if(element > head->nodename) return checkhealthy(head->right,element);
    else return checkhealthy(head->left,element);
}


