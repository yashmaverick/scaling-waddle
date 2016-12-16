//GABBAR STUDIOWORKS 1947
//2:39 AM
//5-03-2015
//ALMOST FINAL ATTEMPT
#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll stack[100003];
ll head=-1;
push(ll l)
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
	while(3)
	{
		ll n,i;
		head=-1;
		ll iden=0,count=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		ll*arr=(ll*)malloc(sizeof(ll)*n);
		ll*b=(ll*)malloc(sizeof(ll)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<n;i++)
			b[i]=1;
		b[0]=0;
		for(i=0;i<n;i++)
		{
			if(head==-1 || arr[i]<arr[stack[head]])
			{
			
				if(head!=-1)
					count++;
				else
					b[i]=0;
				push(i);
				
			}
			else if(arr[i]>arr[stack[head]])
			{
			
				while(head!=-1 && arr[i]>arr[stack[head]] )
				{
					pop();
					count++;
				}
				if(head==-1)
					b[i]=0;
				if(head!=-1)
				{
					if(arr[i]==arr[stack[head]])
					{
						b[i]=b[stack[head]]+1;
                                                count=count+b[i];
					   //     	printf("%lld lola%lld\n",arr[i],b[stack[head]]);
					}
					else
						count++;
				}
				push(i);
			}
			else 
			{
			
				push(i);
				b[i]=b[stack[head-1]]+1;

				count=count+b[i];
			//	push(i);
//printf("%lld lola%lld\n",arr[i],b[stack[head]]);
				
			}
		}
	//	printf("%lld\n",count);
		ll y=((n)*(n-1))/2;
		printf("%lld\n",(y-count));
	//	printf("\n");
	}
	return 0;
}
