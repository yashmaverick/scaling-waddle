#include<stdio.h>
int n,count,flag=0,old=0,new=0;
char a[10000][100];

void append(int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		scanf("%s",a[new]);
		new++;
	//	printf("n:%d\n",n);
		new=(new)%n;
		count++;
		if(count>n-1)
		{
			count=n;
			flag=1;
		}
		if(flag==1)
			old=new;
	//	printf("flag:%d,count:%d",flag,count);
	//	printf(";old:%d,new:%d\n",old,new);
	}
}

void list()
{
	int i=old;
	if(flag==0 && old==new)
		return;
	while(1)
	{
		printf("%s\n",a[i]);
		i++;
		i=(i)%n;
		if(i==new)
			return ;
	}
}

void rem(int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		old++;
		old=(old)%n;
		count--;
		if(count<n)
			flag=0;

	//	printf("flag:%d,count:%d",flag,count);
	//	printf(";old:%d,new:%d\n",old,new);
	}
}


int main()
{
	int m;
	char c;
		scanf("%d",&n);
	while(1)
	{
		scanf("%c",&c);
		if(c=='Q')
			return 0;
		else if(c=='L')
			list();
		else if(c=='A')
		{
			scanf("%d",&m);
			append(m);
		}
		else if(c=='R')
		{
			scanf("%d",&m);
			rem(m);
		}
	}
	return 0;
}

