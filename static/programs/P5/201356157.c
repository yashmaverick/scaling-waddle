#include<stdio.h>
#include <stdlib.h>
int scanarray(int lala[1000000],int size, int k);
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int find3num(int a[1000],int size,int sum)
{
	int move,l,i;
	qsort(a, size, sizeof(int), cmpfunc);
	for( i=0;i<size-2;i++)
	{
		l=size-1;
		move=i+1;
		while(move<l)
		{
			if((a[i]+a[move]+a[l])==sum)
{
				printf("YES\n");
                                return 1;
}
			else
				if((a[i]+a[move]+a[l])<sum)
					move++;
				else
					l--;
		}
	}
        printf("NO\n");
	return 0;
}
int main()
{
	int i,n,check;
	int N,K;
	int l,pass[1000000];
	char nights[1000000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &N, &K);
		for(l=0;l<N;l++)
		{
			scanf("%s",nights);
			scanf("%d",&pass[l]);
		}
		check=find3num(pass,N,K);
	}
	return 0;
}


