#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define maxnum 10000

int num;
char str[maxnum][100];
int head = 0;
int tail = -1;
int current = 0;

void addstring(char string[])
{
	++current;
	++tail;
	if(tail == num)
	{
		tail = 0;
	}
	strcpy(str[tail],string);
	if(tail == head && current>num)
	{
		head++;
		if(head == num)
			head = 0;
		current--;
	}
//	printf("%d %d %d\n",head,current,tail);
	return ;
}

/*void removestring()
{
	++head;
	if( head == num)
		head = 0;
	return ;
}*/

void list()
{
	int i,j;
	i = head;
	while(j!=current)
	{
		printf("%s\n",str[i]);
		i++;
		j++;
		if(i == num)
			i=0;
	}
	return ;
}

int main()
{
	char c,s[100];
	int n;
	scanf("%d",&num);
	scanf("\n%c",&c);
	while(c != 'Q')
	{
		 if(c == 'A')
		 {
			 scanf("%d",&n);
			 while(n--)
			 {
				 scanf("\n%s",s);
				 addstring(s);
			 }
		 }
		 else if(c == 'R')
		 {
			scanf("%d",&n);
			head = head + n;
			assert(n <= current);
			current = current - n;
			if(head >= num)
			{
				head = head%num;
			}
		 }
		 else if(c == 'L')
		 {
			 list();
		 }
		 else 
			 break;
		 scanf("\n%c",&c);
	}
	return 0;
}
			 

