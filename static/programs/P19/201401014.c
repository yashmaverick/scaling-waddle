#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct trie{
	char key;
	int end;
	struct trie *str[11];
};
typedef struct trie trie;
int flag;
int main()
{
	long long int n,i,j,l,k,test,o,q;
	char S[11],c;
	scanf("%lld",&test);
	trie *root;
	root=(trie*)malloc(sizeof(trie));
	root->key='^';
	root->end=0;
	while(test--)
	{
		trie *root,*curr;
		root=(trie *)malloc(sizeof(trie));
		root->key='^';
		root->end=0;
		for(o=0;o<10;o++)
			root->str[o]=NULL;
		scanf("%lld",&n);
		flag=0;
		if(n!=0)
		{
			for(i=0;i<n;i++)
			{
				scanf("%s",S);
				l=strlen(S);
				k=0;
				curr=root;
				if(flag==0)
				{
					while(S[k]!='\0')
		 			{
							if(curr->str[S[k]-'0']==NULL)
							{
								trie *temp;
								temp=(trie *)malloc(sizeof(trie));
								temp->key=S[k];
								temp->end=0;
								for(q=0;q<10;q++)
									temp->str[q]=NULL;
								curr->str[S[k]-'0']=temp;
								curr=curr->str[S[k]-'0'];
							}
							else if(curr->str[S[k]-'0']!=NULL && curr->str[S[k]-'0']->key==S[k])
							{
								if(curr->str[S[k]-'0']->end==1)
									flag=1;
								else
								{
									curr=curr->str[S[k]-'0'];
									if(S[k+1]=='\0' && curr->end==0)
										flag=1;
								}
							}
						k++;
					}
				}
				if(S[k]=='\0')
				{
					if(curr->end!=1)
						curr->end=1;
					else 
						flag=1;
				}
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
		root=NULL;
	}
	return 0;
}
