#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int cmpfunc( const void *a,const void *b)
{
	return( *(int*)a - *(int*)b);
}
int main()
{
	int testc;
	scanf("%d",&testc);
	while(testc--)
	{
		int n,k,i,j,num,first,last,middle,ar[MAX],flag = 0;
		char string[2000];
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s %d",string,&ar[i]);
		}
		qsort(ar,n,sizeof(int),cmpfunc);
		for(i=0;i<n-2;i++)
		{
			for(j = i+1 ;j<n -1 ;j++)
			{
				num = k - (ar[i] + ar[j]);
				first = j+1;
				last = n-1;
				while( first <= last)
				{
					middle = (first + last)/2;
					if( ar[middle] == num)
					{
						flag = 1;
						break;
					}
					else if( ar[middle] < num)
						first = middle + 1;
					else 
						last = middle - 1;
				}
			if(flag == 1)
				break;
			}
		if(flag == 1)
			break;
		}
	if(flag == 1)
		printf("YES\n");
	else 
		printf("NO\n");
	}
	return 0;
}
