#include<stdio.h>
#include<string.h>
struct node
{
	char *data;
	struct node *next;
};
long long int presentsize=0;
long long int n,kk;
struct node *start=0;
struct node *end=0;
char str[100];
void input()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	scanf("%s",str);
	kk=strlen(str);
	temp->data=(char *)malloc(sizeof(char)*kk);
	temp->next=0;
	strcpy(temp->data,str);
	if(start==0)
	{
		start=temp;
		end=temp;
		start->next=0;
		presentsize++;
	}
	else if(presentsize<n)
	{
		end->next=temp;
		end=temp;
		temp->next=start;
		presentsize++;
	}
	else
	{
		end->next=temp;
		temp=start;
		end=end->next;
		start=start->next;
		end->next=start;
		free(temp);
	}
}
void delete()
{
	struct node *temp;
	if(presentsize==0)
		return ;
	else
	{
		temp=start;
		start=start->next;
		if(presentsize==1)
		{start=0;
			end=0;
		}
		free(temp);
		presentsize--;
	}
}
void output()
{
	if(presentsize==0)
		return ;
	if(presentsize==1)
	{
		printf("%s\n",start->data);

	}
	else
	{
		struct node *temp=start;
		while(temp!=end)
		{
			printf("%s\n",temp->data);
			temp=temp->next;
		}
		printf("%s\n",temp->data);
	}
}
int main ()
{
	scanf("%lld",&n);
	char getit;
	int w,i;
	while(23)
	{
		scanf("%c",&getit);
		scanf("%c",&getit);
		if(getit=='A')
		{
			scanf("%d",&w);
			while(w--)
				input();
		}
		else if(getit=='L')
		{
			output();
		}
		else if(getit=='R')
		{
			scanf("%d",&w);
			while(w--)
				delete();
		}
		else
			break;
	}
	return 0;
}
