#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static int cmp (const void * , const void * );
void sort(char **, int );
struct node{
	char s[11];
};
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int fun(char arr1[],char arr2[])
{
	int i,l,l1,l2;
	l1=strlen(arr1);
	l2=strlen(arr2);
	l=min(l1,l2);
	for(i=0;i<l;i++)
	{
		if(arr1[i]!=arr2[i])
			return -1;
	}
	return 1;
}

int main()
{
	char **arr;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,flag=0;
		scanf("%d",&n);
		arr = (char **)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++)
		{
			arr[i] = (char *)malloc(sizeof(char)*11);
			scanf("%s",arr[i]);
		}
		sort(arr,n);
		//	for(i=0;i<n;i++)
		//		printf("%s\n",arr[i].s);
		for(i=0;i<n-1;i++)
		{
			if(fun(arr[i],arr[i+1])==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
static int cmp (const void * a, const void * b)
{
	return strcmp (*(const char **) a, *(const char **) b);
}
void sort(char **arr, int n)
{
	qsort (arr, n, sizeof (char *), cmp);
}

