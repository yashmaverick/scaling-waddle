#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(char a[][20],int f,int m,int l)
{
	int i=f,j=m+1,k=0;
	char c[l-f+1][20];
	while(i<=m && j<=l)
		if(strcmp(a[i],a[j]) < 0)
			strcpy(c[k++],a[i++]);
		else
			strcpy(c[k++],a[j++]);
	while(i<=m)
		strcpy(c[k++],a[i++]);
	while(j<=l)
		strcpy(c[k++],a[j++]);
	for(i=f,k=0;i<=l;i++,k++)
		strcpy(a[i],c[k]);
	return;
}

void msort(char a[][20],int f,int l)
{
	if(f<l)
	{
		int m=(f+l)/2;
		msort(a,f,m);
		msort(a,m+1,l);
		merge(a,f,m,l);
	}
	return;
}

int main()
{
	int i,j,n,t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		char a[20],s[n][20];
		for(i = 0 ; i < n ; i++)
			scanf("%s",s[i]);
		int f = 0;
		msort(s,0,n-1);
		for(i = 0 ; i < n-1 ; i++)
		{
			strcpy(a,s[i+1]); a[strlen(s[i])] = '\0';
			if( !strcmp(a,s[i]) ) { f = 1; break; }
		}
		if(f) puts("NO");
		else puts("YES");
	}
	return 0;
}
