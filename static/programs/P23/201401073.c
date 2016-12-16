#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

void parr(int array[],int start,int end)
{
	int i;
	for (i=start; i<end; i++)
	{
		pi(array[i]);
		space;
	}
	pi(array[i]);
	endl;
	return ;
}

typedef struct vertex
{
	struct vertex *adj;
	int data;
}vertex;

vertex *head[100001];

void insert(int index,int val)
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp->data = val;
	temp->adj = NULL;
	if(head[index] == NULL)
	{
		head[index] = (vertex *)malloc(sizeof(vertex));
		head[index] = temp;
	}
	else
	{
		temp->adj = head[index];
		head[index] = temp;
	}
	return ;
}

int prev[100010],printing[100010];
int end=0;
int n;

void set_prev(int n)
{
	int i;
	for(i=0;i<100010;i++)
		prev[i] = n;
	return ;
}

int minheap[100010];

//function to insert an element into the heap
insert_min(int num)
{
	int temp;
	if(num > 1)
	{
		if(minheap[num] < minheap[num/2])
		{
			temp = minheap[num];
			minheap[num] = minheap[num/2];
			minheap[num/2] = temp;
			insert_min(num/2);
		}
	}
	return ;
}
//delete an element from the minheap
int delete_min()
{
	int ans;
//	parr(minheap,1,end);
	ans = minheap[1];
	minheap[1] = minheap[end];
	end--;
	int j=1,child,temp;
	while((2*j) <= end)
	{
		if(((2*j)+1) > end)
			child = 2*j;
		else
		{
			if(minheap[2*j] < minheap[(2*j)+1])
				child = 2*j;
			else
				child = 2*j + 1;
		}
		if(minheap[child] < minheap[j])
		{
			temp = minheap[child];
			minheap[child] = minheap[j];
			minheap[j] = temp;
		}
		j = child;
	}
//	pi(ans);
//	endl;
//	parr(minheap,1,end);
	return ans;
}

//function to print the list
void print(int index)
{
	vertex *temp;
	temp = head[index];
	while(temp != NULL)
	{
		pi(temp->data);
		space;
		temp = temp->adj;
	}
	endl;
	return ;
}

int main()
{
	int m,num1,num2,flag = 0,ans;
	gi(n);
	gi(m);
	int i;
	set_prev(0);
	for(i=0;i<m;i++)
	{
		gi(num1);
		gi(num2);
		prev[num2]++;
		insert(num1,num2);
	}
	/*	for(i=1;i<=n;i++)
		print(i);*/
	for(i=1;i<=n;i++)
	{
		if(prev[i] == 0)
		{
			flag = 1;
			minheap[++end] = i;
			insert_min(end);
		}
	}
	vertex *temp;
	for(i=1;i<=n;i++)
	{
		ans = delete_min();
		pi(ans);
		if(i!=n)
			space;
		prev[ans]--;
		temp = (vertex *)malloc(sizeof(temp));
		temp = head[ans];
		while(temp != NULL)
		{
			prev[temp->data]--;
			if(prev[temp->data] == 0)
			{
				minheap[++end] = temp->data;
				insert_min(end);
			}
			temp = temp->adj;
		}
		temp = NULL;
	}		
	if(flag == 0)
		printf("Sandro fails.\n");
	endl;
//	else
//		parr(printing,0,count);
	return 0;
}
