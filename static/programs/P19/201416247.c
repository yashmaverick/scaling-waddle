#include<stdio.h>
long long int a[100005];
long long int b[100005];
int n;
int j=0;
int c;
void func1()
{
	long long int i,temp;
	for(i=0;i<n;i++)
	{
		temp=a[i]/10;
		while(1)
		{
			if(temp!=0)
			{
				b[j]=temp;
				temp=temp/10;
				j++;
			}
			else
				break;
		}	
	}
}
long long int func2(const void *p,const void *q)
{
	return (*(long long int*)p-*(long long int*)q);
}
int func3()
{

	int p,q,r,mid;
	for(r=0;r<n;r++)
	{
		p=0,q=j-1,mid=(p+q)/2;
		while(p<=q)
		{
			if(a[r]==b[mid])
			{
				c=0;
				//		printf("NO\n");
				return c;
			}
			else if(a[r]>b[mid])
			{
				p=mid+1;
			}
			else
				q=mid-1;
			mid=(p+q)/2;
		}
		//printf("a\n");
	}
	//printf("YES\n");
	c=1;
	return c;
}
int main()
{
	int i,k,m,t;
	scanf("%d",&m);
	for(t=0;t<m;t++)
	{
		int flag=0;
		j=0;
		for(i=0;i<10000;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		func1();
		qsort(a,n,sizeof(long long int),func2);
		qsort(b,j,sizeof(long long int),func2);
		//	for(k=0;k<j;k++)
		//		printf("%d ",b[k]);
//		printf("\n");
		for(k=0;k<n-1;k++)
		{
			if(a[k]==a[k+1])
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			int p=func3();
			if(p==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;

}
