#include<stdio.h>
#include<limits.h>

#define MAXN 100001
int S[MAXN];
int head=-1;
int L[MAXN];
int R[MAXN];
long long A[MAXN];
int n;

void preComputeLeft()
{
	int i;
	A[0] = INT_MIN;
	S[++head]=0;
	for(i=1;i<=n;i++)
	{
		while(A[S[head]]>=A[i])
			head--;
		L[i] = S[head];
		S[++head]=i;
	}

}


void preComputeRight()
{
	int i;
	head=-1;
	S[++head] =n+1;
	for(i=n;i>=1;i--)
	{
		while(A[S[head]]>=A[i])
			head--;
		R[i] = S[head];
		S[++head]=i;
	}


}

void readInput()
{
	int i;
	for(i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	A[n+1]=INT_MIN;


}

void clearStack()
{
	head=-1;
}

void printOutput()
{
	int i;
	long long int ans = 0;
	for(i=1;i<=n;i++)
	{
		long long int temp = A[i]*(R[i]-L[i]-1);
		if(ans<temp)
			ans=temp;
	}
	printf("%lld\n",ans);

}

int main()
{
	scanf("%d",&n);
	while(n>0)
	{
		readInput();
		preComputeLeft();
		clearStack();
		preComputeRight();
		printOutput();
		scanf("%d",&n);
	}
	return 0;
}
