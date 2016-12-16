#include<stdio.h>
#include<stdlib.h>
//#define INF 200000000

int main()
{
	int *pre,*in;
	int nodes,test,i,j,k,l;
	int js,ww,i1,i2;
	int temp,min,flag;
	scanf("%d",&nodes);
	pre=malloc(nodes*sizeof(int));
	in=malloc(nodes*sizeof(int));
	for(i=0;i<nodes;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<nodes;i++)
		scanf("%d",&in[i]);
//	for(i=0;i<nodes;i++)
//		printf("%d ", in[i]);
//	printf("\n");
	scanf("%d",&test);
	for(j=0;j<test;j++)
	{
		scanf("%d",&js);
		scanf("%d",&ww);
	//	printf("%d ",js);
	//	printf("%d \n",ww);
		for(k=0;k<nodes;k++)
		{
//			printf("%d %d\n",i1,i2);
			if(in[k]==js)
				i1=k;
			if(in[k]==ww)
				i2=k;
		}
//		printf("%d %d\n",i1,i2);
		if(i1>i2)
		{
			temp=i1;
			i1=i2;
			i2=temp;
		}
		flag=0;
		for(k=0;k<nodes;k++)
		{
			for(l=i1;l<=i2;l++)
			{
				if(pre[k]==in[l])
				{
					flag=1;
					min=k;
					break;
				}
			}
			if(flag==1)
				break;
			
		}
		printf("%d\n",pre[min]);
	}
	return 0;
}
