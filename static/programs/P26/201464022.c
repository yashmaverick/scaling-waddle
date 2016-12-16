#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long back=-1;
long long front=-1;
long long int queue[1000006]={0};
void push(long long a)
{
	if(front==-1)
		front=0;
	back++;
	queue[back]=a;

}
long long pop()
{
	long long temp=queue[front];
	front++;
	return temp;

}
int empty()
{
	if(front==back && front!=0)
		return 1;
	
	else return -1;
}
long long getnumber(int a[])
{
	long long temp=0,k=0;
	temp=a[0]+(a[1]*10)+(a[2]*100)+(a[3]*1000);
	return temp;
}
int main()
{
	long long i,j,t,tempnum;
	int primes[10004]={0};
	for(i=2;i<=100;i++)
	{
		if(primes[i]==0)
		{
			for(j=i*i;j<=10000;j+=i)
				primes[j] = 1;
		}
	}
	scanf("%lld",&t);
	while(t--)
	{
		int flag=0;
		back=-1;
		front=-1;
		int digit[5];
		long long a,b,number;
		long long distance[10005];
		for(i=0;i<=10004;i++)
			distance[i]=-1;
		scanf("%lld%lld",&a,&b);
		distance[a]=0;
		push(a);
		while(empty()!=1)
		{
			long long num=pop();
			for(i=3;i>=0;i--)
			{
				tempnum=num;
				int digits=0;
				while(tempnum>0)
				{
					digit[digits]=tempnum%10;
					digits++;
					tempnum=tempnum/10;
				}
				for(j=0;j<10;j++)
				{
					digit[i]=j;
					number=0;
					number=getnumber(digit);
					if(primes[number]!=1 && number>=1000 && distance[number]==-1)
					{
						distance[number]=distance[num]+1;
						push(number);
						if(number==b)
						{
							flag=1;
							break;
						}
					}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		
		}
		printf("%lld\n",distance[b]);
	}
	return 0;
}










