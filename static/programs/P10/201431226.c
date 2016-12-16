#include <stdio.h>
struct node{
	char s[101];
};
int i,s=0,l=0,j=0;
void fun(char c,int N,struct node sree[])
{
	if(c=='A')
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			if(l>=N)
			{
				s++;
			}
			scanf("%s",sree[j%N].s);
			j++;
			if(l<N)
				l++;
		}
		char a;
		scanf(" %c",&a);
		fun(a,N,sree);
	}
	if(c=='R')
	{
		int n;
		scanf("%d",&n);
		l=l-n;
		s=s+n;
		char a;
		scanf(" %c",&a);
		fun(a,N,sree);
	}
	if(c=='L')
	{
		int k=s;
		for(i=0;i<l;i++)
		{
			printf("%s\n",sree[k%N].s);
			k++;
		}
		char a;
		scanf(" %c",&a);
		fun(a,N,sree);
	}
	if(c=='Q')
		return;
}
int main()
{
	int N;
	scanf("%d",&N);
	struct node sree[N];
	char c;
	scanf(" %c",&c);
	fun(c,N,sree);
	return 0;
}