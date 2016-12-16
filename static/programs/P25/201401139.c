#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n)

typedef struct dabba
{
  struct dabba *next;
  long long int num,wght;
}node;

typedef struct adabba
{
  int keyd,wght;
}keyval;

keyval heap[1000005];
int visited[100005];
node *arr[100005];
int heapsize=0,sum;
int flag,n,m,counter;

int swap(keyval arr[],int a,int b)
{
  keyval tempos;
  tempos=arr[a];
  arr[a]=arr[b];
  arr[b]=tempos;
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
      if(li<=heapsize && heap[li].wght<heap[i].wght)
	minpos=li;
      else
	minpos=i;
      
      if(ri<=heapsize && heap[ri].wght<heap[minpos].wght)
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

void minify(int i,node *temp)
{
  heap[i].wght=temp->wght;
  heap[i].keyd=temp->num;
  while(i>1 && heap[i].wght<heap[i/2].wght)
    {
      swap(heap,i,i/2);
      i=i/2;
    }
}

void insert(node* temp)
{
  heapsize++;
  minify(heapsize,temp);
}

keyval getmin()
{
  keyval min;
  
  min.keyd=heap[1].keyd;
  min.wght=heap[1].wght;
  swap(heap,1,heapsize);
  heapsize--;
  shuffledown(1);
  return min;
}

void prim(int vertex)
{
  visited[vertex]=1;
  if(counter==n-1)
    return;
  node* temp=arr[vertex];
  while(temp!=NULL)
    {
      if(visited[temp->num]==0)
	insert(temp);
      temp=temp->next;
    }
  keyval random;
  random=getmin();
  while(visited[random.keyd]==1)
    {
      random=getmin();
      if(heapsize<1)
	{
	  flag=1;
	  return;
	}
    }
  counter++;
  sum+=random.wght;
  if(heapsize>=1)
    prim(random.keyd);
  else
    flag=1;
  
}

int main()
{
  int weight;
  int a,b,c;
  int node1,node2;
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

       if(arr[node2]==NULL)
	 {
	   arr[node2]=(node*)malloc(sizeof(node));
	   arr[node2]->num=node1;
	   arr[node2]->wght=weight;
	 }
       else
	 {
	   temp=(node*)malloc(sizeof(node));
	   temp->num=node1;
	   temp->wght=weight;
	   temp->next=arr[node2]->next;
	   arr[node2]->next=temp;
	 }
       b++;
    }
  
  if(m<n-1)
    flag=1;
  else
    {
      flag=0;
      heapsize=sum=0;
      counter=0;
      prim(1);
    
      for(a=1;a<=n;a++)
	if(visited[a]!=1)
	  flag=1;
    }

  if(flag==1)
    printf("-1\n");
  else
    printf("%d\n",sum);
  return 0;
}
	  

  

