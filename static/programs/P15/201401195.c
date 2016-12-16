#include<stdio.h>
void push(int val,int stack[],int *last)
{
	stack[*last]=val;
	(*last)++;
}
int pop(int stack[],int *last)
{
	if(*last==0)
		return -1;
	else
	{
		(*last)--;
		return stack[*last];
	}
}   
int top(int stack[],int *last)
{   
	if(*last==0)
		return -1;
	else 
		return stack[*last-1];
}

int main()
{
	int t,d;
	scanf("%d",&d);
	for(t=0;t<d;t++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int i,a[n],stack[n],start=0,last=0,p,array[n-k+1],last2=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		i=0;
		while(i<n)
		{
			while(i<k)
			{
				if(i==0)
				push(i,stack,&last);
				else if(a[top(stack,&last)]<=a[i])
				{
					push(i,stack,&last);
				}
				else if(a[top(stack,&last)]>a[i])
				{
					while(a[top(stack,&last)]>a[i]&&top(stack,&last)!=-1)
					p=pop(stack,&last);
					push(i,stack,&last);
					
				}
				//push(start,array);
				i++;	
			}	
			if(i==k)
			{
			push(stack[start],array,&last2);
			if(stack[start]==i-k)
			{
			stack[start]=-1;
			start++;
			}
			}
			if(i>=k||i<n) 
			{
				if(a[top(stack,&last)]<=a[i])
				{
					push(i,stack,&last);
				}
				else
				{
					while(a[top(stack,&last)]>a[i]&&top(stack,&last)!=-1)
					p=pop(stack,&last);
					push(i,stack,&last);
				}		
			
			}
			if(i>=k)
			{
			i++;
			push(stack[start],array,&last2);
			if(stack[start]==i-k)
			{
			stack[start]=-1;
			start++;	
			}
			//push(stack[start],array,&last2);
			}
		//if(i>=k)
		//i++;
		}
		for(i=0;i<n-k+1;i++)
		{
			if(i==n-k)
			printf("%d\n",a[array[i]]);
			else
			printf("%d ",a[array[i]]);
		}
		//printf("\n");	
	}
	return 0;
}



