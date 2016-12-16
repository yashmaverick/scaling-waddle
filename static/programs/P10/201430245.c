#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	char **a;
	a=(char **)malloc(sizeof(char *)*n);
	int i,j,k=0,l;
	for(i=0;i<n;i++)
	{
		a[i]=(char *)malloc(sizeof(char)*100);
	}
	char b;
	int first=0, last=0;
	while(scanf("%c",&b)!='Q')
	{
		if(b=='A')
		{
			scanf("%d",&j);
			if(first==0&&last==0)
			{
				scanf("%s",a[last]);
				k=1;
				for(i=1;i<j;i++)
				{
					last=(last+1)%(n);
					if(last==first)
					{
						first=(first+1)%(n);
					}
					scanf("%s",a[last]);
				}
			}
			else
			{
				for(i=1;i<=j;i++)
				{
					last=(last+1)%(n);
					if(last==first)
					{
						first=(first+1)%(n);
					}
					scanf("%s",a[last]);
				}
			}
		}
		else if(b=='R')
		{
			scanf("%d",&j);
			for(i=1;i<=j;i++)
			{
				if(first==last)
				{
					first=0;
					last=0;
					k=0;
					break;
				}
				first=(first+1)%(n);
			}
		}
		else if(b=='L')
		{
			if(first<last)
			{
				for(i=first;i<=last;i++)
				{
					printf("%s\n",a[i]);
				}
			}
			else if(last<first)
			{
				for(i=first;i<n;i++)
				{
					printf("%s\n",a[i]);
				}
				for(i=0;i<=last;i++)
				{
					printf("%s\n",a[i]);	
				}
			}
			else if(first==last&&k==1)
			{
				printf("%s\n",a[first]);
			}
		}
		else if(b=='Q')
		{
			break;
		}
	}
	return 0;
}
