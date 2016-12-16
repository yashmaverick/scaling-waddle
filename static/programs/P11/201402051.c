#include<stdio.h>
struct node{
	long long int data;
	struct node* next;
};
struct node* top=NULL;

void push(long long int n)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=n;
	temp->next=top;
	top=temp;
}
void pop()
{
	struct node* temp;
	if(top==NULL)
		return;
	temp=top;
	top=top->next;
	free(temp);
}
int stemp()
{
if(top==NULL)
{
return 0;
}
else
{
return 1;
}
}
long long int stop()
{
return top->data;
}

long long int func(long long int hist[], long long int n)
{


	long long int max_area = 0; 
	long long int tp;  
	long long int area_with_top; 
	long long int i = 0;
	while (i < n)
	{
		if (stemp()==0 || hist[stop()]<= hist[i])
		{	push(i);
			i++;
		}
		else{
			tp = stop(); 
				pop(); 
			area_with_top = hist[tp] * ((stemp() == 0) ? i : i - stop() - 1);

			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while (stemp() == 1)
	{
		tp = stop();
		pop();
		area_with_top = hist[tp] * ((stemp() == 0) ? i : i - (stop()) - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}
int main()
{
long long int n,x,hist[100005],i;
while(1)
{ 
scanf("%lld",&n);
if(n==0)
{
return 0;
}
for(i=0;i<n;i++)
{
scanf("%lld",&hist[i]);
}
x=func(hist,n);
printf("%lld\n",x);
}
}
