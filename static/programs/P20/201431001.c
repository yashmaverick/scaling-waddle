#include <stdio.h>
#include <stdlib.h>

#define max(a,b)    ((a) > (b) ? (a) : (b))

typedef struct linklist{
	int data;
	struct linklist *next;
}linklist;

linklist *a[1000001];
int visited[1000001],total;		

int dfs(int root)
{
	visited[root] = 1;
    linklist *temp = a[root];
    
    int m, m1 = -1, m2 = -1;
    while(temp != NULL)
    {
        if(!visited[temp->data])
        {
            m = dfs(temp->data);
            if(m >= m1)
            {
                m2 = m1;
                m1 = m;
            }
            else if(m > m2)
                m2 = m;
        }
        temp = temp->next;
    }
    total = max(total,m1 + m2 + 2);
    return (m1 + 1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,y,i;
		scanf("%d",&n);

		total = 0;
		for(i = 1;i <= n; i++){
			visited[i] = 0;
			a[i] = NULL;
		}
	
		for(i = 0;i < n-1;i++)
		{
			scanf("%d %d",&x,&y);
			linklist *newnode1 = (linklist *)malloc(sizeof(linklist));
			newnode1 -> data = y;
			newnode1 -> next = NULL;

			linklist *newnode2 = (linklist *)malloc(sizeof(linklist));
			newnode2 -> data = x;
			newnode2 -> next = NULL;

			if(a[x] == NULL)
				a[x] = newnode1;
			else{
				newnode1 -> next = a[x];
				a[x] = newnode1;	
			}

			if(a[y] == NULL)
				a[y] = newnode2;
			else{
				newnode2 -> next = a[y];
				a[y] = newnode2;	
			}
		}
		/*
		for(i = 1; i <= n; i++)
		{
			linklist *temp = a[i];
			printf("%d -> ",i);
			while(temp != NULL){
				printf("%d ", temp->data);
				temp = temp -> next;
			}
			printf("\n");
		}
		*/

		dfs(1);
		printf("%d\n", total + 1);
	}
	return 0;
}