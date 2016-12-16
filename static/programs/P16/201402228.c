#include<stdio.h>
#include<math.h>
int main()
{
	int t,i,n,level=0,count,y,max,m;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		count=0;
		scanf("%d",&n);
		m=n;
		while(m)
		{
			m=m/2;
			count++;
		}
		y=pow(2,count-1);
		if(n>=(3*(y/2)))
			max=(2*(count))-2;
		else
			max=(2*(count))-3;
		printf("%d\n",max);
	}
	return 0;
}
			
				






