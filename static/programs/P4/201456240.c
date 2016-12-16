#include <stdio.h>

const int maxL = 1e7;

long long hash[(int)1e7];
int occ[(int)1e7];
long long FC[(int)1e7];
char str[(int)1e7];

int h(long long val)
{
	    return ((unsigned)(1e9+7)*(unsigned)(val))%(maxL);
}
int main()
{
	int i, j, k, t;

	int T;
	scanf("%d ",&T);

	for(t=0;t<T;++t)
	{
		int L;

		scanf(" %s",str);
		for(L=0;str[L];++L)
		{
		          if (str[L]=='J')
				  FC[L] = 1e9+1;
			  else if( str[L]=='M')
				  FC[L] = -1;
			  else
				  FC[L] = -1e9;

		}

		hash[h(0)] = 0;
		occ[h(0)] = 1;

		long long sum = 0, ans = 0;
		for(i=0;i<L;++i)
		{
			sum += FC[i];
			int hv = h(sum);

			if(occ[hv] == 0)
			{
				occ[hv] = 1;
				hash[hv] = sum;
			}
			else if(hash[hv] == sum)
			{
				ans += occ[hv];
				occ[hv]++;
			}
			else
			{
				j = hv;
				while(1)
				{
					if(occ[j] == 0)
					{
						occ[j] = 1;
						hash[j] = sum;
					}
					else if(hash[j] == sum)
					{
						ans += occ[j];
						occ[j]++;
					}

					j = (j+1)%maxL;
				}
			}
		}

		occ[h(0)] = 0;
		sum = 0;
		for(i=0;i<L;++i)
		{
			sum += FC[i];
			int hv = h(sum);

			while(occ[hv]!=0)
			{
				occ[hv] = 0;
				hv = (hv+1)%maxL;
			}
		}

		printf("%lld\n",ans);
	}

	return 0;
}
