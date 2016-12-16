#include<stdio.h>
#include<stdlib.h>
int visited[1005];
struct node{
	int data;
	struct node* next;
};
struct node* graph[1005];
struct node* graph1[1005];
int count=0;
void insert(int i, int val)
{
	int k;
	struct node *temp2;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	if (graph[i] == NULL)
	{
		temp->next = NULL;
		graph[i] = temp;
	//	printf("%d", temp->data);
	}
	else
	{
		temp->next = graph[i];
		graph[i] = temp;
	//	printf("%d", temp->data);
	}
}
void insert1(int i, int val)
{
	int k;
	struct node *temp2;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	if (graph1[i] == NULL)
	{
		temp->next = NULL;
		graph1[i] = temp;
	//	printf("%d", temp->data);
	}
	else
	{
		temp->next = graph1[i];
		graph1[i] = temp;
	//	printf("%d", temp->data);
	}
}

void dfs(int root)
{
	visited[root] = 1;
	struct node* temp;
	count++;
	temp = graph[root];
	//	printf("root :: %d\n", temp->data);
	while (temp != NULL)
	{
		if (visited[temp->data] != 1)
			dfs(temp->data);
		temp = temp->next;
	}
}
void dfs1(int root)
{
	visited[root] = 1;
	struct node* temp;
	count++;
	temp = graph1[root];
//		printf("root :: %d\n", temp->data);
	while (temp != NULL)
	{
		if (visited[temp->data] != 1)
			dfs1(temp->data);
		temp = temp->next;
	}
}
void print(int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        struct node* temp=graph[i];
        while(temp)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
	int test, h, i,j, V, number, t, temp,temp1;
	scanf("%d", &test);

	for (h = 0; h < test; h++)
	{
		scanf("%d", &V);
		for (i = 1; i <= V; i++)
		{
			graph[i] = NULL;
                        graph1[i]=NULL;
		}
		for (i = 1; i <= V; i++)
		{

			scanf("%d", &number);
			for (t = 1; t <= number; t++)
			{
				scanf("%d", &temp);
				insert(temp,i);
				insert1(i, temp);
			}
		}
		
                int f=0;
		//dfs(1);
		for(i=1;i<=V;i++)
		{
			count=0;
			for(j=1;j<=V;j++)
				visited[j]=0;
			dfs(i);
			if(count==V)
				{
					temp1=i;
                                        f=1;
					break;
				}

				
		}
             //   printf("broken at\n%d",temp1);
                
                if(i==V+1)
                  printf("0\n");
                else{
		for(j=1;j<=V;j++)
			visited[j]=0;
		count=0;
		dfs1(temp1);
           
		    printf("%d\n", count);
                }

	}
	return 0;
}
