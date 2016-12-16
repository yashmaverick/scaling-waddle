#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *b[11];
	int count;
	int last;
}node;
typedef struct root
{
	node *d[11];
}root;
void insert(node **x,char c)
{
	int i;
	if(*x==NULL)
	{
		(*x)=(node *)malloc(sizeof(node));
		(*x)->count=1;
		(*x)->last=0;
		(*x)->data=c;
		for(i=0;i<11;i++)
			(*x)->b[i]=NULL;
	}
	else
	{
		(*x)->count++;
	}
}
int main()
{
	int test,n,u,teset;
	scanf("%d",&test);
	int i,j,k;
	char x;
	char s[11],f;
	int st=0;
	root *l;
	node **r,*p,*q;
	for(teset=0;teset<test;teset++)
	{
		l=(root *)malloc(sizeof(root));
		for(i=0;i<11;i++)
			l->d[i]=NULL;
		scanf("%d",&n);
		st=0;
		for(j=0;j<n;j++)
		{
			scanf("%s",s);
			f=s[0];
			r=&(l->d[f-'0']);
			u=0;
			while(s[u]!='\0')
			{
				insert(r,s[u]);
				u=u+1;
				if(s[u]!='\0')
					r=&((*r)->b[s[u]-'0']);
			}
			(*r)->last=1;
			p=l->d[f-'0'];
			k=0;
			while(p!=NULL)
			{
				q=p;
				k=k+1;
				x=s[k];
				if(p->count > 1 && p->last==1)
				{
					st=1;
					break;
				}
				if(x!='\0')
					p=q->b[x-'0'];
				else
					p=NULL;
			}
		}
		if(st==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
