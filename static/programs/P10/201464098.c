#include<stdio.h>
#include<string.h>
#define gi(x) scanf("%d",&x);
int size,rear=-1,front=-1;
void print(char a[size][102]);
void delete();
void insert(char a[size][102]);
int main()
{
	gi(size);
	char a[size][102];
	char ssss=getchar();
	char ch;
	do
	{
		scanf("%c",&ch);
		switch(ch)
		{
			case 'A':insert(a);
					 break;
			case 'R':delete();
					 break;
			case 'L':print(a);
					 break;
			case 'Q':break;
		}
	}while(ch!='Q');
	return 0;
}
void insert(char a[size][102])
{
	int y,i,j;
	gi(y);
	char qq=getchar();
	for(i=0;i<y;i++)
	{

		char arr[101];
		scanf("%s",arr);
		char css=getchar();
		if(rear==-1)
		{
			rear=0;
			front=0;
		}
		else if(rear==size-1)
		{	rear=0;
			if(front==0)
			front=(front+1)%size;
		}
		else if(front>rear)
		{
			if((front-rear)==1)
			front=(front+1)%size ;
			rear++;
		}
		else
			rear=(rear+1)%size;
		int k=strlen(arr);
		for(j=0;j<k;j++)
			a[rear][j]=arr[j];
		a[rear][j]='\0';
		//printf("%d %d\n",front ,rear);
	}
}
void delete()
{
	int d,i;
	gi(d);
	for(i=0;i<d;i++)
	{
		if(front==rear)
		{
			front=-1;rear=-1;
		}
		else if(front==size-1)
		{
			front=0;
		}
		else
			front=(front+1)%size;
	}
}
void print(char a[size][102])
{
	if(front==-1 && rear==-1)
		return;
	int i,j=0;
	if(front>rear)
	{
				for(i=front;i<=size-1;i++)
		{
			for(j=0;a[i][j]!='\0';j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		for(i=0;i<=rear;i++)
		{
			for(j=0;a[i][j]!='\0';j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			for(j=0;a[i][j]!='\0';j++)
			printf("%c",a[i][j]);
			printf("\n");
		}
	}
}