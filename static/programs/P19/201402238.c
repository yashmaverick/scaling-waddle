#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int ll;
char s[105];

ll n,b;
typedef struct trie{
	ll exist;
	struct trie *digit[10];
}trie;                                                                                       

trie* insert(ll i,struct trie *node){
	if(i==n)
		return NULL;

	if(node!=NULL)
	{	
		if(node->exist ==1 && i==n-1)
		{
		b=1;
		//		printf("hello\n");		
		return NULL;	
		}	
	}
	ll y;
	//	printf("hello\n");
	if(node==NULL)
	{ 			node=(trie *)malloc(sizeof(trie));			
		for(y=0;y<10;y++)
			node->digit[y]=NULL;
		//			node->digit[y]->exist=0;
		//		printf("hello2\n");
	}
	else if(node->exist==2 )
	{
		b=1;
		//		printf("hello\n");		
		return NULL;
	}
	//	printf("hello\n");
	node->exist=1;	
	//	printf("hello\n");

	if(i==n-1)
		node->exist=2;
//	else
//		node->end=0;
	//	printf("%lld %lld %c\n",node->exist,node->end,s[i]);

	i++;
	if(s[i]>'0')
		s[i]-='0';
	node->digit[s[i]]=insert(i,node->digit[s[i]]);
	return node;
}

void del(trie *head)
{
	if(head==NULL)
		return;
	ll i;
	for(i=0;i<10;i++)
	{
		del(head->digit[i]);
//		free(head->digit[i]);
	}
	free(head);

}
 
 // if only exist exist=1 else exist=2(case of end) 
int main()
{		
	ll t,m;
	scanf("%lld",&t); 

	while(t--)
	{
		b=0;
		trie *a;
		a=(trie *)malloc(sizeof(trie));
		ll y,f=0,i;
		for(y=0;y<10;y++)
			a->digit[y]=NULL;

		a->exist=1;
		
		scanf("%lld",&m);
		while(m--)
		{
			f=0;
			if(b==0)
			{		
				scanf("%s",s);

				n=strlen(s);
//				printf("%lld\n",n);
				if(s[f]>'0')
				s[f]=s[f]-'0';
				a->digit[s[f]]=insert(f,a->digit[s[f]]);
			}
			else
				scanf("%lld",&n);
		}
		if(b==1)
			printf("NO\n");
		else
			printf("YES\n");
		
		del(a);

	}
	return 0;
}	