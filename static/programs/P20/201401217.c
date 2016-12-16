#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
node* insert(node* root,int value)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->val=value;
	temp->next=NULL;
	return temp;
}
node* arr[1000003];
char array[1000003];
int arra[1000003];
int n,indx,answer=0,count=0,qw=0;
void bfs(int i)
{
//	if(qw>=n)
//		return;
	node* p;
	p=arr[i]->next;
	while(p!=NULL)
	{
		if(array[(p->val)-1]=='1')
		{
			p=p->next;
			continue;
		}
		array[(p->val)-1]='1';
		qw++;
		arra[(p->val)-1]=arra[i]+1;
		if(arra[(p->val)-1]>answer)
		{
			answer=arra[(p->val)-1];
			indx=p->val;
//			printf("djkhsdjk%d\n",indx);
		}	
//		if(qw>=n)
//			return;
		bfs((p->val)-1);
		p=p->next;
	}
	return;
}
int main()
{
	int t,x,y,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		node*p;
		for(i=0;i<n;i++)
		{
			arr[i]=(node*)malloc(sizeof(node));
			arr[i]->next=NULL;
			arr[i]->val=0;
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			p=insert(arr[x-1]->next,y);
			p->next=arr[x-1]->next;
			arr[x-1]->next=p;
			p=insert(arr[y-1]->next,x);
			p->next=arr[y-1]->next;
			arr[y-1]->next=p;
		}
		for(i=0;i<n;i++)
		{
			arra[i]=0;
			array[i]='0';
		}
		answer=0;
		indx=1;
		array[0]='1';
		arra[0]=1;
		bfs(0);
		qw=0;
//		for(i=0;i<n;i++)
//		{
//			printf("array%d arra%d\n",array[i],arra[i]);
//		}
		for(i=0;i<n;i++)
		{
			arra[i]=0;
			array[i]='0';
		}
		arra[indx-1]=1;
		array[indx-1]='1';
//		printf("indx%d\n",indx);
//		printf("ans%d\n",answer);
		answer=0;
		bfs(indx-1);
		printf("%d\n",answer);
	}
	return 0;
}
