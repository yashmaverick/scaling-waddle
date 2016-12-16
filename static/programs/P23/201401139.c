#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n)

typedef struct dabba
{
  int num,dep;
  struct dabba *next;
}node;


int dep[100005];
int topo[100005];
int heap[100005];
int heapsize=0;
node *arr[100005];

int swap(int arr[],int a,int b)
{
  int tempn=arr[a];
  arr[a]=arr[b];
  arr[b]=tempn;
}

void shuffledown(int i)
{
  int minpos=-2;
  int li;
  int ri;

  while(minpos!=i)
    {
      li=i*2;
      ri=i*2+1;
      if(li<=heapsize && heap[li]<heap[i])
	minpos=li;
      else
	minpos=i;
      
      if(ri<=heapsize && heap[ri]<heap[minpos])
	minpos=ri;
      
      if(i==minpos)
	break;
      else
	{
	  swap(heap,minpos,i);
	  i=minpos;
	  minpos=-2;
	}
    }
}

void minify(int i,int num)
{
  heap[i]=num;
  while(i>1 && heap[i]<heap[i/2])
    {
      swap(heap,i,i/2);
      i=i/2;
    }
}

void insert(int num)
{
  heapsize++;
  minify(heapsize,num);
}

int getmin()
{
  int min=heap[1];
  swap(heap,1,heapsize);
  heapsize--;
  shuffledown(1);
  return min;
}

int main()
{
  int n,m,t,count;
  int a,b,c,ele;
  int node1,node2;
  node *temp;

  
  sc(n);

  for(a=0;a<n;a++)
    dep[a]=0;
  sc(m);
  while(m)
    {
      sc(node1);
      sc(node2);
      
      if(arr[node1]==NULL)
	{
	  arr[node1]=(node*)malloc(sizeof(node));
	  arr[node1]->num=node2;
	  dep[node2]+=1;
	}
      else
	{
	  temp=(node*)malloc(sizeof(node));
	  temp->num=node2;
	  dep[node2]+=1;
	  temp->next=arr[node1]->next;
	  arr[node1]->next=temp;
	}
      m--;
    }
  for(a=1;a<=n;a++)
    if(dep[a]==0)
      insert(a);
  count=0;
  do
    {
      ele=getmin();
      
      topo[count++]=ele;
      temp=arr[ele];
      while(temp!=NULL)
	{
	  dep[temp->num]--;
	  if(dep[temp->num]==0)
	    insert(temp->num);
	  temp=temp->next;
	}
    }while(heapsize>0);
      
  for(a=0;a<n-1;a++)
    printf("%d ",topo[a]);
  printf("%d\n",topo[n-1]);
  
  return 0;
}
