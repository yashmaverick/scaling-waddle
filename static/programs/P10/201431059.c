#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char str[101];
	struct node* next;
} node;

int N;
int size;
node* head;
node* tail;

node* createCircularBuff(int n)
{
	node* head;
	head = (node*)malloc(sizeof(node));
	int i;
	node* it = head;
	for(i=1;i<n;i++)
	{
		it->next = (node*)malloc(sizeof(node));
		it = it->next;
	}
	it->next = head;
	return head;
}

void addElem(int n)
{
	int i;
	int state = 0;
	if(size + n > N)
	{
		state = 1;
		size = N;
	}
	else
		size+=n;
	for(i=0;i<n;i++)
	{
		scanf("%s",tail->str);
		tail = tail->next;
	}
	if(state)
		head = tail;
}

void removeElem(int n)
{
	int i;
	size-=n;
	for(i=0;i<n;i++)
		head = head->next;
}

void print()
{
	node* it = head;
	int i;
	for(i=0;i<size;i++)
	{
		printf("%s\n",it->str);
		it = it->next;
	}
}

int main()
{
	scanf("%d",&N);
	size = 0;
	head = createCircularBuff(N);
	tail = head;
	char check = 'S';
	while(check!='Q')
	{
		scanf("%c",&check);

		switch(check)
		{
		case 'A':{
				 int n;
				 scanf("%d",&n);
				 addElem(n);
				 break;
			 }
		case 'R':{
				 int n;
				 scanf("%d",&n);
				 removeElem(n);
				 break;
			 }
		case 'L':{
				 print();
				 break;
			 }
		default:
			 continue;
		}
	}
	return 0;
}
