#include<stdio.h>
#include<string.h>


long long int Stack1[100000],Stack2[100000],Fence[100000];

int main()
{
	while(1)		
	{	
		long long int i,N,MAX_AREA=-1,Top=-1,left,currentarea;
		scanf("%lld",&N);
		if(N==0)
			break;
		else
		{
			for (i = 0; i < N; i++)
				scanf("%lld",&Fence[i]);

			i=0;
			while(i<=N)  //for(i=0;i<=N;i++)
			{
				while(Top>=0 && (i==(N) || Stack1[Top]>Fence[i]) )
				{
					if(Top>0)
							currentarea=(i-Stack2[Top-1]-1)*Stack1[Top];			

					else
						currentarea=i*Stack1[Top];			

					Top--;
					if(currentarea>MAX_AREA)
						MAX_AREA=currentarea;

				}

				if( i<(N) )
				{
					Top++;
					Stack1[Top]=Fence[i];
					Stack2[Top]=i;
				}
				i++;
			}

			printf("%lld\n",MAX_AREA);
		}
	}
	return 0;
}


