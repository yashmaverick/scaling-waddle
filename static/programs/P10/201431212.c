#include<stdio.h>
#include<string.h>
char a[10001][101]={};
int front=-1,rear=-1;
int siz=0;
void insert(char b[],int no)
{
	if(siz==no)
		front=(front+1)%no;
		/*if(rear==(no-1))
		{
			rear=0;
			strcpy(a[rear],b);
			if(siz<no)
				siz++;
			else
				siz=no;
		}
		else
		{
			strcpy(a[++rear],b);	
			if(siz<no)
				siz++;
			else
				siz=no;
		}*/
	rear=(rear+1)%no;
	if(siz<no)siz++;else siz=no;
	strcpy(a[rear],b);
	if(siz==1)front=rear;
	return ;
}
void delete(int no)
{
	/*	if(front==rear)
		{
		front=-1;
		rear=-1;
		}  
		else
		{  */
	front=(front+1)%no;
	siz-=1;
	return ;
	//}
}
void print(int no)
{
	int j;
	/*if(front>rear)
	{
		for(j=front;j<=no-1;j++)
			printf("%s\n",a[j]);
		for(j=0;j<=rear;j++)
			printf("%s\n",a[j]);
	}
	else
	{
		for(j=front;j<=rear && siz!=0;j++)
			printf("%s\n",a[j]);
	}   */
	int i;
	for(i=front;i!=rear && siz!=0;i=(i+1)%no)
	{
		printf("%s\n",a[i]);
	}
	if(i==rear && siz!=0)
		printf("%s\n",a[i]);
	return ;
}
int main()
{
	int no,n,i,j;
	char c;
	char b[101]={};
	scanf("%d",&no);
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&n);			
			for(i=0;i<n;i++)
			{
				scanf("%s",b);
				insert(b,no);
			}
		}
		else if(c=='R')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
				delete(no);
		}
		else if(c=='L')
			print(no); 
		else if(c=='Q')
			break;
	}
	return 0;
}
