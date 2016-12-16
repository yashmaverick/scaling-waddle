#include<stdio.h>
#include<stdlib.h>
int colored[1000001];
int maximumpath;
typedef struct node
{
	int vertex;
	struct node *next;
}node;
int maxatvertex;
node *graph1[1000001];
node *graph[1000001];
void depthfirst(int index,int required,node *main)
{
	if(maximumpath<required)
	{maxatvertex=index;
		maximumpath=required;
	}
	if(main==NULL)
		return;
	colored[index]=22;
	while(main!=NULL)
	{
		if(colored[main->vertex]!=22)
			depthfirst(main->vertex,required+1,graph1[main->vertex]);

		main=main->next;

	}
}
/*void depthfirstsearch(int index1,int required1,node *main1)
{
	if(maximumpath<required1)
	{maxatvertex=index1;
		maximumpath=required1;
	}
	if(main1==NULL)
		return;
	colored[index1]=22;
	while(main1!=NULL)
	{
		if(colored[main1->vertex]!=22)
			depthfirst(main1->vertex,(required1)+1,graph1[main1->vertex]);

		main1=main1->next;
	}
}*/

void undirected2(int vertex11,int vertex22)
{
	if(graph1[vertex11]!=NULL)
	{
		node *kottha1=(node *)malloc(sizeof(node));
		kottha1->vertex=vertex22;
		kottha1->next=graph1[vertex11];
		graph1[vertex11]=kottha1;
	}
	else
	{
		graph1[vertex11]=(node *)malloc(sizeof(node));
		graph1[vertex11]->vertex=vertex22;
		graph1[vertex11]->next=NULL;
	}

}
/*void depthfirstsearch(int index1,int required1,node *main1)
{
	if(maximumpath<required1)
	{maxatvertex=index1;
		maximumpath=required1;
	}
	if(main1==NULL)
		return;
	colored[index1]=22;
	while(main1!=NULL)
	{
		if(colored[main1->vertex]!=22)
		{
			depthfirst(main1->vertex,(required1)+1,graph1[main1->vertex]);
		}

		main1=main1->next;
	}
}*/


void undirected(int vertex1,int vertex2)
{
	
	if(graph[vertex1]!=NULL)
	{
		node *kottha=(node *)malloc(sizeof(node));
		kottha->vertex=vertex2;
		kottha->next=graph[vertex1];
		graph[vertex1]=kottha;
	}
	else
	{
		graph[vertex1]=(node *)malloc(sizeof(node));
		graph[vertex1]->vertex=vertex2;
		graph[vertex1]->next=NULL;
	}
}
int main()
{
	int test,y;
	scanf("%d",&test);
	for(y=0;y<test;y++)
	{
		int vertices,j;
		scanf("%d",&vertices);
		if(vertices==0)
			printf("0\n");
		else
		{
			int source,destination;
			for(j=1;j<=vertices;j++)
			{
				graph[j]=NULL;
				graph1[j]=NULL;
				colored[j]=-1;
			}

			for(j=1;j<vertices;j++)
			{
				scanf("%d %d",&source,&destination);
				undirected(source,destination);
				undirected2(source,destination);
				undirected2(destination,source);

			}		
			int vert=1;
			maximumpath=0;
			depthfirst(vert,0,graph1[1]);
			//printf("%d\n",maxatvertex);
			for(j=1;j<=vertices;j++)
			{
				colored[j]=-1;
			}
			depthfirst(maxatvertex,0,graph1[maxatvertex]);
			//printf("%d\n",maximumpath);
			int answer;
			answer=maximumpath+1;
			printf("%d\n",answer);
		}
	}
	return 0;
}








