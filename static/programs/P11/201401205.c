#include<stdio.h>
	long int a[500001],b[500001];
int main()
{
	long int area,maxarea,tp,top,n;
	n=-1;
	while(1)
	{
		int i=0;
		scanf("%ld",&n);
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
				scanf("%ld",&a[i]);
			top=-1;
			maxarea=0;
			i=0;
			while(i<n)
			{
				if(top==-1||a[b[top]]<=a[i])
				{
					top++;
					b[top]=i;
					i++;
				}
				else
				{
					tp=b[top];
					top--;
					area=a[tp]*(top==-1?i:i-b[top]-1);
					//	printf("%d ",area);
					if(maxarea<area)
						maxarea=area;
				}
			}
			while(top!=-1)
			{
				tp=b[top];
				top--;
				area=a[tp]*(top==-1?i:i-b[top]-1);
				if(maxarea<area)
					maxarea=area;
			}
			printf("%ld\n",maxarea);
		}
	}
	return 0;
}
