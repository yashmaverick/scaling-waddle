#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[10005][105];
int front=-1;
int rear=-1;
int n;
void push(char temp[10005][105],int l)
{
	int i=0;
	if((front==-1)&&(n!=0))
	{
		rear=0;
		front=(front+1)%n;
		strcpy(str[front],temp[i]);
		i++;
	
	}
	
	while((i<l)&&(n!=0))
	{

		front=(front+1)%n;
		strcpy(str[front],temp[i]);

		if((front)%n==rear)
			rear=(rear+1)%n;
		i++;
	}

}
void removeq(int l)
{
	int i;
	if((n==0)||(l==0))
		return;

	if((rear+l-1)%n==front)
	{
		rear=-1;
		front=-1;
	}
	else
		rear=(rear+l)%n;
	

}
void printq()
{
	int i,j=0,flag=0;
	i=rear;
	if(rear==-1)
		return;
	while(flag!=1)
	{
              printf("%s\n",str[i]);
	      if(i==front)
		      flag=1;
	      i=(i+1)%n;
		
	}
}
int main ()
{
	int j,k,l,m,i;
	char a[5],temp[10005][105];
	a[0]='l';
	scanf("%d\n",&n);
	while(a[0]!='Q')
	{
		scanf("%s",a);
		if(a[0]=='A')
		{
		        scanf("%d",&k);
			
			for(i=0;i<k;i++)
				scanf("%s",temp[i]);
			push(temp,k);
		}
		else if(a[0]=='L')
		{
			printq();

		}
		else if(a[0]=='R')
		{
			scanf("%d",&k);
			removeq(k);
		}


	}

	return 0;
}

