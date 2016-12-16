#include<stdio.h>

int A[100001],top=-1;
int flag[100001];
void push(int x)
{
	if(top==(100000))
	{
		return;
	}
	else
	{
		top++;
		A[top]=x;
	}
}

int pop()
{
	int x;
	if(top==-1)
	{
		return -1;
	}
	else
	{
		x=A[top];
		top--;
		return x;
	}
}

int top1()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return A[top];
	}
}
int c[100001],n,min;
int max;

void funct(int l,int r,int root,int sum)
{
	if(l==r)
	{
		sum+=1;
		if(sum>max)
		{
			max=sum;
			min=c[l];
		}
		else if(sum==max)
		{
			if(min>c[l])
			{
				min=c[l];
			}
		}

		return;
	}
	else if(l>r)
	{
		if(sum>max)
		{
			max=sum;
			min=c[l];
		}
		else if(sum==max)
		{
			if(min>c[l])
			{
				min=c[l];
			}
		}
	}
	else
	{
		funct(l,flag[root]-1,flag[root],sum+1);
		funct(flag[root]+1,root-2,root-1,sum+1);
	}
}

	int main()
	{
		int i,test;
		scanf("%d",&test);
		while(test--)
		{
			scanf("%d",&n);
			max=0;
			min=0;
			if(n==0)
			{
				continue;
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&c[i]);
			}

			for(i=n-1;i>=0;i--)
			{
				while((c[i]<c[top1()])&&(top!=-1))
				{
					flag[top1()]=i;
					pop();
				}

				push(i);
			}
			while(top!=-1)
			{
				flag[top1()]=-1;
				pop();
			}
/*			for(i=0;i<n;i++)
			{
				printf("%d ",flag[i]);
			}
			printf("\n");*/
		//	funct(0,n-2,n-1,0);
			if(n==1)
			{
				min=c[0];
			}
			else
			{
				funct(0,n-2,n-1,0);
			}
			printf("%d %d\n",min,max);
		}
		return 0;
	}

