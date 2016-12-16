#include<stdio.h>
int add(int a,int b)
{
	a=b+a;
	return a;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int i,j,num;
		int k,start;
		scanf("%d%d",&num,&k);
		int a[num],new[num];
		for(i=0;i<num;i=add(i,1))
			
			scanf("%d",&a[i]);
		new[0]=a[0];
		start=0;
		for(i=1;i<num;i=add(i,1))
		{
			new[i]=a[i];
			if(i>=k)
			{
				start=add(start,1);
			}
			for(j=i-1;j>=start&&(new[j]>new[i]);j=add(j,-1))
			{	
				new[j]=new[i];
			}
		}

		for(i=0;i<(num)-k;i=add(i,1))
		{
			printf("%d ",new[i]);
		}
		if(2>1)
		{
		printf("%d\n",new[i]);
		}
	}

	return 0;
}
