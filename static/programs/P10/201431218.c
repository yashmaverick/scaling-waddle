#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char buffer[n][101];
	char c;
	int s=0,e=0,i=0;
	while(2>1)
	{	scanf("%c",&c);
		if(c=='A')
		{	int j;
			scanf("%d",&j);
			while(j--)
			{	if(i==n)
					s=(s+1)%n;
				else	i++;
				scanf("%s",buffer[e]);
				e=(e+1)%n;
			}
		}
		else if(c=='L')
		{	int j=i;
			int k=s;
			while(j--)
			{	printf("%s\n",buffer[k]);
				k=(k+1)%n;
			}
		}
		else if(c=='R')
		{	int j;
			scanf("%d",&j);
			while(j--)
			{	i--;
				s=(s+1)%n;
			}
		}
		else if(c=='Q')
			break;
	}
	return 0;
}
