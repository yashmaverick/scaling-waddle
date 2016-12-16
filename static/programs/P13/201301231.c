#include <stdio.h>

long long int m[100000],glevel,leaf;

void postorder(long long int a[100000],long long int start ,long long int end,long long int level)
{
	if(start > end)
		return;
	if(start == end)
	{
		if( glevel <= level )
		{
			if(glevel!=level)
			{
				leaf=a[end];
				glevel=level;
			}
			else if(leaf > a[start])
			{
				leaf=a[end];
			}

		}

		return;
	}
	
	postorder(a,start,m[end],level+1);
	postorder(a,m[end]+1,end-1,level+1);

}

int main()
{
	long long int t,T,i,j,n,a[100000],s[100000],level,min,sp;

	scanf("%lld",&T);

	for(t=0;t<T;t++)
	{
		scanf("%lld",&n);

		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			m[i]=i-1;
		}

		glevel=0;
		leaf=1000000000;
		sp=-1;

		for(i=n-1;i>=0;i--)
		{
			while(sp>-1)
			{
				if(a[s[sp]] < a[i] )
					break;
				else if( a[s[sp]] > a[i])
				{
					m[s[sp]]=i;
					sp--;
				}
			}
			sp++;
			s[sp]=i;
		}

		/*for(i=0;i<n;i++)
			printf("%d ",m[i]);
		printf("\n");*/

		postorder(a,0,n-1,0);

		printf("%lld %lld\n",leaf,glevel);
	}

	return 0;
}
