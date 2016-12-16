#include<stdio.h>
#include<stdlib.h>
int prime[10000];

typedef struct node
{
	int data;
	struct node * next;
}node;
node * a[10000];
int q[10000],head=1,tail=0,inq[10000];
int level[10000];
int bfs(int x,int y)
{
	node *newnode;
	tail++;
	q[tail]=x;
	inq[x]=1;
	level[x]=0;
	if(x==y)
		return 0;
	while(head<=tail)
	{
		newnode=a[q[head]]->next;
		while(newnode!=NULL)
		{
			if(inq[newnode->data]!=1)
			{
				if(newnode->data==y)
					return level[q[head]]+1;
				inq[newnode->data]=1;
				tail++;
				q[tail]=newnode->data;
				level[newnode->data]=level[q[head]]+1;
			}
			newnode=newnode->next;
		}
		head++;
	}
	return -1;
}

int main()
{
	int i,q,r,j,t,x,y;
	node * newnode;
	//cieve
//		printf("a\n");
	for(i=2;i<=10000;i++)
	{
		if(prime[i]==0)
		{
//		printf("a\n");
			if(i>1000)
				a[i]=(node *)malloc(sizeof(node));
			for(j=2*i;j<=10000;j+=i)
				prime[j]=1;
		}
	}
	for(i=1000;i<=9999;i++)
	{
	//		printf("%d\n",i);
		if(prime[i]==0)
	//	i=1259;
		{
	//		printf("%d\n",i);
			//1000
			q=i;
			y=q/1000;
			r=q%1000;
			//printf("%d\n",r);
			for(j=1000;j<=9000;j+=1000)
			{
				if(prime[j+r]==0&&(j+r)!=i)
				{
					newnode=(node *)malloc(sizeof(node));
					newnode->data=j+r;
					newnode->next=a[i]->next;
					a[i]->next=newnode;
				}
			}
	//	printf("a\n");
			//100
			q=i;
			r=i%100;
			y=(i%1000)/100;
			x=i/1000;
			x=x*1000+r;
			//printf("%d\n",y);
			for(j=0;j<=900;j+=100)
			{
				if(prime[j+x]==0&&(j+x)!=i)
				{
					newnode=(node *)malloc(sizeof(node));
					newnode->data=j+x;
					newnode->next=a[i]->next;
					a[i]->next=newnode;
				}
			}
	//	printf("a\n");
			//10
			q=i;
			x=i/100;
			r=i%10;
			y=(i%100)/10;
			x=r+x*100;
			//printf("%d\n",x);
			for(j=0;j<=90;j+=10)
			{
				if(prime[j+x]==0&&(j+x)!=i)
				{
					newnode=(node *)malloc(sizeof(node));
					newnode->data=j+x;
					newnode->next=a[i]->next;
					a[i]->next=newnode;
				}
			}
			//1
			q=i;
			x=q/10;
			r=q%10;
			x=x*10;
			//printf("%d\n",x);
			for(j=0;j<=9;j++)
			{
				if(prime[j+x]==0&&(j+x)!=i)
				{
					newnode=(node *)malloc(sizeof(node));
					newnode->data=j+x;
					newnode->next=a[i]->next;
					a[i]->next=newnode;
				}
			}
		}
	}
/*	for(i=1000;i<=9999;i++)
	{
		if(prime[i]==0)
		{
			printf("i %d\n",i);
			newnode=a[i]->next;
			while(newnode!=NULL)
			{
				printf("%d ",newnode->data);
				newnode=newnode->next;
			}
			printf("\n");
		}
	}*/
/*	for(i=1000;i<=9999;i++)
	{
		if(prime[i]==0)
			printf("%d ",i);
	}
	printf("\n");*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		if(x>y)
		{
			r=x;
			x=y;
			y=r;
		}//always x<y
		if(prime[x]!=0||prime[y]!=0)
			printf("Impossible\n");
		else
		{
			x=bfs(x,y);
		if(x==-1)
			printf("Impossible\n");
		else
			printf("%d\n",x);
		}
		for(i=1000;i<=9999;i++)
		{
			head=1;tail=0;
			inq[i]=0;
			level[i]=0;
		}
	}
	return 0;
}
