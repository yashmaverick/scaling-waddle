#include<stdio.h>
long long int top=-1,A[100001],S[100001];
void push(long long int i)
{
	top=top+1;
	S[top]=i;
}
void pop()
{
	if(top==-1)
		return ;
	else
		top=top-1;
}
long long int topv()
{
	return top;
}
int main()
{
	long long int i,bar,n,p;
	long long int max=0,area;
	p=1;
	while(p==1)
	{
		max=0;
		scanf("%lld",&n);
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		i=0;
		while(i<n)
		{
			if(A[i]>=A[S[topv()]] || topv()==-1)
			{
				push(i);
				i++;
			//	printf("tooop=%lld\n",S[topv()]);
			//	printf("i=%lld \n",i);
			}
			else
			{
				bar=S[topv()];
				pop();
			//	printf("bar=%lld\n",bar);
			//	printf("topv=%lld\n",topv());
			//	printf("s=%lld \n",S[topv()]);
				if(topv()==-1)
					area=i*A[bar];
				else
					area=A[bar]*(i-S[topv()]-1);
				if(max<area)
				{
					max=area;
			//		printf("maxarea=%lld\n",max);
				}	
			}
		}
	//	for(i=0;i<n;i++)
	//		printf("s=%lld ",S[i]);
	//	printf("\n");
		while(topv()!=-1)
		{
	//		printf("i=%lld \n",i);
			bar=S[topv()];
	//		printf("bar=%lld \n",bar);
	//		printf("Abar=%lld \n",A[bar]);
			pop();
	//		printf("topv=%lld \n",topv());
			if(topv()==-1)
				area=i*A[bar];
			else
			{
				area=A[bar]*(i-S[topv()]-1);
			}
			if(max<area)
			{
				max=area;
	//			printf("max=%lld \n",max);
			}
		}
		if(max!=-1)
			printf("%lld\n",max);
	}
	return 0;
}
