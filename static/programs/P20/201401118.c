#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	struct ll *next;
	int val;
	int height;
}list;
list *a[1000000];
int s[1000010],front=0,end=-1;
void bfs(list *node)
{
	list *temp;
	temp=node;
	while(temp!=NULL)
	{
		if(a[temp->val]->height==-1)
		{
			a[temp->val]->height=node->height+1;
			end++;
			s[end]=temp->val;
		}
		temp=temp->next;
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			a[i]=(list *)malloc(sizeof(list));
			a[i]->val=i;
			a[i]->height=-1;
			a[i]->next=NULL;
		}
		int x,y,k;
		list *temp,*ins1,*ins2,*tx,*ty;
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&x,&y);
			tx=a[x];
			ty=a[y];
			while(tx->next!=NULL)
				tx=tx->next;
			while(ty->next!=NULL)
				ty=ty->next;
			ins1=(list *)malloc(sizeof(list));
			ins2=(list *)malloc(sizeof(list));
			ins1->val=x;
			ins2->val=y;
			tx->next=ins2;
			ty->next=ins1;
			ins1->next=NULL;
			ins2->next=NULL;
		}
		end++;
		s[end]=1;
		a[1]->height=0;
		while(end!=n-1)
		{
			bfs(a[s[front]]);
			front++;
		}
		s[0]=s[end];
		for(i=1;i<=n;i++)
			a[i]->height=-1;
		a[s[0]]->height=0;
		end=0;
		front=0;
		while(end!=n-1)
		{
			bfs(a[s[front]]);
			front++;
		}
		printf("%d\n",a[s[end]]->height+1);
		front=0;
		end=-1;
	}
	return 0;
}
