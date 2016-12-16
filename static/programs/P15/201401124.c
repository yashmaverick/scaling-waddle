#include<stdio.h>
int main()
{

	int t,j,n,k,i;
	scanf("%d",&t);
	while(t)
	{
		int front=-1,rear=-1,p=1,fr=-1,re=-1,temp;
		scanf("%d %d",&n,&k);
		int a[n],q1[n],q2[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			if(rear==-1)
			{
				front=0;
				rear=0;
			}
			else
				rear++;
			if((re==-1)||(fr>re))
			{
				re=0;
				fr=0;
			}
			else
				re++;
			q1[rear]=a[i];
			q2[re]=i;
			if(a[i]<=q1[front])
			{
				front=i;
				while((q2[re]<=front)&&(re!=-1))
				{
					re--;
				}
			}
			else
			{
				while((q1[q2[re]]<=q1[q2[re-1]])&&(re!=0))
				{
					re--;
					q2[re]=q2[re+1];
				}
			}
			if(i>=k-1)
			{
				if(i==n-1)
					printf("%d",q1[front]);
				else
					printf("%d ",q1[front]);
				if(front<=i-k+1)
				{
					if(re!=-1)
						front=q2[fr];
					else
						front++;
					fr++;
				}
			}

		}
		printf("\n");

		t--;

	}
	return 0;
}
