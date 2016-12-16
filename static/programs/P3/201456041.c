#include<stdio.h>
int main()
{
	int test,j=0;
	scanf("%d",&test);
	int array[100000];
	int max=0;
	while(j<test)
	{
		int days,k=0;
		scanf("%d",&days);
		while(k<days)
		{
			scanf("%d",&array[k]);
			k++;
		}
		int min= array[0],i;
		max=0;
		int diff=0;
		for(i=0;i<k;i++)
		{
			if(array[i]<min)
				min=array[i];
			diff= array[i]-min;
			if(diff>0 && diff>max)
				max=diff;
		}
		printf("%d\n",max);
		j++;
	}
	return 0;
}
