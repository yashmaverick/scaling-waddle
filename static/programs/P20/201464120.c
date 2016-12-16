//implement a breadth first search
#include<stdio.h>
#include<stdlib.h>
int q[1000010],dis[1000010],sta[1000010];
typedef struct elem
{
	int a;
	struct elem *next;
}node;
node *arr[1000010];
int mv;
void reset(int a[],int n)
{
	int i;
	for(i=0;i<n+1;i++)
		a[i]=0;
}
int bfs(int s,int n)
{	
	
	node *l;
	int j=0;
	q[j]=s;
	sta[s]=1;
	dis[s]=0;
	int f=1;
	int max=-1;
	while(j!=n)
	{
		l=arr[q[j]];
		while(l!=NULL)
		{
			if((sta[l->a])==0)
			{
				q[f]=l->a;
				dis[l->a]=dis[q[j]]+1;
				sta[l->a]=1;
				if(dis[q[f]]>max)
				{
					max=dis[q[f]];
					mv=q[f];
				}
				f++;
			}
			l=l->next;
		}
		//printf("%d ",q[j]);
		j++;
	}
	reset(q,n);
	reset(dis,n);
	reset(sta,n);
	return max+1;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
	int e,n,i,x,f,s,j,v1,v2;
	//printf("the number of nodes:\n");
	scanf("%d",&n);
	node *l1,*l2,*l;
	int q[n],sta[n+1],dis[n+1],flag[n+1];
	//printf("ENTER NEIGHBOURS OF EACH VERTEX ENDING WITH -1\n");
	reset(q,n);
	reset(sta,n);
	reset(dis,n);
	for(i=0;i<(n+1);i++)
	{
		arr[i]=(node*)malloc(sizeof(node));
		arr[i]->next=NULL;
	}
	for(i=1;i<n;i++)
	{

		scanf("%d %d",&v1,&v2);
		l1=(node*)malloc(sizeof(node));	
		l1->a=v2;
		l1->next=arr[v1]->next;
		arr[v1]->next=l1;
		l2=(node*)malloc(sizeof(node));	
		l2->a=v1;
		l2->next=arr[v2]->next;
		arr[v2]->next=l2;
	}
/*	printf("Graph in adjacency list form:\n");
		for(i=1;i<=n;i++)
	{
		l=arr[i]->next;
		printf("%d --> ",i);
		while((l->next)!=NULL)
		{
			printf("%d ",l->a);
			l=l->next;
		}
		printf("%d\n",l->a);
	}
*/	for(i=1;i<=n;i++)
	{
		sta[i]=0;
		dis[i]=99999;
	}
//	scanf("%d",&s);
	int d=bfs(1,n);
	//printf("%d\n",d);
	d=bfs(mv,n);
	/*j=0;
	  q[j]=s;
	  sta[s]=1;
	  dis[s]=0;
	  f=1;
	  while(j!=n)
	  {
	  l=arr[q[j]];
	  while(l!=NULL)
	  {
	  if((sta[l->a])==0)
	  {
	  q[f]=l->a;
	  dis[l->a]=dis[q[j]]+1;
	  sta[l->a]=1;
	  f++;
	  }
	  l=l->next;
	  }
	  printf("%d ",q[j]);
	  j++;
	  }
	  printf("\n");
	  for(i=0;i<n;i++)
	  printf("%d ",dis[q[i]]);
	  printf("\n");
	 */
	printf("%d\n",d);
	test--;
	}
	return 0;
}

