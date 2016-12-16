#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	long long int val;
	node *next;
	long long int *con;
	long long int num;
};
node *insertLL(node *head,long long int M)
{
	if(!head)
	{
		long long int j,s=0,m;
		scanf("%lld",&m);
		node *tmp;
		tmp=(node*)malloc(sizeof(node));
		tmp->con=(long long int*)malloc(m*sizeof(long long int));
		tmp->num=m;
		for(j=0;j<m;j++)
		{
			scanf("%lld",&(tmp->con[j]));
			s=s+(tmp->con[j]);
			s%=M;
		}
		tmp->val=(s%M);
		tmp->next=NULL;
		return tmp;
	}
	else
		head->next=insertLL(head->next,M);
	return head;
}
int main()
{
	long long int n,x,i,M,T,j,*t,l;
	node *head,*tmp1,*tmp2;
	head=NULL;
	scanf("%lld%lld",&n,&M);
	for(i=0;i<n;i++)
		head=insertLL(head,M);
	tmp1=head;
	while(tmp1!=NULL)
	{
		tmp2=tmp1->next;
		while(tmp2!=NULL)
		{
			if(tmp1->val>tmp2->val)
			{
				T=tmp2->val;
				t=tmp2->con;
				l=tmp2->num;
				tmp2->val=tmp1->val;
				tmp2->con=tmp1->con;
				tmp2->num=tmp1->num;
				tmp1->val=T;
				tmp1->con=t;
				tmp1->num=l;
			}
			tmp2=tmp2->next;
		}
		tmp1=tmp1->next;
	}
	i=0;
	while(head)
	{
		printf("%lld\n",head->val);
		for(j=0;j<(head->num);j++)
			printf("%lld\n",head->con[j]);
		printf("\n");
		head=head->next;
		i++;
	}
	return 0;
}
