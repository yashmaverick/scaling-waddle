#include<stdio.h>
int a[500000][4],i,s;
push(long long int x,long long int c,long long int e,long long int index)
{
    i++;
    a[i][0]=x;
    s=x;
    a[i][1]=c;
    a[i][2]=e;
    a[i][3]=index;
}
pop()
{
    i--;
    if(i!=-1)
    	s=a[i][0];
    else
	s=0;
}
int main()
{
    long long int n,j,c,e,x,k;
    long long int b;
    scanf("%lld",&n);
    while(n!=0)
    {
    b=0;
    i=-1;
    s=0;
    scanf("%lld",&x);
    push(x,0,0,0);
    for(j=1;j<n;j++)
    {
	scanf("%lld",&x);
	c=e=0;
	    while(s<=x && i!=-1)
	    {
		b+=a[i][1];
		if(s<x)
		    c+=(a[i][1]+a[i][2]+1);
		else
		{
		    c+=a[i][1];
		    e+=(a[i][2]+1);
		}
		pop();
	    }
	    if(i!=-1)
		b+=a[i][3];
	    push(x,c,e,j);
    }
    printf("%lld\n",b);
    scanf("%lld",&n);
    }
return 0;
}
