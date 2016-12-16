#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int den;
typedef struct child
{
	int val;
	struct child *branches[10];
}child;
typedef struct trie
{
	child *node;
	int cnt;
}trie;
child *defi()
{
	child *d=NULL;
	d=(child*)malloc(sizeof(child));
	if(d)
	{
		int i;
		
		for(i=0;i<10;i++)
		{
			d->branches[i]=NULL;
		}

		d->val=0;
	}
	return d;
}
void initialize(trie *d)
{
	
	d->cnt=0;
	d->node=defi();
}
void inst(trie *d,char a[])
{
	child *e;
	d->cnt=d->cnt+1;
	e=d->node;
	int w;
	int len;
	len=strlen(a);
	for(w=0;w<len;w++)
	{
		int r;
		r=(int) a[w]-(int) '0';
		if(!e->branches[r])
		{
			e->branches[r]=defi();
		}
		e=e->branches[r];
	}
	if(e->val!=0)
	{
		den=2;
		e->val=d->cnt;
	}
	else
		e->val=d->cnt;
}
int srch(trie *d, char a[])
{
	
	
	child *e;
	e = d->node;
	int i;
	int lnt;
	lnt = strlen(a);
	for( i = 0; i < lnt; i++ )
	{
		int r;
		r=(int) a[i]-(int) '0';
		
		e = e->branches[r];
	}
	for(i=0;i<10;i++)
	{
		if(e->branches[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		den=1;
		int numb,i;
		trie tr;
		initialize(&tr);
		scanf("%d",&numb);
		char a[numb][11];
		for(i=0;i<numb;i++)
		{
			scanf("%s",a[i]);
			if(den!=2)
				inst(&tr,a[i]);
			/*if(den==2)
			  {
			  printf("NO\n");
			  break;
			  }*/
		}
		if(den==2)
		{
			printf("NO\n");
		}

		if(den!=2)
		{
			int y;
			for(i=0;i<numb;i++)
			{
				y=srch(&tr,a[i]);
				if(y==1)
				{
					printf("NO\n");
					break;
				}
			}
			if(y==0)
				printf("YES\n");
		}
	}
	return 0;
}
