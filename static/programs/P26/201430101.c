#include<stdio.h>
//#include<stdlib.h>
int count=0;
int n1,n2;
int found=0;
int b=0;
int vis[10000];
int level[10000];
int queue[10000];
int head=0;
int tail=-1;
void push(int l)
{
	queue[++tail]=l;
}
int pop()
{
	head++;
	return queue[head-1];
}/*
void scant(int *p)
{
	register int c = getchar_unlocked();
	int x = 0;
	for(;(c<48 || c>57);c = getchar_unlocked())
		;
	for(;c>47 && c<58;c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	*p = x;
}*/
int sieve[10000]={0};
void sievefunc()
{
	int i,j;
	for(i=2;i<=97;i++)
	{
		if(sieve[i]!=-1)
		{
			for(j=i*i;j<10000;j=j+i)
				sieve[j]=-1;
		}
	}
}
int num[4];
/*
   void numtoarr(int x)
   {
   num[3]=x%10;
   x=x/10;
   num[2]=x%10;
   x=x/10;
   num[1]=x%10;
   x=x/10;
   num[0]=x%10;
   }*/
/*
   int arrtonum(int*a)
   {
   int ans;
   ans=a[3]+10*a[2]+100*a[1]+1000*a[0];
   return ans;
   }*/
void numgen(int *a)
{
	int i,j;
	int lp=a[3]+10*a[2]+100*a[1]+1000*a[0];
	//arrtonum(a);
	int b[4];
	b[0]=a[0];b[1]=a[1];b[2]=a[2];b[3]=a[3];
	for(i=0;i<4;i++)
	{
		for(j=0;j<=9;j++)
		{
		  if(j==b[i])
		    continue;	
		  	a[i]=j;
			if(i==0 && a[i]==0)
				continue;
			//	a[i]=(a[i]+1)%10;
			int e=a[3]+10*a[2]+100*a[1]+1000*a[0];//arrtonum(a);
			if(sieve[e]==-1)
				continue;
			if(e==n2)
			{
				found=1;
				level[e]=level[lp]+1;
				return;
			}
			if(vis[e]!=1)
			{
				push(e);
				level[e]=level[lp]+1;
			}
			vis[e]=1;
		}
		a[i]=b[i];
	}
}
int main()
{
	int test,i;
	scanf("%d",&test);
//	scant(&test);
	sievefunc();
	while(test--)
	{
		head=0;
		//ten=9;
		tail=-1;
		for(i=0;i<10000;i++)
		{
			//if(sieve[i]!=-1)
			//{
				queue[i]=0;
				vis[i]=0;
				level[i]=0;
			//}
		}
		found=0;
		count=0;
		scanf("%d%d",&n1,&n2);
		//scant(&n1);
		//scant(&n2);
		push(n1);
		if(n1==n2)
			found=1;
		while(found!=1)
		{
			int r;
			if(head-tail!=1)
				r=pop();
			else
				break;

			//numtoarr(r);
			num[3]=r%10;
			r=r/10;
			num[2]=r%10;
			r=r/10;
			num[1]=r%10;
			r=r/10;
			num[0]=r%10;
			numgen(num);
		}
		if(found==1)
			printf("%d\n",level[n2]);
		else
			printf("Impossible\n");
	}
	return 0;
}

