#include<stdio.h>
#include<string.h>
int main()
{
       long long int m,START,STOP,i,NS,k,x,w;

	START=0;
	STOP=0;
	scanf("%lld",&m);
	char c,p[m][100],T,z;
	w=0;
	while(1)
	{
		
	        scanf("%c",&z);
		scanf("%c",&T);
		if(T=='A')
		{
			scanf("%lld",&NS);
			
			i=0;
			while(i<NS)
			{
				if(w==m)
				{
					if(START==m-1)
					{
						START=0;
					}
					else
					{
						START++;
					}
				}
				scanf("%s",p[STOP]);
				STOP++;
				if(STOP==m)
				{
					STOP=0;
				}
				if(w<m)
				{
                                     w++;
				}
				
				i++;
			}
		}
		else if(T=='R')
		{
		scanf("%c",&z);
			scanf("%lld",&NS);
			w=w-NS;
			i=0;
			
			while(i<NS)
			{
				
				if(START==m-1)
				{
					
					START=0;
				}
				else
				{
					START++;
				}
			
				i++;
			}
		}
		else if(T=='L')
		{
			if(w!=0)
			{
				i=START;
				if(START==STOP)
				{
					if(STOP==0)
					{
						k=m-1;
					}
					else
					{
						k=STOP-1;
					}
				}
				else
				{
					if(STOP!=0)
					{

					k=STOP-1;
					}
					else
					{
						k=m-1;

					}

				}
				while(i!=k)
				{
					printf("%s\n",p[i]);
					i++;
					if(i==m)
					{
						i=0;
					}
				}
				printf("%s\n",p[i]);
			}

		}
		else
		{
			return 0;
		}
	}


	return 0;
}
