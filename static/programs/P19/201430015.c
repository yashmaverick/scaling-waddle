#include<stdio.h>
#include<stdlib.h>
int found;
typedef struct node{
	int value;
	int notlast;
	struct node* next[11];
}node;
char str[13];
node *create()
{
	int i;
	node *p;
	p=(node*)malloc(sizeof(node));
	p->value=0;
	p->notlast=0;
	for(i=0;i<10;i++)
	{
		p->next[i]=NULL;
	}
	return p;
}

node *root;

void insert(node *p)
{
	int i,x;
	node *q;
	i=0;
	while(str[i]!='\0')
	{
		x=str[i]-'0'; 
		if(p->next[x]==NULL)
		{
//			printf("value1:%d\n",p->value);
			p->notlast=1;
			p->next[x]=create();
			p=p->next[x];
//			printf("%d-",x);
//			printf("value2:%d\n",p->value);
		}
		else
			{
				p=p->next[x];
				if(p->value!=0)
				{
//					printf("becoz1");
					found=1;
				}
//				printf("value3:%d\n",p->value);
//				printf("%d:",x);
			}
		i++;	
		if(str[i]=='\0')
		{
		p->value=i;
		break;
		}
//		printf("value4:%d\n",p->value);	
	}
	if(p->notlast==1)
	{
//		printf("becoz2");
		found=1;
	}
}

void rem(node *p)
{
	int i;
	if(p==NULL)
	{
		return;
	}
	for(i=0;i<10;i++)
	{
		rem(p->next[i]);
	}
	if(p!=NULL)
	{
		free(p);
	}
}

int main()
{
	int test,i,n;
//	char str[12];
	scanf("%d",&test);
	while(test)
	{
		root=create();
		test--;
		scanf("%d",&n);
		found=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
				if(found!=1)
				insert(root);
				else
				{continue;
				}
//				printf("\n");
		
		}
		if(found==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		rem(root);
		root=NULL;
	}
	return 0;
}

	

