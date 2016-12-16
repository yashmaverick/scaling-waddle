#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n)

typedef struct dabba
{
  struct dabba *next;
  long long int num,wght;
  
}node;


int heap[100005];
int dfs[100005];
int visited[100005];
int nodepos[100005];
node *arr[100005];
int heapsize=0;
int dest,m,counter;

int swap(int arr[],int a,int b)
{
  int tempos;
  tempos=nodepos[arr[a]];
  nodepos[arr[a]]=nodepos[arr[b]];
  nodepos[arr[b]]=tempos;
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
      if(li<=heapsize && dfs[heap[li]]<dfs[heap[i]])
	minpos=li;
      else
	minpos=i;
      
      if(ri<=heapsize && dfs[heap[ri]]<dfs[heap[minpos]])
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
  while(i>1 && dfs[heap[i]]<dfs[heap[i/2]])
    {
      swap(heap,i,i/2);
      i=i/2;
    }
}

void insert(int num)
{
  heapsize++;
  nodepos[num]=heapsize;
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

void djikstra(int source)
{
  if(source==dest)
    return ;

  if(counter==m)
    return;
  counter++;

  node* temp=arr[source];
  while(temp!=NULL)
    {
      if(visited[temp->num]==0 && dfs[temp->num]==-1)
	{
	  dfs[temp->num]=dfs[source]+temp->wght;
	  insert(temp->num);
	}
      else if(visited[temp->num]==0 && dfs[source]+temp->wght < dfs[temp->num])
	{
	  dfs[temp->num]=dfs[source]+temp->wght;
	  minify(nodepos[temp->num],temp->num);
	}
      temp=temp->next;
    }
  visited[source]=1;
  int random=getmin();
  djikstra(heap[1]);
}

int main()
{
  int n,weight;
  int a,b,c;
  int source,node1,node2;
  node *temp;
  sc(n);
  sc(m);
  b=0;
  while(b<m)
    {
      sc(node1);
      sc(node2);
      sc(weight);
      
      if(arr[node1]==NULL)
	{
	  arr[node1]=(node*)malloc(sizeof(node));
	  arr[node1]->num=node2;
	  arr[node1]->wght=weight;
	}
      else
	{
	  temp=(node*)malloc(sizeof(node));
	  temp->num=node2;
	  temp->wght=weight;
	  temp->next=arr[node1]->next;
	  arr[node1]->next=temp;
	}

      b++;
    }
  
  for(a=0;a<=n;a++)
    dfs[a]=-1;

  sc(source);
  sc(dest);
  dfs[source]=0;
  heapsize=1;
  heap[1]=source;
  
  counter=0;
  djikstra(source);

  if(dfs[dest]==-1)
    printf("NO\n");
  else
    printf("%d\n",dfs[heap[1]]);
  return 0;
}
	  

  
