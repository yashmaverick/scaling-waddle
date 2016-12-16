#include<stdio.h>
#include<string.h>
char s[10010][110];
int q;
int start=0;
void append()
{

	if(q==0)
	{
		return;
	}
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",s[start]);
		start+=1;
		start%=q;
	}
	return;
}


void list()
{
	if(q==0)
		return;
	int n;
	int x=start;
	x=x%q;
	int y;
	y=x;
	int flg=0;
	while(x!=y || flg==0)
	{
		flg=1;
		if(s[x][0]!='*')
		{	printf("%s\n",s[x]);
		}
		x+=1;
		x%=q;
	}
	return;
}

void pr()
{
	int i;
	for(i=0;i<q;i++)
		printf("%s %d |",s[i],i);
	printf("\n");
}

void remv()
{
	if(q==0)
	{
		return;
	}
	int d;
	scanf("%d",&d);
	int c=0;
	int x=start;
	x%=q;
	int y=x;
	while(c!=d)
	{
		if(s[x][0]!='*')
		{	
			c+=1;
			s[x][0]='*';
			x+=1;
		}
		else
			x+=1;
		x%=q;
		if(x==y)
			break;
		
	}	
	return;
}

void initialize()
{
	int i;
	for(i=0;i<q;i++)
	{
		s[i][0]='*';
	}
	return;
}






int main()
{
	scanf("%d",&q);
	int i;
	char c;
	initialize();
	scanf("%c",&c);
	while(c!='Q')
	{
		if(c=='A')
			append();
		if(c=='R')
			remv();
		if(c=='L')
			list();
		scanf("%c",&c);
	}
	return 0;
}
