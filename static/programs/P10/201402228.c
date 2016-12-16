#include<stdio.h>
#include<string.h>
char q[10000][100];
char a[100];
int head=-1;
int tail=-1;
int n;
int flag=0;
int i;
void push(char *val)
{
	if(head==-1)
		head=0;
	tail=(tail+1)%n;
strcpy(q[tail],val);
	//printf("%d\n",q[tail]);
}

void pop()
{
	head=(head+1)%n;
}
int main()
{
	int m,j;
	scanf("%d",&n);
	while(1)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='A')
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				scanf("%s",a);
				//printf("%d ",a[i]);
			
		//	for(i=0;i<m;i++)
			
				if(head==tail)
					push(a);
				else if(head>tail)
				{
					flag=1;
					push(a);
					if(head==tail)
					{
						head=(head+1)%n;
						if(head==0)
							flag=0;
					}
				}
				else if(head<tail)
				{
					flag=0;
					push(a);
					if(head==tail)
						head=(head+1)%n;
				}
			

		}}
		else if(ch=='R')
		{

			scanf("%d",&m);
			if(m==n)
			{
				head=-1;
				tail=-1;
			}
			for(i=0;i<m;i++)
			{
				if(head==tail)
				{
					if(head==-1)
						continue;
					pop();
					head=-1;
					tail=-1;
				}
				else if(head>tail)
				{
					pop();
				}
				else if(head<tail)
				{
					pop();
					//if(head==tail)
					//	head=(head+1)%n;
				}
			}

		}
		else if(ch=='L')
		{
			if(head==tail)
			{
				if(tail==-1)
					continue;
				else
				{
					printf("%s\n",q[head]);
				}
			}
			else
			{
				j=head;
				while(j!=tail)
				{
					printf("%s\n",q[j]);
					j=(j+1)%n;
				}
				printf("%s\n",q[tail]);
			}
		}
		else if(ch=='Q')
			break;


	}
	return 0;
}






