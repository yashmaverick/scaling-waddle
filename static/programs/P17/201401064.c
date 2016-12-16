#include<stdio.h>
int main()
{
	int num,i,j,k;
	scanf("%d",&num);
	int A[100000],B[100000];
	for(i=0;i<num;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<num;i++)
	{
		scanf("%d",&B[i]);
	}
	int test,state;
	scanf("%d",&test);
	int a,b,fi,li;
	while(test--)
	{
		state=0;
		scanf("%d %d",&a,&b);
		for(i=0;i<num;i++)
		{
			if(a==B[i])
			{
				fi=i;
			}
			if(b==B[i])
			{
				li=i;
			}
			
		}

		if(fi>li)
		{
		for(i=0;i<num;i++)
		{
		//	printf("%d ",B[i]);
			for(j=li;j<=fi;j++)
			{
				if(B[j]==A[i])
				{
				printf("%d\n",A[i]);
					
					state=1;
				break;
				}
			}
			if(state==1)
				break;
			}
		}
		else
		{
		for(i=0;i<num;i++)
		{
		//	printf("%d",B[i]);

			for(j=fi;j<=li;j++)
			{
				if(B[j]==A[i])
				{
				printf("%d\n",A[i]);
					
					state=1;
					break;
				}
			}
		if(state==1)
				break;
		}
		
		}
	}
	return 0;
}
