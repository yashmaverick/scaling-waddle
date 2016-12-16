

#include<stdio.h>

int main()
{
	int q[100005];
	int a[100005];
	int t,n,k,top,end,i,el,range;
	scanf("%d",&t);
	while(t--)
	{
		top=0;
		end=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		top=1;
		end=1;
		q[top]=0;
		el=1;
		if(k==1)
	
		{
			for(i=0;i<n-1;i++)
				printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
		else
		{
		for(i=1;i<n;i++)
		{
			range=i-k+1;
			if(q[end]<range)
			{
				end++;
				el--;
			}
			while(el!=0)
			{
				if(a[i]>a[q[top]])
					break;
				else
				{
					top--;
					el--;
				}
			}
			q[++top]=i;
			el++;
			if(i==n-1)
				printf("%d\n",a[q[end]]);
			else
			if(i>=k-1)
				printf("%d ",a[q[end]]);
		}
		}
	}
	return 0;
}
