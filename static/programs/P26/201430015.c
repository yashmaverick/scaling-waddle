#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	int level;
	struct node *next;
}node;
node *head[100000];
int iscomp[100000];
node *A[100000];

int visited[100000];

int Head=-1,Tail=-1;

void enqueue(node *x)
{
	if(Tail==100000)
	{
		return;
	}
	if(Head==-1)
	{
		Head++;
		Tail++;
		A[Head]=x;
	}
	else
	{
		Tail++;
		A[Tail]=x;
	}
}

node *dequeue()
{
	if(Head==-1)
	{
		return NULL;
	}
	node *x;
	x=A[Head];
	Head++;
	return x;
}


int seive()
{
	int i,n,j;
	for(i=2;i<10000;i++)
	{
		if(iscomp[i]==0)
		{
			for(j=i*i;j<10000;j+=i)
			{
				iscomp[j]=1;
			}
		}
	}
	iscomp[1]=1;
	return 0;
}
void insert(int y,int x)
{
	node *p;
	p=(node *)(malloc(sizeof(node)));
	p->value=x;
	p->level=0;
	p->next=NULL;
	if(head[y]==NULL)
	{
		head[y]=p;
		return;
	}
	else
	{
		p->next=head[y];
		head[y]=p;
	}
}
void create(int n)
{
	int x,y,z,i,t;
	x=n/10;
	for(i=1;i<=9;i+=2)
	{
		t=10*x+i;
		if((!iscomp[t])&&(t!=n))
		{
			insert(n,t);
		}
	}
	x=n/100;
	y=n%10;
	for(i=0;i<=9;i++)
	{
		t=x*100+10*i+y;
		if((!iscomp[t])&&(t!=n))
		{
			insert(n,t);
		}
	}
	x=n/1000;
	y=n%100;
	for(i=0;i<=9;i++)
	{
		t=x*1000+i*100+y;
		if((!iscomp[t])&&(t!=n))
		{
			insert(n,t);
		}
	}
	y=n%1000;
	for(i=1;i<=9;i++)
	{
		t=i*1000+y;
		if((!iscomp[t])&&(t!=n))
		{
			insert(n,t);
		}
	}
}
void display(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}
int main()
{
	int i,j,test,x,y,ans,flag;
	node *temp,*p;
	seive();

	for(i=1009;i<=9999;i++)
	{
		if(!iscomp[i])
		{
			create(i);
		}
	}

	for(i=1009;i<=9999;i++)
	{
		if(!iscomp[i])
			insert(i,i);
	}
	scanf("%d",&test);
	while(test--)
	{
		flag=0;
		Head=-1;
		Tail=-1;
		scanf("%d %d",&x,&y);
		if(x==y)
		{
			printf("0\n");
			continue;
		}
		enqueue(head[x]);
		visited[x]=1;
		while(Head<=Tail)
		{
			temp=dequeue();
			if(temp->value==y)
			{
				flag=1;
				ans=temp->level;
				break;
			}
			p=temp;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				x=temp->value;
				if((visited[x]!=1)&&(!iscomp[x]))
				{
					head[x]->level=p->level+1;
					enqueue(head[x]);
					visited[x]=1;
				}
			}
		}			

		if(flag==1)
		{
			printf("%d\n",ans);
		}
		else 
		{
			printf("Impossible\n");
		}
		Head=-1;
		Tail=-1;
		for(j=1;j<10000;j++)
		{
			visited[j]=0;
		}
		for(i=1009;i<=9999;i++)
		{
			if(!iscomp[i])
			{
				head[i]->level=0;
			}
		}
	}
	return 0;
}
