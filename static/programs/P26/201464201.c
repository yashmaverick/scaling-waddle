#include<stdio.h>
#include<stdlib.h>
int reach[10006];
typedef struct linklist
{
	int data;
	struct linklist *next;
}node;
typedef struct queue
{
	int data;
	int height;
}q;
int front,rear;q *a[10005];
void enqueue(int k,int h)
{
	if(front==rear && front==-1)
	{
		front++;
		rear++;
		a[rear]=malloc(sizeof(q));
		a[rear]->data=k;
		a[rear]->height=h;
	}
	else
	{
		rear++;
		a[rear]=malloc(sizeof(q));
		a[rear]->height=h;
		a[rear]->data=k;
	}
}
void dequeue()
{
	if(front==rear && rear==-1)
	{
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}

}
void printlist(node *head[],int prime[])
{
	int i;
	for(i=1000;i<=9999;i++)
	{
		if(prime[i]==0)
		{
			node *p=head[i];
			while(p!=NULL)
			{
				printf("%d->",p->data);
				p=p->next;
			}
		}
	}
}
void print()
{
	int k;
	if(front==rear && front==-1)
	{
		return;
	}
	else
	{
		for(k=front;k<=rear;k++)
		{
			printf("%d->", a[k]->data);
		}
		printf("\n");
		for(k=front;k<=rear;k++)
		{
			printf("%d->", a[k]->height);
		}
		printf("\n");
	}
}


node *insert(node *head,int k)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=k;
	if(head==NULL)
	{
		head=p;
		return head;
	}
	else
	{
		p->next=head;
		head=p;
		return head;
	}
}
void dfs(node *q,node *head[])
{
	int i;
	reach[q->data]=1;
	while(q!=NULL)
	{
		if(reach[q->data]==0)
		{
			dfs(head[q->data],head);
		}
		q=q->next;
	}
}
int form_num(int x, int y, int z, int t)
{
	return (x*1000)+(y*100)+(z*10)+t;
}
void bfs(node *q,int n2,int height,node *head[])
{
	int flag=0;
	reach[q->data]=1;
	while(1)
	{
		while(q!=NULL)
		{
			if(reach[q->data]!=1)
			{
		//		printf("%d->", q->data);
				enqueue(q->data,height);
				reach[q->data]=1;
				if(q->data==n2)
				{
					flag=1;
					break;
				}
			}
			q=q->next;
		}
//	printf("\n");
		if(flag==1)
		{
			printf("%d\n", a[rear]->height+1);
			break;
		}
		if(front==-1)
		{
			printf("Impossible\n");
			break;
		}
		int temp=a[front]->data;
		int temp2=a[front]->height;
		dequeue();
		reach[temp]=1;
		if(temp==n2)
		{
			printf("%d\n", temp2+1);
			break;
		}
		if(front==-1)
		{
			printf("Impossible\n");
			break;
		}
		height=temp2+1;
		q=head[temp];
	}

}
int main()
{
	int num,s,x,y,z,t,e,n1,k,n2,numb[10000],p,q,i,j,test,prime[10000],tot,count,flag;
	node *head[10000];
	for(i=0;i<=10000;i++)
	{
		prime[i]=0;
	}k=0;
	for(p=2;p<=1000;p++)
	{
		if(prime[p]==0)
		{
			i=2;
			while(p*i<=10000)
			{
				prime[p*i]=1;
				i++;
			}

		}
	}k=0;
	for(i=1000;i<=9999;i++)
	{
		if(prime[i]==0)
		{
			numb[k]=i;
			tot=k;
			k++;
		}
	}
//	printf("%d\n", tot);
	front=-1;
	rear=-1;
	for(i=1000;i<=9999;i++)
	{
		head[i]=NULL;
	}
	for(k=0;k<tot;k++)
	{
		i=3;int dig[6],number=numb[k];
//		printf("-1");

		while(number!=0)
		{
			dig[i]=number%10;
			number=number/10;
			i--;
		}
		x=dig[0];y=dig[1];z=dig[2];t=dig[3];
		for(i=0;i<=3;i++)
		{    
			dig[0]=x;dig[1]=y;dig[2]=z;dig[3]=t;
			dig[i]=0;
			while(dig[i]<=9)
			{
				num=form_num(dig[0], dig[1], dig[2], dig[3]);
				//              printf("%d\n", num);
				if(num!=numb[k] && prime[num]==0 && num>=1000)
				{
			//		printf("%d ", num);
					head[numb[k]]=insert(head[numb[k]],num);
				}
				dig[i]++;

				//                      print();
			}

		}
	}
	for(i=1000;i<=9999;i++)
	{
		head[i]=insert(head[i],i);
	}
//	printlist(head,prime);
	scanf("%d", &test);
	for(s=0;s<test;s++)
	{
		front=-1;
		rear=-1;
		for(i=1000;i<9999;i++)
		{
			reach[i]=0;
		}
		scanf("%d", &n1);
		scanf("%d", &n2);
		if(n1==n2)
		{
			printf("0\n");
		}
		else
		{
			bfs(head[n1],n2,0,head);
		}
	}
	return 0;
}


