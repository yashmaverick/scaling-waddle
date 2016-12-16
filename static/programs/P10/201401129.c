#include<stdio.h>
#include<string.h>

struct circularQueue
{
	char data[100];
};

typedef struct circularQueue cq;

int n , head = -1 , tail = -1;

void push ( cq a[1000] )
{
	int app , i;
	char x[100];
	scanf("%d\n",&app);
	for ( i = 0 ; i < app ; i ++ )
	{
		scanf("%s",x);
		if ( head == -1 )
			head = tail = 0;
		else if ( (head+1)%n == tail )
		{
			head = (head+1)%n;
			tail = (tail+1)%n;
		}
		else
			head = (head+1)%n;
		strcpy(a[head].data,x);
	}
}

void pop ( cq a[1000] )
{
	int app , i;
	scanf("%d",&app);
	for ( i = 0 ; i < app ; i ++ )
	{
		if ( head == tail )
			head = tail = -1;
		else
			tail = (tail+1)%n;
	}
}

void load ( cq a[1000] )
{
	int i;
	if ( head >= tail && head != -1)
	{
		for ( i = tail ; i <= head ; i ++ )
			printf("%s\n",a[i].data);
		//printf("head:%d tail:%d\n",head,tail);
	}
	else if ( head != -1 )
	{
		for ( i = tail ; i <= n-1 ; i ++ )
			printf("%s\n",a[i].data);
		for ( i = 0 ; i <= head ; i ++ )
			printf("%s\n",a[i].data);
		//printf("head:%d tail:%d\n",head,tail);
	}
}


int main ()
{
	char ch;
	cq a[1000];
	scanf("%d",&n);
	scanf("\n%c",&ch);
//	printf("%c",ch);
	while ( ch != 'Q' ) 
	{
//		printf("YES\n");
//		scanf("%c",&ch);
		switch (ch)
		{
			case 'A':
				push ( a );
				break;
			case 'R':
				pop ( a );
				break;
			case 'L':
				load ( a );
				break;
		}
		scanf("%c",&ch);
	}
	return 0;
}
		

