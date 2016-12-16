#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100005

int n,e;

typedef struct adj
{
	int val;
	struct adj* next;
}list;

list *adjlist[SIZE];
int visited[SIZE];
int no_of_visited;
int depend[SIZE];

int H[SIZE];
int size;

void shuffle_up(int pos)
{
	if(pos<=1)
		return;
	if(H[pos]<H[pos/2])
	{
		int temp;
		temp=H[pos/2];
		H[pos/2]=H[pos];
		H[pos]=temp;
		shuffle_up(pos/2);
	}
}

void shuffle_down(int pos)
{
	if(2*pos>size)
		return;
	int l=0,r=0;
	if(2*pos<=size)
		l=2*pos;
	if(2*pos+1<=size)
		r=2*pos+1;
	int num=pos;
	if(l!=0&&H[num]>H[l])
		num=l;
	if(r!=0&&H[num]>H[r])
		num=r;
	if(num!=pos)
    {
		int temp;
		temp=H[num];
		H[num]=H[pos];
		H[pos]=temp;
		shuffle_down(num);
    }
}

void print_heap()
{
	printf("##########################\n");
	int i;
	int num,count;
	num=1;
	count=num;
	for(i=1;i<=size;i++)
    {
		printf("%d ",H[i]);
		if(--count==0)
		{
			printf("\n");
			count=1<<num++;
		}
    }
	printf("##########################\n");
	//printf("\n");
}

void insert_heap(int node)
{
		H[++size]=node;
		shuffle_up(size);
}

int pop_min()
{
	int temp=H[1];
	H[1]=H[size--];
	shuffle_down(1);
	return temp;
}

void print_list()
{
	int i;
	list *temp;
	for(i=1;i<=n;i++)
    {
		printf("%d: ",i);
		temp=adjlist[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
		}
		printf("\n");
    }
}

int main()
{
	int e1,e2,i;
	scanf("%d",&n);
	scanf("%d",&e);
	for(i=0;i<=n;i++)
		adjlist[i]=NULL;
	i=e;
	no_of_visited=0;
	memset(depend,0,sizeof(int)*SIZE);
	memset(visited,0,sizeof(int)*SIZE);
	while(i--)
    {
		scanf("%d",&e1);
		scanf("%d",&e2);
		list* temp=(list*)malloc(sizeof(list));
		temp->val=e2;
		temp->next=adjlist[e1];
		adjlist[e1]=temp;
		depend[e2]++;
    }
	//print_list();
	for(i=1;i<=n;i++)
		if(depend[i]==0)
			insert_heap(i);
	while(no_of_visited<n-1)
	{
		//print_heap();
		int node=pop_min();
		printf("%d ",node);
		no_of_visited++;
		list* temp=adjlist[node];
		while(temp!=NULL)
		{
			if(--depend[temp->val]==0)
			   insert_heap(temp->val);
			temp=temp->next;
		}
	}
	int node=pop_min();
	printf("%d",node);
	printf("\n");
	return 0;
}
