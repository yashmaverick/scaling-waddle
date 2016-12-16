#include<stdio.h>
#include<stdlib.h>
int *a1,*a2,*a3,*temp1;
int main()
{
//	int n1,n2,n3,*a1,i,*a2,*a3,t,*temp1,count2=0,count3=0;
//	long long int final,count=0;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n1,n2,n3,i,count2=0,count3=0;
		long long int final,count=0;
		final=0;
		scanf("%d",&n1);
		a1=(int *)malloc(sizeof(int)*(n1+1));
		for(i=0;i<n1;i++)
			scanf("%d",&a1[i]);
		scanf("%d",&n2);
		a2=(int *)malloc(sizeof(int)*(n2+1));
		for(i=0;i<n2;i++)
			scanf("%d",&a2[i]);
		scanf("%d",&n3);
		a3=(int *)malloc(sizeof(int)*(n3+1));
		for(i=0;i<n3;i++)
			scanf("%d",&a3[i]);
		temp1=(int *)malloc(sizeof(int)*(n2+1));
		//	temp2=malloc(sizeof(int)*n3);
		int m=0;
		int n=0;
		count=0;
		while(m<n2)
		{
			if(a2[m]>=a1[n] && n<=m && n<n1)
			{
				count++;
				n++;
			}
			else
				//	temp=temp+count;
			{
				temp1[m]=count;
				m++;
			}
		}
		m=0;
		n=0;
		count=0;
		while(m<n3)
		{
			if(a3[m]>=a2[n] && (n<=m && n<n2))
			{
				//	tempcount=
				count=count+temp1[n];
				//	final=final+temp1[n]
				n++;

			}
			else
			{

				//	temp=temp+count;
				final=final+count;
				m++;
				count3++;
			}
			count3=count2+1;
			//		for(i=0;i<m;i++)
			//		{
			//			printf("%d ",temp1[i]);
			//		}
			//		printf("%d\n",m);
			//	return 0;
			//	printf("%d %d\n",count2,count3);
		}
		printf("%lld\n",final);
		free(a1);
		free(a2);
		free(a3);
		free(temp1);
	}
	return 0;
}
