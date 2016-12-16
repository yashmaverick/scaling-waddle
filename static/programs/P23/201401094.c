#include<stdio.h>
#include<stdlib.h>
#define INF 1000000009
typedef struct heap{
  int indeg;
  int nn;
}hp;
typedef struct adj{
  int val;
  struct adj *next;
}node;
hp heap[100005];
int pos[100005];
node* insert(node *head,int val)
{
  node *temp=malloc(sizeof(node));
  temp->val=val;
  temp->next=head;
  return temp;
}
int comp(hp a,hp b)
{
  if(a.indeg!=b.indeg)
    return (a.indeg<b.indeg);
  else
    return (a.nn<b.nn);
}
void swap(int i)
{
  int t;
  hp temp;
  t=pos[heap[i].nn];
  pos[heap[i].nn]=pos[heap[i>>1].nn];
  pos[heap[i>>1].nn]=t;
  temp=heap[i];
  heap[i]=heap[i>>1];
  heap[i>>1]=temp;
}
void update(int i)
{
  int t;
  while(i>1 && comp(heap[i],heap[i>>1]))
  {
    swap(i);
    i=i>>1;
  }

}
void shuldn(int n)
{
  int i=2,t;
  while(i<=n)
  {
    if(i+1<=n && comp(heap[i+1],heap[i]))
      i=i+1;
    if(comp(heap[i],heap[i>>1]))
    {
      swap(i);
    }
    else
      break;
    i=i<<1;
  }
}
void print(hp *hs,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
    printf("indeg:%d: nn:%d ",hs[i].indeg,hs[i].nn);
  }
  printf("\n");
}
void pr(int *hs,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
    printf("pos:%d ",hs[i]);
  }
  printf("\n");
}
void frp( node *head)
{
  if(head==NULL)
  {   return ;}
  frp(head->next);
  free(head);
}

int main()
{
  int n,m,i,a,b;
  node *head[100005];
  int vis[100005];
  scanf("%d %d",&n,&m);
  for(i=0;i<=n;i++)
  {
    heap[i].indeg=0;
    heap[i].nn=i;
    pos[i]=i;
    head[i]=NULL;
    vis[i]=0;
  }
  for(i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    head[a]=insert(head[a],b);
    heap[b].indeg++;
  }
  for(i=1;i<=n;i++)
   update(i);
    //int(heap,i+1);}
  int s=n;
  while(n!=0)
  {
    printf("%d",heap[1].nn);
   if(n!=1)
      printf(" ");
    vis[heap[1].nn]=1;
  //print(heap,n+1);
  //pr(pos,s+1);
    node *temp=head[heap[1].nn];
    heap[1]=heap[n];
    pos[heap[n].nn]=1;
    shuldn(n);
    n--;
    while(temp!=NULL)
    {
      if(vis[temp->val]!=1)
      {
        heap[pos[temp->val]].indeg-=1;
        update(pos[temp->val]);
      }
      temp=temp->next;
    }
  }
  printf("\n");
  for(i=1;i<=n;i++)
    frp(head[i]);
  return 0;
}

