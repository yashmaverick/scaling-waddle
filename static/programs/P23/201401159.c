#include <stdio.h>
#include <stdlib.h>

#define MAX 500100

typedef struct node {
  int x;
  struct node* next;
} node;

int end=1;
node* arr[MAX];
int d[MAX];
int p[MAX];

int min(int a,int b)
{
  return a>b?b:a;
}

void swap(int *ar,int a,int b)
{
  int temp=ar[a];
  ar[a]=ar[b];
  ar[b]=temp;
}

void insert(int i)
{
  d[end++]=i;
  int b=end-1;
  while(d[b/2]>d[b] && b/2>=1)
    {
      swap(d,b/2,b);
      b=b/2;
    }
}

void delete()
{
  int i=1,a,b,j,k;
  d[i]=d[end-1];
  end--;
  a=min(d[2*i],d[2*i+1]);
  while(a<d[i] && 2*i+1 <end)
    {
      if(d[2*i]<d[2*i+1])
	{
	  swap(d,i,2*i);
	  i=2*i;
	}
      else
	{
	  swap(d,i,2*i+1);
	  i=2*i+1;
	}
      a=min(d[2*i],d[2*i+1]);
    }
  if(2*i<end && d[2*i]<d[i])
    swap(d,i,2*i);
}

void up(int i)
{
  int j,k,l;
  node* temp=arr[i]->next;
  while(temp!=NULL)
    {
      p[temp->x]++;
      if(p[temp->x]==0)
	insert(temp->x);
      temp=temp->next;
    }
}

int main()
{
  int i,j,k,n,t,a,b;
  scanf("%d %d",&n,&t);
  for(i=1;i<=n;i++)
    arr[i]=(node*)malloc(sizeof(node));
  for(i=0;i<t;i++)
    {
      scanf("%d %d",&a,&b);
      node* temp=(node*)malloc(sizeof(node));
      temp->x=b;
      temp->next=arr[a]->next;
      arr[a]->next=temp;
      p[b]--;
    }
  for(i=1;i<=n;i++)
    {
      if(p[i]==0)
	insert(i);
    }
  for(i=0;i<n-1;i++)
    {
      a=d[1];
      printf("%d ",d[1]);
      delete();
      up(a);
    }
  printf("%d\n",d[1]);
  return 0;
}
