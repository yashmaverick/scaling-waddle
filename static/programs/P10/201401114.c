#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char arr[100];
	struct node*next;
}node;
node* first=NULL;
node*last;
int count=0, N;
void append(char str[])
{
        if(N==0)
            return;
	node*ptr=malloc(sizeof(node));
	if(first==NULL)
	{

		strcpy(ptr->arr, str);
		ptr->next=NULL;
		first=ptr;
		last=ptr;
		count=1;
	}
	else
	{
		if(count==N)
		{
			strcpy(ptr->arr, str);
			ptr->next=NULL;
                        node * tmp=first;
			first=first->next;
                        free(tmp);
			last->next=ptr;
			last=ptr;
	
		}
		else 
		{
			++count;
			strcpy(ptr->arr, str);
			ptr->next=NULL;
			last->next=ptr;
			last=ptr;
		}
	}
              
}
void list()
{
	if(first==NULL)
	{
		return;
	}
	else
	{
		node*pointer=first;
		while(pointer!=NULL)
		{
			printf("%s\n", pointer->arr);
			pointer=pointer->next;
		}
	}
}

void del(int n)
{
	if(first==NULL)
		return;
	else
	{
		while(n!=0)
		{
                        node * tmp=first;
			first=first->next;
                        free(tmp);
			n--;
                        count--;
			
		}
	}
}
int main()
{
	char op, str[10000];
	int num;
	scanf("%d", &N);
	scanf("%c", &op);
	while( op!='Q')
	{
		switch(op)
		{
			case 'A' : scanf("%d", &num);
				  while(num!=0)
				  {
					 scanf("%s", str);
					 append(str);
					 num--;
				  }
				  break;
			case 'L': list();
				  break; 
		        case 'R': scanf("%d", &num);
				  del(num);
				  break;
		}
//                printf("count-->%d\n",count);

		scanf("%c", &op);
	}
	return 0;
}
	



