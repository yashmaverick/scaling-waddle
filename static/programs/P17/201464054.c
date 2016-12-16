#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>=0;i--)
#define set(x,y) memset(x,y,sizeof(x));

int main()
{
	ll st,en,a,b,n,i;
	int pre[500005],in[500005];
	char arr[500005];
	/*f0(i,n){	pre[i]=0;	in[i]=0;	}*/
	sll(n);
	f1(i,n){sint(pre[i]);}
	f1(i,n){sint(in[i]);}
	TEST
	{
		sll(a);	sll(b);
		st=-1;	en=-1;
		set(arr,'0');
		f1(i,n){
			if (st!=-1)
				arr[in[i]]='1';
			if (in[i]==a || in[i]==b)
			{
				if (st==-1)
				{
					st=i;
					arr[in[i]]='1';
				}
				else
				{
					en=i;
					arr[in[i]]='1';
					break;
				}
			}
		}
		//pll(st);pll(en);
//		f1(i,n){printf ("%lld->%c ",i,arr[i]);}		printf ("\n");
		f1(i,n)
		{
			if (arr[pre[i]]=='1')
			{
				pint(pre[i]);
				break;
			}
		}

	}

	return 0;
}
