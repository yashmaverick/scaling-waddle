#include<stdio.h>
#include<stdlib.h>
#define ll long long int
typedef struct trie{
	long long int end;
	struct trie* child[10];
}trie;
trie* root;
long long int flag;
void ranp()
{
	int x=2,y=3;
	int sum=x+y;
	return;
}
void funi()
{
	int x=3,y=5;
	int sum=x+y;
	return;
}
/*void insert(long long int a[],long long int j)
{
	if(root->child[a[j]]==NULL)
	{
	//	printf("1\n");
		root->child[a[j]]=(trie*)malloc(sizeof(trie));
	}
	else if(root->child[a[j]]->end==1)
	{
	//	printf("2\n");
		flag=1;
		return;
	}
	else if(j==0)
	{
	//	printf("3\n");
		flag=1;
		return;
	}
	trie* temp=root->child[a[j]];
	j--;
	while(j>=0)
	{
		if(temp->child[a[j]]!=NULL&&temp->child[a[j]]->end==1)
		{
	//		printf("4\n");
			flag=1;
			return;
		}
		else if(temp->child[a[j]]==NULL)
		{
	//		printf("5\n");
			temp->child[a[j]]=(trie*)malloc(sizeof(trie));
			temp->end=-1;
		}
		else if(j==0)
		{
	//		printf("6\n");
			flag=1;
			return;
		}
		temp=temp->child[a[j]];
		j--;
	}
	temp->end=1;
}*/
int main()
{
	long long int v,n,i,j,w,t,r[11],s,k;
	root=(trie*)malloc(sizeof(trie));
	root->end=999;
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		for(i=0;i<10;i++)
			root->child[i]=NULL;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&v);
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
if(root->child[r[j]]==NULL)
	{
	//	printf("1\n");
		root->child[r[j]]=(trie*)malloc(sizeof(trie));
	}
	else if(root->child[r[j]]->end==1)
	{
	//	printf("2\n");
		flag=1;
	}
	else if(j==0)
	{
	//	printf("3\n");
		flag=1;
	}
	trie* temp=root->child[r[j]];
	j--;
	while(j>=0)
	{
		if(temp->child[r[j]]!=NULL&&temp->child[r[j]]->end==1)
		{
	//		printf("4\n");
			flag=1;
		}
		else if(temp->child[r[j]]==NULL)
		{
	//		printf("5\n");
			temp->child[r[j]]=(trie*)malloc(sizeof(trie));
			temp->end=-1;
		}
		else if(j==0)
		{
	//		printf("6\n");
			flag=1;
		}
		temp=temp->child[r[j]];
		j--;
	}
	temp->end=1;
}
				//insert(r,j);
		}
		ranp();
		funi();
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}





