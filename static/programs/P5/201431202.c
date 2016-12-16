#include<stdio.h>
int  partition(int *a,int start,int end,int n)
{
	int pivot=*(a+end);
	int j=start,k,temp;
	for(k=start;k<end;k++)
	{
		if(*(a+k)<=pivot)
		{
			temp=*(a+k);
			*(a+k)=*(a+j);
			*(a+j)=temp;
			j++;
		}
	}
	temp=*(a+end);
	*(a+end)=*(a+j);
	*(a+j)=temp;
	return j;
}
void Qs(int *a,int start,int end,int n)
{
	if(start<=end)
	{
		int pin=partition(a,start,end,n),i;
		Qs(a,start,pin-1,n);
		Qs(a,pin+1,end,n);
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n=0,i=0,k=0;
		scanf("%d %d",&n,&k);
		int a[n+1],flag=0;
		char b[100000];
		for(i=1;i<=n;i++)
		{
			scanf("%s %d",b,&a[i]);
		}
		Qs(a,1,n,n);
		int j,l,temp=0;
		for(i=1;i<=n-2;i++)
		{
			j=i+1;
			l=n;
			while(j<l)
			{	
				temp=a[i]+a[j]+a[l];	
				if(temp==k)
					break;
				else if(temp>k)
				{
					l--;
				}
				else
				{
					j++;
				}
			}
			if(temp==k)
			{
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("NO\n");
		}
	}
	return 0;
}
