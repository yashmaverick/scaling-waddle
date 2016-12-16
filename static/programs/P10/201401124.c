#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int front=-1;
int rear=-1;
void enque(char q[][100],char t[],int n)
{
	int i;
	if((front==-1)&&(rear==-1))
	{
		front++;
		rear++;
	}
	else if(front==(rear+1)%n)
	{
		front=(front+1)%n;
		rear=(rear+1)%n;
	}
	else
		rear=(rear+1)%n;
	//q[rear]=t;
	int len;
	len=strlen(t);
	for(i=0;i<len;i++)
	{
		q[rear][i]=t[i];
	}
	q[rear][i]='\0';


}
/*void prin(char q[][100])
  {
  int i=front,j;
  while(i!=rear)
  {
  for(j=0;q[i][j]!='\0';j++)
  {
  printf("%c",q[i][j]);
  }
  i=(i+1)%6;
  }

  for(j=0;q[rear][j]!='\0';j++)
  {
  printf("%c",q[rear][j]);
  }
  printf("\n");
  }*/
void del(char q[][100],int n)
{
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%n;
	}



}
int main()
{
	int n,i,j ;
	char c='J';
	char t[100];
	scanf("%d",&n);
	char q[n][100];
	if(n!=0)
	{
		while(c!='Q')
		{
			scanf("%c",&c);
			if(c=='A')
			{
				scanf("%d",&i);
				for(j=0;j<i;j++)
				{
					scanf("%s",t);
					enque(q,t,n);
				}
				//printf("done\n");
			}
			if(c=='L')
			{
				//prin(q);
				if(front!=-1)
				{
				int i=front,j;
				while(i!=rear)
				{
					for(j=0;q[i][j]!='\0';j++)
					{
						printf("%c",q[i][j]);
					}
					printf("\n");
					i=(i+1)%n;
				}

				for(j=0;q[rear][j]!='\0';j++)
				{
					printf("%c",q[rear][j]);
				}
				printf("\n");
				}


			}
			if(c=='R')
			{
				scanf("%d",&i);
				for(j=0;j<i;j++)
					del(q,n);
				//printf("done\n");
			}
		}
	}
	return 0;

}
