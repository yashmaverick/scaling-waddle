#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
	int boolean;
	int p;
	struct node* next[10];
};
struct trie
{
	struct  node* root;
	int count;
};
struct node* new()
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->boolean=0;
	newnode->p=0;
	int i;
	for(i=0;i<10;i++)
		newnode->next[i]=NULL;
	return newnode;
}
void insert(struct trie* p,char* s)
{
	int len=strlen(s);
	struct node* temp=p->root;
	p->count++;
	int i;
	for(i=0;i<len;i++)
	{
		int index=(int)s[i]-'0';
		if(!temp->next[index])
		{
			temp->next[index]=new();
		}
		temp=temp->next[index];
		(temp->p)++;
	}
	temp->boolean=p->count;
}
 int check(struct trie* p,char* s)

{
	int len=strlen(s);
	struct node* temp=p->root;
	int i;
	for(i=0;i<len;i++)
	{
		int index=(int)s[i]-'0';
		if(!temp->next[index])
		{
			return 0;
		}
		temp=temp->next[index];
	}
	return temp->p;
}
//int func(char *a,char *b)
int func(const void * a, const void * b)
{
	return strcmp(a,b);
// return ( *(int*)a - *(int*)b );
}
void sort(int *arr, int fst, int last)
{
	int i,j,pivot,tmp;
	if(fst<last)
	{
		pivot=fst;
		i=fst;
		j=last;
		while(i<j)
		{
			while(arr[i]<=arr[pivot] && i<last)
				i++;
			while(arr[j]>arr[pivot])
				j--;
			if(i<j)
			{
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
		tmp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=tmp;
		sort(arr,fst,j-1);
		sort(arr,j+1,last);
	}
}
int main()
{
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--)
	{
		struct trie t;
	        t.root=new();
	        t.count=0;
		int f=0;
		scanf("%d",&n);
		char s[n][11];
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		if(n==1)
		{
			printf("NO\n");
			continue;
		}
		int ti=(sizeof(char))*11;
		qsort(s,n,ti,func);
//		for(i=0;i<n;i++)
//		{
//			printf("%s\n",s[i]);
//		}
		for(i=n-1;i>=0;i--)
		{
			insert(&t,s[i]);
			if(check(&t,s[i])>1)
			{
				f=1;
				break;
			}
		}
		if(f==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;		
}
