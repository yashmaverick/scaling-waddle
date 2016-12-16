#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char str[100];
int y;
struct node
{
	int value;
	struct node* c[10];

};

int cou=0,len,temp=0;
void newnode()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	return ;
}

void  insert(struct node* root)
{
 
	if(cou==len)
		return;
	int u;
	if(root->c[str[cou]-'0']==NULL)
	{
		struct node* p=(struct node*)malloc(sizeof(struct node));
		u=str[cou]-'0';
		root->c[u]=p;
		if(cou==len-1)
			root->c[u]->value=1;
	}
	else
	{	if(root->c[str[cou]-'0']->value==1 || cou==len-1)
		{
			temp=1;
                        newnode(temp);
                        y++;
			return ;
		}

	}
	cou++;
	insert(root->c[str[cou-1]-'0']);
	return ;
}
int main()
{
	int test,num,i,vi[1000],t;
	struct node* root=(struct node*)malloc(sizeof(struct node));
	newnode();
	scanf("%d",&test);
	while(test--)
	{
		int k;
		temp=0;
		for(i=0;i<10;i++)
			root->c[i]=NULL;
		scanf("%d",&num);
                newnode(num);
		for(k=1;k<1000;k++)
			vi[k]=0;
		while(num--)
		{
			cou=0;
			scanf("%s",str);
			len=strlen(str);
			newnode(len);
			insert(root);
                        y++;
		}
		if(temp!=0)
		{
			t++;
			printf("NO\n");
		}
		else
			printf("YES\n");
	}

	return 0;
}
