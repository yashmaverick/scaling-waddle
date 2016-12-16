#include<stdio.h>
#include<string.h>
#define gi(x) scanf("%d\n",&x);
#define pi(x) printf("%s\n",x);
char a[10001][101]={};
int front=-1,rear=-1,size=0,flag[10001]={};
void print(int n)
{
	int i,s;
	s=front;
	for(i=0;i<size;i++)
	{
		pi(a[s]);
		s=(s+1)%n;
	}
	return ;
}
void insert(char *c,int n)
{
	if(size==n)front=(front+1)%n;
	rear=(rear+1)%n;
	strcpy(a[rear],c);
	flag[rear]=1;
	if(size<n)
		size++;
	else	
		size=n;
	if(size==1)
		front=rear;
	return ;
}
void delete(int n)
{
	front=(front+1)%n;
	size=size-1;
	if(size==0)
		rear=front;
	return ;
}
int main()
{
	int n,i,t,y;gi(n);
	char b[5]={},c[101]={};
	while(1)
	{	
		scanf("%s",b);
		if(b[0]=='Q')
			break;
		else if(b[0]=='A')
		{
			gi(t);
			for(i=0;i<t;i++)
			{
				scanf("%s",c);
				insert(c,n);
				//printf("%d %d %d\n",front,rear,size);
			}
		}
		else if(b[0]=='L')
		{
			print(n);
		}
		else if(b[0]=='R')
		{
			gi(y);
			for(i=0;i<y;i++)
			{
				delete(n);	
				//printf("%d %d %d\n",front,rear,size);
			}
		}
	}
	return 0;
}
