//adjacency list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int vertex;
	struct node* next;
}node;

node* array[1000000];

void add_edge(int a, int b)
{
	if(array[a]==NULL)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));

		temp->vertex=b;
		temp->next=NULL;

		array[a]=temp;
	}
	else
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));

		node* count;
		count=array[a];

		array[a]=temp;

		temp->vertex=b;
		temp->next=count;
	}
}

// int v[1000000];
 int max=0;
 int deep=0;
// void visit(int a , int c)
// {
// 	v[a]=1;

// 	node* count;
// 	count=array[a];

// 	int t;

// 	while(count!=NULL)
// 	{
// 		if(v[count->vertex]==0)
// 		{
// 			visit(count->vertex, c+1);
// 			t=count->vertex;
// 		}
		
// 		count=count->next;
// 	}
// 	printf("%d\n", deep);

// 	if(max<c)
// 	{
// 		max=c;
// 		deep=t;
// 	}
// }

int v[1000000];
int max;
void visit(int a, int depth)
{
//	printf("vert%d\n", a);
	v[a]=1;

	depth++;

	node* count=array[a];

	while(count!=NULL)
	{
		if(v[count->vertex]==0)
		{
			visit(count->vertex, depth);
//			printf("%d\n", count->vertex);
		}
		count=count->next;
	}
	if(max<depth)
	{
		max=depth;
		deep=a;
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t!=0)
	{
		max=0;
		deep=0;

		int n;
		scanf("%d", &n);

		int i;
		for(i=0; i<=n; i++)
		{
			array[i]=NULL;
			v[i]=0;
		}

		for(i=0; i<n-1; i++)
		{
			int a;
			int b;
			scanf("%d%d", &a, &b);

			add_edge(a,b);
			add_edge(b,a);
		}
/*
		for(i=1; i<=n; i++)
		{
			node* temp=array[i];

			while(temp!=NULL)
			{
				printf("%d ", temp->vertex);
				temp=temp->next;
			}
			printf("\n");
		}
*/
		visit(1, 0);
//		printf("%d %d\n" ,max, deep);
//		visit(deep, 0);
		
//		printf("%d %d\n", max , deep);
		max = 0;
		for(i=0; i<=n; i++)
		{
//			array[i]=NULL;
			v[i]=0;
		}
		visit(deep, 0);
		printf("%d\n", max );
		t--;
	}
}