#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
   int d,w;              //data(node number),weight
   struct node *next;
};

typedef struct node NODE;
typedef struct node *LINK;

LINK adj_list[100005];

LINK heap[100005];
int size;

int pos[100005];

#define INF 1000005

void shuffle_up(int x)
{
   LINK temp=heap[pos[x]];
   int i=pos[x];
   for(;i>1 && heap[i/2]->w>temp->w;i/=2)
   {
      heap[i]=heap[i/2];
      pos[heap[i]->d]=i;
   }
   heap[i]=temp;
   pos[temp->d]=i;
}

LINK pop()
{
   LINK ans=heap[1];
   LINK last=heap[size--];
   int i,minchild;
   for(i=1;i<=size/2;i=minchild)
   {
      minchild=2*i;
      if(2*i!=size && heap[2*i+1]->w<heap[minchild]->w)
         minchild=2*i+1;
      if(last->w<heap[minchild]->w)
         break;
      else
      {
         heap[i]=heap[minchild];
         pos[heap[i]->d]=i;
      }
   }
   heap[i]=last;
   pos[heap[i]->d]=i;
   return ans;
}

int visited[100005];

int main()
{
   int ans=0;
   int n,m,i;
   scanf("%d%d",&n,&m);
   if(n==0)
   {
      printf("-1\n");
      return 0;
   }
   memset(visited,0,sizeof(visited));

   heap[0]=NULL;
   for(i=1;i<=n;i++)
   {
      adj_list[i]=NULL;
      pos[i]=-1;
   }

   LINK temp;
   int a,b,w;
   for(i=1;i<=m;i++)          //scanning the graph
   {
      scanf("%d%d%d",&a,&b,&w);

      temp=(LINK)malloc(sizeof(NODE));
      temp->d=b;
      temp->w=w;
      temp->next=adj_list[a];
      adj_list[a]=temp;

      temp=(LINK)malloc(sizeof(NODE));
      temp->d=a;
      temp->w=w;
      temp->next=adj_list[b];
      adj_list[b]=temp;
   }

   size=0;
   for(i=2;i<=n;i++)         //pushing inf for all vertices in the heap
   {
      temp=(LINK)malloc(sizeof(NODE));
      temp->d=i;
      temp->w=INF;
      heap[++size]=temp;
      pos[i]=size;
   }
   visited[1]=1;
   for(temp=adj_list[1];temp!=NULL;temp=temp->next)
   {
      if(visited[temp->d]==1)
            continue;
      if(temp->w<heap[pos[temp->d]]->w)
      {
         heap[pos[temp->d]]->w=temp->w;
         shuffle_up(temp->d);
      }
   }
   while(size!=0)
   {
      temp=pop();
      if(temp->w==INF)           //graph is disconnected
      {
         printf("-1\n");
         return 0;
      }
      visited[temp->d]=1;
      ans=ans+temp->w;
      for(temp=adj_list[temp->d];temp!=NULL;temp=temp->next)
      {
         if(visited[temp->d]==1)
            continue;
         if(temp->w<heap[pos[temp->d]]->w)
         {
            heap[pos[temp->d]]->w=temp->w;
            shuffle_up(temp->d);
         }
      }
   }

   printf("%d\n",ans);

   return 0;
}
