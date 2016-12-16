#include<stdio.h>
int main()
{
	long long int s,e,n;
	int N;
	char a[10000][100];
	long long int i;
	char c;
	scanf("%d",&N);
	s=0;
	e=-1;
	getchar();
	while((c=getchar())!='Q')
	{
		if(c=='A')
		{
			scanf("%lld",&n);	
			if(e==s-1)
			{
				scanf("%s",a[(e+1)%N]);
				e++;
				for(i=1;i<n;i++)
				{
					if((e+1)%N==s%N)
						s++;
					scanf("%s",a[(e+1)%N]);
					e++;
				}
			}
			else
			{
				for(i=0;i<n;i++)
				{
					if((e+1)%N==s%N)
						s++;
					scanf("%s",a[(e+1)%N]);
					e++;
				}
			}
			getchar();
		}
		else if(c=='R')
		{
			scanf("%lld",&n);
			s+=n;
			getchar();
		}
		else if(c=='L')
		{
			getchar();
			for(i=s;i<=e;i++)
				printf("%s\n",a[i%N]);
		}
	}
	return 0;
}
