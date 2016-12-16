#include<stdio.h>
long long int i,s;
long long int a[1000000][2];
void push(long long int x,long long int l)
{
    i++;
    a[i][0]=x;
    a[i][1]=l;
    s=a[i][0];
}
void pop()
{
    i--;
    s=a[i][0];
}
int main()
{
    long long int n,j,c,x;
    long long int max,ar;
    scanf("%lld",&n);
    while(n!=0)
    {
	s=0;
	i=-1;
	max=0;
	while(n--)
	{
	    scanf("%lld",&x);
	    if(x>s)
	    {
		push(x,0);
	    }
	    else if(x<=s)
	    {
		c=0;
		while(s>=x)
		{
		    c+=a[i][1];
		    c++;
		    ar=a[i][0]*c;
		    if(ar>max)
			max=ar;
		    pop();
		    if (i==-1)
		    {
			s=0;
			break;
		    }
		    s=a[i][0];
		}
		push(x,c);
	    }
	}
	c=0;
	while(i!=-1)
	{
	    c+=a[i][1];
	    c++;
	    ar=a[i][0]*c;
	    if(ar>max)
		max=ar;
	    pop();
	    s=a[i][0];
	}
	printf("%lld\n",max);
	scanf("%lld",&n);
    }
    return 0;
}
