#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int
#define sc(x) scanf("%d",&x)
/*typedef struct heapstruct
{
	int size;
	int *a;
	//struct heapstruct *next;
}pq;
pq *h;*/
ll heap[100005]={0},end=0;
typedef struct c
{
	int data;
	struct c *next;
}node;
node *head[500005];
void insertmin(ll x)
{
	//printf("1");
	end++;
	heap[end]=x;
	ll last=end;
	//ll j=last/2;
	while(x<heap[last/2]&&last/2!=0)
	{
		heap[last]=heap[last/2];
		last=last/2;
	}
	heap[last]=x;
	return;
}
ll deletemin()
{
	//printf("333333333\n");
	ll x=heap[end],child;
	end--;
	ll w=heap[1];
	heap[1]=x;
	ll j=1;
	for(j=1;j*2<=end;j=child)
	{ //printf("5");
		//printf("%lld\n",heap[j*2]);
		child=j*2;
		if(child!=end&&heap[child+1]<heap[child])
			child++;
		if(x>heap[child])
			heap[j]=heap[child];
		else
			break;
	}
	heap[j]=x;
	return w;
}

/*void insert(int x)
{
	int i;
	//h->a[(h->size)+1]=(int*)malloc(sizeof(int));
	for(i=++h->size;h->a[i/2]>x;i=i/2)
	{
		h->a[i]=h->a[i/2];
	}
	h->a[i]=x;
}*/
void inserthead(int x,int y)
{
	int i;
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=x;
	temp->next=head[y];
	head[y]=temp;
	//head[y]->a[(head[y]->size)+1]=(int*)malloc(sizeof(int));
	return;
}
/*int delmin()
{
	int i,mina,lasta,child;	
	mina=h->a[1];
	lasta=h->a[h->size--];
	h->a[1]=lasta;
	for(i=1;i*2<=h->size;i=child)
	{
		child=i*2;
		if(child!=h->size && h->a[child+1]>h->a[child])
			child++;
		if(lasta>h->a[child])
		{
			h->a[i]=h->a[child];
		}
		else
			break;
	}
	h->a[i]=lasta;
	return mina;
}*/
/*int delminhead(int y)
  {
  int i,mina,lasta,child;	
  mina=head[y]->a[1];
  lasta=head[y]->a[head[y]->size--];
  head[y]->a[1]=lasta;
  for(i=1;i*2<=head[y]->size;i=child)
  {
  child=i*2;
  if(child!=head[y]->size && head[y]->a[child+1]>head[y]->a[child])
  child++;
  if(lasta>head[y]->a[child])
  {
  head[y]->a[i]=head[y]->a[child];
  }
  else
  break;
  }
  head[y]->a[i]=lasta;
  return mina;
  }*/
/*void display(int u)
  {
  int i;
  for(i=1;i<=h[u]->size;i++)
  {
  printf("\nThe data is: %d",h[u]->a[i]);
  }
  return;
  }
 */
int main()
{
	int vis[500005]={0};
	int arr[500005]={0};
	int yana[500005]={0};
	int index=0,n,m,u,v,k;
	sc(n);
	sc(m);
	for(k=0;k<=n;k++)
	{
		//h[k]=malloc(sizeof(pq));
		//h[k]->a[0]=malloc(sizeof(int));
		//h[k]->size=0;
		//h[k]->a[0]=0;
		head[k]=malloc(sizeof(node));
		//head[k]->a[0]=malloc(sizeof(int));
		//head[k]->data=k;
		head[k]->data=k;
		head[k]->next=NULL;
	}
	//h=malloc(sizeof(pq));
	//head[k]->a[0]=malloc(sizeof(int));
	//head[k]->data=k;
	//h->size=0;
	//h->a=malloc((m+5)*sizeof(int));
	//printf("%d\n",h->a[1]);
	//h->a[0]=0;
	while(m--)
	{
		sc(u);sc(v);
		//insert(u,v);
		yana[v]++;
		inserthead(v,u);
		vis[v]=1;
	}
	for(k=1;k<=n;k++)
		if(vis[k]==0)
			insertmin(k);

	while(end>0)
	{
		int r=deletemin();
		//	printf("Check dependent on %d\n",r);
		arr[index]=r;
		index++;
		while(head[r]->next!=NULL)
		{	int l=head[r]->data;
			//		printf("%d Depends\n",l);
			yana[l]--;
			if(yana[l]==0)
				insertmin(l);
			head[r]=head[r]->next;
		}
		//	printf("Size: %d\n",h[0]->size);
	}
	for(k=0;k<index-1;k++)
		printf("%d ",arr[k]);
	printf("%d\n",arr[index-1]);
	return 0;
}

