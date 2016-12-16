#include<stdio.h>
int logfunc(int N)
{
	int ret=0;
	while(N>1)
	{
		N=N/2;
		ret++;
	}
	return ret;
}
int main()
{
	int N, T,L, left,right,ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		L=logfunc(N);
		left=1<<L;
		right=left*2-1;
	
		if(N-left<right-N)
			ans=2*L-1;
		else
			ans=2*L;
		
		//printf("Left: %d Right: %d Level: %d Ans:%d\n",left,right,L,ans);
		printf("%d\n", ans);
	}
	return 0;
}


