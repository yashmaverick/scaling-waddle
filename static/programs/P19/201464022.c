#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char value;
	int null;
	struct node *a[10];
}node;
int flag;
int trie(char s[],node *head)
{
	int j;
	/*if(head==NULL)
	{

		head=malloc(sizeof(node));
		head->value='.';
		for(j=0;j<10;j++)
			head->a[j]=NULL;
		head->null=0;
		return head;
	}*/
	int l,i;
	l=strlen(s);
	flag=0;
	node *temp=head;
	for(i=0;i<l-1;i++)
	{
		if(temp->a[s[i]-'0']==NULL)
		{
			//printf("entering to create\n");
		//	if(temp->null==1)
		//	flag=0;
		//	else flag=1;
			temp->a[s[i]-'0']=malloc(sizeof(node));
			temp->a[s[i]-'0']->value=s[i];
			for(j=0;j<10;j++)
				temp->a[s[i]-'0']->a[j]=NULL;
			temp->a[s[i]-'0']->null=0;
			//		head=head->a[s[i]-'0'];
		}
		else
		{
			if(temp->a[s[i]-'0']->null==1)
				return 0;
		}

		temp=temp->a[s[i]-'0'];
		//head->null=0;
		//if(i!=l-1)
		//	temp=temp->a[s[i]-'0'];


	}
	if(temp->a[s[i]-'0']==NULL)
	{
			temp->a[s[i]-'0']=malloc(sizeof(node));
			temp->a[s[i]-'0']->value=s[i];
			for(j=0;j<10;j++)
				temp->a[s[i]-'0']->a[j]=NULL;
	temp->a[s[i]-'0']->null=1;
	return 1;
	}
	else
	return 0;
}



/*void print(node *head)
  {
  if(head==NULL)
  return;
  int i;
  printf("%c ",head->value);
  for(i=0;i<10;i++)
  print(head->a[i]);
  }*/
int main()
{
	int i,j,n,finalans=1,ans,t;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		finalans=1;
		scanf("%d",&n);
	//scanf("%s",s);
	node *head;
	head=malloc(sizeof(node));
	head->value='.';
	for(j=0;j<10;j++)
		head->a[j]=NULL;
	head->null=0;
	for(i=0;i<n;i++)
	{

	scanf("%s",s);
//	if(finalans!=0)
	ans=trie(s,head);
	if(ans==0)
		finalans=0;
//	if(ans==0)
//		finalans=0;
	}
//	printf("%c\n",head->a[1]->value);
	//	print(head);
	if(finalans==0)
		printf("NO\n");
	else printf("YES\n");
	free(head);
	}
	return 0;
}


