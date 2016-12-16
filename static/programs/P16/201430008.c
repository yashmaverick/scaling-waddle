#include<stdio.h>
int pav(int x,int i)
		{
			int j,prod=1;
				if(i==0)
				return 1;
				else
				{
			for(j=0;j<i;j++)
			{
				prod=prod*x;
			}
			return prod;
		}
		}
int lagu(int y)
{
	int v;
	int k=0;
	for(v=1;v<y;v++)
	{	
	if(y>=pav(2,v))
		k++;
	else break;
	}
return k;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int n,h,w;
	scanf("%d",&n);
	if(n==1)
		printf("0\n");
	else if(n==2)
		printf("1\n"); 
	else
	{
	h=lagu(n);
	w=3*(pav(2,h-1));
	if(n<w)
		printf("%d\n",((2*h)-1));
	else
		printf("%d\n",(2*h));
	}
	}
	return 0;
}
