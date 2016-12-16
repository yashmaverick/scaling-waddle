#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	int step;
}Node;
int prim[10000];
Node a[10000],t1,t2;
int front=0;
int rear=0;
int visit[10000];
void enqueue(Node data)
{
	a[rear]=data;
	rear++;
}
Node dequeue()
{
	return a[front++];
}
/*int cal(int d)
{
	if(prim[t1.data]==0 && !visit[t1.data])
	{
		t1.step = t2.step + 1;
		if(t1.data == d)
			return t1.step;
		visit[t1.data] = 1;
		enqueue(t1);
	}
	return 0;
}*/
int check()
{
	return (prim[t1.data]==0 && visit[t1.data]==0)?1:0;
}
int BFS(int s,int d)
{
	front = rear = 0;
	t1.data = s;
	t1.step = 0;
	visit[s] = 1;
	enqueue(t1);
	while(front != rear)
	{
		t2 = dequeue();
		int i;
		for(i = 1;i < 10;i++)
		{
			t1.data = t2.data - t2.data%10 + i;
			//return cal(d);
			if(check())
			{
				t1.step = t2.step + 1;
				if(t1.data == d)
					return t1.step;
				visit[t1.data] = 1;
				enqueue(t1);
			}
		}
		for(i = 0;i < 10;i++)
		{
			t1.data = t2.data - t2.data%100 + i*10 + t2.data%10;
			//return cal(d);
			if(check())
			{
				t1.step = t2.step + 1;
				if(t1.data == d)
					return t1.step;
				visit[t1.data] = 1;
				enqueue(t1);
			}	
		}
		for(i = 0;i < 10;i++)
		{
			t1.data = t2.data - t2.data%1000 + i*100 + t2.data%100;
			//return cal(d);
			if(check())
			{
				t1.step = t2.step + 1;
				if(t1.data == d)
					return t1.step;
				visit[t1.data] = 1;
				enqueue(t1);
			}	
		}
		for(i = 1;i < 10;i++)
		{
			t1.data = t2.data - t2.data%10000 + i*1000 + t2.data%1000;
			//return cal(d);
			if(check())
			{
				t1.step = t2.step + 1;
				if(t1.data == d)
					return t1.step;
				visit[t1.data] = 1;
				enqueue(t1);
			}
		}
	}
	return -9;   
}
void Makeprime()
{	
	int i,j;
	prim[0]=prim[1]=1;
	for(i=2;i<10000;i++)
	{       
		if(prim[i]==0)
		{
			for(j=2;i*j<10000;j++)
			{
				prim[i*j]=1;	
			}
		}
	}
}
int main()
{
	int s,d,n,x,t,i,j;
	Makeprime();
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&s,&d);
		t1.data=0;
		t2.data=0;
		t1.step=0;
		t2.step=0;
		front=0;
		rear=0;
		if(s==d)
			printf("0\n");
		else
		{
			printf("%d\n",BFS(s,d));
			for(i=0;i<10000;i++)
			{
				visit[i]=0;
			}
		}
	}
	return 0;
}
