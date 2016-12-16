#include<stdio.h>
#include<stdlib.h>
int b[1000003];
int n,cnt,key;
int max=0;
typedef struct node{
	int val;
	struct node *next;
}node;

node *a[1000003];
node* insert(node *head , int data)
{
	node *tmp,*start = head;
	tmp=(node *)malloc(sizeof(node));
	tmp->val = data;
	tmp->next = NULL;
	if(head == NULL)
	{
		return tmp;
	}
	tmp->next=head->next;
	head->next = tmp;
	return start;
}

int   dfs(int element)
{
/*	if(b[element] == 1)
	{
		cnt--;
		return ;
	}*/
	if(max < cnt)
	{
		max=cnt;
		key=element;
	}
	cnt++;
	b[element]=1;
	node *p=a[element];
	while(p != NULL)
	{
		if(b[p->val] != 1)
		{
			dfs(p->val);	
			cnt--;
		}
		p=p->next;
	}
	return ;
}

int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		int m,i;
		cnt=1;
		max=0;
		scanf("%d",&n);
		m=n;
		for(i=1;i<=n;i++)
		{
			b[i]=0;
			a[i]=(node *)malloc(sizeof(node));
			a[i]=NULL;
			//a[i]=insert(a[i],i);
		}
		m--;
		int k;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			a[y]=insert(a[y],x);
			a[x]=insert(a[x],y);	
		}
		int h;
		dfs(1);
		cnt=1;
		h=key;
		for(i=1;i<=n;i++)
		{
			b[i]=0;
		}
		max=0;
		dfs(h);
		printf("%d\n",max);
	}
	return 0;
}
