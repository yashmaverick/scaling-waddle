#include <stdio.h>
#include <stdlib.h>

#define s(n) scanf("%d",&n)

typedef struct node
{
	char st[101];
	struct node *next;
}n;

n *front,*rear,*temp;
int nn;
int count = 0;
void initialise()
{
	front = rear = NULL;
}

void display()
{
	if(count!=0)
	{
		n *tf;
		tf = front;
		if ((tf == NULL) && (rear == NULL))
			return;
		while (tf != rear)
		{
			printf("%s\n", tf->st);
			tf = tf->next;
		}
		if (tf == rear)
			printf("%s\n", tf->st);
	}
	else 
		return;
}

void enq(char *st);

void deq();


int main()
{
	int no;
	initialise();
	scanf("%d",&nn);
	if(nn==0)
		return 0;
	char y;
	int f=1;
	char l[101];
	while (f)
	{
		//		printf("COUNT = %d\n",count);
		scanf("%c",&y);
		if(y=='A')
		{
			s(no);
			while(no--)
			{
				scanf("%s",l);
				enq(l);
			}
		}
		else if(y=='R')
		{
			s(no);
			while(no--)
				deq();
		}
		else if(y=='L')
			display();
		else if(y=='Q')
			f=0;
	}
	return 0;
}

/* Enqueing the queue */

void enq(char *x)
{
	int i;
	if(count < nn)
	{
		if (rear == NULL)
		{
			rear = (n*)malloc(sizeof(n));
			rear->next = NULL;
			for(i=0;x[i]!='\0';i++)
				rear->st[i] = x[i];
			rear->st[i]='\0';
			front = rear;
		}
		else
		{
			temp=(n*)malloc(sizeof(n));
			rear->next = temp;
			// run a for loop here if strings cannot be assigned

			for(i=0;x[i]!='\0';i++)
				temp->st[i] = x[i];
			temp->st[i]='\0';
		//	temp->next = front;
			if(count!=nn-1)
				temp->next = NULL;
			rear = temp;
		}
		count++;
		if(count==nn)
			rear->next=front;
	}
	else 
	{
		temp=(n*)malloc(sizeof(n));
		for(i=0;x[i]!='\0';i++)
			temp->st[i]=x[i];
		
			temp->st[i]='\0';
		n *t2;
		t2 = front;
		front=rear->next->next;
		rear->next = temp;
		temp->next = front;
		free(t2);
		rear=temp;
	}

//debug	printf("count=%d \n",count);
}

/* Dequeing the queue */

void deq()
{
	if(count>0)
	{
		n *tf;
		tf = front;

		if (tf == NULL)
			return;
		else
		{
			if (tf->next == NULL)
			{
				front->st[0]='\0';
				free(front);
				front = NULL;
				rear = NULL;
			}
			else
			{
				tf = tf->next;
				front->st[0]='\0';
				free(front);
				front = tf;
				if(count==nn)
					rear->next=NULL;
			}
			count--;
			if(count<0)
				count=0;
		}
	}
	//	else
	//		return;
}
