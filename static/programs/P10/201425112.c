//circular buffer

#include <stdio.h>
#include <stdlib.h>

int main()
{

	char buff[10000][100];
	
	char query[2];
	
	int N;
	scanf("%d", &N);
	                                             
    int n;
    
    int i;
    
    int f;
    f=0;
    
    int k;
    k=0;
    
    int fin;
    fin=0;
	                                             
	while(!fin)
	{
		scanf("%s", query);
		
		if(query[0]=='A')
		{
			scanf("%d", &n);
		
			for(i=0;i<n;i++)
			{
				scanf("%s", buff[(f+k)%N]);
		
				if(k!=N)
				{
					k++;
				}
		
				else
				{
					f=(f+1)%N;
				}
			}
		}
		
		else if(query[0]=='R')
		{
			scanf("%d", &n);
			
			f=(f+n)%N;
			
			k=k-n;
		}
		
		else if(query[0]=='L')
		{
			for(i=0;i<k;i++)
			{
				printf("%s\n", buff[(f+i)%N]);
			}
		}
		
		else if(query[0]=='Q')
		{
				fin=1;
		}

	}

	return 0;
}
