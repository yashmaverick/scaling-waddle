#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int front=0;
int rear=0, count=0;
int size,n;
//char q[10000][104];

struct ins{
	char s[104];
};
struct ins arr[10000];
void enq()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[rear++].s);
		count++;
		/*if((rear+1)%size==front)
		{
			front=(front+1)%size;
		}*/
		//rear=(rear+1)%size;
		rear%=size;
		if(count>size)
		{
			count=size;
			front++;
			front%=size;
		}
	}
}	
void deq()
{
	int i;
	scanf("%d",&n);
	if(n>count)
		n=count;
	count=count-n;
	front=(front+n)%size;
}
void disp()
{
	int i;
	bool condition=true;
	for(i=front;(condition && (count>0))||(i!=rear);)
	{
		condition=false;
		printf("%s\n",arr[i].s);
		i++;
		i%=size;
	}
	/*if(front>rear)
	{
		for(i=front;i<size;i++)
		{
			printf("%s",arr[i].s);
			printf("\n");
		}
		for(i=0;i<=rear;i++)
		{
			printf("%s",arr[i].s);
			printf("\n");
		}

	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%s",arr[i].s);
			printf("\n");
		}
	}*/
}

	int main()
	{
		int n,i,k=0;
		scanf("%d",&size);
		char c;
		//struct inst arr[10000];
		while(1)
		{
			scanf("%c",&c);
			if(c=='A')
			{
				enq();
			}
			if(c=='R')
			{
				deq();
			}
			if(c=='L')
			{
				disp();
			}
			if(c=='Q')
			{
				break;
			}
		}
		return 0;
	}


