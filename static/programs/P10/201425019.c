#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char string[105];
string q[10001];
int N, front=-1, rear=-1;

void app()
{
	if(front == -1)
		front = rear = 0;
	else
	{
		if(rear == N-1)
			rear = 0;
		else
			rear++;
		if(rear == front)
			if(front == N-1)
				front = 0;
			else
				front++;
	}

	char word[100];
	scanf("%s",word);
	strcpy(q[rear] , word);
	return;
}

void del()
{
	if(front == -1)
		return;
	else
	{
		if(front == rear)
			front = rear = -1;
		else
		{
			if(front == N-1)
				front = 0;
			else
				front++;
		}   
	}
	return;
}


int main()
{
	char c ;
	int no;
	scanf("%d",&N);
	c='p';
	while(c!='Q')
	{

		scanf("%c", &c);
		if(c == 'A')
		{
			scanf("%d",&no);
			while(no)
			{
				app();
				no--;
			}
		}

		else if(c == 'R')
		{
			scanf("%d",&no);
			while(no)
			{
				del();
				no--;
			}
		}
		else if(c == 'L')
		{
			int i = front;
			if(front!=-1)
			{
				while(i != rear)
				{
					printf("%s\n",q[i]);
					i=(i+1)%N;
				}
				printf("%s\n",q[rear]);
			}

		}

	}
	return 0;
}
