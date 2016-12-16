#include<stdio.h>
#include<stdlib.h>
int bit;
typedef struct try try;
struct try{
	int set;
	try* a[10];
};
int count;
try* insert(char* s,try* c,int k)
{
	if(s[k]=='\0')
	{
		c->set=1;
		if(count==0)
			bit=0;
		return c;
	}
	if(c->set==0)
	{
		if(c->a[s[k]-'0']==NULL)
		{
			count++;
			c->a[s[k]-'0']=malloc(sizeof(try));
		}
	}
	else
	{
		bit=0;
		return c;
	}
	c->a[s[k]-'0']=insert(s,c->a[s[k]-'0'],k+1);
	return c;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,i;
		bit=1;
		scanf("%d",&n);
		try* b;
		b=malloc(sizeof(try));
		for(i=0;i<n;i++)
		{
			char q[11];
			scanf("%s",q);
			count=0;
			if(bit!=0)
			{
				b=insert(q,b,0);
			}
		}
		if(bit==0)
			printf("NO\n");
		if(bit==1)
			printf("YES\n");
	}
	return 0;
}
