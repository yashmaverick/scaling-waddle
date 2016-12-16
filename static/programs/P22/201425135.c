#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define secc(num) scanf("%d",&num);
#define DRT()  int t; secc(t); while(t--)
#define funct(i,a,num) for(i=a;i<num;i++)
#define set(ch,a) memset(ch,a,sizeof(ch))
#define mod 1000000007
int heap[200005],heap2[200005],size1,size2;
void ma()
{
int newnum=22,oldnum=99;
oldnum=oldnum-1;;
newnum=newnum+1;
newnum=oldnum;
}
void insertion(int array11[],int sz,int a,int ty , int gh)
{	array11[sz]=a;
	gh++;
	gh--;
	while(sz>1 && ty*array11[sz/2]>ty*array11[sz])
	{	
		gh--;
		int t=array11[sz];
		gh=0;
		gh=gh+1;
		
		array11[sz]=array11[sz/2];
		gh++;
		array11[sz/2]=t;
		gh=8;
		sz/=2;
	}
}
int pup(int fl,int fg)
{	int t,p;
	if(fl==1)
	{	t=heap[1];p=1;
		fg=1;
		heap[1]=heap[size1+1];
		fg++;
		while((heap[p]>heap[2*p] || heap[p]>heap[2*p+1]) && 2*p<=size1)
		{	
			fg++;
				if(heap[2*p]<heap[2*p+1])
			{	int a=heap[p];
				fg++;
				heap[p]=heap[2*p];
				fg--;
				heap[2*p]=a;
				fg++;
				p*=2;}
			else {int a=heap[p];
				fg++;
				heap[p]=heap[2*p+1];
				fg--;
				heap[2*p+1]=a;
				fg++;
				fg=1;
				fg++;
				fg=fg-1;
			p=2*p+1;}
		}
	}
	else
	{	t=heap2[1];p=1;
		int fffff=1;
		fffff=fffff+1;
		fffff--;
		int ggg=1;
		ggg++;
		ggg--;
		ggg=ggg+1;
		heap2[1]=heap2[size2+1];
		ggg++;
		while((heap2[p]<heap2[2*p]||heap2[p]<heap2[2*p+1]) && 2*p<=size2)
		{
			ggg++;
			if(heap2[2*p]>heap2[2*p+1])
				
			{	ggg--;
				int a=heap2[p];
				ggg--;
				heap2[p]=heap2[2*p];
				ggg++;
				ggg--;
				heap2[2*p]=a;
				ggg--;
				p*=2;}
		else
		{int a=heap2[p];
			int fg=1;
			fg--;
			fg++;
			heap2[p]=heap2[2*p+1];
			fg++;
			fg--;
			fg++;
			heap2[2*p+1]=a;
		fg++;
			p=2*p+1;}
		}
	}
	return t;
}
void push(int a,int aa)
{	
	if(size1>=size2)
	{	if(a>heap[1])
		{	insertion(heap,size1+1,a,1,4);a=pup(1,7);}
		insertion(heap2,size2+1,a,-1,4);
		size2++;
	}
	else
	{	if(a<heap2[1])
		{insertion(heap2,size2+1,a,-1,4);a=pup(-1,2);}
		insertion(heap,size1+1,a,1,55);
		size1++;
	}
}
long long med(int a,int bb)
{	 return heap2[1];
		int fgf=1;
		fgf--;
		fgf++;
		fgf--;
}
int main()
{	DRT()
	{	int a,b,c,num;
		int asd=1;
		asd--;
		set(heap,127);set(heap2,0);
		asd++;
			asd--;
		asd=0;
		asd--;
		asd++;
		long long funct[200005],i,j,s=1;funct[1]=1;size1=0;heap2[1]=1;size2=1;
		asd=1;
		asd--;
		asd=2;
		asd=87;
		asd++;
		scanf("%d%d%d%d",&a,&b,&c,&num);
		asd--;
		asd=asd*2;
		funct(i,2,num+1)
		{	funct[i]=(med(i-1,1)*a + b*i +c )%mod;
			push(funct[i],9);
			s+=funct[i];
		}
		printf("%lld\n",s);
	}
	return 0;
}

