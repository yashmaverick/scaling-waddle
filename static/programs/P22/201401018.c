#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

long long int A[1000001],maxsize=1;
void maxinsert(long long int x)
{
    long long int y,temp1;
    A[maxsize]=x;
    maxsize++;
    temp1=maxsize-1;
    while(A[temp1/2]<x)
    {
	y=A[temp1/2];
	A[temp1/2]=x;
	A[temp1]=y;
	temp1/=2;

    }
}

void maxdelete()
{
    A[1]=A[maxsize-1];
    A[maxsize-1]=-1;
    maxsize--;
    long long int temp=1;
    long long int swap,swap1;
    while(A[temp]!=-1)
    {
	if(maxsize> 2*temp)
	{
	    int flag = 0; 
	    if((maxsize > (2*temp)+1) && (A[(2 * temp) + 1] > A[2 * temp]))
	    {
		flag = 1;
	    }
	    //else
	    //minchild = A[2 * temp];
	    if(flag == 1 && (A[temp] < A[(2*temp)+1]))
	    {
		swap = A[temp];
		A[temp] = A[(2*temp)+1];
		A[(2*temp)+1] = swap;
		temp = (2 * temp) + 1;
	    }
	    else if(flag == 0 && A[temp] < A[2*temp])
	    {
		swap = A[temp];
		A[temp] = A[2*temp];
		A[2*temp] = swap;
		temp *= 2;
	    }
	    else
		break;
	    /*if(flag == 1)
	      {
	      temp = 2 * temp + 1;
	      }
	      else
	      temp*=2;
	     */
	}
	else if(maxsize - 1 == 2 * temp)
	{
	    if(A[temp] < A[2 * temp])
	    {
		swap1=A[temp];
		A[temp]=A[2*temp];
		A[2*temp]=swap1;
		temp*=2;
	    }
	    else
		break;
	}
	else
	    break;
    }
}

long long int B[1000001],minsize=1;
void mininsert(long long int x)
{
    long long int y,temp1;
    B[minsize]=x;
    minsize++;
    temp1=minsize-1;
    while(B[temp1/2]>x)
    {
	y=B[temp1/2];
	B[temp1/2]=x;
	B[temp1]=y;
	temp1/=2;
    }
}
void mindelete()
{
    B[1]=B[minsize-1];
    B[minsize-1]=-1;
    minsize--;
    long long int temp=1;
    long long int swap,swap1;
    while(B[temp]!=-1)
    {
	if(minsize> 2*temp && minsize > 2*temp+1)
	{
	    long long int flag = 0; 
	    if(B[2 * temp + 1] < B[2 * temp])
	    {
		flag = 1;
	    }
	    //else
	    //minchild = A[2 * temp];
	    if(flag == 1 && B[temp] > B[2*temp+1])
	    {
		swap = B[temp];
		B[temp] = B[2*temp+1];
		B[2*temp+1] = swap;
		temp = 2 * temp + 1;
	    }
	    else if(flag == 0 && B[temp] > B[2*temp])
	    {
		swap = B[temp];
		B[temp] = B[2*temp];
		B[2*temp] = swap;
		temp *= 2;
	    }
	    else
		break;
	    /*if(flag == 1)
	      {
	      temp = 2 * temp + 1;
	      }
	      else
	      temp*=2;
	     */
	}
	else if(minsize - 1 == 2 * temp)
	{
	    if(B[temp] > B[2 * temp])
	    {
		swap1=B[temp];
		B[temp]=B[2*temp];
		B[2*temp]=swap1;
		temp*=2;
	    }
	    else
		break;
	}
	else
	    break;
    }
}
void print(long long A[] , long long B[])
{

}
long long int F[1000007];
int main()
{
    B[0]=-9999999999999999;
    A[0]=10000000000000000;
    int t;
    scanf("%d",&t);
    while(t--)
    {
	maxsize=1;
	minsize=1;
	long long int n,a,b,c,i,median=1,sum=0;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	F[1]=1;
	sum=sum+F[1];
	maxinsert(F[1]);
	for (i = 2; i <= n; i++)
	{
	    F[i]=((((a%MOD)*(median%MOD))%MOD+((b%MOD)*(i%MOD))%MOD)%MOD+ c%MOD)%MOD;
//	    printf("%d\n",F[i]);
	    sum=(sum+F[i]);
	    /*if(F[i] >= median)
	      mininsert(median);
	      else
	      maxinsert(median);*/
	    if(minsize < maxsize)
	    {
		if(F[i] < median)
		{
		    mininsert(A[1]);
		    maxdelete();
		    maxinsert(F[i]);
		    median = A[1];
		}
		else
		{
		    mininsert(F[i]);
		    median = A[1];
		}
	    }
	    else if(minsize == maxsize)
	    {
		if(F[i] < median)
		{
		    maxinsert(F[i]);
		    median = A[1];
		}
		else
		{
		    mininsert(F[i]);
		    median = B[1];
		}
	    }
	    else if(minsize > maxsize)
	    {
		if(F[i] < median)
		{
		    maxinsert(F[i]);
		    median = A[1];
		}
		else
		{

		    maxinsert(B[1]);
		    mindelete();
		    mininsert(F[i]);
		    median = A[1];
		}
	    }
	    
	}
	//for(i=1;i<=maxsize;i++)
	//    printf("%lld ",A[i]);
	//printf("\n");
	//for(i=1;i<=minsize;i++)
	//    printf("%lld ",B[i]);
	if(n==0)
	    printf("0\n");
	else
	    printf("%lld\n",sum);
    }
    return 0;
}
