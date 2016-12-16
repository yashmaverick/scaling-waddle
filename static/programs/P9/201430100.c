#include<stdio.h>
#include<stdlib.h>
int n,mod;

typedef struct ba
{
	int number;
	long long int weight;
	int *a;
}ba;

typedef struct ba *bag;

typedef struct list
{
	int x;
	long long int weight;
	struct list *next;
}list;
typedef struct list *link;
	
link head=NULL,present=NULL;

void addme(long long int sum,int i)
{
	if(head==NULL)
	{
		head=malloc(sizeof(list));
		head->x=i;
		head->weight=sum;
		head->next=NULL;
		present=head;
		return;
	}
	link temp=head;

	if(head->weight>sum)
	{
		link temp1;
		temp1=malloc(sizeof(list));
		temp1->x=i;
		temp1->weight=sum;
		temp1->next=head;
		head=temp1;
		return;
	}

	while((temp->next)!=NULL)
	{
		if((temp->next->weight)>sum)
		{

			link temp1;
			temp1=malloc(sizeof(list));
			temp1->x=i;
			temp1->weight=sum;
			temp1->next=temp->next;
			temp->next=temp1;
			return;
		}
		temp=temp->next;
	}
	present->next=malloc(sizeof(list));
	present=present->next;
	present->x=i;
	present->weight=sum;
	present->next=NULL;
	return;
}

void pri(bag item[])
{
	int p;
	link temp=head;
	for(p=0;p<n;p++)
	{
		int index=temp->x;
		int s=item[index]->number;
		int i;
		printf("%lld\n",temp->weight);
		for(i=0;i<s;i++)
		{
			printf("%d\n",item[index]->a[i]);
		}
		printf("\n");
		temp=temp->next;
	}	
}


int main()
{
	scanf("%d %d",&n,&mod);

	bag item[n];
	int i;
	head=NULL;
	present=NULL;

	for(i=0;i<n;i++)
	{
		item[i]=malloc(sizeof(ba));

		int m,j;
		scanf("%d",&m);
		long long int temp=0;

		item[i]->number=m;
		item[i]->a=(int *)malloc(sizeof(int)*m);

		for(j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			temp=(temp+x)%mod;
			item[i]->a[j]=x;
		}	
		item[i]->weight=temp;
		addme(temp,i);
	}
	pri(item);
	return 0;
}