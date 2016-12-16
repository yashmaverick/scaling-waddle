#include <stdio.h>

//big k
//small k
//up to k
void bubble(int array[],int len)
{
	int i,j,temp,flag=0;

	for (i=0;i<len;i++)
	{
		for (j=0;j<len-i-1;j++)
		{
			if (array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				flag=1;
			}
		}

		if (flag==0)break;
	}



}

void shortest(int array[],int len,int K)
{
	int smallest=array[0];
	int sum=0;
	int diff=0;
	int count=1;
	int flag=0;

	while(K>0 && count<len)
	{
		//		printf("loop\n");

		diff=array[count]-array[count-1];
		//		printf("diff%d\n",diff);
		sum=diff*count;
		//		printf("sum:%d\n",sum);
		//		printf("K,len%d,%d\n",K,len);
		//		printf("smallest%d\n",smallest);

		if (K<sum)
		{
			smallest+=K/count;
			flag=1;
			break;
		}
		K-=sum;
		smallest+=diff;

		count++;
	}

	if (K>0 && flag==0)smallest+=K/len;

	printf("%d\n",smallest);

}



int main()
{
	int array[1000000],k,n,i;
	scanf("%d",&n);

	for(i=0;i<n;i++)scanf("%d",&array[i]);
	scanf("%d",&k);


	bubble(array,n);
	shortest(array,n,k);



	//	for(i=0;i<5;i++)printf("%d\n",array[i]);

	return 0;
}

