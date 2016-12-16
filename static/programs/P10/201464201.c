#include<stdio.h>
#include<string.h>
int front,rare,count=0;
char que[10005][105];
int enqueue(char s[],int cap)
{
	if(count<cap)
	{
		count++;
	}
	if(rare==front && rare==-1)
	{
		rare=(rare+1)%cap;
		front=(front+1)%cap;
		strcpy(que[rare],s);
	}
	else
	{
		rare=(rare+1)%cap;
		strcpy(que[rare], s);
	}
	if(front==rare && count!=1)
	{
		front=(front+1)%cap;
	}
	return front;
}
void dequeue(int cap)
{
	count--;
	if(count==0)
	{
		rare=front=-1;
	}
	else
	{
		front=(front+1)%cap;
	}
}

void print(int cap)
{
	int i,j;
	i=front;j=count;
	while(j>0)
	{
		printf("%s\n", que[i%cap]);
		i++;j--;
	}
}
int main()
{
	int k,i,x,cap,num;
	char n[3],str[100];
	front=rare=-1;
	int t=-10;
	n[0]='w';
	scanf("%d", &cap);
	while(n[0]!='Q')
	{
		scanf("%s",n);
		if(n[0]=='A')
		{
			scanf("%d", &num);
			for(i=0;i<num;i++)
			{
				scanf("%s", str);
				enqueue(str,cap);
			}
		}
		else if(n[0]=='R')
		{
			scanf("%d", &num);
			for(i=0;i<num;i++)
			{
				dequeue(cap);
			}

		}
		else if(n[0]=='L')
		{
			print(cap);
		}
		else if(n[0]=='Q')
		{
			break;
		}

	}
	return 0;
}
	
