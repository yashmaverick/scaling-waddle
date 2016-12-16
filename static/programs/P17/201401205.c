#include<stdio.h>
int num1,num2;
int partition(int a[],int b[],int start1,int end1,int start2,int end2)
{
	int i,n,j;
	if(num1==num2)
		return num1;
	else
	{
		for(i=start2;i<=end2;i++)
		{
			if(a[start1]==b[i])
				break;
		}
		n=0;
		for(j=start2;j<i;j++)
		{
			if(b[j]==num1||b[j]==num2)
				n++;
		}
		if(n==1||b[i]==num1||b[i]==num2)
			return b[i];
		else if(n==2)
			return partition(a,b,start1+1,start1+i,start2,start2+i-1);
		else if(n==0)
			return partition(a,b,i,end1,i+1,end2);
	}
}
int main()
{
	int n,a[1000001],b[1000001],i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&num1,&num2);
		printf("%d\n",partition(a,b,0,n-1,0,n-1));
	}
	return 0;
}
