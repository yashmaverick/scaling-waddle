#include<stdio.h>
int first=0,last=-1;
char A[10000][100];
int nu=0;
int flag=0;
void append(int n,int size)
{
	int i;
	for(i=0;i<n;i++)
	{

		if(nu<size)
			nu++;
		last=(last+1)%size;
		scanf("%s",A[last]);
		if(nu==size)
			flag=1;
	}
	if(flag==1)
	{
		first=(last+1)%size;
		flag=0;
	}
}
void re_move(int n , int size)
{	
	nu-=n;
	if(nu<0)
		nu=0;
	first = (first+n)%size;
	if(nu==0)
	{
		first=0;
		last=-1;
	}
}
void print(int size)
{
	int i;
	for(i=0;i<nu;i++)
		printf("%s\n",A[(first+i)%size]);
}
int main()
{
	char query;
	int n,size;
	scanf("%d",&size);
	while (1)
	{
		scanf("%c",&query);
		switch(query)
		{
			case 'A':
				scanf("%d",&n);
				append(n,size);
				break;
			case 'R':
				scanf("%d",&n);
				re_move(n,size);
				break;
			case 'L':
				print(size);
				break;
			case 'Q':
				return 0;
			default:
				break;
		}
	}
	return 0;
}
