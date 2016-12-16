#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trie
{
	struct trie *c[10];
	int flag;
};

char  str[12]={};

int count=0,len,temp=0;

void  insert(struct trie* root)
{
	if(count==len)
		return ;
	if(root->c[str[count]-'0']==NULL)
	{
		root->c[str[count]-'0']=malloc(sizeof(struct trie));
		if(count==len-1)
			root->c[str[count]-'0']->flag=1;
	}
	else
	{	if(root->c[str[count]-'0']->flag==1 || count==len-1)
		{
			temp=1;
			return ;
		}
		/*else if(count==len-1)
			root->c[str[count]-'0']->flag=1;*/
	}
	count++;
	insert(root->c[str[count-1]-'0']);
	return ;
}
int main()
{
struct trie *root;
	root=malloc(sizeof(struct trie));
	int test,num,i;
	scanf("%d",&test);
	while(test--)
	{
		temp=0;
		for(i=0;i<10;i++)
			root->c[i]=NULL;
		scanf("%d",&num);
		while(num--)
		{
			count=0;
			scanf("%s",str);
			len=strlen(str);
			insert(root);
		}
		if(temp==1)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
