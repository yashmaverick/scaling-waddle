#include<stdio.h>
int front=0;
int rear=-1;
int a1[100010];
int prime[10010];
int distance[100000];
void push(int val)
{
	rear++;
	a1[rear]=val;

}
void pop()
{
	front++;

}
int digit[4];
void digitfunc(int a)
{int h=3;
	int r;
        while(a!=0)
	{r=a%10;
	digit[h--]=r;
	a=a/10;
	}
}
int convertton(int digit[])
{
   return digit[3]+digit[2]*10+digit[1]*100+digit[0]*1000;

}
int main()
{ int t,i,j,a,b,k;     
       int number;	
	for(i=0;i<10000;i++)
	{
		prime[i]=i;
	}
	for(i=2;i<=100;i++)
	{
		if(prime[i]!=-1)
		{
			for(j=i*i;j<=10000;j+=i)
				prime[j]=-1;
		
		
		}
	}
	scanf("%d",&t);
        while(t--)
	{
	scanf("%d%d",&a,&b);
	if(a==b)
		printf("0\n");
	else
	{
        push(a);
	for(i=999;i<=10000;i++)
	{	distance[i]=-1;
	}
	distance[a]=0;
	int flag=0;
	while(front<=rear)
	{  
	for(k=3;k>=0;k--)
	{    digitfunc(a1[front]);
		for(i=0;i<=9;i++)
		{
			digit[k]=i;
			number=convertton(digit);
			if(prime[number]!=-1 && number>=1000 && number<=9999 && distance[number]==-1)
			{
				distance[number]=distance[a1[front]]+1;
			        push(number);
				if(number==b)
				{	flag=1;
					break;}
			}
		
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		break;
	pop();
	}
		printf("%d\n",distance[b]);
	}
	front=0;
	rear=-1;
	
	}
	return 0;
}
