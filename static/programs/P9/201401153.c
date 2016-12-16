#include<stdio.h> 
#include<stdlib.h>
typedef struct linked_list
{
	long long int value;
	long long int items;
	struct linked_list *next;
	long long int *bag;
}node;

node * bubble_sort(node *head)
{
	node *q,*t;
	long long int tmp, tempo;
	long long int *temp;
	q=head;
	t=head;
	while(q !=NULL)
	{
		t=q->next;
		while(t!=NULL)
		{
			if(q->value > t->value)
			{
				//printf("%lld\n",q->value);
				tmp = q->value;
				q->value = t->value;
				t->value = tmp;
				
				temp=q->bag;
				q->bag=t->bag;
				t->bag=temp;

				tempo=q->items;
				q->items=t->items;
				t->items=tempo;
			}
			t=t->next;
		}
		q=q->next;
	}
	return head;
}

node *insert(node *head,long long int mod)
{
	long long int j,m;
	long long int sum=0;
	node *p;
	p=(node *)malloc(sizeof(node));
	scanf("%lld",&m);
	p->bag=(long long int*)malloc(m*sizeof(long long int));
	for(j=0;j<m;j++)
	{
		scanf("%lld",&p->bag[j]);
		sum=(sum+p->bag[j]);
		sum%=mod;
	}
//	p->bag[m]='\0';
	p->items=m;
	p->value = sum%mod;
	p->next = NULL;

	if(head==NULL)
	{
		head = p;
	}
	else
	{
		node *q; 
		q = head;
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
	return head;
}

int main()
{
	long long int n,i,k;
	long long int mod;
	scanf("%lld %lld",&n,&mod);
	node *head = NULL;
	for(i=0;i<n;i++)
	{
		head=insert(head,mod);
	}
	head=bubble_sort(head);
	node *r;
	r=head;
	while(r!=NULL)
	{
		printf("%lld\n",r->value);
		for(k=0; k < r->items; k++)
			printf("%lld\n",r->bag[k]);
		printf("\n");
		r=r->next;
	}	
	return 0;
}
