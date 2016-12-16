#include<stdio.h>
#include<stdlib.h>
#define ll long long int
typedef struct trie{
	ll end;
	struct trie *child[10];
}trie;
trie* root;
ll flag;
void insert(ll a[],ll j)
{
	if(root->child[a[j]]==NULL)
		root->child[a[j]]=(trie*)malloc(sizeof(trie));
	else if(root->child[a[j]]->end==1)
	{
		flag=1;
		return;
	}
	else if(j==0)
	{
		flag=1;
		return;
	}
	trie* temp=root->child[a[j]];
	j--;
	while(j>=0)
	{
		if(temp->child[a[j]]!=NULL && temp->child[a[j]]->end==1)
		{
			flag=1;
			return;
		}
		else if(temp->child[a[j]]==NULL)
		{
			temp->child[a[j]]=(trie*)malloc(sizeof(trie));
			temp->end=-1;
		}
		else if(j==0)
		{
			flag=1;
			return;
		}
		temp=temp->child[a[j]];
		j--;
	}
	temp->end=1;
	return ;
}
int main()
{
	ll a[100000],v;
	ll n,i,j,t,r[11],s,k;
	root=(trie* )malloc(sizeof(trie));
	root->end=99;
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		for(i=0;i<10;i++)
			root->child[i]=NULL;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			v=a[i];
			j=0;
			if(v==0)
				r[0]=0;
			else
			{
			while(v>0)
			{
				r[j]=v%10;
				v/=10;
				j++;
			}
			j--;
			}
			if(flag!=1)
			{
				insert(r,j);
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}





