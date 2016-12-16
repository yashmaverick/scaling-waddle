#include<stdio.h>
#include<stdlib.h>
void walk(int f,int l,int *input,int height);

struct node
{
    int val;
    int i;
    struct node *next;
}*top,*top1,*temp;

int count=0,a[100001];
int x=1;
void push(int data,int index)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(x*sizeof(struct node));
        top->next = NULL;
        top->val = data;
	top->i = index;
    }
    else
    {
        temp =(struct node *)malloc(x*sizeof(struct node));
        temp->next = top;
        temp->val = data;
	temp->i = index;
        top = temp;
    }
    count++;
}
void pop()
{
    top1 = top; 
    if (top1 == NULL)
        return;
    else
        top1 = top1->next;
    free(top);
    top = top1;
    count--;
}
int max=0,mn;


int main()
{
	int test,n;
	int i,j,sum,temp;
	scanf("%d",&test);
	while(test--)
	{
		sum=0;
		scanf("%d",&n);
		j=n-1;
		int b[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		while(j>=0)
		{
			if(top==NULL || b[j]>=top->val)
			{
				push(b[j],j);
				j--;
			}
			else
			{
				a[top->i]=j;
				pop();
			}
		}
		while(top!=NULL)
		{
			a[top->i]=(top->i)-1;
			pop();
		}
		max=0;
		mn=1000000001;
	//	for(i=0;i<n;i++)
	//	{
	//		printf("%d ",a[i]);
	//	}
	walk(n-1,0,b,0);
		printf("%d %d\n",mn,max);
	}
	return 0;
}

void walk(int f,int l,int *input,int height)
{
	if(f<l)
		return ;
	if(f==l)
	if(height>=max)
	{
//	printf("saavuanaja\n");
		if(height!=max)
			mn=input[f];
		else if(input[f]<mn)
			mn=input[f];
		max=height;
	}
//	printf("height:%d\n",height);
	height++;
//	printf("height:%d\n",height);
	walk(f-1,a[f]+1,input,height);
	walk(a[f],l,input,height);
	return ;
}

