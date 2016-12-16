#include<stdio.h>
long long int a[1000005],b[1000005],top,top1;
void minheap(long long int i)
{
	long long int y,c;
	top1++;
	b[top1]=i;
	y=top1;
	while(y>1&&b[y]<b[y/2])
	{
		c=b[y]; 
		b[y]=b[y/2];	
		b[y/2]=c;
		y=y/2;
	}
}
void mindel()
{
	long long int y,c,tu;
	b[1]=b[top1];
	top1--;
	//j=j<<1;
	for(y=1;y*2<=top1;y=tu)
	{		
		tu=2*y;	
		if(tu<top1&&b[tu]>b[tu+1])
			tu+=1;
		if(b[y]>b[tu])
		{
		c=b[y];
		b[y]=b[tu];
		b[tu]=c;
		}	
	}
}		
void maxheap(long long int i)
{
	long long int y,c;
	top++;
	a[top]=i;
	y=top;
	while(y>1&&a[y]>a[y/2])
	{
		
			c=a[y];
			a[y]=a[y/2];
			a[y/2]=c;
		y=y/2;
	}
		//else
		//	return;
		//y=y/2;
}
void maxdel()
{
	long long int y=1,c,re;
	a[y]=a[top];
	top--;
	for(y=1;y*2<=top;y=re)
	{
		re=2*y;
		if(re<top&&a[re]<a[re+1])
			re+=1;
		if(a[y]<a[re])
		{
		c=a[y];
		a[y]=a[re];
		a[re]=c;
		}	
	}
}			
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
		long long int ans,q,w,e,n,median,r,i,count=1,er;
		scanf("%lld %lld %lld %lld",&q,&w,&e,&n);
		median=1;
		a[1]=1;
		top=1;
		top1=0;
		for(i=2;i<=n;i++)
		{
			ans=((((q%1000000007)*(median%1000000007)))%1000000007+((w%1000000007*i%1000000007))%1000000007+e)%1000000007;
			count=(count+ans);
			if(ans>median)
				minheap(ans);
			else
			{
				maxheap(ans);
			}
			if(top==top1+1)
			{
				median=a[1];
			}
			else if(top>top1)
			{
				minheap(a[1]);
				maxdel();
				median=a[1];
			}
			else if(top<top1)
			{
				maxheap(b[1]);
				mindel();
				median=a[1];
			}
			else if(top==top1)
				median=a[1];
		}	
		printf("%lld\n",count);
	}
	return 0;
}
