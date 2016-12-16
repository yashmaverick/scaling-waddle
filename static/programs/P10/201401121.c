#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int front=0,tail=0;
int x=0,y=0;
typedef struct node
{
	char b[101];
}node;
node *a;
void enq(int n)
{
	
	scanf("%s",a[tail].b);
	if(front==tail&&x==y)
	{
		tail=(tail+1)%n;
		y++;

	}
	else if(front==tail&&x!=y)
	{
		front=(front+1)%n;
		tail=(tail+1)%n;
		x++;
		y++;
	}
	else
	{
		tail=(tail+1)%n;
		y++;
	}
}
void deq(int n)
{
	if(x==y)
		return ;
	else
	{
		front=(front+1)%n;
		x++;
	}
}
/*void top(int n)
{
	if(x==y)
		cout<<"Queue is empty\n";
	else
	cout<<a[front]<<" ";
}*/

void print(int n)
{
	if(x==y)
	{
		return ;
	}
	else
	{
		int m=0;
		int i;
		for( i=front;m<y-x;i=(i+1)%n)
		{
			printf("%s\n",a[i].b);
			m++;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	a=malloc(sizeof(node)*n);
	char b;
	b=getchar();
	char c;
	do
	{
		c=getchar();
		if(c=='A')
		{
			int e;
			scanf("%d",&e);
			int i=0;
			for(;i<e;i++)
				enq(n);
		}
		else if(c=='R')
		{

			int e;
			scanf("%d",&e);
			int i=0;
			for(;i<e;i++)
				deq(n);
		}
		else if(c=='L')
		{
			print(n);
		}
		b=getchar();
	}while(c!='Q');
	return 0;
}



	
			



		
		



	
