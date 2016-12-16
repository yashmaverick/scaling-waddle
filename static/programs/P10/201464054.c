#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
int main()
{
	ll N,front,rear,elements,full;
	char arr[10005][105];
	char query,tmp[105];
	ll i,j,n,ct=0;
	sll(N);
	front=0;	rear=-1;	elements=0;	full=0;
	getchar();
	while(1)
	{
		scanf ("%c",&query);
	//	printf("%c",query);
		if (query=='Q')
			break;
		else if (query=='A')
		{
			sll(n);
			f0(i,n)
			{
				sst(tmp);
				if (elements<N)
					elements++;
				rear++;
				rear%=N;
				if (rear==front && elements==N)
				{
					front++;
					front%=N;
				}
				strcpy(arr[rear],tmp);
			}
		}
		else if (query=='R')
		{
			sll(n);
			f0(i,n)
			{
				front++;
				front%=N;
				elements--;
			}
		}
		else if (query=='L')
		{
			if (elements>0)
			{
				i=front;
				while (i!=rear)
				{
					pst(arr[i]);
					i++;
					i%=N;
				}
				pst(arr[rear]);
			}
		}
//		printf ("elements = %lld front = %lld rear = %lld\n",elements,front,rear);
	//	for (i=0;i<5;i++)
	//		pst(arr[i]);
	}
	return 0;
}
