#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1000009];
int vis[1000009];
int q[1000009];
int dis[1000009],p[1000009];
void push(int x)
{
	if(rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=x;
	}
	else q[++rear]=x;
}
int pop()
{
	if(front==-1)
		return;
	else
	{
		return q[front++];
	}
}
void initial()
{
int i;
for(i=1009;i<=9973;i++)
{
	dis[i]=-1;
	vis[i]=0;
}
}
void sieve()
{
//	printf("hi\n");
	int i,j;
	for(i=0;i<=10002;i++)
		p[i]=i+2;
	for(i=0;i<=10002;i++)
	{
		if(p[i]!=-1)
		{
			for(j=2*p[i]-2;j<=9999;j=j+p[i])
				p[j]=-1;
		}
	}
}
void insert(int x,int y)
{
	node* temp=NULL;
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->next=NULL;
	if(a[x]!=NULL)
	{   
		temp=a[x]->next;
		new1->next=temp;
		a[x]->next=new1;
	}   
	else a[x]=new1;
	//new1->next=temp;
	//vice versa
/*	node* new2=malloc(sizeof(node));
	new2->val=x;
	new2->next=NULL;
	if(a[y]!=NULL)
	{
		temp=a[y]->next;
		new2->next=temp;
		a[y]->next=new2;
	}    
	else a[y]=new2;*/
}
int main()
{
	int po,flag,t,i,h,j,k,l,a1,x,y,b,m,n,arr[5];
	sieve();
//	printf("hi\n");
	//printf("%d\n",p[1007]);
	for(i=1009;i<=9973;i++)
	{	
//		printf("a\n");
		for(j=1009;j<=9973;j++)
			vis[j]=0;
		if(p[i-2]!=-1)
		{
//			printf("hi\n");
			j=3;
			while(j>=0)
			{
//				printf("b\n");
				h=i;
//				printf("1\n");
				for(k=0;k<=9;k++)
				{
//					printf("2\n");
					h=i;
					l=3;
					while(l>=0)
					{
//						printf("c\n");
//						printf("3\n");
						arr[l]=h%10;
						h/=10;
						l--;
					}
					arr[j]=k;
					m=3;
					po=1;
					n=0;
					while(m>=0)
					{
//						printf("4\n");
						n=n+arr[m]*po;
						po=po*10;
						m--;
					}
					if(n!=i&&vis[n]!=1&&p[n-2]!=-1&&n>=1009&&n<=9973)
					{	vis[n]=1;
					insert(i,n);}
		//			printf("%d %d\n",i,n);
				}
				j--;
			}
		}
	}
//	printf("hi\n");
	scanf("%d",&t);
/*	node* ml;
	ml=a[1033];
	while(ml)
	{
		printf("%d\n",ml->val);
		ml=ml->next;
	}*/
	while(t--)
	{
//		int a1,b,x,y;
		node* temp=NULL;
		initial();	
		front=-1;
		rear=-1;
		flag=0;
		scanf("%d%d",&a1,&b);
		dis[a1]=0;
		vis[a1]=1;
		push(a1);
		while(front<=rear&&front!=-1&&rear!=-1)
		{
//			printf("5\n");
			x=pop();
			temp=a[x];
			while(temp!=NULL)
			{
			//	printf("6\n");
				y=temp->val;
				if(vis[y]!=1)
				{
					push(y);
					vis[y]=1;
					dis[y]=dis[x]+1;
					if(y==b)
					flag=1;
				}
				if(flag==1)
					break;
				temp=temp->next;
			}
			if(flag==1)
				break;
		}
		if(dis[b]!=-1)
			printf("%d\n",dis[b]);
		else printf("Impossible\n");
		//dis[y]!=-1?printf("%d\n",dis[y]):printf("Impossible\n");
	}
	return 0;
}
