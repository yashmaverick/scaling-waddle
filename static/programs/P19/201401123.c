/*Rohan Karnawat*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s(n) scanf("%lld",&n)
#define d(n) tp n;n=(tp)malloc(1*sizeof(t))
#define f(i,n) for(i=0;i<n;i++)
#define endl printf("\n")
typedef long long ll;
typedef struct trie{
	struct trie* child[10];
	int flag[10];
}t;
typedef t* tp;
tp init_node()
{
	d(node);
	ll i;
	for(i=0;i<10;i++){
		node->child[i]=NULL;node->flag[i]=0;
	}
	return node;
}
int length;
ll n;
int insert(int* x,ll k,tp groot)
{
	ll i;
	int fag=0;
	int j;
	tp root;
	root=groot;
	for(i=0;i<k;i++)
	{
		if(root->child[x[i]]==NULL)
		{
			root->child[x[i]]=init_node();
			if(i==k-1)
				root->flag[x[i]]=1;
			else
				root->flag[x[i]]=0;
			root=root->child[x[i]];
		}
		else
		{
			if(i==k-1)
			{
				if(root->flag[x[i]]==1)
					return 1;
				else
					root->flag[x[i]]=1;
				for(j=0;j<10;j++)
				{
					if(root->child[x[i]]!=NULL)
					{
						fag=1;
						break;
					}
				}
				if(fag==1)
					return 1;
			}
			else if(root->flag[x[i]]==1)
			{
				return 1;
			}
			root=root->child[x[i]];
		}
	}
	return 0;
}
int main()
{
	tp groot;
	ll t;
	ll b,c,d;
	ll i,j,k,l,m,nn;
	char x[11];
	int a[11];
	int insert_flag,p;
	s(t);
	f(nn,t)
	{
		groot = init_node();
		s(n);
		b=n;
		insert_flag=0;
		while(n--)
		{
			f(m,10)
				x[m]='\0';
			length=0;
			k=0;
			scanf("%s",x);
			if(n==b)
			{
				c=0;
				for(l=0;x[l]!='\0';l++)
				{
					length+=1;
					a[k++]=x[l]-'0';
					c=1;
				}
				if(c==1)
					p=insert(a,k,groot);
			}
			else
			{
				c=0;
				for(l=0;x[l]!='\0' && insert_flag==0;l++)
				{
					length+=1;
					a[k++]=x[l]-'0';c=1;
				}
				if(c==1)
					insert_flag=insert(a,k,groot);
			}
		}
		if(insert_flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
