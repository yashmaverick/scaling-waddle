#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[10001][101];
int head=0,tail=0,flag=0,elements=0,N;


void print_buffer();
void append_buffer(int n);
void remove_buffer(int n);
int main()
{
	int n;
	scanf("%d",&N);getchar();

	while(1)
	{
		int c=getchar();
		if(c!='Q' && c!='L')
		{
			scanf("%d",&n);
			if(c=='A')
				append_buffer(n);
			else if(c=='R')
				remove_buffer(n);
		}
		else if(c=='L')
			print_buffer(a);
		else
			break;


	}


	return 0;
}

void print_buffer()
{
	int i=head;
	int j;
	for(j=0;j<elements;j++)
	{
		if(i==N)
			i=0;
		printf("%s\n",a[i++]);
	}
}

void append_buffer(int n)
{ 
	int i;
	for(i=0;i<n;i++)
	{
		if(elements!=N)
			elements++;
		scanf("%s",a[tail++]);
		if(tail==N)
			tail=0;

		//if(head==tail && a[tail]!=NULL)
		//	flag=1;
		if(elements==N)
			flag=1;
	}
	if(flag==1)
	{
		head=tail;
		flag=0;
	}
}

void remove_buffer(int n)
{  
	int i;
	int x;
	if(n>N)
		x=N;
	else
		x=n>elements?elements:n;
	for(i=0;i<x;i++)
	{
		head++;
		if(head==N)
			head=0;
		elements--;
	}
}
