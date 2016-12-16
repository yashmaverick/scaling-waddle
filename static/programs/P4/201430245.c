#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int values[1000000];

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	 char a[1000000];
    int values[1000000],i,n,p;
        scanf("%s",a);
         p=strlen(a);
        for(i=0;i<p;i++)
    {
        if(a[i]=='J')
        {
                values[i]=1000;
        }
        else if(a[i]=='M')
        {
                values[i]=-1;
        }
        else if(a[i]=='R')
        {
               values[i]=-999;
        }

        }
        for(i=1;i<p;i++)
        {
                values[i]=values[i]+values[i-1];
        }

	int count=1,result=0;
   qsort(values, p, sizeof(int), cmpfunc);
//		printf("%d	\n",values[0]);
	for(i=1;i<p;i++)
	{
		if(values[i]==values[i-1])
		{
			count++;		
		}	
		if(values[i]!=values[i-1])
		{
			result=result+(count*(count-1)/2);
			count=1;		
		}	
		//printf("%d	\n",values[i]);
	}
			result=result+(count*(count-1)/2);
	int cont=0;
	//printf("	R%d\n",result);
   for( n = 0 ; n < p; n++ ) 
	{
		if(values[n]==0)
		{
			cont++;
		}
   }
//	printf("%d	%d	",result,cont);

	result=result+cont;
	printf("%d\n",result);
	
  }
  return(0);
}
