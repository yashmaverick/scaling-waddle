#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX 100
struct node
{
    char *data;
    struct node *next;
};
typedef struct node node;
int size;
void freecall(node *a)
{
    free(a->data);
    free(a);
}
node *head=NULL;
node *tail=NULL;
node *create()
{
    char tra[MAX];
    node *a=malloc(sizeof(node));
    a->data=malloc(sizeof(char)*MAX);
    scanf("%s",tra);
    strcpy(a->data,tra);
    a->next=NULL;
    return a;
}
void append(int max)
{
    node *a=create();
    if(head==NULL)
    {
        head=tail=a;
        head->next=NULL;
        size++;
    }
    else if(size<max)
    {
        tail->next=a;
        tail=a;
        a->next=head;
        size++;
    }
    else if(size==max)
    {
        tail->next=a;
        a=head;
        tail=tail->next;
        head=head->next;
        tail->next=head;
        freecall(a);
    }
}
void print()
{
    node *a=head;
    if(size==1)
        printf("%s\n",a->data);
    if(size<2)
        return ;
    while(a!=tail)
    {
        printf("%s\n",a->data);
        a=a->next;
        if(a==tail)
            printf("%s\n",a->data);
    }
}
void totalremove()
{
    node *a;
    if(size==0)
        return ;
    if(size==1)
    {
        a=head;
        head=tail=NULL;
        freecall(a);
        size--;
    }
    else
    {
        a=head;
        head=head->next;
        freecall(a);
        size--;
    }
}
int main ()
{   
    int max;
    scanf("%d",&max);
    char c;
    char trash;
    int n,i;
    size=0;
    while(1)
    {
        scanf("%c",&trash);
        scanf("%c",&c);
        if(c=='Q')
            break;
        if(c=='A')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                append(max);
        }
        else if(c=='L')
            print();
        else if(c=='R')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                totalremove();
        }
    }
    return 0;
}
