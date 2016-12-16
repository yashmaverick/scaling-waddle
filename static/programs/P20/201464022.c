#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int val;
	struct node *next;
}node;
//node *a;
//long long int *visited;
long long maxlevel;
void create(long long int v1,long long int v2,node *a)
{
	node *p=malloc(sizeof(node));
	node *q=malloc(sizeof(node));
	p->val=v1;
	q->val=v2;
	p->next=NULL;
	q->next=NULL;

	node *temp=&a[v2];
	if(temp->next==NULL)
		temp->next=p;
	else
	{
		p->next=temp->next;
		temp->next=p;
	}
	temp=&a[v1];
	if(temp->next==NULL)
		temp->next=q;
	else
	{
		q->next=temp->next;
		temp->next=q;
	}
}
long long maxvert;
long long max(long long  a,long long  b)
{
	if(a>b)
		return a;
	else return b;
}
long long  firstdfs(long long  v1,long long  level,node *a,long long int visited[])
{
	if(visited[v1]==1)
		return 0;
	visited[v1]=1;
//	printf("visiting vertex=%lld where level=%lld\n",v1,level);
//	printf("maxlevel now=%lld\n",maxlevel);
	long long int level1=level;
	long long int level2;
	node *temp=&a[v1];
	while(temp->next!=NULL)
	{
//		if(level==maxlevel)
//			maxvert=temp->val;
		temp=temp->next;
//		level1=max(level1,firstdfs(temp->next->val,level+1));
//		printf("v1=%lld\n",temp->val);
		level2=firstdfs(temp->val,level+1,a,visited);
		if(level1>level2 && level1>maxlevel)
		{
			
//			printf("entering\n");
			maxlevel=level1;
		}

		else {
	//		printf("level changes for %lld\n",temp->val);
//			printf("entering\n");			
			level1=level2;
			if(level2>maxlevel)
				maxlevel=level2;
			//maxlevel=level2;
		//	maxvert=temp->next->val;
		}
		//printf("maxlevel now=%lld\n",maxlevel);
		if(level==maxlevel)
		{
			maxvert=v1;
//			printf("maxver now =%lld\n",maxvert);
		}

		//temp=temp->next;
	}
	return maxlevel;

}


int main()
{
	long long int n,t,i,j;
//	node *a;
	scanf("%lld",&t);
	while(t--)
	{
		long long v1,v2;
		node *a;
		long long int *visited;
		long long maxlev;
		maxlevel=0;
		maxvert=0;
		scanf("%lld",&n);
		if( n==1)
		{
			printf("1\n");
			continue;
		}
		if(n==0)
		{
			printf("0\n");
			continue;
		}

		a=malloc(sizeof(node)*(n+1));
		visited=malloc(sizeof(long long int)*(n+1));
		for(i=1;i<=n;i++)
			a[i].val=i;
//		visited=malloc(sizeof(int)*(n+1));
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&v1,&v2);
			create(v1,v2,a);
//			create(v2,v1);
		}
		node *temp;
/*		for(i=1;i<=n;i++)
		{
			temp=&a[i];
			while(temp->next!=NULL)
			{
				printf("%lld ",temp->val);
				temp=temp->next;
			}
			printf("%lld",temp->val);
			printf("\n");
		}*/
		maxlev=firstdfs(v1,0,a,visited);
		//printf("level1=%lld\n",maxlev);
		//printf("maxvert initially=%lld\n",maxvert);
		for(i=0;i<=n;i++)
			visited[i]=0;
		long long int maxlevel2=firstdfs(maxvert,0,a,visited);
		//printf("maxvert=%lld\n",maxvert);
		printf("%lld\n",maxlevel2+1);
	//	free(visited);
	//	free(a);
	}
	return 0;
}


	
	

