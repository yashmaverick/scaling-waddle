#include<stdio.h>
#include<stdlib.h>
int stack;
typedef struct abbo
{
	int val;
	struct abbo* next;
}abbo;
void dfs(abbo* a[],int s[],int b[],int f)
{
	abbo* tmp;
	tmp=a[f]->next;
        if(b[f]==1)
	{
		return;
	}
	while(tmp!=NULL)
	{
		dfs(a,s,b,tmp->val);
		b[tmp->val]=1;
		tmp=tmp->next;
	}
		if(b[f]!=1)
		{
			s[stack]=f;
			stack++;
			b[f]=1;
		}
		return;


}
void insert(abbo* a[],int l,int k)
{
	abbo* tmp;
        tmp=malloc(sizeof(abbo));
	tmp->val=k;
	tmp->next=a[l]->next;
	a[l]->next=tmp;
	return;
}
int s[100001],b[100001],m;
abbo* a[100001];
int main()
{
	int n,i,j,l,k;
	scanf("%d%d",&m,&n);
	i=0;
	while(i<=m)
	{
		a[i]=malloc(sizeof(abbo));
		i++;
	}
	i=0;
	while(i<=m)
	{
		a[i]->next=NULL;
		b[i]=0;
		i++;
	}
	b[i]=0;
	i=0;
	while(i<n)
	{
		scanf("%d%d",&k,&l);
		insert(a,k,l);
//		printf("*\n");
		i++;
	}
	i=m;
	while(i>0)
	{
		dfs(a,s,b,i);
		i--;
	}
	i=stack-1;
	while(i>=0)
	{
		if(i!=0)
		{
			printf("%d ",s[i]);
		}
		else
		{
			printf("%d\n",s[i]);
		}
		i--;
	}
	return 0;

}
