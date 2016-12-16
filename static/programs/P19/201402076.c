#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trienode
{
	char val;
	struct trienode* pt[10];
	int partial;
	int total;
};
typedef struct trienode trienode;
char c[20];
int len;
int ans=0;
trienode* inserttrie(trienode* head,int p)
{
	if(head==NULL)
	{
		head=(trienode*)malloc(sizeof(trienode));
		head->val=c[p];
		head->partial=0;
		head->total=0;
	}
	if(p==len-1)
	{
		if(head->total==1)
			ans=1;
		head->total=1;
	}	
	else
	{
		head->partial=1;
		head->pt[c[p+1]-'0']=inserttrie(head->pt[c[p+1]-'0'],p+1);
	}
	if(head->partial==1&&head->total==1)
		ans=1;
	return head;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		trienode* head=NULL;
		head=(trienode*)malloc(sizeof(trienode));
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			len=strlen(c);
			head->pt[c[0]-'0']=inserttrie(head->pt[c[0]-'0'],0);
		}
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;
}
