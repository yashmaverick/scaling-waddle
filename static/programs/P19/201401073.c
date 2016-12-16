#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define check printf("--------------");
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a

typedef struct node
{
	struct node *num[11];
	int data;
	int end;
}node;

node *head;
int flag;

void insert(char string[10],node *head)
{
	int j=0,index,i,len;
	node *ch,*temp;
	temp = (node *)malloc(sizeof(node));
//	ch = (node *)malloc(sizeof(node));
	temp = head;
	len = strlen(string);
//	pi(len);
//	endl;
	while(j<len)
	{
		ch = (node *)malloc(sizeof(node));
		ch->data = 1;
		ch->end = 0;
		for(i=0;i<11;i++)
			ch->num[i] = NULL;
		index = string[j] - 48; 
		if(temp->num[index] == NULL)
		{
			temp->num[index] = ch;
			temp = temp->num[index];
		}
		else
		{
			temp = temp->num[index];
			if(temp->end == 1)
				flag = 1;
		}
		j++;
		if(j==len)
		{
			for(i=0;i<10;i++)
			{
				if(temp->num[i]!=NULL)
					flag = 1;
			}
			temp->end = 1;
		}
		//pi(flag);
		//endl;
		ch = NULL;
	}
	temp = NULL;
	return ;	
}

/*void print()
{
	int i,j;
	node *temp;
	temp = malloc(sizeof(node));
	temp = head;
	for(i=0;i<11;i++)
	{
		if(temp->num[i] != NULL)
		{
			pi(i);space;pi(temp->num[i]->data);space;pi(temp->num[i]->end);
			tab;
			endl;

		}
	}
	return;
}*/

int  main()
{
	int t,n,i,j,ans=0,as;
	char str[10];
	gi(t);
	while(t--)
	{
		gi(n);
		flag = 0;
		head = malloc(sizeof(node));
		for(i=0;i<11;i++)
			head->num[i] = NULL;
		for (i=0;i<n;i++)
		{
			scanf("%s",str);
			insert(str,head);
		}
//		print();
		if(flag == 1)
			printf("NO");
		else 
			printf("YES");
		endl;
		head = NULL;
	}		
	return 0;
}
