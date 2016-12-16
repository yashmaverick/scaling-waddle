#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
int cap;
int size=0;
struct node
{
	char* str;
	struct node* next;
};
node* end=NULL;
node* append(node* start,char* s)
{
	if(start==NULL)
	{
		node* tmp=(node*)malloc(sizeof(node));
		tmp->str=s;
		tmp->next=tmp;
		end=tmp->next;
		size++;
		return tmp;
	}
	if(size<cap)
	{
		node* tmp=(node*)malloc(sizeof(node));
		tmp->str=s;
		end->next=tmp;
		tmp->next=start;
		end=tmp;
		size++;
		return start;
	}
	else
	{
		start->str=s;
		end=end->next;
		start=start->next;
		return start;
	}
}
int main()
{
	scanf("%d",&cap);
	char c;
	char news[101];
	char* s;
	int n;
	node* start=NULL;
	int i;
	while(1)
	{
		scanf("%c",&c);
		if(c=='R')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				node* tmp=start;
				end->next=start->next;
				start=start->next;
				free(tmp->str);
				free(tmp);
				size--;
			}
			if(size==0)
			{
				start=NULL;
				end=NULL;
			}
		}
		else if(c=='A')
		{
			scanf("%d",&n);
			while(n--)
			{
				scanf("%s",news);
				int len=strlen(news);
				s=(char*)malloc((len+1)*sizeof(char));
				for(i=0;news[i]!='\0';i++)
				{
					s[i]=news[i];
				}
				s[i]='\0';
				start=append(start,s);
			}
		}
		else if(c=='L')
		{
			node* tmp=start;
			if(size!=0)
			{
			while(tmp!=end)
			{
				printf("%s\n",tmp->str);
				tmp=tmp->next;
			}
			if(tmp!=NULL)
			{
				printf("%s\n",tmp->str);
			}
			}
		}
		else if(c=='Q')
		{
			return 0;
		}
	}

}
