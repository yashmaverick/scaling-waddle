#include<stdio.h>
#include<stdlib.h>
struct node
{ 

	int data;
	struct node* next;
};
int count=0,visit[100000];
typedef struct node noddy;
noddy *a[1000005],*b[1000005];
noddy *q;
noddy* create(int e)
{
	noddy* p=(noddy*)malloc(sizeof(noddy));
	p->data=e;
	p->next=NULL;
	return p;
}

void insert(int k,int e,int fl)
{
	if(fl==1)
	{if(a[k]==NULL)
		a[k]=create(k);
		q=a[k]->next;
		a[k]->next=create(e);
		a[k]->next->next=q;}
	else
	{if(b[k]==NULL)
		b[k]=create(k);
		q=b[k]->next;
		b[k]->next=create(e);
		b[k]->next->next=q;}
	return;

}
void dfs(int e,int fl)
{
	noddy* t;
	visit[e]=1;
	if(fl==1)
		t=a[e];
	else
		t=b[e];
	int r;
	if(t!=NULL)
		t=t->next;
	count=count+1;
	while(t!=NULL)
	{
		if(visit[t->data]==0)
		{r=t->data;
			dfs(r,fl);}
		t=t->next;
	}
	return;
}
int main()
{ int t,i,n,g,k,d,e,ew;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{count=0;

		scanf("%d",&n);
		for(g=1;g<=n;g++)
		{
			a[g]=NULL;
			b[g]=NULL;
		}
		for(g=1;g<=n;g++)
		{       q=NULL;
			scanf("%d",&k);
			//a[g]=create(g);
			for(d=1;d<=k;d++)
			{
				scanf("%d",&e);
				insert(g,e,1);
				insert(e,g,0);
			}
		}int ok=0,sum;
		for(g=1;g<=n;g++)
		{
			count=0;
			for(ew=1;ew<=n;ew++)
			{
				visit[ew]=0;
			}
			dfs(g,0);
			int state=0;
			for(ew=1;ew<=n;ew++)
				if(visit[ew]==0)
					state=1;
			if(state==0)
			{ok=1;
				break;}
			//printf("%d",count);
		}
		if(ok==1)
		{count=0;
			for(ew=1;ew<=n;ew++)
			{
				visit[ew]=0;
			}
			dfs(g,1);
			count=0;
			for(ew=1;ew<=n;ew++)
				if(visit[ew]==1)
					count++;
			printf("%d\n",count);
		}
		else
			printf("0\n");
	}
	return 0;
}

