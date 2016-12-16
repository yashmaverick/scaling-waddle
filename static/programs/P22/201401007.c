#include<stdio.h>
typedef long long int LL;
#define MOD 1000000007
#define MAX 1000000000000000003
LL A[200005];
LL B[200005];
void swapmin(LL i,LL j)
{
    LL c=A[i];
    A[i]=A[j];
    A[j]=c;
}
void swapmax(LL i,LL j)
{
    LL c=B[i];
    B[i]=B[j];
    B[j]=c;
}
LL min(LL a,LL b)
{
    if(a<b)
    {
	return a;
    }
    else
    {
	return b;
    }
}
LL countmin;
LL countmax;
void insertmin(LL d)
{
    LL jugad=countmin;
    A[jugad]=d;
    LL parent=jugad/2;
    while(A[parent]>A[jugad])
    {
	swapmin(parent,jugad);
	jugad=jugad/2;
	parent=jugad/2;
    }
    countmin++;
}
LL max(LL a,LL b)
{
    if(a>b)
    {
	return a;
    }
    else
    {
	return b;
    }
}
void deletemin()
{
    A[1]=A[countmin-1];
    A[countmin-1]=0;
    countmin--;
    int parent=1;
    int child1=2;
    int child2=3;
    while(1)
    {
	if(child1<countmin&&child2<countmin)
	{
	    if(A[parent]>min(A[child1],A[child2]))
	    {
		if(A[child1]<A[child2])
		{
		    swapmin(parent,child1);
		    parent=child1;
		    child1=2*parent;
		    child2=2*parent+1;

		}
		else
		{
		    swapmin(parent,child2);
		    parent=child2;
		    child1=2*parent;
		    child2=2*parent+1;
		}
	    }
	    else
	    {
		break;
	    }
	}
	else if(child1<countmin&&child2>=countmin)
	{
	    if(A[parent]>A[child1])
	    {
		swapmin(parent,child1);
		parent=child1;
		child1=2*parent;
		child2=2*parent+1;
	    }
	    else
	    {
		break;
	    }
	}
	else if (child1>=countmin&&child2>=countmin)
	{
	    break;
	}
    }

}
void insertmax(LL d)
{
    LL jugad=countmax;
    B[jugad]=d;
    LL parent=jugad/2;
    while(B[parent]<B[jugad])
    {
	swapmax(parent,jugad);
	jugad=jugad/2;
	parent=jugad/2;
    }
    countmax++;
}
void deletemax()
{
    B[1]=B[countmax-1];
    B[countmax-1]=0;
    countmax--;
    LL parent=1;
    LL child1=2;
    LL child2=3;
    while(1)
    {
	if(child1<countmax&&child2<countmax)
	{
	    if(B[parent]<max(B[child1],B[child2]))
	    {
		if(B[child1]>B[child2])
		{
		    swapmax(parent,child1);
		    parent=child1;
		    child1=2*parent;
		    child2=2*parent+1;

		}
		else
		{
		    swapmax(parent,child2);
		    parent=child2;
		    child1=2*parent;
		    child2=2*parent+1;
		}
	    }
	    else
	    {
		break;
	    }
	}
	else if(child1<countmax&&child2>=countmax)
	{
	    if(B[parent]<B[child1])
	    {
		swapmax(parent,child1);
		parent=child1;
		child1=2*parent;
		child2=2*parent+1;
	    }
	    else
	    {
		break;
	    }
	}
	else if (child1>=countmax&&child2>=countmax)
	{
	    break;
	}
    }
}
LL value(LL a,LL b,LL c,LL i,LL median)
{
    LL tmp1=((a%MOD)*(median%MOD))%MOD;
    LL tmp2=((b%MOD)*(i%MOD))%MOD;
    LL tmp3=c%MOD;
    LL tmp=((((tmp1)%MOD+(tmp2)%MOD)%MOD)+(tmp3)%MOD)%MOD;
    return tmp;
}
int main()
{
    LL F[200005];
    LL a,b,c,n,temp,t,i,sum,median,myvalue,c1,c2;
    scanf("%lld",&t);
    while(t--)
    {
	countmin=1;
	countmax=1;
	A[0]=1-MAX;
	B[0]=MAX;
	sum=0;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	F[1]=1;
	insertmax(F[1]);
	sum=sum+F[1];
	median=1;
	for(i=2;i<=n;i++)
	{
	    myvalue=value(a,b,c,i,median);
	    F[i]=myvalue;
	    sum=sum+F[i];
	    c1=countmax-1;
	    c2=countmin-1;
	    if(c1>c2)
	    {
		if(myvalue<median)
		{
		    insertmin(B[1]);
		    deletemax();
		    insertmax(myvalue);
		}
		else
		{
		    insertmin(myvalue);
		}
		median=B[1];
	    }
	    else if(c1==c2)
	    {
		if(myvalue<median)
		{
		    insertmax(myvalue);
		    median=B[1];
		}
		else
		{
		    insertmin(myvalue);
		    median=A[1];
		}
	    }
	    else if(c2>c1)
	    {
		if(myvalue<median)
		{
		    insertmax(myvalue);
		}
		else
		{
		    insertmax(A[1]);
		    deletemin();
		    insertmin(myvalue);
		}
		median=B[1];
	    }
	}
	if(n==0)
	{
	    printf("0\n");
	}
	else
	{
	    printf("%lld\n",sum);
	}
    }
    return 0;
}
