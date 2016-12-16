#include<stdio.h>
#include<stdlib.h>
typedef struct que que;
struct que
{
	char s[105];
	que *next;
};
que *enque(que *head)
{
	//static char i='a';
	que *tmp;
	tmp=(que*)malloc(sizeof(que)+5);
	//tmp->s[0]=i;
	//tmp->s[1]='\0';
	//i++;
	tmp->next=NULL;
	if(head==NULL)
		return tmp;
	if(head->next==NULL)
		head->next=tmp;
	return tmp;
}
int main()
{
	int x,l=0,n,i,flag=0,k,j;
	que *head,*tail;
	head=(que*)malloc(sizeof(que));
	tail=(que*)malloc(sizeof(que));
	head=NULL;
	tail=NULL;
	char S[105];
	char o;
	scanf("%d\n",&n);
	if(n==0)
	{
		while(1)
		{
			scanf("%c", &o);
			if(o=='Q')
				return 0;
		}
	}
	head=enque(head);
	tail=head;
	for(i=1;i<n;i++)
		tail=enque(tail);
	tail->next=head;
	tail=head;
	while(1)
	{
		//o=getchar();
		scanf("%c", &o);
		if(o=='A')
		{
			scanf("%d",&x);
			while(x--)
			{
				l++;
				scanf("%s",S);
				j=0;
				while(S[j]!='\0')
				{
					tail->s[j]=S[j];
					j++;
				}
				tail->s[j]='\0';
				if(l>n)
				{
					head=head->next;
					flag=1;
				}
				tail=tail->next;
			}
			if(l>=n)
			{
				flag=1;
				l=n;
			}
		}
		else if(o=='R')
		{
			scanf("%d",&x);
			if(x==0)
				continue;
			l-=x;
			while(x--)
				head=head->next;
			flag=0;
		}
		else if(o=='L')
		{
			if(flag==1)
			{
				i=0;
				while(i<n)
				{
					i++;
					printf("%s\n",(head->s));
					head=head->next;
				}
			}
			else
			{
				que *tmp;
				tmp=head;
				while(tmp!=tail)
				{
					printf("%s\n",tmp->s);
					tmp=tmp->next;
				}
			}
		}
		else if(o=='Q')
			break;
	}
	return 0;
}
