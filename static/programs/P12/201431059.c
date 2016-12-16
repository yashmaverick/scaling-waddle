#include<stdio.h>
#include<limits.h>
#define N 500002
int S[N];
int head=-1;
int A[N];
long long int R[N];
long long int n;

long long int nCr(int n,int r)
{
	if(r==1)
		return (long long int)n;
	else 
		return ((long long int)n*nCr(n-1,r-1))/(long long int)r;
}



void readInput()
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",A+i);
}

long long canSee()
{
	int i;
	head=-1;
	S[++head]=n-1;
	long long int M=0;
	R[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		int f=0;
		while((head+1)>0)
		{
			if(A[i]>=A[S[head]])
			{
				f=1;
				if(A[S[head]]==A[i])
					R[i] = R[S[head]]+1;
				else
					R[i]=0;
				M+=R[S[head]];
				head--;
				M++;

			}
			else
			{
				if(!f)
					R[i]=0;
				break;
			}
		}
		if(head>=0)
			M++;
		S[++head]=i;
	}
	return M;

}

int main()
{
	scanf("%lld",&n);
	while(n>0)
	{
		readInput();
		printf("%lld\n",nCr(n,2) - canSee());
		scanf("%lld",&n);
	}
	return 0;
}
