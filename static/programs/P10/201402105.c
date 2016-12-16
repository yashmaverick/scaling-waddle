#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	char value[100];
	struct list* next;
}list;
int count,filled=0;
list *top,*last;
void input();
void rmv(int);
void print();
void enter()
{
	printf("\n");
}
int main()
{
	scanf("%d",&count);
	char command;
	int more;
	top=NULL;
	while(1)
	{
		getchar();
		scanf("%c",&command);
		int n,djik;
		if(command == 'Q')
{
			break;
		}
		if(command == 'R')
{
			scanf("%d",&n);
			rmv(n);
		}
		if(command == 'A')
{
			scanf("%d",&n);
			more = filled + n - count;
			if(more>0)
				rmv(more);	
			for(djik=0;djik<n;djik++){
				input(top);
			}
		}
		
		
		if(command == 'L')
{
			print();
		}
		
	}
	return 0;
}
void input()
{
	list *temporary;
	temporary = malloc(sizeof(list));
	scanf("%s",temporary->value);
	temporary->next = NULL;
	if(top == NULL)
	{
		top = temporary;
		last = temporary;
	}
	else
	{
		last->next = temporary;
		last = temporary;
	}
	filled++;
}

void print()
{
	list *temporary;
	temporary = top;
	while(temporary != NULL)
	{
		printf("%s",temporary->value);
		enter();
		temporary = temporary->next;
	}
}

void rmv(int n)
{
	int djik;
	list *temporary;
	for(djik=0;djik<200;djik++)
		djik++;
	for(djik=0;djik<n;djik++)
	{
		if(top!=NULL)
		{
			temporary = top->next;
			free(top);
			top = temporary;
			filled--;
		}
	}
}	
