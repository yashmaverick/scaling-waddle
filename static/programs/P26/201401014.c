#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node node;
node *A[10000];
int shpath[10000],prime[10000],visited[10000],visit[10000];

void adj_list(int vi,int vj)
{
	node *temp;
	if(visit[vj]==0)
	{
		visit[vj]=1;
		temp=(node *)malloc(sizeof(node));
		temp->data=vj;
		temp->next=NULL;
		if(A[vi]==NULL)
			A[vi]=temp;
		else
		{
			temp->next=A[vi];
			A[vi]=temp;
		}
	}
}

void dfs(int i)
{
	node *t;
	visited[i]=1;
//	printf("%d-->",i);
	t=A[i];
	while(t!=NULL)
	{
		if(visited[t->data]==0)
			dfs(t->data);
		t=t->next;
	}
}

void seive()
{
	int i,n;
	n=2;
	for(n=2;n<5000;n++)
	{
//		printf("seive ");
		if(prime[n]==0)
		{
			i=2;
			while((i*n)<10001)
			{
				prime[i*n]=1;
				i++;
			}
		}
	}
//	printf("sieve ends\n");
}

int main()
{	
	int source,test,dest,i,k,num1,flag,num2,var_num,num,rear,z,front,deque[10000],pathlen[10000];
	node *curr;
	scanf("%d",&test);
	{
		flag=0;
		seive();
		for(k=1001;k<=9999;k++)
		{
			A[k]=NULL;
			visited[k]=0;
	//		shpath[k]=0;
		}
		for(i=0;i<=9999;i++)
			pathlen[i]=0;
		// making adj_list for all four digit numbers 
			for(k=1009;k<=9999;k=k+2)	
			{
				for(z=1009;z<=9999;z++)
					visit[z]=0;
				num=k;
				if(prime[k]==0)
				{
				//altering the last digit
					num1=k/10;
					num2=k%10;
					for(i=1;i<=9;i=i+2)
					{
						var_num=(10*num1)+i;
						if(prime[var_num]==0 && num!=var_num && visit[var_num]!=1)
							adj_list(num,var_num);
						
					}

				//altering the ten's place
					num1=k/100;
					num2=k%10;
					for(i=0;i<=9;i++)
					{
						var_num=(100*num1)+(10*i)+num2;
						if(prime[var_num]==0 && num!=var_num && visit[var_num]!=1)
							adj_list(num,var_num);
					}

				//altering the hundred's place
					num1=k/1000;
					num2=k%100;
					for(i=0;i<=9;i++)
					{
						var_num=(num1*1000)+(100*i)+num2;
						if(prime[var_num]==0 && num!=var_num && visit[var_num]!=1)
							adj_list(num,var_num);
					}
				
				//altering the thousand's place
					num2=k%1000;
					for(i=1;i<=9;i++)
					{
						var_num=(i*1000)+num2;
						if(prime[var_num]==0 && num!=var_num && visit[var_num]!=1)
							adj_list(num,var_num);
					}
				}
			}

			while(test--)
			{
				flag=0;
				for(k=0;k<=9999;k++)
				{
					visited[k]=0;
					pathlen[k]=0;
					deque[k]=0;
				}
				scanf("%d%d",&source,&dest);
				{
					{
						for(i=1000;i<=9999;i++)
							visited[i]=0;
						//finding the shortest path using bfs
						rear=0;
						front=0;
						pathlen[0]=0;
						deque[rear]=source;
							while(rear<=front)
						{
							curr=A[deque[rear]];
							visited[deque[rear]]=2;								
							while(curr!=NULL)	
							{
								if(visited[curr->data]==0)
								{
									visited[curr->data]=1;
									pathlen[front+1]=pathlen[rear]+1;
									deque[front+1]=curr->data;
									front++;
									if(curr->data==dest)
									{
										flag=1;
										break;
									}
								}
								curr=curr->next;
							}
							if(flag==1)
								break;
							rear++;
						}
						if(source!=dest)
						{
							if(visited[dest]!=0)
								printf("%d\n",pathlen[front]);	
							else
								printf("Impossible\n");
						}
						else 
							printf("0\n");
					}
				}

			} 
		}
	return 0;
}
