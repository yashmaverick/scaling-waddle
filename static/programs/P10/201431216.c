#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
int rear=-1;
void enque(char a[][101],int num,int n)
{
	//printf("enque-> top is %d and rear is %d\n",top,rear);	
	int j;
	char str[101];
	for(j=0;j<num;j++)
	{
		if(rear==-1 )
		{

			top=0;
			rear=0;
		}
		else
		{
			if(top==n-1)
			{
				top=0;
			     
			}
			else if(top!=n-1)
			{
			   top=(top+1)%n;
			}
		        if(top==rear)
			{
				rear=(rear+1)%n;
			}
		}

	scanf("%s",str);
	strcpy(a[top],str);
	}
	return;
}
void deque(int num,int n)
{
	//printf("deque-> top is %d and rear is %d\n", top, rear);
	int j;
	for(j=0;j<num;j++)
	{
		if(rear==-1)
			return;
		if(top==rear)
		{
			top=-1;
			rear=-1;
			return;
		}
		else
			if(rear==n-1)
				rear=0;
			else
				rear=(rear+1)%n;
	}
	return;
}
void display(char a[][101],int n)
{
	//printf("display-> top is %d and rear is %d\n", top, rear);
	int j;
	if(top==-1 && rear==-1)
		return ;
	else
	{
		for(j=rear;j!=top;j=(j+1)%n) {
			//printf("Hello\n");
		printf("%s\n",a[j]);
	 }
	 printf("%s\n",a[j]);
	}
	return;
}
int main()
{
	int num,n;
	scanf("%d",&n);
	char a[10010][101],ch;
	getchar();
	if(n!=0)
	{
		while(1)
		{

		scanf("%c",&ch);
		if(ch=='A')
		{
			scanf("%d",&num);
			enque(a,num,n);
		}
		if(ch=='R')
		{

			scanf("%d",&num);
			deque(num,n);

		}
		if(ch=='L')
		{	

			display(a,n);
		}
		if(ch=='Q')
		{
			break;

		}
                   getchar();
		}
	}
	return 0;
}
