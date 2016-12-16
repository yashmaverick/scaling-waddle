#include<stdio.h>
#include<math.h>
int p=1;
int Log2(int n)
{
	int l=0;
	while(n)
	{
		n=n>>1;
		l++;
		p=p*2;
	}
	l--;
	p=p/2;
	return l;
	//return (n> r-1)? 1+ Log2(n/r):0;
}

int main()
{
	int test,i,diam,h,g,y,z;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		p=1;
		scanf("%d",&z);
		y=Log2(z);
//		printf("%d ",y);
		//while(x--)
		//	h=h*2;
	//	printf("%d ",h);
		g=p+p/2;
	//	printf("%d ",g);
	//	printf("%d ",y);
		if(z<g)
			diam=(2*y-1);
		else
			diam=2*y;
		printf("%d\n",diam);
	}
	return 0;

}
