#include<stdio.h>
long long int arr[100003],count,node,max,sa[100003],sun,sw[100003];
void push(long long int a)
{
	sun=sun+1;
	sa[sun]=a;
	return;
}
void pop()
{
	sun--;
}
long long int insert(long long int start,long long int stop,long long int count)
{
	long long int i;
	count++;
	i=sw[stop];
	if(start-i+1<0)
		insert(start,i-1,count);
	if(i-stop+1<0)
		insert(i,stop-1,count);
	if(start-i+1>=0&&i-stop+1>=0)
	{
		if(max<count)
		{
			max=count;
			node=arr[start];
		}
		if(max==count&&node>arr[start])	
			node=arr[start];	
	}
}
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
		count=0;
		max=0;
		node=0;
		long long int n,i,j,we;
		scanf("%lld",&n);
		we=n;
		for(i=0;i<n;i++)
		{
			sw[i]=0;
			scanf("%lld",&arr[i]);
		}
		sun=-1;
		push(n-1);
		for(i=n-2;i>=0;i--)
		{
			if(sun>=0)
			{
				if(arr[sa[sun]] < arr[i])
				{
					push(i);
				}
				else
				{
					for(j=sun;j>=0;j--)
					{
						if(arr[sa[j]]>arr[i])
						{
							sw[sa[sun]]=i+1;
							pop();
						}
						else
						{
							//push(i);
						break;
						}

					}
					push(i);
				}
			}
			else
				push(i);
		}
		for(i=sun;i>=0;i--)
		{
		sw[sa[i]]=0;
		}
			insert(0,n-1,0);
			printf("%lld %lld\n",node,max);
	}
		return 0;
}
