#include<stdio.h>
#include<stdlib.h>

 struct linkedlist
  {
          int data;
          struct linkedlist *next;
 };  

/*node *list(node *head , int val)
{
	node *tmp,*start=head;
	tmp=(node *)malloc(sizeof(node));
	tmp->data = val;
	tmp->next = NULL;
	if(head == NULL)
	{
		return tmp;
	}
	while(head->next !=NULL)
	{
		head = head->next;
	}
	head->next = tmp;
	return start;
}*/

int visit[1000000];
int max;
/*typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;*/
int maxv;
struct linkedlist *new1[1000000];
struct linkedlist *old[1000000];
void dfs(int vertex,int len,struct linkedlist *b,int visit[])
{
	if(len>max)
	{maxv=vertex;
		max=len;
	}
	if(b==NULL)
		return;
	visit[vertex]=1;
	while(b!=NULL)
	{
		if(visit[b->data]!=1)
			dfs(b->data,len+1,new1[b->data],visit);

		b=b->next;

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

void list(int a,int b)
{
	if(new1[a]!=NULL)
	{
		struct linkedlist *new=(struct linkedlist *)malloc(sizeof(struct linkedlist));
		new->data=b;
		new->next=new1[a];
		new1[a]=new;
	}
	else
	{
		new1[a]=(struct linkedlist *)malloc(sizeof(struct linkedlist));
		new1[a]->data=b;
		new1[a]->next=NULL;
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


/*void undirected(int vertex1,int vertex2)
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
}*/
int main()
{
	int t,x,p;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		int n,j;
		scanf("%d",&n);
		if(n==0)
			printf("0\n");
		else
		{
			int l,m;
			for(j=0;j<n;j++)
			{
				old[j+1]=NULL;
				new1[j+1]=NULL;
				visit[j+1]=-1;
			}

			for(j=1;j<n;j++)
			{
				scanf("%d %d",&l,&m);
				//undirected(source,destination);
				list(l,m);
				list(m,l);

			}		
			max=0;
			dfs(1,0,new1[1],visit);
			//printf("%d\n",maxatvertex);
			for(j=1;j<=n;j++)
			{
				visit[j]=-1;
			}
			dfs(maxv,0,new1[maxv],visit);
			//printf("%d\n",maximumpath);
			int p;
			p=max+1;
			printf("%d\n",p);
		}
	}
	return 0;
}








