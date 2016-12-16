#include<stdio.h>
#include<stdlib.h>
typedef struct stack stack;
struct stack
{
	int val;
	stack *down;
};
stack *top;
void print()
{
	if(top==NULL)
		return;
	stack *tmp;
	tmp=top;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->val);
		tmp=tmp->down;
	}
}
stack *pop()
{
	if(top==NULL)
		return NULL;
	stack *D;
	D=top->down;
	free(top);
	return D;
}
stack *push(int x)
{
	stack *tmp;
	tmp=(stack*)malloc(sizeof(stack));
	tmp->val=x;
	tmp->down=top;
	return tmp;
}
void deepN(int *post,int m)
{
	int i,t,L=0,E=post[0],c=1;
	int sta[m+1];
	for(i=m-1;i>=0;i--)
	{
		if(top==NULL)
		{
			top=push(post[i]);
			sta[top->val]=0;
		}
		else if(post[i]>top->val)
		{
			sta[post[i]]=sta[top->val]+1;
			top=push(post[i]);
		}
		else
		{
			while(top!=NULL)
			{
				if(post[i]<top->val)
				{
					t=top->val;
					top=pop();
				}
				else
				{
					sta[post[i]]=sta[t]+1;
					top=push(post[i]);
					break;
				}
			}
			if(top==NULL)
			{
				top=push(t);
				top=push(post[i]);
				sta[post[i]]=c;
				c++;
			}
		}
		if(sta[post[i]]>=L)
		{
			if(sta[post[i]]>L)
			{
				L=sta[post[i]];
				E=top->val;
			}
			else
			{
				if(E>top->val)
					E=top->val;
			}
		}
		//print(top);
		//printf("\n");
	}
	/*for(i=1;i<=m;i++)
		printf("%d ",i);
	printf("\n");
	for(i=1;i<=m;i++)
		printf("%d ",sta[i]);
	printf("\n");*/
	printf("%d %d\n",E,L);
}
int main()
{
	int x,n,i,m;
	int post[100000];
	scanf("%d",&n);
	top=NULL;
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&post[i]);
		deepN(post,m);
		while(top!=NULL)
			top=pop();
	}
	return 0;
}
