#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
node *a[100005],*b[100005];
int n,c,visited[100005],l=0,p;
void rdfs(node *head,int i)
{
	node *temp=head;
	if(temp==NULL)
		return ;
	visited[i]=1;
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
		{
			c++;
			rdfs(b[temp->val],temp->val);
		}
		temp=temp->next;
	}
}
void mdfs(node *head,int i)
{
	int k;
	node *temp=head;
	//	if(temp==NULL)
	//		return ;
	visited[i]=1;
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
		{
			mdfs(a[temp->val],temp->val);
		}
		temp=temp->next;
	}
}
void binsert(int x,int y)
{
	node *new,*tmp;
	if(b[x]==NULL)
	{
		b[x]=(node*)malloc(sizeof(node));
		b[x]->val=y;
		b[x]->next=NULL;
	}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->val=y;
		new->next=b[x];
		b[x]=new;
	}
}
void ainsert(int x,int y)
{
	node *new,*tmp;
	if(a[x]==NULL)
	{
		a[x]=(node*)malloc(sizeof(node));
		a[x]->val=y;
		a[x]->next=NULL;
	}
	else
	{
		new=(node*)malloc(sizeof(node));
		new->val=y;
		new->next=a[x];
		a[x]=new;
	}
}
int main()
{
	int i,j,k;
	int e,t,m;
	node *temp;
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		l=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=n;i++)
			b[i]=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&e);
				ainsert(e,i);
				binsert(i,e);
			}
		}
		/*for(i=1;i<=n;i++)
		  {
		  printf("%d-> ",i);
		  temp=a[i];
		  while(temp!=NULL)
		  {
		  printf("%d ",temp->val);
		  temp=temp->next;
		  }
		  printf("\n");
		  }*/
		for(i=1;i<=n;i++)
		{
			l=0;
			//if(c==1)
			//	break;
			for(j=1;j<=n;j++)
				visited[j]=0;
			mdfs(a[i],i);
			for(k=1;k<=n;k++)
			{
				if(visited[k])
					l++;
			}
			if(l==n)
				c++;
			p=i;
			if(c==1)
				break;
			//	for(j=1;j<=n;j++)
			//		printf("%d  ",visited[j]);
			//	printf("c  %d\n",c);
		}
		if(c==0)
			printf("0\n");
		else
		{
		c=0;
			for(j=1;j<=n;j++)
				visited[j]=0;
		rdfs(b[p],p);
		printf("%d\n",c+1);
		}
	}
	return 0;
}
