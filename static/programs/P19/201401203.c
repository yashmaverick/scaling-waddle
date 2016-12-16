//using tries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	//char n[12];
	struct node * next[11];
	int edge,mark;
	char c;
}node;

char s[12];
int found=0;

node * newnode;
void insert(node * cur,int i,int j)
{
	if(s[i]=='\0')
		return;
	else if(j==cur->edge)
	{
//		printf("a\n");
		newnode=(node *)malloc(sizeof(node));
		newnode->edge=0;
		newnode->mark=0;
		//strcpy(newnode->n,cur->n); 
		//newnode->n[i]=s[i];
		newnode->c=s[i];
		if(s[i+1]=='\0')
			newnode->mark=1;
		if(cur->mark==1)
		{
//			printf("c\n");
			found=1;
			return;
		}
		cur->next[j]=newnode;
		cur->edge+=1;
		insert(newnode,i+1,0);
	}
	else
	{
		if(cur->next[j]->c==s[i])
		{
//			printf("b\n");
			if(s[i+1]=='\0'||cur->next[j]->mark==1)
			{
//				printf("d\n");
				found=1;cur->next[j]->mark=1;
				return ;
			}
			insert(cur->next[j],i+1,0);
		}
		else
			insert(cur,i,j+1);
	}
}

int main()
{
	int i,j,l,t,n;
	node * root;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
			root=(node *)malloc(sizeof(node));
			//root->n[0]='\0';
			root->edge=0;
			root->mark=0;
			root->c='\0';
			found=0;
		while(n--)
		{
		//	found=0;
			scanf("%s",s);
			l=strlen(s);
			s[l]='\0';
//			printf("%s\n",s);
			if(found==0)
				insert(root,0,0);
		}
/*		while(root->next[0]!=NULL)
		{
			printf("%c %d\n",root->next[0]->c,root->next[0]->mark);
			root=root->next[0];
		}
*/	
		if(found==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
