#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trie
{
	int leaf;
	struct trie * child[10];
};
void leaves(int k,int s)
{
	k=0;
}
int main()
{
	long long int t,n;
	scanf("%lld",&t);
	int s,w,k,i,j,l,flag,b,m,count;
	char a[20];
	long long int num,rem,tem;
	while(t>0)
	{
		count=0;
		scanf("%lld",&n);
		struct trie * dummy = (struct trie *)malloc(sizeof(struct trie)* 1);
		dummy -> leaf = 0;
		s=1;w=1,k=0;
		m=10;
		struct trie * temp = dummy;
		flag = 0;
		if(s==1)
		{
		for(i = 0; i < n;i++)
		{
			scanf("%s",a);
			temp = dummy;
			l = strlen(a);
			if(flag == 0)
			{
				if(w==1)
				{
			for(j = 0;j < l;j++)
			{
				rem = a[j]-'0';
				if(k==0)
				{
				if(temp->child[rem]==NULL)
				{
					temp->child[rem] = (struct trie *)malloc(sizeof(struct trie) * 1);
					temp->child[rem]->leaf = 0;
					temp = temp->child[rem];
					if(j == l-1)
					{
						temp->leaf = -1;
						count++;
						break;
					}
					if(k==1)
					{
						w=k;
					}
				}
				else
				{
					if(k==1)
					{
						w=1;
					}
				
					temp = temp->child[rem];
					if(j==l-1)
					{
						s=1;
					}
					if(j!=l-1)
					{
						w=1;
					}
					if(j == l-1)
					{
						flag = 1;
						temp->leaf = -1;
						count++;
						break;
					}
					else if(temp->leaf == -1)
					{
						flag = 1;
						count++;
						break;
					}
				}
				}
			}
			}
			}
		}
		leaves(k,s);
		if(k==0)
		{
		for(m=0;m<10;m++)
		{
			k=0;
			count++;
		}
		}
		if(flag == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		}
		t--;
	}
	return 0;
}
