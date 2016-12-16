#include<stdio.h>
#include<stdlib.h>
int mincount=0;
int minh[200007];
void shuffledown(int number);
int count[100000];
int n;

typedef struct list
{
	int value;
	struct list *next;
}list;


list *insert(list *head,int value)
{
	list *new=(list *)malloc(sizeof(list));
	new->value=value;
	new->next=NULL;
	list *temp;
	temp=head;
	if(head==NULL)
	{
		head=new;
		return head;
	}
	else
	{
		new->next=temp;
		head=new;
		return head;
	}
}

void insertheap(int number)
{
	int x;
	x=mincount+1;
	minh[x]=number;
	int parent=x/2,temp;
	while(minh[parent]>=minh[x] && x!=1 && parent!=0)
	{
		temp=minh[x];
		minh[x]=minh[parent];
		minh[parent]=temp;
		x=x/2;
		parent=parent/2;
	}
}

int deletemin()
{
	int tmp;
	tmp=minh[1];
	minh[1]=minh[mincount];
	mincount=mincount-1;
	shuffledown(minh[1]);
	return tmp;
}

void shuffledown(int num)
{
	int i=1,mini,temp,j;
	while(i<=mincount/2 && (num >= minh[2*i] || num >= minh[2*i+1]) && (2*i+1)<=mincount)
	{
		if(2*i<mincount)
		{
			mini=min(minh[2*i],minh[2*i+1]);
			if(mini==minh[2*i])
				j=2*i;
			else j=2*i+1;
		}
		else 
		{
			mini=minh[2*i];
			j=2*i;
		}	
		temp=mini;
		minh[j]=minh[i];
		minh[i]=temp;
		i=j;
	}
	if(2*i == mincount) 
		if(num>minh[2*i]) 
		{ 
			temp=minh[i]; minh[i]=minh[2*i]; minh[2*i]=temp;
		}
}

int min(int a,int b)
{
	if(a<=b)
		return a;
	return b;
}

int main()
{
	list *head[100005];
	minh[0]=-1;
	mincount=0;
	int m;
	scanf("%d %d",&n,&m);
	int m1,i;
	m1=m;
	for(i=1;i<=n;i++)
	{
		head[i]=NULL;
		count[i]=0;
	}

	int v1,v2;
	while(m1--)
	{
		scanf("%d%d",&v1,&v2);
		head[v1]=insert(head[v1],v2);
		count[v2]++;
	}
	for(i=1;i<=n;i++)
	{
		if(count[i]==0)
		{
			insertheap(i);
			mincount++;
		}
	}
	int root,count1=0;
	while(mincount!=0)
	{
		root=deletemin();
		printf("%d",root);
		count1++;
		if(count1==n)
		{
			printf("\n");
		}
		else 
			printf(" ");

		list *temp=head[root];
		while(temp!=NULL)
		{
			count[temp->value]--;
			if(count[temp->value]==0)
			{
				insertheap(temp->value);
				mincount++;
			}
			temp=temp->next;
		}
	}
	return 0;
}

