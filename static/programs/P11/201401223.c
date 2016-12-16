#include<stdio.h>
#include<stdlib.h>
long long int  a[100000],b[100000],sr[100000],sl[100000];
long long int temp[100000];
typedef struct stack 
{
	int data;
	struct stack *next;
} node;
node * get_node(int item) 
{
	node * temp;
	temp = (node *) malloc(sizeof(node));
	if (temp == NULL)
	return;
		temp->data = item;
	temp->next = NULL;
	return (temp);
}
void Push(int Item, node **top) 
{
	node *New;
	node * get_node(int);
	New = get_node(Item);
	New->next = *top;
	*top = New;
}
int Sempty(node *temp) 
{
	if (temp == NULL)
		return 1;
	else
		return 0;
}
int Pop(node **top) 
{
	int item;
	node *temp;
	item = (*top)->data;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return (item);
}

int main()
{
long long 	int n,tc,max;
	while (1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		else 
		{
		long long 	int i,j;
			node *right=NULL;
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			sl[0]=0;
			Push(0,&right);
			for(i=1;i<n;i++)
			{
				while (! Sempty(right) && a[right -> data] >=  a[i])
					Pop(&right);
				sl[i] = (Sempty(right)) ? (i ) : (i-right -> data-1);
				Push(i,&right);
			}
			//	for(i=0;i<n;i++)
			//		printf("%d\n",sl[i]);
			for(i=0;i<n;i++)
				b[i]=a[n-i-1];
			node *left=NULL;
			sr[0]=0;
			Push(0,&left);
			for(i=1;i<n;i++)
			{
				while (!Sempty(left) && b[left -> data] >=  b[i])
					Pop(&left);
				sr[i] = (Sempty(left)) ? (i ) : (i-left -> data-1);
				Push(i,&left);
			}
			//	for(i=0;i<n;i++)
			//		printf("%d\n",sr[n-i-1]);
			//	printf("%d\n",sr[i]);
			for(i=0;i<n;i++)
				temp[i]=1+sl[i]+sr[n-1-i];
			for(i=0;i<n;i++)
				temp[i]=temp[i]*a[i];
			//	for(i=0;i<n;i++)
			//	printf("%d\n",temp[i]);
			max=temp[0];
			for(i=1;i<n;i++){
				if(temp[i]>max)
					max=temp[i];}
			printf("%lld\n",max);
		}
	}
	return 0;
}
