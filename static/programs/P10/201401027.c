#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	char str[150];
}list;
list *arr;
int n,f=1,start=0,end=0,size=0;
void insert()
{
	int i,ins;
	scanf("%d",&ins);
	for(i=0;i<ins;i++)
	{
		if(size!=n)
			size++;
		else
			start=(start+1)%n;
		scanf("%s",arr[end].str);
		end=(end+1)%n;
	}
}
void delete()
{
	int i,rem;
	scanf("%d",&rem);
	size-=rem;
	start=(start+rem)%n;
}
void print()
{
	int i,t;
	//printf("%d %d\n",size,start);
	for(i=0;i<size;i++)
	{
		t=(start+i)%n;
		printf("%s\n",arr[t].str);
	}
}
int main()
{
	char c;
	scanf("%d",&n);
	arr=(list*)malloc(n*sizeof(list));
	while(f)
	{
		scanf("%c",&c);
		switch(c)
		{
			case 'A':insert();
				 break;
			case 'R':delete();
				 break;
			case 'L':print();
				 break;
			case 'Q':f=0;
				 break;
			default: break;
		}
	}
	return 0;
}
