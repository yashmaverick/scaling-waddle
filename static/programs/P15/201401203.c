#include<stdio.h>

int a[10001],n,k,m,m1,sq[10001];
int main()
{
	int i,t,tail,head,j;
	scanf("%d",&t);
	while(t--)
	{
		tail=1;head=1;
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=k;i++)
		{
			if(tail==head)
			{
				sq[tail++]=i;
				m=head;
			}
			else
			{
				if(a[i]>=a[sq[tail-1]])
					sq[tail++]=i;
				else
				{
					while(tail>0&&a[i]<a[sq[tail-1]])
						tail--;
					sq[tail++]=i;
					m=head;
				}
			}
		}
		if(k!=n)
			printf("%d ",a[sq[m]]);
		else
			printf("%d\n",a[sq[m]]);
		//printf("%d",tail);
		for(i=k+1;i<=n;i++)
		{
			if(sq[tail-1]-sq[head]>=k-1)
			{
				head++;
			}
			if(a[i]>=a[sq[tail-1]])
				sq[tail++]=i;
			else
			{
				while(tail>0&&a[i]<a[sq[tail-1]])
				{
					if(tail==head)
						head--;
					tail--;
				}
				sq[tail++]=i;
				//if(i==10)
				//	printf("a%d %d %d %d\n",head,tail,sq[tail-1],sq[head]);
			}
			if(i<n)
				printf("%d ",a[sq[head]]);
			else
				printf("%d\n",a[sq[head]]);

		}
		/*for(i=head;i<tail;i++)
			printf("%d ",a[sq[i]]);
		printf("\n");*/
	}
	return 0;
}

