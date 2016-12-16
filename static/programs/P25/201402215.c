#include<stdio.h>
int parent[100001],end,size[100001],count;
struct node{
	int x;
	int y;
	int distance;
};
typedef struct node node;
node heap[1000001];
int min(int j)
{
	if(heap[2*j].distance>heap[2*j+1].distance)
		return 2*j+1;
	else
		return 2*j;
}
void shuffledown(int j)
{
	node temp;
	int k;
	if(2*j+1<=end-1)
	{
		k=min(j);
		if(heap[j].distance>heap[k].distance)
		{
			temp = heap[k];
			heap[k] = heap[j];
			heap[j] = temp;
			shuffledown(k);
		}
		else
			return ;
	}
	else if(2*j==end-1)
	{
		if(heap[j].distance>heap[2*j].distance)
		{
			temp=heap[2*j];
			heap[2*j]=heap[j];
			heap[j]=temp;
			shuffledown(2*j);
		}
	}
	else
		return ;
}
int deletemin()
{
	int j;
	heap[1] = heap[end-1];
	j=1;
	end--;
	shuffledown(j);
	return end;
}

int heapinsert(int x,int y,int w)
{	int j;
	node  temp;
	heap[end].x=x;
	heap[end].y=y;
	heap[end].distance=w;
	if(end>1)
	{
		j=end;
		while(heap[j/2].distance>heap[j].distance && j>1)
		{
			temp=heap[j];
			heap[j]=heap[j/2];
			heap[j/2]=temp;
			j=j/2;
		}
	}
	return end+1;
}

/*node1 *insert(node1 *head,int y,int w)
  {
  if(head==NULL)
  {
  head=(node1*)malloc(sizeof(node1));
  head->val=y;
  head->dist=w;
  head->next=NULL;
  return head;
  }
  else
  {
  head->next=insert(head->next,y,w);
  return head;
  }
  }*/
int root(int a)
{	int j,i;
	j=a;
	while(parent[j]!=j)
	{
		j=parent[j];
//		printf("sfajk\n");
	}
	parent[a]=j;
	return j;
}
long long int function(long long int sum)
{
	int i;
	if(end==1)
		return sum;

//	printf("%d\n",heap[1].distance);
	int l,k;
	l=root(heap[1].x);
	k=root(heap[1].y);
		//printf("root of %d have size %d\n",heap[1].x,size[l]);
		//printf("root of %d have size %d\n",heap[1].y,size[k]);
	if(l!=k)
	{	//printf("......%d\n",sum);
		sum+=heap[1].distance;
		count++;
		//printf("edge b/w %d and %d\n",heap[1].x,heap[1].y);
		//printf("sum is %d\n",sum); 
		if(size[l]<size[k])
		{	parent[l]=k;
			size[k]++;
		}
		else
		{
			parent[k]=l;
			size[l]++;
		}
		//printf("root of %d is %d and root of %d is %d\n",heap[1].x,parent[heap[1].x],heap[1].y,parent[heap[1].y]);

	//		printf("%d ",parent[i]);
	//	printf("\n");
	}
	end=deletemin();
	function(sum);
}

int main()
{
	int n,m,i,x,y,w;
	end=1;
	long long int sum=0;
	    int flag=0;
	    count=0;
	//printf("sum is\n");
	//printf("%d\n",sum);
	scanf("%d %d",&n,&m);
	for(i=0;i<1000001;i++)
	{
		if(i>=100001)
		{
			heap[i].x=0;
			heap[i].distance=0;
			heap[i].y=0;
		}
		else
		{
			heap[i].x=0;
			heap[i].distance=0;
			heap[i].y=0;
			parent[i]=i;

				size[i]=1;
			//	k[i]=NULL;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		//	k[x]=insert(k[x],y,w);
		//	size[x]++;
		//	parent[y]=x;
		end=heapinsert(x,y,w);
	//	printf("%d\n",heap[i].distance);
	}
	//for(i=1;i<end;i++)
	//{
	//	printf("%d ",heap[i].distance);
	//}
	//printf("\n");
	//printf("24234\n");
	sum=function(0);
	//printf("2342\n");
//	for(i=1;i<=3;i++)
//		printf("%d ",parent[i]);
//	printf("\n");
	for(i=1;i<=n;i++)
	{	if(size[i]==1)
			flag=1;
	}
	if(count==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
