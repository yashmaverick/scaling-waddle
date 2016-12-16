#include<stdio.h>
#define gcu getchar_unlocked
inline void scn(int *p) 
{
	register int x=0;
	register int c=gcu();
	for(;(c<48 || c>57);c = getchar_unlocked())
		;   
	for(;c>47 && c<58;c=gcu())
		x=(x<<1)+(x<<3)+c-48;
	*p=x;
}

int main()
{
	int i,t,n,a,max=0,sum=0,b;
	scn(&t);
	while(t--)
	{
		sum=0;
		max=0;
		scn(&n);
		scn(&a);
		for(i=1;i<n;i++)
		{
			scn(&b);
			sum+=(b-a);
			if(sum<0)
				sum=0;
			if(sum>max)
				max=sum;
			a=b;
		}
		printf("%d\n",max);
	}
	return 0;
}
