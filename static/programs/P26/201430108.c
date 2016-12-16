#include<stdio.h>
#include<stdlib.h>
struct node{
    int num;
    int distance;
    int visited;
    struct node * next;
}*head;
typedef struct node node;
node * a[100001];
int vis[100001],dist[100001],k;
int s[100001];
void sieve()
{	
	int i,j;
	for(i=0;i<=9999;i++)
		s[i]=1;
		for(i=4;i<=9999;i+=2)
				s[i]=0;
		for(i=3;i<=9999;i+=2)
				for(j=2*i;j<=9999;j+=i)
					s[j]=0;
}
void insert(int i,int j)
{
		node *temp1;
		temp1=malloc(sizeof(node));
		temp1->num=j;
		temp1->next=a[i];
		a[i]=temp1;
}
void graph()
{
	int i,j;
	for(i=1001;i<=9999;i+=2)
	{
		if(s[i]==1)
			{
				for(j=i+2;j<=9999;j+=2)
					{
						if(s[j]==1)
						{
										if(i%1000==j%1000)
												{
													insert(i,j);
													insert(j,i);
												}
										else if(i/1000==j/1000&&i%100==j%100)
												{
													insert(i,j);
													insert(j,i);
												}
										else if(i/100==j/100&&i%10==j%10)
												{
													insert(i,j);
													insert(j,i);
												}
										else if(i/10==j/10)
												{
													insert(i,j);
													insert(j,i);
												}
						}
					}
			}
	}
}
int q[100001],start=0,end=0;
void push(int k)
{
		q[end]=k;
		end++;
		return;
}

void pop()
{
		start++;
		return;
}
void cost(int s,int t)
{
		node *temp;
		temp=a[s];
		temp->distance=0;
		temp->visited=1;
		if(t==s)
		{
				printf("0\n");
				return;
		}
		push(s);
		int i;
		while(start!=0||end!=0)
		{
				node *temp=a[q[start]];
				while(temp!=NULL)
				{
						if(temp->num==t)
						{		node* temp3=a[q[start]];
								printf("%d\n" ,(temp3->distance+1));
								return;
						}
						node* temp2=a[temp->num];
						if(temp2->visited==0)
						{
								push(temp->num);
								temp2->visited=1;
								node* temp3=a[q[start]];
								temp2->distance=temp3->distance+1;
						}
						temp=temp->next;
				}
				pop();
		}
		printf("Impossible\n");
		return;
}
void initial()
{
	start=0;
	end=0;
		int i;
		for(i=1001;i<=9999;i++)
		{
				node *temp;
				temp=a[i];
				if(temp!=NULL)
				{
					temp->visited=0;
					temp->distance=-1;
				}
		}
}
int main()
{	
	
	int i;
	for(i=1000;i<=9999;i++)
				a[i]=NULL;
	sieve();
	graph();
	int t;
	scanf("%d",&t);
	while(t--)
	{	initial();
		int source,target;
		scanf("%d%d",&source,&target);
		cost(source,target);
	}
	return 0;
}