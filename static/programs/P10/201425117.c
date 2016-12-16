#include<stdio.h>
int MAX;
int s=0,e=0,p=0;
char b[10000][200];
void incr(int *a)
{
	*a=(*a+1)%MAX;
}
void Append(int i)
{
	while(i--)
	{
		if(p==MAX)
			incr(&s);
		else
			p++;
		scanf("%s",b[e]);
		incr(&e);
	}
}
void Remove(int i)
{
	while(i--)
	{
		p--;
		incr(&s);
	}
}
void List()
{
	int i=s,j=p;
	while(j--)
	{
		printf("%s\n",b[i]);
		incr(&i);
	}
}
int main()
{
	scanf("%d",&MAX);
	while(1)
	{
		char c;
		scanf("%c",&c);
		if(c=='A')
		{
			int i;
			scanf("%d",&i);
			Append(i);
		}
		else if(c=='R')
		{
			int i;
			scanf("%d",&i);
			Remove(i);
		}
		else if(c=='L')
		{
			List();
		}
		else if(c=='Q')
			break;
	}
	return 0;
}
