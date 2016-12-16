#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int value;
	struct list *next;
}list;
int count,n,res,flag;
int boo[1000000];
int ref[1000000];
list *itr;
list *head[1000000];
list *root[1000000];
void dfs(list *tmp)
{
	if(tmp==NULL)
		return ;
	ref[tmp->value]=1;
	res++;
	tmp=head[tmp->value];
	while(tmp!=NULL)
	{
		if(ref[tmp->value]!=1)
			dfs(tmp);
		tmp=tmp->next;
	}
	if(res==n)
		flag=1;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int j,k,a,b,c,w,x;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			boo[j]=0;
			head[j]=(list *)malloc(sizeof(list));
			root[j]=(list *)malloc(sizeof(list));
			head[j]->value=j;
			head[j]->next=NULL;
			root[j]->value=j;
			root[j]->next=NULL;
		}
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w);
			for(k=1;k<=w;k++)
			{
				scanf("%d",&x);
				list *tmp=(list *)malloc(sizeof(list));
				tmp->value=j;
				itr=head[x]->next;
				head[x]->next=tmp;
				tmp->next=itr;

				list *tt=(list *)malloc(sizeof(list));
				tt->value=x;
				itr=root[j]->next;
				root[j]->next=tt;
				tt->next=itr;
			}
		}
		for(j=1;j<=n;j++)
		{
			itr=head[j];
			if(boo[j]!=1)
			{
				flag=res=0;
				dfs(head[j]);
				if(flag==1)
				{
					//printf("%d\n",j);
					itr=root[j];
					while(itr!=NULL)
					{
						if(boo[itr->value]!=1)
							count++;
						boo[itr->value]=1;
						itr=itr->next;
					}
				}
				for(k=0;k<=n;k++)
					ref[k]=0;
			}
		}
		printf("%d\n",count);
		count=0;
		free(head[0]);
		/*for(j=1;j<=n;j++)
		  {
		  itr=head[j];
		  while(itr!=NULL)
		  {
		  printf("%d->",itr->value);
		  itr=itr->next;
		  }
		  printf("\n");
		  }*/
	}
	return 0;
}

