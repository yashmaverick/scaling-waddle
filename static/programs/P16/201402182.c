#include<stdio.h>
int po(int a,int b)
{int x;
	if(b==0)
		return 1;
	x=po(a,b/2);
	if(b%2==0)
		return x*x;
	else 
		return a*x*x;
}
int main()
{
	int n,x,q,i,k,g;
		scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&q);
		if(q==1)
		{printf("0\n");
		continue;}
		k=0;x=1;
		while(x<=q)
		{
			k++;
			x=po(2,k);
		}
		//printf("%d %d== ",k,po(2,k));
		//if(x==n)
		//	k=k+1;
		
		g=(po(2,k-1)+po(2,k))/2;
		if(q>=g)
		{
			printf("%d\n",(2*k)-2);
		}
		else
			printf("%d\n",(2*k)-3);

	}
	return 0;
}
