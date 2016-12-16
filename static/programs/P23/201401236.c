#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	struct link *next;
	long long int vl;

}link;	
typedef struct arra
{
	link *new;
	link *head;
	link *itr;
	link *r;
}arra;
arra *jo;
long long int top=-1,stack[100004],flag[100004]={0};
void push(long long int i)
{
	top++;
	stack[top]=i;
}
void dfs(long long int i)
{
	if(flag[i]==0)
	{
		flag[i]=1;	
		while(jo[i].head!=NULL)
		{
			dfs(jo[i].head->vl);	
			jo[i].head=jo[i].head->next;	
		}	
		push(i);	
	}	
}
	int main()
	{
		long long int n,m,i,x,y;
		scanf("%lld%lld",&n,&m);
		jo=malloc(sizeof(arra)*100004);
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld",&x,&y);
		//	printf("%d",i);
			jo[x].new=malloc(sizeof(link));
			jo[x].new->vl=y;
			if(jo[x].head==NULL)
			{
				jo[x].head=jo[x].new;
				jo[x].itr=jo[x].new;
				jo[x].r=jo[x].new;
			}
			else
			{
				jo[x].itr->next=jo[x].new;
				jo[x].itr=jo[x].itr->next;

			}
		
		}
		//printf("jj");
		
		
		for(i=n;i>0;i--)
			dfs(i);
		for(i=top;i>=0;i--)
		{
			if(i!=0)
			printf("%lld ",stack[i]);
			if(i==0)
			printf("%lld",stack[i]);
		}
			printf("\n");
		return 0;
	}
