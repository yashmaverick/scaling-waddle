#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n1,n2,n3,i,j,k;
	int a1[100004],a2[100004],a3[100004],*c1,c2[100004]={0},t;
	int x,s,s1,y,z,s3;
	long long int sum,total;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n1);
		for(i=0;i<n1;i++)
			scanf("%d",&a1[i]);
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
			scanf("%d",&a2[i]);
		scanf("%d",&n3);
		for(i=0;i<n3;i++)
			scanf("%d",&a3[i]);
		i=0;j=0;
		s=0;x=0;
		c1=(int *)malloc(sizeof(int)*n2);
		while(j<n2)
		{
			if (a2[j]>=a1[i] && (j>=i && i<n1))
			{
				i++;;
			}
			else
			{	c1[j]=i;
				j++;
			}
		}
//		for(i=0;i<n2;i++)
//			printf("%d ",c1[i]);
		i=0;j=0;k=0;
		s1=0;y=0;
		total=0;
		sum=0;
		while(k<n3)
		{
			if(a3[k]>=a2[j] && (k>=j && j<n2))
			{
				sum=sum+c1[j];
				j++;
			}
			else
			{
				total=total+sum;
				k++;
			}
		}
		s3=0;
		//printf("% d",s1);
		printf("%lld\n",total);
	}
	return 0;
}
