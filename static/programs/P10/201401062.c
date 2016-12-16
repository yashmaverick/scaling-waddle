#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

#define MAXN 10001

int main()
{
	char buff[MAXN][101];
	int N;
	din(N);
	int start = -1;
	int end = -1;
	char in = 'T';
	int i;
	while(in!='Q')
	{
		scanf("%c",&in);
		switch(in)
		{
			case 'A':{
					 int n;
					 din(n);
					 if(n==0)
						 continue;
					 int state = 0;
					 if(N==0)
					 {
						 for(i=0;i<n;i++)
							 FLUSHN;
						 continue;
					 }
					 for(i=0;i<n;i++)
					 {
						 end =	(end + 1)%N;
						 scanf("%s",buff[end]);
						 if(end == start)
							 state=1;
					 }
					 if(start==-1)
						 start = (n>N?end+1:0);
					 if(state)
						 start = end+1;
					 break;
				 }
			case 'R':{
					 int n;
					 din(n);
					 if(n==0)
						 continue;
					 if(N==0)
					 	continue;
					 if((start + n -1)%N == end)
						 start = end = -1;
					 else
						 start = (start+n)%N;
					 break;
				 }
			case 'L':{
					 if(start==-1 && end==-1)
						 continue;
					 for(i=start;i!=end;i = (i+1)%N)
						 printf("%s\n",buff[i]);
				 	 printf("%s\n",buff[end]);
					 break;
				 }
			default:
				 continue;

		}
	}
	return 0;
}
