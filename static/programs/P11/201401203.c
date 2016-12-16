#include<stdio.h>
#define ll long long int
ll ar[100001],al[100001],a[100001];
int stack[100001];
int main()
{
	int n,i,p,pos,j;
	ll max,area;
	while(1)
	{
		max=0;
		scanf("%d",&n);
		if(n==0)
			return 0;
		pos=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		/*for(i=0;i<n;i++)
			printf("%d\n",al[i]);
		printf("\n");*/

		for(i=0;i<n;i++)
		{
			//printf("a\n");
			if(pos==0||a[i]>=a[stack[pos-1]])
				stack[pos++]=i;
			else
			{
				while(pos>0&&a[stack[pos-1]]>a[i])
				{
			//printf("a\n");
					pos--;
					al[stack[pos]]=i-stack[pos];
				}
				stack[pos++]=i;
			}
		/*for(j=0;j<pos;j++)
			printf("%d ",stack[j]);
		printf("\n");*/

		}
		while(pos>0)
		{
			//printf("b\n");
			pos--;
			al[stack[pos]]=i-stack[pos];
		}
		/*for(i=0;i<n;i++)
			printf("%d\n",al[i]);
		printf("\n");*/
		pos=0;
		for(i=n-1;i>=0;i--)
		{
			//printf("c\n");
			if(pos==0||a[i]>=a[stack[pos-1]])
				stack[pos++]=i;
			else
			{
				while(pos>0&&a[stack[pos-1]]>a[i])
				{
			//printf("d\n");
					pos--;
					ar[stack[pos]]=stack[pos]-i-1;
				}
				stack[pos++]=i;
			}
		}
		while(pos>0)
		{
			//printf("e\n");
			pos--;
			ar[stack[pos]]=stack[pos]-i-1;
		}
		for(i=0;i<n;i++)
		{
		//	printf("%d %d\n",al[i],ar[i]);
			area=((al[i]+ar[i])*a[i]);
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
	}
}
