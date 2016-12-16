#include<stdio.h>
#include<stdlib.h>

#define N 10010
int A[N];
int n,k;
int length=0;
typedef struct node{
	int val;
	struct node* next;
	struct node* prev;
}node;
node* head=NULL;
node* tail=NULL;

void enqueue(int elem)
{
	if(head==NULL && tail==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->val=elem;
		head->next = NULL;
		head->prev = NULL;
		tail=head;
		length=1;
	}
	else
	{
		tail->next = (node*)malloc(sizeof(node));
		tail->next->prev=tail;
		tail = tail->next;
		tail->val=elem;
		tail->next=NULL;
		length++;
	}


}

void dequeueBack()
{
	if(length==0)
		return;
	length--;
	node* temp = tail;
	tail = tail->prev;
	free(temp);
	if(length==0)
		head=tail=NULL;
	else
		tail->next = NULL;

}

void dequeueFront()
{
	if(length==0)
		return;
	length--;
	node* temp = head;
	head = head->next;
	free(temp);
	if(length==0)
		head = tail = NULL;
	else
		head->prev = NULL;

}
int front()
{
	if(length==0)
		return -1;
	return head->val;
}

int back()
{
	if(length==0)
		return -1;
	return tail->val;
}
void clear()
{
	while(head!=tail)
	{
		node* temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
	head=tail=NULL;
	length=0;
}

void readInput()
{
	int i;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",A + i);
}

void solve()
{
	int i;
	int min=0;
	for(i=1;i<=k;i++)
		if(A[i]<A[min])
			min = i;
	enqueue(min);
	for(i=min+1;i<=k;i++)
	{
		while(length>0)
			if(A[i]<A[back()]) dequeueBack();
			else break;
		enqueue(i);
	}
	if(k+1>n) printf("%d",A[front()]);
	else 	printf("%d ",A[front()]);
	
	for(i=k+1;i<=n;i++)
	{
		if(front()==i-k)
			dequeueFront();
		while(length>0)
			if(A[i]<A[back()]) dequeueBack();
			else break;
		enqueue(i);
		if(i==n)
			printf("%d",A[front()]);
		else
			printf("%d ",A[front()]);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	A[0]=1000000000;
	while(t--)
	{
		clear();
		readInput();
		solve();
		printf("\n");
	}
	return 0;
}
