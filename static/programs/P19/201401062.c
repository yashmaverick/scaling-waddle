#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define LL long long int
#define ULL unsigned long long int
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

typedef struct node{
	int val;
	struct node* child[10];
}node;

node init(int val)
{
	node temp;
	temp.val = val;
	int i;
	for(i=0;i<10;i++)
		temp.child[i] = NULL;
	return temp;
}
int ans;
void insert(node* head,char* str)
{
	if(*str == '\0')
	{
		int flag=1;
		int i;
		for(i=0;i<10;i++)
			if(head->child[i])
				flag=0;
		if(!flag || head->val)
			ans = 0;
		head->val = 1;
		return;
	}
	if(!head->child[*str - '0'])
	{
		head->child[*str-'0']=(node*)malloc(sizeof(node));
		*(head->child[*str-'0']) = init(0);
	}
	else if(head->child[*str-'0']->val)
		ans = 0;
	insert(head->child[*str-'0'],str+1);
}

node* erase(node* head)
{
	if(!head) return NULL;
	int i;
	for(i=0;i<10;i++)
		head->child[i] = erase(head->child[i]);
	free(head);
	return NULL;
}

int main()
{
	int t;si(t);
	while(t--)
	{
		node* trie = (node*)malloc(sizeof(node));
		*trie = init(0);
		int n;si(n);
		char str[11];
		ans = 1;
		while(n--)
			scanf("%s\n",str),insert(trie,str);
		printf("%s\n",ans?"YES":"NO");
		erase(trie);
	}

	return 0;
}
