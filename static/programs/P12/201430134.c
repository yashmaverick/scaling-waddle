#include<stdio.h>
long long int f(long long int mt[],long long int stack[500002][2],long long int t)
{
	long long int sp=-1;long long int cnt3=0;
	long long int i,j;
	for(i=0;i<t;i++)
	{
		if(sp==-1)
		{
			sp=sp+1;
			stack[sp][0]=mt[i];
			stack[sp][1]=1;
		}
		else if(mt[i]<stack[sp][0])
		{
			sp=sp+1;
			stack[sp][0]=mt[i];
			stack[sp][1]=1;
		}
		else if(mt[i]>stack[sp][0])
		{
			while(sp>=0 && mt[i]>stack[sp][0])
			{
				sp=sp-1;
			}
			if(sp==-1)
			{
				sp=sp+1;
				stack[sp][0]=mt[i];
				stack[sp][1]=1;
			}
			else
			{
				if(mt[i]<stack[sp][0])
				{
					sp=sp+1;
					stack[sp][0]=mt[i];
					stack[sp][1]=1;
				}
				else
				{
					cnt3=cnt3+stack[sp][1];
					stack[sp][1]++;
				}
			}
		}
		else
		{
			cnt3=cnt3+stack[sp][1];
			stack[sp][1]++;
		}
	}
	return cnt3;
}
int main()
{
	long long int t,i,max,j;long long int cnt1,cnt2,cnt3,total;
	long long int mt[500002],stack[500002][2];
	scanf("%lld",&t);
	while(t!=0)
	{
		cnt1=0;cnt2=0;
		for(i=0;i<t;i++)
		{
			scanf("%lld",&mt[i]);
		}
		max=mt[0];
		for(i=1;i<t;i++)
		{
			if(mt[i]<max)
			{
				cnt1++;
			}
			else
			{
				max=mt[i];
			}
		}
		max=mt[t-1];
		for(i=t-2;i>=0;i--)
		{
			if(mt[i]<max)
			{
				cnt2++;
			}
			else
			{
				max=mt[i];
			}
		}
		total=(t*(t-1))/2;
		cnt3=f(mt,stack,t);
		cnt3=cnt1+cnt2+cnt3;
		printf("%lld\n",total-cnt3);
		scanf("%lld",&t);
	}
	return 0;
}


