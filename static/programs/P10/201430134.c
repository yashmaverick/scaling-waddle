#include<stdio.h>
#include<stdlib.h>
struct q
{
	int size;
	int front;
	int rear;
	int capacity;
	char* array[10002];
};
typedef struct q* qp;
/*int check(int s,qp q1)
{
	if(s==q1->capacity)
	{
		return 0;
	}
	else
	{
		return s;
	}
}*/	
qp enque(char str[],qp q1)
{
	int i=0;
		q1->size++;
		if(q1->size>q1->capacity)
		{
			
			q1->size=q1->capacity;
			q1->front=q1->rear+1;
			free(q1->array[q1->rear]);
		}
		if(q1->size==1)
		{
			q1->front=q1->rear;
		}
		q1->array[q1->rear]=(char *)malloc(102*sizeof(char));
		while(str[i]!='\0')
		{
			q1->array[q1->rear][i]=str[i];
			i++;
		}
		q1->array[q1->rear][i]='\0';
		q1->rear++;
		q1->rear=(q1->rear)%q1->capacity;
	
	return q1;
}
qp deque(qp q1)
{
	if(q1->size!=0)
	{
		q1->size--;
		free(q1->array[q1->front]);
		q1->front++;
		q1->front=(q1->front)%q1->capacity;
		/*if(q1->front==q1->rear)
		{
			q1->rear=0;
			q1->front=-1;
		}*/
	}
	else
	{
		return q1;
	}
	return q1;
}
void pri(qp q1)
{
	int i,t;
	t=q1->front;
	for(i=0;i<q1->size;i++)
	{
		printf("%s\n",q1->array[t]);
		t=(t+1)%q1->capacity;
	}
//	printf("\n");
}
int main()
{
	qp q1;
	q1=(qp)malloc(sizeof(struct q));
	q1->size=0;
	//q1->capacity=10000;
	q1->front=-1;
	q1->rear=0;
	int N,no,i,j,k;
	scanf("%d",&N);
	q1->capacity=N;
	char com,x;
	char str[102];
	scanf(" %c",&com);
	//printf("%d",x);
	while(com!='Q')
	{
		if(com=='A')
		{
			scanf("%d",&no);
			//printf("no=%d x=%d\n",no,x);
			for(i=0;i<no;i++)
			{
				scanf("%s",str);
				q1=enque(str,q1);
			}
		}
		else if(com=='R')
		{
			scanf("%d",&no);
			//printf("%c",x);
			for(i=0;i<no;i++)
			{
				q1=deque(q1);
			}
		}
		else 
		{
			pri(q1);
		}
		scanf(" %c",&com);
		//printf("%c",x);
	}
	return 0;
}


