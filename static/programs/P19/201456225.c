#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10000

void merge(char a[][11], int m, int f, int l)
{
	char c[l - f + 1][11];
	int i = f , j = m+1 , k = 0;
	while(i <= m && j <= l)
		if(strcmp(a[i] , a[j]) <= 0)
			strcpy(c[k++] , a[i++]);
		else
			strcpy(c[k++] , a[j++]);
	while(i <= m)
		strcpy(c[k++] , a[i++]);
	while(j <= l)
		strcpy(c[k++] , a[j++]);
	for(i = f , k = 0 ; i <= l ; i++ , k++)
		strcpy(a[i] , c[k]);
	return;
}

void msort(char a[][11] , int f , int l)
{
	if(f < l)
	{
		int m = (f + l) / 2;
		msort(a , f , m);
		msort(a , m+1 , l);
		merge(a , m , f , l);
	}
	return;
}

void main()
{
	int n,p=0; 			//number of test cases
	scanf("%d", &n);
	while(n--)
	{
		int i,j,x;			//x is the number of numbers that bryan has seen
		int ret=0,flag=0;
		char str[MAX][11],temp[11];
		scanf("%d ", &x);
		for(i=0;i<x;i++)
			scanf("%s" , str[i]);
		msort(str , 0 , x-1);
		for(i=0;i<x-1;i++)
		{
			//for(j=i+1;j<x;j++)
			{
				p=strlen(str[i]);
				ret=strncmp(str[i],str[i+1],p);
				if(ret==0)
				{
					flag=1;
					printf("NO\n");
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag!=1)
			printf("YES\n");
	}
	return;
}
