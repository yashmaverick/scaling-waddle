#include<stdio.h>

int Stack1[500003],Mountain[500003];

int main()
{
	while(1)		
	{	
		long long int i,N,j,Top=-1,count=0,vikas=0,Sum=0,flag=0,flag2=0;
		scanf("%lld",&N);
		if(N==0)
			break;
		else
		{
			Top=-1;
			vikas=-1;
			for (i = 0; i < N; i++)
				scanf("%d",&Mountain[i]);

			for(i=0;i<N;i++)
			{
				flag=0;
				vikas=-1;
				while(Stack1[Top]<=Mountain[i] &&  Top>=0)
				{
					if(Top>0)
						count++;

					//printf("count=%d\n",count);
					if(flag==0)
					{
						flag=1;
						vikas=Top;
					}	
						
					Top--;
				}

				for(j=vikas;j>=Top;j--)
					if(Mountain[i]==Stack1[j])
					{
						Top=j;
						break;
					}	

				//printf("vikas=%d  Top=%d\n",vikas,Top);
				if( i<N-1 )
				{
					Top++;
					Stack1[Top]=Mountain[i];
					//printf("Stack1[%d]= %d\n",Top,Stack1[Top]);
				}
			}
			Sum=(N*(N-1))/2-(count+(N-1));			

			printf("%lld\n",Sum);
		}
	}
	return 0;
}