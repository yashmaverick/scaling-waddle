#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int A[100005];
	while(t--)
	{
		int i,na,diff,maxdiff=0;
		scanf("%d",&na);
		int min=10000000;
		for(i=0;i<na;i++)
		{
			scanf("%d",&A[i]);
			if(A[i]<min)
				min=A[i];
			diff=A[i]-min;
			if(diff>maxdiff)
				maxdiff=diff;
		}
		if(maxdiff!=0)
			printf("%d\n",maxdiff);
		else
			printf("0\n");
	}
	return 0;
}
