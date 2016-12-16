#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char value[100];
	struct node* next;
}node;

int size,capacity=0;
node *head,*last;

void insert()
{
	node *temp;
	temp=malloc(sizeof(node));
	scanf("%s",temp->value);
	temp->next=NULL;

	if(head==NULL)
	{
		head=temp;
		last=temp;
	}
	else
	{
		last->next=temp;
		last=temp;
	}
	capacity++;
}

void rem(int n)
{
	int i;
	node *temp;
	for(i=0;i<n;i++)
	{
		if(head!=NULL)
		{
			temp=head->next;
			free(head);
			head=temp;
			capacity--;
		}
	}
}
	
	
void print(){
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%s\n",temp->value);
		temp=temp->next;
	}
}

int main(){
	scanf("%d",&size);
	char q;
	int more;
	head=NULL;
	while(1)
	{
		getchar();
		scanf("%c",&q);
		int n,i;
		if(q=='A'){
			scanf("%d",&n);
			more=capacity+n-size;
			if(more>0)
				rem(more);	
			for(i=0;i<n;i++){
				insert(head);
			}
		}
		if(q=='R'){
			scanf("%d",&n);
			rem(n);
		}
		if(q=='L'){
			print();
		}
		if(q=='Q'){
			break;
		}
	}
	return 0;
}
