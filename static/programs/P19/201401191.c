#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef long long int ll;
struct node{
	char val;
	struct node* arr[11];
};
node* lol[11];
int ans;
void insert(char s[11])
{
	int i,jj;
	i=0;
	node* tmp=lol[s[i]-'0'];
	while(s[i]!='\0')
	{
		//	printf("%d",s[i]-'0');
		if(i==0&&lol[s[i]-'0']==NULL)
		{
			tmp=(node*)malloc(sizeof(node));
			tmp->val=s[0];
			for(jj=0;jj<11;jj++)
			{
				tmp->arr[jj]=NULL;
			}
			lol[s[i]-'0']=tmp;
		}
		else if(i==0)
		{
			tmp=lol[s[i]-'0'];
		}
		else if(tmp->arr[s[i]-'0']==NULL)
		{
			if((tmp->arr[10])!=NULL&&tmp->arr[10]->val=='_')
			{
				ans=1;
			} 
			node* temp=(node*)malloc(sizeof(node));
			temp->val=s[i];
			for(jj=0;jj<11;jj++)
			{
				temp->arr[jj]=NULL;
			}
			tmp->arr[s[i]-'0']=temp;
			tmp=temp;
		}
		else
		{
			if((tmp->arr[10])!=NULL&&tmp->arr[10]->val=='_')
			{
				ans=1;
			}
			tmp=tmp->arr[s[i]-'0'];
		}
		i++;
	}
	if((tmp->arr[10])!=NULL&&tmp->arr[10]->val=='_')
	{
		ans=1;
	}
	else
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->val='_';
		tmp->arr[10]=temp;
		for(jj=0;jj<10;jj++)
		{
			if(tmp->arr[jj]!=NULL)
			{
				ans=1;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n;
		for(i=0;i<11;i++)
		{
			lol[i]=NULL;
		}
		ans=0;
		scanf("%d",&n);
		while(n--)
		{
			char s[11];
			scanf("%s",s);
			if(ans!=1)
			{
			insert(s);
			}
		}
		if(ans==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
