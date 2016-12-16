#include<stdio.h>
#include<stdlib.h>
typedef struct nde
{
	int m;
	long long int *a;
	long long int wt;
	struct nde *next;
}node;
int main()
{
	int n,i,j;
	long long int mod;
	scanf("%d %lld",&n,&mod);
	node *head;
	node *cur,*end;

	head=malloc(sizeof(node));
	scanf("%d",&(head->m));
	head->a=malloc((head->m)*sizeof(long long int));
	for(i=0;i<(head->m);i++)
	{
		scanf("%lld",&((head->a)[i]));
		head->wt+=(head->a)[i];
		head->wt%=mod;
	}
	head->next=NULL;
	cur=head;


	for(i=1;i<n;i++)
	{
		node *new=malloc(sizeof(node));
		cur->next=new;
		cur=new;
		scanf("%d",&(cur->m));
		cur->a=malloc((cur->m)*sizeof(long long int));
		for(j=0;j<(cur->m);j++)
		{
			scanf("%lld",&((cur->a)[j]));
			cur->wt+=(cur->a)[j];
			cur->wt%=mod;
		}
		cur->next=NULL;

	}
	end=cur;

	cur=head;

	int tm;
	long long int *ta,twt;
	while(end!=head)
	{
		cur=head;
		for(i=0;cur->next!=end;i++)
		{
			if((cur->wt)>cur->next->wt)
			{
				tm=cur->m;
				ta=cur->a;
				twt=cur->wt;
				cur->m=cur->next->m;
				cur->a=cur->next->a;
				cur->wt=cur->next->wt;
				cur->next->m=tm;
				cur->next->a=ta;
				cur->next->wt=twt;
			}
			cur=cur->next;
		}
		if((cur->wt)>end->wt)
		{
			tm=cur->m;
			ta=cur->a;
			twt=cur->wt;
			cur->m=end->m;
			cur->a=end->a;
			cur->wt=end->wt;
			end->m=tm;
			end->a=ta;
			end->wt=twt;
		}
		end=cur;
	}

	cur=head;
	while(cur->next!=NULL)
	{
		printf("%lld\n",(cur->wt));
		for(j=0;j<(cur->m);j++)
			printf("%lld\n",(cur->a)[j]);
		putchar('\n');
		cur=cur->next;
	}
	printf("%lld\n",cur->wt);
	for(j=0;j<(cur->m);j++)
		printf("%lld\n",(cur->a)[j]);
	putchar('\n');

	return 0;
}
