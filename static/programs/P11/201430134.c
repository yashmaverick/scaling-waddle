#include<stdio.h>
#include<stdlib.h>
long long int push(long long int i,long long int stack[],long long int sp)
{
	sp=sp+1;
	//printf("%d ",sp);
	stack[sp]=i;
	return sp;
}
int main()
{
	long long int l[100002],r[100002],stack[100002],orig[100002];
	long long int p[100002];
	long long int sp;
	//printf("%d %d\n",sp,stack);
	long long int N,i,j,k,cnt;
	long long int max;
	scanf("%lld",&N);
	while(N!=0)
	{
	sp=-1;
	for(i=0;i<N;i++)
	{
		scanf("%lld",&orig[i]);
	}
	for(i=0;i<N;i++)
	{
		//cnt=0;
		if(sp==-1 || orig[i]>orig[stack[sp]])
		{
			sp=push(i,stack,sp);
			l[i]=0;
			//printf("l[%d] is %d\n",i,l[i]);
		}
		else
		{
			while(sp>=0 && orig[stack[sp]]>=orig[i])
			{
				sp=sp-1;
				//cnt++;
			}
			if(sp==-1)
			{
				l[i]=i;
				//printf("l[%d] is %d\n",i,l[i]);
				sp=push(i,stack,sp);
			}
			else
			{
			
				l[i]=i-stack[sp]-1;
				//printf("l[%d] is %d\n",i,l[i]);
				sp=push(i,stack,sp);
			}
		}
	}
	sp=-1;
	for(i=N-1;i>=0;i--)
	{
		//cnt=0;
		if(sp==-1 || orig[i]>orig[stack[sp]])
		{
			sp=push(i,stack,sp);
			r[i]=0;
				//printf("r[%d] is %d\n",i,r[i]);
		}
		else
		{
			while(sp>=0 && orig[stack[sp]]>=orig[i])
			{
				sp=sp-1;
				//cnt++;
			}
			if(sp==-1)
			{
				r[i]=N-i-1;
				//printf("r[%d] is %d\n",i,r[i]);
				sp=push(i,stack,sp);
			}
			else
			{
			
				r[i]=stack[sp]-i-1;
				//printf("r[%d] is %d\n",i,r[i]);
				sp=push(i,stack,sp);
			}
		}
	}
	for(i=0;i<N;i++)
	{
		l[i]=l[i]+r[i]+1;
	}
	for(i=0;i<N;i++)
	{
		p[i]=orig[i]*l[i];
	}
	max=p[0];
	for(i=0;i<N;i++)
	{
		if(p[i]>max)
		{
			max=p[i];
		}
	}
	printf("%lld\n",max);
	scanf("%lld",&N);
	}
	return 0;
}

