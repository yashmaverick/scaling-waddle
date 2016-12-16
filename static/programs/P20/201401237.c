#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define LIST_SIZE 1000002

struct node{
	int data;
	struct node *next;
};

struct node * adjList[LIST_SIZE];
int vistedList[LIST_SIZE];
int maxPath,farNode,count;

struct node* newNode(int data)
{
  struct node* tempNode = (struct node*) malloc(sizeof(struct node));
  tempNode->data = data;
  tempNode->next = NULL;

  return(tempNode);
}

void addNodesToTree(int x,int y)
{
	struct node *temp;
	temp=newNode(y);
	if(adjList[x]!=NULL)
		temp->next=adjList[x];
	adjList[x]=temp;

	temp=newNode(x);
	if(adjList[y]!=NULL)
		temp->next=adjList[y];
	adjList[y]=temp;
}

void longestPath(struct node *head)
{
    while(head!=NULL)
    {
        if(vistedList[head->data]==0)
        {
            count++;
            if(count>maxPath)
            {
                maxPath=count;
                farNode=head->data;
            }
            vistedList[head->data]=1;
            longestPath(adjList[head->data]);
        }
        head=head->next;
	}
	count--;
}

int main()
{
	int i,it,n,x,y;

    // Read Iterations
	scanf("%d",&it);

	while (it--)
	{
		scanf("%d",&n);

		// Initialize
		for(i=1;i<=n;i++)
        {
            adjList[i]=NULL;
            vistedList[i]=0;
        }

		//Boundary Case
		if(n<=2)
        {
            printf("%d\n",n);
            continue;
        }

        for(i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            addNodesToTree(x,y);
        }

        // Find Deepest Node
        //printf("Start Node=%d\n",x);
        maxPath=0; count=0;
        longestPath(newNode(x));
        //printf("Far Node=%d\n",farNode);

        maxPath=0; count=0;
        for(i=0;i<=n;i++)
            vistedList[i]=0;

        longestPath(newNode(farNode));

        printf("%d\n",maxPath);
        //printf("Far Node=%d\n",farNode);
	}
	return 0;
}
