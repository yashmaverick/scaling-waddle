#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ll
{
	struct ll *s[11];
	int val;
}list;
list *head;
int flag=0;
void insert(char a[])
{
	list *temp,*ins;
	temp=head;
	int i=0,k,l,j;
	l=strlen(a);
	while(a[i]==0)
		i++;
//	printf("length=%d\n",l);
	while(i<l)
	{
		k=a[i];
		k=k-48;		
	//	printf("i=%d k=%d\n",i,k);	
		if(temp->s[k]==NULL)
		{
			ins=(list *)malloc(sizeof(list));
			ins->val=k;
			for(j=0;j<=10;j++)
				ins->s[j]=NULL;
			temp->s[k]=ins;
			temp=ins;
			i++;
		}
		else if(temp->s[k]!=NULL)
		{
			temp=temp->s[k];
			i++;
		}
		if(temp->s[10]!=NULL)
		{
			flag=1;
			break;
		}
//		printf("i=%d k=%d\n",i,k);	
		//printf("k=%d flag=%d\n",k,flag);
	}
	for(j=0;j<=10;j++)
	{
		if(temp->s[j]!=NULL)
			flag=1;
	}
	ins=(list *)malloc(sizeof(list));
	ins->val=-10;
	temp->s[10]=ins;
//	printf("flag=%d\n",flag);
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		char a[11];
		head=(list *)malloc(sizeof(list));
		head->val=-1;
		for(i=0;i<=10;i++)
			head->s[i]=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%s",a);
			insert(a);
	//		printf("\n");
		}
//		printf("flag=%d\n",flag);
		if(flag==1)
			printf("NO\n");
		else if(flag==0)
			printf("YES\n");
		flag=0;
	}
	return 0;
}
