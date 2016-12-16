#include<stdio.h>
int main()
{
	long long int N,i,top,a[100001],stack[100001],pop;
	long long int area,max;
	scanf("%lld",&N);//
	while(N!=0)
	{
		top=0;max=0;
		scanf("%lld",&a[0]);
		stack[top]=0;
		for(i=1;i<N;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=a[stack[top]])
			{
				top++;
				stack[top]=i;
			}
			else
			{
				while(a[i]<a[stack[top]])
				{
					pop=stack[top];
					top--;
					if(top==-1)
						area=a[pop]*(i);
					else
						area=a[pop]*(i-stack[top]-1);
					if(area>max)
						max=area;
					//printf("%lld\n",area);
					if(top==-1)
						break;
				}
				top++;
				stack[top]=i;
			}
		}
		while(top!=-1)
		{
			pop=stack[top];
			top--;
			if(top==-1)
				area=a[pop]*(i);
			else
				area=a[pop]*(i-stack[top]-1);
			if(area>max)
				max=area;
			//		printf("%lld\n",area);
		}
		printf("%lld\n",max);
		scanf("%lld",&N);
	}
	return 0;
}
