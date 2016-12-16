#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

int poi=0,b[100001];
node* insert(node *head,int ver)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->val=ver;
	temp->next=head;
	return temp;
}

void insert1(int poi)
{
	if(b[(poi-1)/2]<=b[poi])
	{
		return;
	}
	else
	{
		int temp;
		temp=b[poi];
		b[poi]=b[(poi-1)/2];
		b[(poi-1)/2]=temp;
		insert1((poi-1)/2);
	}
}

void delete(int index)
{
	int temp;
	if(((2*index)+1)>poi)
		return;
	if(((2*index)+2)<=poi)
	{
		int n,m;
		n=b[(2*index)+1];
		m=b[(2*index)+2];
		if(n<=m)
		{
			if(b[index]>n)
			{
				temp=b[index];
				b[index]=b[(2*index)+1];
				b[(2*index)+1]=temp;
				delete((2*index)+1);
				return;
			}
		}
		if(m<n)
		{
			if(b[index]>m)
			{
				temp=b[index];
				b[index]=b[(2*index)+2];
				b[(2*index)+2]=temp;
				delete((2*index)+2);
				return;
			}
		}
		return;
	}
	if(((2*index)+1)==poi)
	{
		if(b[(2*index)+1]<b[index])
		{
			temp=b[index];
			b[index]=b[(2*index)+1];
			b[(2*index)+1]=temp;
			delete((2*index)+1);
			return;
		}
		return;
	}
}


int main()
{
	int v,e,i;
	node* a[100001];
	int c[100001]={0};
	scanf("%d%d",&v,&e);
	int fi,se;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&fi,&se);
		fi=fi-1;
		se=se-1;
		a[fi]=insert(a[fi],se);
		c[se]++;
	}
	for(i=0;i<v;i++)
	{
		if(c[i]==0)
		{
			b[poi]=i;
			insert1(poi);
			poi++;
		}
	}
	int ex=v;
	for(i=0;i<ex;i++)
	{
		node *head=a[b[0]];
		printf("%d",b[0]+1);
		if(i!=ex-1)
			printf(" ");
		b[0]=b[poi-1];
		poi=poi-2;
		delete(0);
		poi++;
		while(head!=NULL)
		{
			c[head->val]--;
			if(c[head->val]==0)
			{
				b[poi]=head->val;
				insert1(poi);
				poi++;
			}
			head=head->next;
		}
	}
	printf("\n");
	return 0;
}



