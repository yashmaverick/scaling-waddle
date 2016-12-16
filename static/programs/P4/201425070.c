// #Authored : Jaipal Singh Goud
// Sem I-II
// Data Structures
// Assignment 1
// Problem 5

#include <stdio.h>

#define jchar 100000
#define rchar 1
#define mchar -100001

typedef struct pv{
	int val;
	int count;
}data;

void scanint(int *p);
int nc2(int x);
int permutations(int a[],int n);
int cmp(const void *a,const void *b);

int main()
{
	int test,i,j,k,n;
	char c;
	char x[100010];
	int a[100010];
	int presum[100010];
	int czero;
	int value = 0;
	scanf("%d",&test);
        getchar();
	while(test--)
	{
		int temp = 0;
		czero = 0;
		i=0;
		temp = 0;
                c = getchar();
		while(c!='\n' && c!=EOF)
		{
			if(c == 'J')
				temp = temp + jchar;
			else if(c == 'M')
				temp = temp + mchar;
			else if(c == 'R')
				temp = temp + rchar;
			a[i] = temp;
			if(temp == 0)
				czero++;
			i++;
                        c = getchar();
		}
		int len = i;

/*		printf("before sort-----------\n");
		for(i=0;i<len;i++)
			printf("%d\n",a[i]);
		presum[0] = a[0];
*/		
		/*
		 	for(j=1;j<len;j++)
		{
			presum[j] = presum[j-1]+a[j];
			if (presum[j] == 0)
				czero++;
		}
		*/

		qsort(a,len,sizeof(int),cmp);

//		mergesort(presum,0,len-1);

//		for(i=0;i<len;i++)
//			printf("%d\n",a[i]);
		value = permutations(a,len);
		printf("%d\n",value+czero);
	}
}

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int permutations(int a[],int n)
{
	int i,k;
	int temp,perm;
	int sum = 0;
	data var;
	var.val = a[0];
	var.count = 0;
	for(i=0;i<n;i++)
	{
		temp = a[i];
		if(var.val == temp)
			var.count++;
		else
		{
			perm = nc2(var.count);
			var.val = temp;
			var.count = 1;
			sum = perm + sum;
		}
	}
	perm = nc2(var.count);
	sum = perm + sum;
	return sum;
}

int nc2(int n)
{
	if(n<2)
		return 0;
	else
		return (n*(n-1))/2;
}
void scanint(int *p)
{
	register int c = getchar_unlocked();
	int x = 0;
	for(;(c<48 || c>57);c = getchar_unlocked())
		;
	for(;c>47 && c<58;c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	*p = x;
}
