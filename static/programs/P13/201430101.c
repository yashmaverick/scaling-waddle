//GABBAR STUDIOWORKS 1947
//LAST ATTEMPT
//04-03-2015
#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll stack[100003];
ll head=-1;
ll arr[100002][2];
void push(ll l)
{
	stack[++head]=l;
}
ll pop()
{
	head--;
	return stack[head+1];
}
int main()
{
	ll n,test,i,max,node,temp;
	scanf("%lld",&test);
	while(test--)
	{
		head=-1;
		scanf("%lld",&n);
		for(i=n-1;i>=0;i--)
			scanf("%lld",&arr[i][0]);
		if(n==0)
			printf("0 0\n");
		if(n==1)
			printf("%lld 0\n",arr[0][0]);
		else
		{

			arr[0][1]=0;
			push(0);
			for(i=1;i<n;i++)
			{
				if(head==-1 || arr[stack[head]][0]<=arr[i][0])
				{
					push(i);	
					//	if(head==0)
					//	{}	
					//	else
					arr[i][1]=arr[i-1][1]+1;
					//push(i);
					//i++;
				}
				else if(arr[i][0]<arr[stack[head]][0] )
				{
					while(arr[i][0]<arr[stack[head]][0] && head!=-1)
					{
						temp=pop();
					}
					arr[i][1]=arr[temp][1]+1;
					push(i);

				}
			}
			max=arr[0][1];
			for(i=1;i<n;i++)
			{
				if(max==arr[i][1])
				{
					if(arr[i][0]<node)
					{
						max=arr[i][1];
						node=arr[i][0];
					}
				}
				else if(max<arr[i][1])
				{
					max=arr[i][1];
					node=arr[i][0];

				}
			}
			printf("%lld %lld\n",node,max);
		}
	}
	return 0;
}

