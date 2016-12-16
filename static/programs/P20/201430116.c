#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list element;
typedef element *link;
link start;
int max=0;
void dfs(link node,link a[],int visited[],int count)
{
        visited[node->data]=1;
        (count)++;
        if(count > max)
        {
        	max=count;
        	start=a[node->data];
        }
        link tmp;
        tmp=node->next;
        while(tmp!=NULL){
            if(visited[tmp->data]!=1){
                dfs(a[tmp->data],a,visited,count);
            }
            tmp=(tmp->next);
        }
        return;
}
void dfs2(link node,link a[],int visited[],int count)
{
        visited[node->data]=1;
        (count)++;
        if(count > max)
        {
        	max=count;
        //	start=a[node->data];
        } 
        link tmp;
        tmp=node->next;
        while(tmp!=NULL){
            if(visited[tmp->data]!=1){
                dfs2(a[tmp->data],a,visited,count);
            }
            tmp=(tmp->next);
        }
        return;
}
int main()
{
	int sw,z;
    scanf("%d",&sw);
    for(z=0;z<sw;z++)
    {
	int n,i;
	scanf("%d",&n);
	link *a;
	a=malloc((n+1)*sizeof(link));
	for(i=1;i<=n;i++)
	{
		a[i]=malloc(sizeof(element));
		a[i]->data=i;
		a[i]->next=NULL;
	}
	int u,v;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d",&u,&v);
		link temp1;
		temp1=malloc(sizeof(element));
		temp1->data=v;
		temp1->next=a[u]->next;
		a[u]->next=temp1;
		link temp2;
		temp2=malloc(sizeof(element));
		temp2->data=u;
		temp2->next=a[v]->next;
		a[v]->next=temp2;
	}
	int min=0,count=0;
	link minnode;
/*	for(i=1;i<=n;i++)
	{
		link temp;
		temp=a[i];
		count=0;
		while(temp!=NULL)
		{
			count++;
//			printf("%d ",temp->data);
			temp=temp->next;
			if(temp==NULL && count > min)
			{
				min=count;
				minnode=a[i];
			}	
		}
//		printf("\n");
	} */
	int *visited;
	visited=malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	count=0;
	max=0;
    dfs(a[1],a,visited,count);
    for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
//	printf("start->data=%d\n",start->data);
	max=0;
	count=0;
	dfs2(start,a,visited,count);
/*	count=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==1)
			count++;
	}
	*/
	printf("%d\n",max);
	}
	return 0;
}