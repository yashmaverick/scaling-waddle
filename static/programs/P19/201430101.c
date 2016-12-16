//GABBAR STUDIOWORKS
//4 apr 2015
//endsem assgn
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link{
	int a;
	struct link*next[10];
}node;
int flag=0,ret=0;
node*head;
char s[100004];
void insert(char*s,int length,node*head)
{
	node*temp=head;
	int i;
	flag=0;
	for(i=0;i<length;i++)
	{
		int x=(int)s[i]-48;
		node*obj;
		if(temp->next[x]==NULL)
		{
			obj=(node*)malloc(sizeof(node));
			obj->a=x;
			temp->next[x]=obj;
			flag=1;
		}
		else
		{
			if((temp->next[x])->next[0]==NULL && (temp->next[x])->next[1]==NULL &&(temp->next[x])->next[2]==NULL &&(temp->next[x])->next[3]==NULL &&(temp->next[x])->next[4]==NULL &&(temp->next[x])->next[5]==NULL &&(temp->next[x])->next[6]==NULL &&(temp->next[x])->next[7]==NULL &&(temp->next[x])->next[8]==NULL &&(temp->next[x])->next[9]==NULL )
			{
				ret=1;
				return;	
			}
		}
		
		temp=temp->next[x];
	}
	if(flag==0)
	{
		ret=1;
		return;
	}
	
}
int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--)
	{
		ret=0;
		flag=0;
		head=malloc(sizeof(node));
		head->a=-1;
		scanf("%d",&n);
		while(n--)
		{
			scanf(" %[^\n]",s);
			int v=strlen(s);
			insert(s,v,head);
	
		}
		if(ret==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
