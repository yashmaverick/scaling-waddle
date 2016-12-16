#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char *input;
	struct node *next;
};
typedef struct node node;
int capacity,size;
node *head=NULL;
node *tail=NULL;
char str[100];
node *create()
{
	node *temp=(node *)malloc(sizeof(node));
	scanf("%s",str);
	temp->input=(char *)malloc(sizeof(char)*100);
	strcpy(temp->input,str);
	temp->next=NULL;
	return temp;
}
void append()
{
	node *temp=create();
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		head->next=NULL;
		size++;
	}
	else if(size<capacity)
	{
		tail->next=temp;
		tail=temp;
		temp->next=head;
		size++;
	}
	else if(size==capacity)
	{
		tail->next=temp;
		temp=head;
		tail=tail->next;
		head=head->next;
		tail->next=head;
		//free(temp->input);
		//free(temp);
	}
}
void print()
{
	node *temp=head;
	if(size==0)
		return ;
	if(size==1)
	{
		printf("%s\n",temp->input);
		return;
	}
	while(temp!=tail)
	{
		printf("%s\n",temp->input);
		temp=temp->next;
	}
	printf("%s\n",temp->input);
}
void remover()
{
	node *temp;
	if(size==0)
		return ;
	if(size==1)
	{
		temp=head;
		head=NULL;
		tail=NULL;
		//free(temp->input);
		//free(temp);
		size--;
	}
	else
	{
		temp=head;
		head=head->next;
	//	free(temp->input);
		//free(temp);
		size--;
	}
}


int main ()
{
	scanf("%d",&capacity);
	char c;
	int n,i;
	size=0;
	scanf("%c",&c);
	scanf("%c",&c);
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
				append();
		}
		else if(c=='L')
		{
			print();
		}
		else if(c=='R')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
				remover();
		}
		scanf("%c",&c);
		scanf("%c",&c);

	}
	return 0;
}
