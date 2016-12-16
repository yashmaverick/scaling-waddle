#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int leaf;
int n,deepest;
int function(node *a[],int visited[],int i,int dep)
{
	node *temp;
	 int templeaf,val,tempmax,count=0;
	tempmax=0;
	visited[i]=1;
	temp=a[i];
	if(dep>deepest){
		deepest=dep;
		leaf=i;
	}
	while(temp!=NULL)
	{
		if(visited[(temp->data)-1]!=1)
		{
			templeaf=leaf;
			val=function(a,visited,(temp->data)-1,dep+1);
			count++;
			if(tempmax<val)
				tempmax=val;
		}
		temp=temp->next;
	}
	return 1+tempmax;
}
void insert(node *a[],int i,int j)
{
	node *temp;
	if(a[i-1]==NULL)
	{
		a[i-1]=(node*)malloc(sizeof(node));
		a[i-1]->data=j;
		a[i-1]->next=NULL;
	}
	else
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=j;
		temp->next=a[i-1]->next;
		a[i-1]->next=temp;
	}
}
int main()
{
	node *a[1000001];
	int i,u,v,visited[1000001],n,z,junk,test;
	scanf("%d",&test);
	while(test--)
{
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		a[i]=NULL;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		insert(a,u,v);
		insert(a,v,u);
	}
	leaf=1;
	deepest=0;
	for(i=0;i<=n;i++)
		visited[i]=0;
	junk=function(a,visited,1,0);
//	printf("%d\n",junk);
//	printf("%d\n",leaf+1);
	for(i=0;i<=n;i++)
		visited[i]=0;
	deepest=0;
	z=function(a,visited,leaf,1);
	printf("%d\n",deepest);
}
	return 0;
}
