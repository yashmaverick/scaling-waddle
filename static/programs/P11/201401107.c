#include<stdio.h>
#include<stdlib.h>

long long int stack[100000],head=0;
void push(long long int val)
{
	stack[head++]=val;
	return;
}
void pop()
{
	if((head-1)==0||(head-1)<0)
	{
		head=0;
		return;
	}
	head--;
	return;
}

long long int top()
{
	if(head==0)
		return -1;
	return stack[head-1];
}

int isSempty()
{
	if(head==0)
		return 1;
	else return -1;
}
int main()
{
	//mark0
	long long int area1,k=0,num,counter,top1,i,j=0,a[100000],val2,max=0,t=100;


		
		
		
		while(t!=0)
		{
			scanf("%lld",&num);
			t=num;
			if(t==0)
				return 0;

		for(i=0;i<num;i++)
		{
			scanf("%lld",&a[i]);

		}
		j=0,k=0,max=0;

		head=0;
		//mark2
		for(j=0;j<num;)
		{
			if(isSempty()==1||a[j]>=a[top()])
			{
				push(j);
				j++;
			}
			else if(isSempty()==-1&&a[top()]>a[j])
			{
				top1=top();
				pop();
				if(isSempty()==1)
					val2=j;
				else
					val2=j-top()-1;
				area1=a[top1]*val2;
				if(area1>max)
				{

					max=area1;
				}
			}
		}

		//mark3
		while(isSempty()==-1)//issempty()==0)
		{

			top1=top();

			pop();
			if(isSempty()==1)
				val2=j;
			else
				val2=j-top()-1;

			area1=a[top1]*val2;
			if(area1>max)
			{
				max=area1;
			}

		}

		printf("%lld\n",max);
	
		}
	return 0;
}
