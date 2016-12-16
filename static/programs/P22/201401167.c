#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#define set(ch,a) memset(ch,a,sizeof(ch))
#define mod 1000000007
int hp1[200005],hp2[200005],sz1,sz2;
void insert(int ar[],int sz,int a,int ty)
{	ar[sz]=a;
	while(sz>1 && ty*ar[sz/2]>ty*ar[sz])
	{	int t=ar[sz];
		ar[sz]=ar[sz/2];
		ar[sz/2]=t;
		sz/=2;
	}
}
int pop(int fl)
{	int t,p;
	if(fl==1)
	{	t=hp1[1];p=1;
		hp1[1]=hp1[sz1+1];
		while((hp1[p]>hp1[2*p] || hp1[p]>hp1[2*p+1]) && 2*p<=sz1)
		{	if(hp1[2*p]<hp1[2*p+1])
			{	int a=hp1[p];
				hp1[p]=hp1[2*p];
				hp1[2*p]=a;
				p*=2;}
			else {int a=hp1[p];
				hp1[p]=hp1[2*p+1];
				hp1[2*p+1]=a;
			p=2*p+1;}
		}
	}
	else
	{	t=hp2[1];p=1;
		hp2[1]=hp2[sz2+1];
		while((hp2[p]<hp2[2*p]||hp2[p]<hp2[2*p+1]) && 2*p<=sz2)
		{if(hp2[2*p]>hp2[2*p+1])
			{int a=hp2[p];
				hp2[p]=hp2[2*p];
				hp2[2*p]=a;
				p*=2;}
		else
		{int a=hp2[p];
			hp2[p]=hp2[2*p+1];
			hp2[2*p+1]=a;
			p=2*p+1;}
		}
	}
	return t;
}
void push(int a)
{	
	if(sz1>=sz2)
	{	if(a>hp1[1])
		{	insert(hp1,sz1+1,a,1);a=pop(1);}
		insert(hp2,sz2+1,a,-1);
		sz2++;
	}
	else
	{	if(a<hp2[1])
		{insert(hp2,sz2+1,a,-1);a=pop(-1);}
		insert(hp1,sz1+1,a,1);
		sz1++;
	}
}
long long med(int a)
{	 return hp2[1];
	//return (hp1[1]+hp2[1])/2;
}
int main()
{	DRT()
	{	int a,b,c,n;
		set(hp1,127);set(hp2,0);
			//printf("hp1->%d\n",hp1[1]);
		long long f[200005],i,j,s=1;f[1]=1;sz1=0;hp2[1]=1;sz2=1;
		scanf("%d%d%d%d",&a,&b,&c,&n);
		//	f(i,0,n)insert(hp1,sz1++,i*i+1,1);
		//	f(i,1,n+1)printf("%d %d\n",hp1[i],hp2[i]);
		f(i,2,n+1)
		{	f[i]=(med(i-1)*a + b*i +c )%mod;
			push(f[i]);
			s+=f[i];
		//	printf("%lld\n",f[i]);
		}
		//	f(j,1,i/2+1)printf("%d %d\n",hp1[j],hp2[j]);}
		printf("%lld\n",s);
	}
	return 0;
}

