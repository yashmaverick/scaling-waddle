#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next[10];
};
typedef struct node node;
int state;
long long int find(long long int n)
{
	if(n==0)
		return 0;
	return find(n/10)+1;
}
long long int ten[12];
void tenn()
{
	int i;
	ten[0]=1;
	for(i=1;i<11;i++)
		ten[i]=ten[i-1]*10;
	return;
}
node* insert(node* head,long long int n,int r,int c)
{
	int i;
	if(r==0)
	{
		if(c==2)
			state=1;
	}
	else
	{
		long long int k=ten[r-1];
		if(head->next[n/k]==NULL)
		{
			if(c==0)
			{
				head->next[n/k]=malloc(sizeof(node));
				head->next[n/k]->val=n/k;
				for(i=0;i<10;i++)
					head->next[n/k]->next[i]=NULL;
				head->next[n/k]=insert(head->next[n/k],n%k,r-1,1);
			}
			else
			{
				for(i=0;i<10;i++)
					if(head->next[i]!=NULL)
						break;
				if(i==10 && c==2)
					state=1;
				else
				{
					head->next[n/k]=malloc(sizeof(node));
					head->next[n/k]->val=n/k;
					for(i=0;i<10;i++)
						head->next[n/k]->next[i]=NULL;
					head->next[n/k]=insert(head->next[n/k],n%k,r-1,1);
				}
			}
		}
		else
			head->next[n/k]=insert(head->next[n/k],n%k,r-1,2);
	}
	return head;
}
int main()
{
	int t;
	scanf("%d",&t);
	tenn();
	while(t--)
	{
		state=0;
		int n,i;
		scanf("%d\n",&n);
		long long int x;
		node* head;
		head=malloc(sizeof(node));
		head->val=0;
		for(i=0;i<10;i++)
			head->next[i]=NULL;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			if(state==0)
				head=insert(head,x,find(x),0);
		}
		if(state==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
