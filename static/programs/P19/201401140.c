#include<stdio.h>
#include<stdlib.h>
int vee=0;
typedef struct node{
	int no;
	struct node *arr[10];
}node;
void check(node* head)
{
//	if(vee==1)
//		return;
	int j=0;
	int k=0,l=0;
	while(j<=9)
	{
		if(head->arr[j]!=NULL)
		{
//			printf("head->arr[%d]->no=%d\n",j,head->arr[j]->no);
			if(head->arr[j]->no==0)
				k++;
			else
				k=k+head->arr[j]->no;
			l++;
		}
		j++;
	}
//	printf("k=%d l=%d head->no=%d",k,l,head->no);
//	printf("\n");
	if(k==head->no || l==head->no)
	{
		j=0;
		while(j<=9)
		{
			if(head->arr[j]!=NULL)
				check(head->arr[j]);
			j++;
		}
	}
	else
		vee=1;
	return;
}
node* make()
{
	node* temp;
	temp=malloc(sizeof(node));
	temp->no=0;
	int i=0;
	while(i<10)
	{
		temp->arr[i]=NULL;
		i++;
	}
	return temp;
}
node* func(node* head,char c[])
{
	int i,j;
	i=0;
	node *temp1;
	temp1=head;
	while(c[i]!='\0')
	{
		j=c[i]-'0';
		if(head->arr[j]==NULL)
			head->arr[j]=make();
		head->no=head->no+1;
		head=head->arr[j];
		i++;
	}
//	printf("%d\n",temp1->no);
	return temp1;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j;
		char c[11];
		vee=0;
		node* head;
		head=make();
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%s",c);
			head=func(head,c);
		}
		check(head);
		if(vee==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
