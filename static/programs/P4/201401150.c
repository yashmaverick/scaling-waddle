#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pair struct pair
typedef int (*compfn)(const void*, const void*);

pair
{
	int x,y;
};

void printAoS(pair A[],int n)
{
	int i;
	for(i=0;i<n;i++)	
		printf("%d %d\n",A[i].x,A[i].y);	
}

int comp(pair *a,pair *b)
{
	if((a->x)==(b->x) && (a->y)<(b->y))
		return -1;
	else if((a->x)<(b->x))
		return -1;
	else if((a->x)==(b->x) && (a->y)>(b->y))
		return 1;
	else if((a->x)>(b->x))
		return 1;
	else
		return 0;		
}

int tSum(int x)
{
	return (x-1)*(x)/2;
}

void Sum(pair A[],int n)
{
	int i,sum=0,t=1;
	for(i=0;i<n-1;i++)
	{
		if(A[i].x==A[i+1].x && A[i].y==A[i+1].y)
			t++;
		else
		{
			sum+=tSum(t);
			t=1;
		}
	}
	sum+=tSum(t);
	printf("%d\n",sum);
}

int main()
{
	int i,t,j,m,r,k;char c[100000],ch;pair A[100001];	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		j=m=0;
		scanf("%s",c);
		int length=strlen(c);
		for(k=0;k<length;k++)
		{
			if(c[k]=='J')
				j++;
			if(c[k]=='M')
				m++;
			if(c[k]=='R')
			{j--;m--;}
			A[k].x=j;A[k].y=m;
		}
		A[length].x=0;A[length].y=0;
		qsort((void*)&A,length+1,sizeof(pair),(compfn)comp);
		Sum(A,length+1);
	}

	return 0;
}