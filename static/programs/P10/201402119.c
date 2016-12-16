#include<stdio.h>

int n,start=0,end=-1;
char a[10005][100];
int flag=0;

void append(int data)
{
	while(data--)
	{
		if(end == n-1+start)
		{
			flag=1;
			end =-1;	
		}
		end++;
		scanf("%s",a[end]);
	}
}
void remov(int data)
{
	while(data--)
	{	
		start++;
		if(start == n)
		{
			start=end+1;
		}
	}
}

void list()
{
	int i;
	if(flag)
	{
		for(i=0;i<=end;i++)
		{
			printf("%s\n",a[i]);
		}
	}
	else
	{
		for(i=start;i<=end;i++)
		{
			printf("%s\n",a[i]);
		}
	}
}


int main()
{
	int m;
	char c;
	scanf("%d",&n);
	getchar();
	while(1)
	{
		scanf("%c",&c);
		if(c == 'A')
		{
			scanf("%d",&m);
		//	getchar();
			append(m);
		}
		else if(c == 'L')
		{
			list();
		}
		else if(c == 'R')
		{
			scanf("%d",&m);
		//	getchar();
			remov(m);
		}
		else if(c =='Q')
		{
			break;
		}
	}
	return 0;
}
