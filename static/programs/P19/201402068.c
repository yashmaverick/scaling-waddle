#include <stdio.h>
#include <stdlib.h>
int flag;
typedef struct num{
	int val;
	struct num *arr[10];
}num;
num *root;
void insert(char *s);
void search(char *s);
num *setnull();

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);getchar();
		int count=n;
		root=setnull();
		flag=1;
		while(count--)
		{
			char s[100000];
			scanf("%s",s);
		//	printf("input is=%s\n",s);
			if(count==n-1)
			{
			    insert(s);
				continue;
			}
			else
			{
            if(flag==0)
				continue;
			search(s);
			if(flag==1)
			insert(s);
			}
		}
		if(flag==0)
			printf("NO\n");
		else if(flag==1)
			printf("YES\n");
	}
	return 0;
}
num *setnull()
{
	int i;
	num *temp=(num *)malloc(sizeof(num));
	temp->val=-9999;
	for(i=0;i<10;i++)
	{
		temp->arr[i]=NULL;
	}
	return temp;
}


void insert(char *s)
{
	num *temp=root;
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		int ins=(int)s[i]-48;
		//printf("%d\n",ins);
		if(temp->arr[ins]==NULL)
		{
		//	printf("insertion done\n");
			temp->arr[ins]=setnull();
		}
		temp=temp->arr[ins];
	}
	temp->val=i;
}

void search(char *s)
{
	int i;
	num *temp=root;
	for(i=0;s[i]!='\0';i++)
	{
		int ins=(int)s[i]-48;
		//printf("%d\n",ins);
		if(temp->arr[ins]!=NULL)
		{
			//printf("searching going on\n");
			temp=temp->arr[ins];
		}
		else if(temp->arr[ins]==NULL && i>0 && temp->val!=-9999)
		{
			//printf("became 1 0\n");
			flag=0;
			return;
		}
		else
		{
			flag=1;
			return;
		}
	}
//	printf("became 2 0\n");
	flag=0;
	return;
}
