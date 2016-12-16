#include<stdio.h>
#include<stdlib.h>
/*struct stack 
  {
  int s[100000];
  int top;
  } st;*/
# if 0
int top=-1;
int s[100004];
void push(int item) 
{
	top++;
	s[top] = item;
}
/*
   int stempty() 
   {
   if (st.top == -1)
   return 1;
   else
   return 0;
   }*/

void display() 
{
	int i;
	//	if (stempty())
	//		return;   
	//	else 
	//	{
	for (i = top-1; i >0; i--){
		if(i!=1)
			printf("%d ",s[i]);
		else
			printf("%d\n",s[i]);
		//	}
}
}
#endif
int stack[100004];
int top=0;
struct node
{
	int data;
	struct node* next;
};
struct node* a[100004];
void inserta(int i,int j)
{
	struct node* new;
	new = malloc(sizeof(struct node));
	new->next = a[i];
	new->data = j;
	a[i] = new;
	return ;
}
int visited[100004];
void dfsa(int i)
{
	struct node* temp;
	temp=a[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		int j;
		j=temp->data;
		if(visited[j]!=1)
			dfsa(j);
		temp=temp->next;
	
	}
//	printf("%d",top);
	stack[top]=i;
	top++;
	return;
}
int main()
{
	int n,m,x,y,i;
	struct node* tmp;
	for(i=1;i<=n;i++)
	{
		a[i]=NULL;
	}
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		inserta(x,y);
	}
	/*
	for(i=1;i<=n;i++)
	{
		tmp = a[i];
		if(tmp!=NULL)
		{
			printf("%d->",i);
			while(tmp!=NULL)
			{
				printf("%d ",tmp->data);
				tmp = tmp->next;
			}
			printf("\n");
		}
	}	
	*/
	for(i=n;i>=1;i--)
	{
		if(visited[i]==0)
		{
			dfsa(i);
		}
	}
//	printf("%d\n",top);
	for(i=top-1;i>0;i--)
		printf("%d ",stack[i]);
	printf("%d",stack[0]);
	printf("\n");
	return 0;
}
