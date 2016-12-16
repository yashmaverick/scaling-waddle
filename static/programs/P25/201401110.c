#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
long long int n,m,sum;

typedef struct graph
{
  ll v;
  ll u;
  ll w;
}node;

typedef struct subsets
{
  ll parent;
  ll rank;
}set;

ll visited[100001];
set *subset[100001];
node arr[100001];

typedef int (*compfn)(const void*, const void*);

int compare(node *,node *);

int compare(node *node1,node *node2)
{
  if(node1->w < node2->w)
    return -1;
  else if(node1->w > node2->w)
    return 1;
  else
    return 0;
}

ll find(ll i)
{
  ll j=i;
  if(j!=subset[j]->parent)
  {
    subset[j]->parent=find(subset[j]->parent);
  }
  return subset[j]->parent;
}

void Union(ll x,ll y)
{
    ll xroot=find(x);
    ll yroot=find(y);
//    printf("Root of %d : %d Root of %d: %d\n",x,xroot,y,yroot);

  if(subset[xroot]->rank==subset[yroot]->rank) //attach y tree under x
  {
    subset[yroot]->parent=xroot;
    subset[xroot]->rank++;
  }
  else if(subset[xroot]->rank>subset[yroot]->rank)
  {
    subset[yroot]->parent=xroot;
  }
  else if(subset[xroot]->rank<subset[yroot]->rank)
  {
    subset[xroot]->parent=yroot;
  }
}

ll e;

void kruskal()
{
  ll i=1;
  while(e<n-1&&i<=m)
  {
    ll xroot=find(arr[i].v);
    ll yroot=find(arr[i].u);
  //  printf("Root of %d : %d Root of %d: %d\n",cur->v,xroot,cur->u,yroot);
    if(xroot!=yroot)
    {
      sum+=arr[i].w;
      e++;
//      printf("%d-%d-%d\n",cur->v,cur->w,cur->u);
      Union(arr[i].v,arr[i].u);
  //  printf("Root of %d : %d Root of %d: %d\n",cur->v,xroot,cur->u,yroot);
      i++;
    }
    else
     i++;
  }
}
int main()
{
  ll x,y,w,i,j;
  e=0;
  node *root=malloc(sizeof(node));
  scanf("%lld%lld",&n,&m);
    subset[0]=malloc(sizeof(set));
    subset[0]->parent=i;
    subset[0]->rank=0;
  for(i=1;i<=n;i++)
  {
    subset[i]=malloc(sizeof(set));
    subset[i]->parent=i;
    subset[i]->rank=0;
  }
  
  for(i=1;i<=m;i++)
  {
    scanf("%lld%lld%lld",&x,&y,&w);
    visited[x]=1;
    visited[y]=1;
    arr[i].v=x;
    arr[i].u=y;
    arr[i].w=w;
  }

  qsort((void *) &arr, m+1, sizeof(node),(compfn)compare );

  for(i=1;i<=m;i++)
  {
//    printf("::%lld-%lld-%lld\n",arr[i].v,arr[i].w,arr[i].u);
  }
  if(m!=0)
    kruskal();
  if(m==0&&n==1)
  {
    sum=0;
  }
  else if(e!=n-1||(m==0&&n>1))
  {
    sum=-1;
  }
  else
  {
    for(i=1;i<=n;i++)
    {
      if(visited[i]!=1)
      {
        sum=-1;
        break;
      }
    }
  }
  printf("%lld\n",sum);
  return 0;
}
