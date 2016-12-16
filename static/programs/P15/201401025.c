#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,K,T,i,j,top,start,k;
	int *a,*min,*b;

	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d%d",&N,&K);
		i=1;top=0;start=0;j=0;
		a=malloc((N+2)*sizeof(int));
		b=malloc((N+2)*sizeof(int));
		min=malloc((N+2)*sizeof(int));

		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(i=1;j!=(N-K+1);i++)
		{
			if(i<=K)
			{
				if(start == top || a[i]>=a[b[top-1]])
				{b[top]=i;
					top++;
				}
				else
				{
					while(a[i]<a[b[top-1]] && top>start)
					{
						top--;
					}
					b[top]=i;
					top++;
				}
			}
			if(i==(K+1))
			{
				min[j]=a[b[start]];
				j++;
				if(j==(N-K+1))
					break;
			}
			if(i>K)
			{
				if(start == top || a[i]>=a[b[top-1]])
				{b[top]=i;
					top++;
				}
				else
				{
					while(a[i]<a[b[top-1]] && top>start)
					{
						top--;
					}
					b[top]=i;
					top++;
				}
				if(b[start]==(i-K))
					start++;
				min[j]=a[b[start]];
				j++;
//				if(j==(N-K+1))
//					break;
			}
		}
		for(i=0;i<(j-1);i++)
			printf("%d ",min[i]);
		printf("%d\n",min[j-1]);
		free(min);
		free(a);
		free(b);
		T--;


	}
	return 0;
}
