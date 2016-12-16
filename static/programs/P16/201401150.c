#include <stdio.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d\n",n)

int main()
{
	int N,Q,k,i,M,l;
	s(N);
	for(i=0;i<N;i++)
	{
		s(Q);k=1;l=0;
		if(Q==1)
			printf("0\n");
		else
		{	while(Q>=k)
			{
				k*=2;
				l++;
			}
			int M=k-k/4;
			if(Q<M)
				p(2*(l-1)-1);
			else
				p(2*(l-1));
		}
	}
	
	return 0;
}