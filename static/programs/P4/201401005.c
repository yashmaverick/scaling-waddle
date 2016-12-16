#include<stdio.h>
#include<stdlib.h>
long long int a[100007];
char s[100001];

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long int i, j, count=1, ans=0, len;
		scanf("%s", s);
		a[0] = 0;
		len = 0;
		i = 0;
		while((s[i])!='\0')
		{
			if(s[i] == 'J')
				a[i+1] = (a[i]+100007);
			else if(s[i] == 'M')
				a[i+1] = (a[i]-100006);
			else if(s[i] == 'R')
				a[i+1] = (a[i]-1);
			else 
				a[i+1]=a[i];
			len++;
			i++;
		}

		qsort(a, len+1, sizeof(long long int), compare);

		for(j=0; j<=len; j++)
		{
			if(a[j]==a[j+1])
				count++;
			else
			{
				if(count%2 == 0)
					ans += (count/2)*(count-1);
				else
					ans += ((count-1)/2)*count;
				count = 1;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
