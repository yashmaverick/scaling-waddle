#include<stdio.h>
#include<stdlib.h>
#define sn(x) scanf("%lld", &x);
#define pn(x) printf("%lld\n", x);

struct Stack{
  long long int val;
  long long int pos;
  struct Stack* next;
};

long long int size=0;

struct Stack* head=NULL;

void pushstack(long long int x,long long int sizex)
{
  size++;
  struct Stack* tempor=malloc(sizeof(struct Stack));
  tempor->val=x;
  tempor->pos=sizex;
  tempor->next=head;
  head=tempor;
}

void popstack()
{
  if(head!=NULL)
  {
    size--;
    struct Stack* tempor=head;
    head=head->next;
    free(tempor);
  }
}

long long int topstack()
{
  if(head!=NULL)
    return head->val;
}

long long int top1stack()
{
  if(head!=NULL)
    return head->pos;
}

int main()
{
  long long int pp,kk,tc,n,m,a,b,c,i,j,k;
  long long int cur, max=0;
  sn(n)
  long long int A[100011]={0};
  long long int prev[100011]={0};
  long long int after[100011]={0};
  while(n!=0)
  {
    max=0;
    head=NULL;
    size=0;
    for(i=0;i<n;i++)
      sn(A[i])
    for(i=0;i<n;i++)
    {
      while(size!=0 && topstack()>=A[i])
        popstack();
      if(size==0)
        prev[i]=-1;
      else
        prev[i]=top1stack();
      pushstack(A[i],i);
    }
    head=NULL;
    size=0;
    for(i=n-1;i>=0;i--)
    {
      while(size!=0 && topstack()>=A[i])
        popstack();
      if(size==0)
        after[i]=n;
      else
        after[i]=top1stack();
      pushstack(A[i],i);
      cur=A[i]*((after[i]-i-1)+(i-prev[i]-1)+1);
      if(cur>=max)
        max=cur;
    }
    pn(max)
    sn(n);
  }
  return 0;
}
