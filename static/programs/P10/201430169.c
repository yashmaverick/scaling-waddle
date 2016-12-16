#include<stdio.h>
char  A[10001][101];
int p=0,q=0;		/*'p' points to start and 'q' to end of queue*/
void append(char s[],int N)
{
	if(p==N)
		p=0;
	if(q==N)
		q=0;//printf("q==N\n");}
	if(p==q && A[0][0]!='\0' && A[p][0]!='/')
		p++;
	int i=0;//printf("q=%d p=%d\n",q,p);
	while(s[i]!='\0')
	{	
		A[q][i]=s[i];
		i++;
	}
	A[q][i]='\0';
	q++;//printf("q=%d p=%d\n",q,p);
}

void rem(int n,int N)
{
	if(p==N)
		p=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(p==N)
			p=0;
		A[p++][0]='/';
	}
	//if(p==N)
	//	p=0;
}

void print(int N)
{
	int i,j;
	if(p>0 && p==q && A[p-1][0]=='/')
		return;
	else if(p==0 && q==0 && A[0][0]=='\0')
		return;
	else if(p<q)
	{
		for(i=p;i<q;i++)
		{
			for(j=0;A[i][j]!='\0';j++)
				printf("%c",A[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(i=p;i<N;i++)
		{
			for(j=0;A[i][j]!='\0';j++)
				printf("%c",A[i][j]);
			printf("\n");
		}
		for(i=0;i<q;i++)
		{
			for(j=0;A[i][j]!='\0';j++)
				printf("%c",A[i][j]);
			printf("\n");
		}
	}
}			
	
int main()
{
	char c,s[105];
	int N,i,n;
	scanf("%d",&N);
	if(N==0)
		return 0;
	A[0][0]='\0';
	while(1)
	{
		scanf("%c",&c);
		if(c=='Q')
			return 0;
		else if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s",s);	
				append(s,N);
			}
		}
		else if(c=='R')
		{
			scanf("%d",&n);
			rem(n,N);
		}
		else if(c=='L')
			print(N);
	}
}		
