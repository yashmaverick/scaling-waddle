#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie{
	int val;
	struct trie *c[12];
}t;
char s[100000][12];
int main()
{
	t *head,*x,*y,*temp;
	int i,j,k,v,tst,n,l,flag;
	char u;
	scanf("%d",&tst);
	while(tst--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		head=malloc(sizeof(t));
		head->val='_';
		for(i=0;i<n;i++)
		{
			temp=head;
			flag=0;
			l=strlen(s[i]);
			for(j=0;j<l;j++)
			{
				u=s[i][j];
				//printf("u=%d\n",u);
				v=u-'0';
				//printf("v=%d\n",v);
				if(temp->c[v]!=NULL)
				{
					if(j==l-1)
					{
						flag=1;
						printf("NO\n");
						break;
					}
					temp=temp->c[v];
					continue;
				}
				else
				{
					if(j!=0  && i!=0)
					{
						if(temp->c[10]!=NULL)
						{
							flag=1;
							printf("NO\n");
							break;
						}
					}
					if(j==l-1)
					{
						x=malloc(sizeof(t));
						x->val=v;
						temp->c[v]=x;
						temp=temp->c[v];
						x=malloc(sizeof(t));
						x->val=-1;
						temp->c[10]=x;
					}
					else
					{
						x=malloc(sizeof(t));
						x->val=v;
						temp->c[v]=x;
						temp=temp->c[v];
					}


				}

			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("YES\n");
	}
	return 0;
}
