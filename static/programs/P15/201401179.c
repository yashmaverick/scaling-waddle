#include<stdio.h>

int Array[100010];
int IINDEX;
int start,end;
int FindingMinimum()
{
	int j,min;
	min=Array[start];
	for(j=start;j<=end;j++)
	{
		if(Array[j]<=min)
		{	min=Array[j];
			IINDEX=j;
		}	
	}
	return min;
}
int main()
{

	int Test;
	scanf("%d",&Test);
	while(Test>0)
	{
		int N,K,i,m,flag=1,currentmin;
		int Minimals[100001];
		scanf("%d %d",&N,&K);
		
			if(K==1)
			{
				for (i = 1; i <= N;i++)
					scanf("%d",&Array[i]);
				for (i = 1; i < N;i++)
					printf("%d ",Array[i]);
				printf("%d",Array[N]);
				
			}
			else
			{
				for (i = 1; i <= N ;i++)
					scanf("%d",&Array[i]);

				start=1;
				end=K;
				currentmin=FindingMinimum();
				Minimals[flag++]=currentmin;
				for (m=K+1; m <=N; m++)
				{
					start++;	
						if(currentmin<=Array[m])
						{	
							if(IINDEX==start-1)
							{
								end=m;
								currentmin=FindingMinimum();
								Minimals[flag++]=currentmin;
							}

							else
								Minimals[flag++]=currentmin;		
						}		

						else if(currentmin>=Array[m])
						{
							currentmin=Array[m];
							IINDEX=m;
							Minimals[flag++]=Array[m];
						}	

				}

				for(i=1;i<flag-1;i++)
					printf("%d ",Minimals[i]);	
				printf("%d",Minimals[flag-1]);			
			}

		printf("\n");
		Test--;
	}
	return 0;
}

	/*	if(K==2)
		{
			for (i = 1; i <= N;i++)
			{
				scanf("%d",&Array[i]);
				if(i==1)
					currentmin=Array[1];
				if(Array[i]<=Array[i-1] && i!=1)				
					currentmin=Array[i];
				else if(Array[i]>=Array[i-1] && i!=1)
					currentmin=Array[i-1];

				if(i!=1)
					Minimals[flag++]=currentmin;
			}	

			for(i=1;i<flag-1;i++)
				printf("%d ",Minimals[i]);
			printf("%d",Minimals[flag-1]);
a		}*/
