#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int ab,ac;
}node;


int compare(node *a,node *b)
{
	int l1 = a->ab;
	int l2 = b->ab;
	int k1 = a->ac;
	int k2 = b->ac;
	if(l1==l2)
		return (k1-k2);
	else
		return (l1-l2);
}	

int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		node array[1000001];
		char s[100001];
		int i,l,a=0,b=0,c=0,ab=-1,ac=-1;
		scanf("%s",s);
		l=strlen(s);

		array[0].ab=0;
		array[0].ac=0;

		for(i=0;i<l;i++)
		{
			if(s[i]=='J')
				a++;
			if(s[i]=='M')
				b++;
			if(s[i]=='R')
				c++;
			array[i+1].ab=b-a;
			array[i+1].ac=c-a;
		}
		qsort (array,l+1, sizeof(node), compare);
		int count=0,ans=0;
		ab=array[0].ab;
		ac=array[0].ac;

		for(i=1;i<=l;i++)
		{
			if(array[i].ab==ab && array[i].ac==ac)
			{
				count++;
				ans = ans + count;
			}
			else
			{
				count=0;
				ab=array[i].ab;
				ac=array[i].ac;
			}

		}
		printf("%d\n",ans);
		test--;
	}
	return 0;
}
