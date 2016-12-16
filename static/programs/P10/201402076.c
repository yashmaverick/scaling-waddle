#include<stdio.h>
char buffer[10023][123];
int n,sp,e;
void input()
{
	int len;
	scanf("%d",&len);
	int i;
	for(i=0;i<len;i++)
	{
		int ep=e+sp;
		ep%=n;
		scanf("%s",buffer[ep]);
		e++;
		if(e>n)
		{
			sp++;
			e--;
		}		

		
	}
}
void rm()
{
	int len;
	scanf("%d",&len);
	sp=sp+len;
	e-=len;
	sp%=n;
	
}
void output()
{
	int i;
	for(i=0;i<e;i++)
	{
		int temp=sp+i;
		temp%=n;
		printf("%s\n",buffer[temp]);
	}
}
int main()
{
	sp=0;
	e=0;
	scanf("%d",&n);
	char c;
	scanf("%c",&c);
	while(c!='Q')
	{
		if(c=='A')
			input();
		else if(c=='R')
			rm();
		else if(c=='L')
			output();


		scanf("%c",&c);
	}
	return 0;
}
	
	
