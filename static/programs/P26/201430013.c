#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100000],c[100000],start,max,bit,ptr,m,visited[1000000],level[1000000];
void sieve()
{
	a[0]=0;
	a[1]=0;
	long long int i,j,l;
	for(i=2;i<=9999;i++)
	{
		a[i]=1;
	}
	for(i=2;i<=9999;i++)
	{
		if(a[i]==1)
		{
			for(j=i;(j*i)<=9999;j++)
			{
				a[i*j]=0;
			}
		}
	}
}
void make(int n);
void  push(int s)
{
	if(bit==1)
		return;
	c[ptr]=s;
	ptr++;
}
void pop()
{
	if(bit==1)
		return;
	//	printf("start=%d\n",c[start]);
	make(c[start]);
	start++;
}
void make(int n)
{
	if(bit==1)
		return;
	int i,count=0;;
	for(i=1;i<10;i++)
	{
		if(i!=n/1000)
		{
			if(a[i*1000+n%1000]==1&&visited[i*1000+n%1000]!=1)
			{
				if(i*1000+n%1000==m)
					bit=1;
				level[i*1000+n%1000]=level[n]+1;
				visited[i*1000+n%1000]=1;
				push(i*1000+n%1000);
				//				count++;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(i!=(n/100)%10)
		{
			if(a[n/1000*1000+i*100+n%100]==1&&visited[n/1000*1000+i*100+n%100]!=1)
			{
				if(n/1000*1000+i*100+n%100==m)
					bit=1;
				level[n/1000*1000+i*100+n%100]=level[n]+1;
				visited[n/1000*1000+i*100+n%100]=1;
				push(n/1000*1000+i*100+n%100);
				//				count++;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(i!=(n/10)%10)
		{
			if(a[n/100*100+i*10+n%10]==1&&visited[n/100*100+i*10+n%10]!=1)
			{
				if(n/100*100+i*10+n%10==m)
					bit=1;
				level[n/100*100+i*10+n%10]=level[n]+1;
				visited[n/100*100+i*10+n%10]=1;
				push(n/100*100+i*10+n%10);
				//				count++;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(i!=n%10)
			if(a[n/10*10+i]==1&&visited[n/10*10+i]!=1)
			{
				if(n/10*10+i==m)
					bit=1;
				level[n/10*10+i]=level[n]+1;
				visited[n/10*10+i]=1;
				push(n/10*10+i);
				//				count++;
			}
	}
}
int main()
{
	int test;
	sieve();
	scanf("%d",&test);
	while(test--)
	{
		int i;
		bit=0;
		max=0;
		ptr=0,start=0;
		memset(visited,-1,100000);
		int n;
		scanf("%d %d",&n,&m);
		visited[n]=1;
		level[n]=0;
		push(n);
		if(m==n)
			printf("0\n");
		else
		{
			while(ptr!=start)
			{
				pop();
				if(bit==1)
					break;
			}
			printf("%d\n",level[m]);
		}
	}
	return 0;
}
