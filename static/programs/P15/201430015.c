#include<stdio.h>

long long int q[100004],c[100004];
long long int l=-1,r=-1;

void insert(long long int x)
{
	if(r==1000004)
	{
		return;
	}
	if((l==-1)||(r==-1))
	{
		l=0;
		r=0;
	}
	else
	{
		r++;
	}
	q[r]=x;
//	printf("inserting %lld lis: %lld ris:%lld\n",c[x],l,r);
}

int main()
{
	long long int flag[100004],i;
	long long int n,k,test,t,count;
	scanf("%lld",&test);
	while(test)
	{
		test--;
		scanf("%lld %lld",&n,&k);
		if(n==0)
		{

			continue;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
		}
			if(k==0)
		{
			for(i=0;i<n-1;i++)
			{
				printf("1000000001 ");
			}
			printf("1000000001\n");
			continue;
		}
		l=-1;
		r=-1;
		insert(0);
		for(i=1;i<n;i++)
		{
			if(q[l]<=(i-k))
			{
				l++;
			}
			if(c[q[r]]>c[i])
			{
				while(c[q[r]]>c[i])
				{
					r--;
					if((r<l)||(r==-1))
					{
						l=-1;
						r=-1;
						break;
					}
				}
			}
			insert(i);
			flag[i]=q[l];
//			for(t=l;t<=r;t++)
//			{
//				printf("%lld ",c[q[t]]);
//			}
//			printf("\n");
			
		}

		for(i=k-1;i<n-1;i++)
		{
			printf("%lld ",c[flag[i]]);
		}
		printf("%lld\n",c[flag[n-1]]);
	}
	return 0;
}	
