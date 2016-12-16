#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char S[11];
}node;

typedef node* ptr;


node A[100000];



int cmp(const void* a, const void* b)
{
	ptr aa = (ptr)a; ptr bb = (ptr)b;
	int i = 0;
	while(aa->S[i] && bb->S[i])
	{
		if(aa->S[i]!=bb->S[i])
			return (aa->S[i] - bb->S[i]);
		i++;
	}
	return (aa->S[i] - bb->S[i]);
}
int f(int x, int y)
{
	int N = strlen(A[x].S);
	int M = strlen(A[y].S);
	if(N>M)
		return 0;
	int i;
	for(i=0; i<N;i++)
		if(A[x].S[i] != A[y].S[i])
			return 0;
	return 1;
}
int main()
{
	int test;	
	scanf("%d",&test);
	while(test--)
	{
		int flag = 0;
		int i,j,input;
		scanf("%d",&input);
		for(i=0;i<input;i++)
			scanf("%s",A[i].S); //input array
		qsort(A,input,sizeof(node),cmp);

		for(i=0;i<input-1;i++)	// 2 same inputs
		{
			if(f(i,i+1))
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
