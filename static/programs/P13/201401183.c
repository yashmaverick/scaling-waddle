#include<stdio.h>
int depth[100009],a[100009],st[100009],top=-1;
void push(int val);
int pop();
void peek();
void print();
int main()
{
	int i,n,cur,t,max=0,v,curval,maxval,val;
	scanf("%d",&t);
	while(t--)
	{
	top=-1;max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	maxval=a[n-1];
//	printf("maxval int %d\n",maxval);
	push(a[n-1]);
	depth[a[n-1]]=0;
	for(i=n-2;i>=0;i--)
	{
		if(a[i]>st[top])
		{
			//push(a[i]);
			depth[a[i]]=depth[st[top]]+1;
			push(a[i]);
//			printf("1depth of %d is %d\n",a[i],depth[a[i]]);
		}
		else 
		{
			//temp=i;
			while(top!=-1&&a[i]<st[top])
			{
				v=pop();
			}
			push(a[i]);
			depth[a[i]]=depth[v]+1;
//			printf("2depth of %d is %d and v is %d\n",a[i],depth[a[i]],v);
		}
	}
	for(i=0;i<n;i++)
	{
		cur=depth[a[i]];
		curval=a[i];
//		printf("cur %d\n",cur);
//		printf("curval %d\n",curval);
		if(cur>max)
		{
			maxval=curval;
			max=cur;
		}
	}
	printf("%d %d\n",maxval,max);
	}
	return 0;
}
void push(int val)
{
	st[++top]=val;
}
int pop()
{
	if(top==-1)
		printf("-1\n");
	else
	{
		return st[top--];
	}
}
void peek()
{
	printf("%d\n",st[top]);
}
void print()
{
	int i;
	if(top>-1)
	{
		for(i=0;i<=top;i++)
			printf("%d  ",st[i]);
	printf("\n");
	}

}


