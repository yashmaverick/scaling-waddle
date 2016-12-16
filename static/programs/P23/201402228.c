#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	node *next;
};
node *arr[500003];
int v[500003]={0};
int t[500003];
int top=-1;
void order(int i)
{
	if(v[i]!=0)
		return;
	else
	{
		node *tmp;
		v[i]=1;
		tmp=arr[i];
		while(tmp!=NULL)
		{
			int n=tmp->val;
			if(v[n]==0)
				order(n);
			tmp=tmp->next;
		}
		top++;
		t[top]=i;
	}

}

int main()
{
	int m,n,i,p,q,j;
	scanf("%d%d",&n,&m);
	j=n;
	for(i=1;i<=m;i++)
	{

		scanf("%d%d",&p,&q);
		node *s;
		s=malloc(sizeof(node));
		s->val=q;
		if(arr[p]==NULL)
		{
			s->next=NULL;
			arr[p]=s;
		}
		else
		{
			s->next=arr[p];
			arr[p]=s;
		}
	}

	while(j>0)
	{
		order(j);
		j--;

	}
	
	while(top!=0)
	{
		printf("%d ",t[top]);
		top--;
	}
	printf("%d\n",t[top]);
//	printf("\n");
	return 0;
}





