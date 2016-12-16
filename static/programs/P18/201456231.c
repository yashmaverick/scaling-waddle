#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 1000000
#define MAXSIZE 1000000
typedef struct stack
{
    int stk[MAXSIZE];
    int top;
}STACK;
STACK s;
int  pop();
void push (int num)
{
    if (s.top == (MAXSIZE - 1))
    {
	return;
    }
    else
    {
	s.top = s.top + 1;
	s.stk[s.top] = num;
    }
    return;
}
int pop ()
{
    int num;
    if (s.top == - 1)
    {
	return (s.top);
    }
    else
    {
	num = s.stk[s.top];
	s.top = s.top - 1;
    }
    return(num);
}

int stempty()
{
    if (s.top == -1)
	return 1;

    else
	return 0;
}
struct node
{
    int val;
    struct node* next;
};
struct node* varray[MAX];
struct node* reverse[MAX];
struct node* insert(struct node* root, int n)
{
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->val=n;
    temp->next=root;
    return temp;
}

void print(struct node* array)
{
    struct node* tmp=array;
    while(tmp!= NULL)
    {
	printf("%d\n",tmp-> val);
	tmp= tmp-> next;
    }
}
int visited[MAX+1] = {0};
int main()
{
    int vertex,nu;
    int i, a ,b,n,length=0,t,indi,count,tmp,test;
    scanf("%d",&test);
    while(test--)
    {
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    visited[i]=0;
	    varray[i]=NULL;
	    reverse[i]=NULL;
	}
	for (i = 1; i <=n; i++)
	{
	    scanf("%d",&count);
	    while(count--)
	    {
		scanf("%d",&tmp);
		varray[tmp]=insert(varray[tmp],i);
		reverse[i]=insert(reverse[i],tmp);
	    }
	}
	for(i=1;i<=n;i++)
	{
	    memset(visited,0,sizeof(visited));
	    nu=0;
	    push(i);
	    nu++;
	    while (!stempty())
	    {
		vertex = pop();
		visited[vertex] = 1;
		struct node* temp = varray[vertex];
		while(temp != NULL)
		{
		    if (visited[temp->val] == 0)
		    {
			push(temp->val);
			nu++;
			visited[temp->val] = 2;
		    }
		    temp = temp -> next;
		}
	    }
	    if(nu==n)
	    {
		break;
	    }
	}
	if(i<=n)
	{
	    memset(visited,0,sizeof(visited));
	    nu=0;
	    push(i);
	    nu++;
	    while (!stempty())
	    {
		vertex = pop();
		visited[vertex] = 1;
		struct node* temp = reverse[vertex];
		while(temp != NULL)
		{
		    if (visited[temp->val] == 0)
		    {
			push(temp->val);
			nu++;
			visited[temp->val] = 2;
		    }
		    temp = temp -> next;
		}
	    }
	    printf("%d\n",nu);
	}
	else
	{
	    printf("0\n");
	}
    }
    return 0;
}
