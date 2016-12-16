#include<stdio.h>
#include<stdlib.h>

int a,b;
int maxval=0;
int pos=0;

struct List{
	int val;
	struct List* next;
};

int state=0;
struct List* mylist[1000005]={NULL};
int marked[1000005]={0};

void dfs(int a,int count)
{
	if(count>maxval)
	{
		maxval=count;
		pos=a;
	}
	struct List* temp=mylist[a];
	while(temp!=NULL)
	{
		if(marked[temp->val]==0)
		{
			marked[temp->val]=1;
			dfs(temp->val,count+1);
		}
		temp=temp->next;
	}
}

int main()
{
	int tc,n,m,i,j,k,c;
	scanf("%d", &tc);
	for(k=0;k<tc;k++)
	{
		maxval=0;
		pos=0;
		for(i=0;i<1000005;i++)
		{
			marked[i]=0;
			mylist[i]=NULL;
		}
	scanf("%d", &m);
	m=m-1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d", &a, &b);
		//We insert at the head so insertion in in O(1)
		struct List* temp=malloc(sizeof(struct List));
		temp->val=b;
		temp->next=mylist[a];
		mylist[a]=temp;
		struct List* temp2=malloc(sizeof(struct List));
		temp2->val=a;
		temp2->next=mylist[b];
		mylist[b]=temp2;
	}
	marked[a]=1;
	dfs(a,0);
	for(i=0;i<1000005;i++)
		marked[i]=0;
	marked[pos]=1;
	dfs(pos,0);
	printf("%d\n", maxval+1);
	}
	return 0;
}
