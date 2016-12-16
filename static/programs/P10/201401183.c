#include<stdio.h>
#include<string.h>
char a[10009][109];
int n,front=-1,rear=-1;
void A(int ap)
{
	char s[109];
	while(ap--)
	{
		scanf("%s",s);
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==n-1)
		{
			rear=0;
			if(front==0)
				front=rear+1;
		}
		else if(front==rear+1)
		{
			rear=rear+1;
			if(front==n-1)
				front=0;
			else
			front=front+1;
		}
		else rear=rear+1;
		strcpy(a[rear],s);
	//	printf("front:%d  rear:%d\n",front,rear);
	}
}
void R(int r)
{
	while(r--)
	{
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==n-1)
		front=0;
	else front=front+1;
//	printf("front:%d  rear:%d\n",front,rear);
	}
}
void L()
{
	int i,j;
	if(front>rear)
	{
	for(i=front;i<n;i++)
		printf("%s\n",a[i]);
	for(i=0;i<=rear;i++)
		printf("%s\n",a[i]);
	}
	else
	{
		if(front!=-1&&rear!=-1)
		for(i=front;i<=rear;i++)
			printf("%s\n",a[i]);
	}
}
int main()
{
	int ap,r,i,j;
	char ch;
	scanf("%d",&n);
	while(ch!='Q')
	{
		getchar();
		scanf("%c",&ch);
		if(ch=='A')
		{
			scanf("%d",&ap);
			A(ap);
		}
		else if(ch=='R')
		{
			scanf("%d",&r);
			R(r);
		}
		else if(ch=='L')
		L();
		else break;
	}
	return 0;
}
