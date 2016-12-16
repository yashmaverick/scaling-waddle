#include <stdio.h>
#include <string.h>
int main()
{
	long long int nb,n=0;
	char a[10000][100];
	char s[150];
	char s1;
	long long int d,i,j;
	long long int start=0;
	long long int end=0;
	scanf("%lld",&nb);
	while(1)
	{
		scanf(" %c",&s1);
		if (s1 == 'A')
		{
			scanf("%lld",&d);
			for (i = 0; i < d; i++)
			{
				if (end == nb)
					end = 0;
				scanf("%s",s);
				if (n >= nb)
				{
					strcpy(a[end],s);
					end++;
					start++;
				}
				else
				{	
					strcpy(a[end],s);
					end++;
					n++;
				}
			}
		}
		if (s1 == 'R')
		{
			scanf("%lld",&d);
			start = (start+d)%nb;
			n -= d;
		}
		if (s1 == 'L')
		{
				for (i = 0; i < n; i++)
				{
					j = (start+i)%nb;
					printf("%s\n",a[j]);
				}
		}
		
		if (s1 == 'Q')
			break;
	}
	return 0;
}
