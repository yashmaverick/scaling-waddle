#include<stdio.h>
char a[10000][100];
int oldest=-1,latest=-1,sz;
void append()
{
	if(latest==-1)
	{
		latest=0;
		oldest=0;
	}
	else if(latest==sz-1)
	{
		latest=0;
		if(oldest==0)
			oldest++;
	}
	else if(latest+1==oldest)
	{
		latest++;
		if(oldest<sz-1)
			oldest++;
		else
			oldest=0;
	}
	else
		latest++;
	scanf("%s",a[latest]);
	return;
}
void remov()
{
	int j;
	if(oldest==latest)
	{
		oldest=-1;
		latest=-1;
	}
	else if(oldest<latest)
	{
		a[oldest][0]='\0';
		oldest++;
	}
	else if(oldest>latest)
	{
		a[oldest][0]='\0';
		if(oldest==sz-1)
			oldest=0;
		else
			oldest++;
	}
	return;
}
void print()
{
	int i;
	if(oldest!=-1 && latest!=-1)
	{
	if(oldest<latest)
	{
		for(i=oldest;i<=latest;i++)
			printf("%s\n",a[i]);
	}
	if(oldest==latest)
	{
		printf("%s\n",a[oldest]);
	}
	if(oldest>latest)
	{
		for(i=oldest;i<sz;i++)
			printf("%s\n",a[i]);
		for(i=0;i<=latest;i++)
			printf("%s\n",a[i]);
	}
	}
	return;
}
int main()
{
	int n,m,c,i,d,j;
	scanf("%d",&sz);
	c=getchar();
	c=getchar();
	while(c!='Q')
	{
		if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				append();
			}
		}
		if(c=='R')
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
				remov();
		}
		if(c=='L')
		{
			print();
		}
		c=getchar();
		c=getchar();
	}
	return 0;
}
