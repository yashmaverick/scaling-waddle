#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie
{
	int data;
	struct trie *next[11];
}node;
node *root;
int flag=0;
void insert(char s[])
{
	int i,d,r=1,y;
	d=strlen(s);
	node *temp;
	temp=malloc(sizeof(node));
	temp=root;
	for(i=0;i<d;i++)
	{
		//printf("Now at %d\n",temp->data);
		int u;
		u=s[i]-'0';
		//y=temp->data;
		/*if(f==1)
		{
			at=(y*r*10)+u;
			f=0;
		}
		else
			at=(y*r)+u;*/
		int j;
		if(temp->next[u]==NULL)
		{
			//printf("Here for %d\n",u);
			node *tem;
			tem=malloc(sizeof(node));
			//tem->data=at;
			tem->data=0;
			for(j=0;j<11;j++)
				tem->next[j]=NULL;
			temp->next[u]=tem;
		}
		else
		{
			if(temp->next[u]->data==-1)
			{	//printf("Making\n");
				flag=1;
			}

		}
		temp=temp->next[u];
	}
	int k;
	temp->data=-1;
	for(k=0;k<10;k++)
		if(temp->next[k]!=NULL)
			flag=1;
	return;
}

int main()
{
	root=malloc(sizeof(node));
	int o;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	for(o=0;o<11;o++)
	{
		root->next[o]=NULL;
		//root->data[o]=0;
	}
		flag=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			char p[10];
			scanf("%s",p);
			insert(p);
			//printf("%d\n",re);
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

		

