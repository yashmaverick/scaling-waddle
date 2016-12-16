#include<stdio.h>
long long int a[500001],sz=0,start=0;
void push(long long int ele)
{
	a[sz]=ele;
	sz=sz+1;
	return;
}
void pop()
{
	sz=sz-1;
	a[sz]=0;
	start++;
	return;
}	
long long int top()
{
	long long int j;
	j=a[sz-1];
	return j;
}
int main()
{
	long long int n,max,j,i,index,c[500001],b[500001],count,index3;
	scanf("%lld",&n);
	while(n!=0)
	{


		max=0;
		start=0;
		count=0;
		sz=0;
		for(i=0;i<n;i++)
			scanf("%lld",&c[i]);
		if(n==2)
			printf("0\n");
		else
		{
			for(i=0;i<n;i++)
			{
				if(i==0)
				{
					push(i);
					b[0]=0;
				}
				else if(i>0)
				{
					index=top();
					if(c[i]==c[index])
					{
						push(i);
						b[i]=b[i-1];
						count=count+b[i];
					}
					else if(c[i]<c[index])
					{
						push(i);
                                                index3=top();
						b[i]=index3-start-1;
						count=count+b[i];
					}
					else if(c[i]>c[index])
					{
						while(c[i]>c[index] && sz>0 && i<n)
						{
							pop();
							index=top();
							count=count+n-1-i;
						}
						push(i);
						if(c[i]==c[index])
						{
							b[i]=b[index];
							count=count+b[i];
						}
						else if(c[i]<c[index])
						{
							index=top();
							b[i]=index-start-1;
							count=count+b[i];
						}

					}
				}
			}
			printf("%lld\n",count);
		}
		for(i=0;i<n;i++)
		{
			b[i]=0;
			a[i]=0;
			c[i]=0;
		}
		scanf("%lld",&n);
	}
	return 0;
}
