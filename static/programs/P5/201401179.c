#include<stdio.h>
#include<stdlib.h>

# define MAX 100001

                                                                                                 //void quicksort(int ENT_VALUE[],int first,int last);
int yolo_swag (const void * X, const void * Y)
{
   return ( *(int*)X - *(int*)Y );
}

int main()
{
	int TEST;
	scanf("%d",&TEST);
	while(TEST>0)
	{
		int n,K,i,j,b,ENT_VALUE[MAX],flag=0,SUM=0,tempSUM=0; 
		char NIGHT[MAX];
		scanf("%d %d",&n,&K);

		for(i=0;i<n;i++)
		{
			scanf("%s",&NIGHT[i]);
			scanf("%d",&ENT_VALUE[i]);

			SUM += ENT_VALUE[i];
		}
		// printf("SUM=%d\n",SUM );
		if(n==3)
		{
			if(K==SUM)
				printf("YES\n");
			else
				printf("NO\n");
		}	

		else
		{
			qsort(ENT_VALUE, n, sizeof(int), yolo_swag);

			for(i=0;i<n-2;i++)
			{
				
				j=i+1;
				b=n-1;
				while(b>j && flag==0)
				{
					tempSUM = ENT_VALUE[i]+ENT_VALUE[j]+ENT_VALUE[b];

					if( tempSUM ==K && j!=b)
					{	 
						flag = 1;
						printf("YES\n");
						break;
					}
					
					(tempSUM > K) ? b-- : j++ ;

				}
				if(flag==1)
					break;
			}
			if(flag==0)
				printf("NO\n");	
		}	

		TEST--;
	}		

	return 0;
}








/*
void quicksort(int ENT_VALUE[],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last)
     {
         pivot=first;
         i=first
;         j=last;

         while(i<j){
             while(ENT_VALUE[i]<=ENT_VALUE[pivot]&&i<last)
                 i++;
             while(ENT_VALUE[j]>ENT_VALUE[pivot])
                 j--;
             if(i<j){
                 temp=ENT_VALUE[i];
                  ENT_VALUE[i]=ENT_VALUE[j];
                  ENT_VALUE[j]=temp;
             }
         }

         temp=ENT_VALUE[pivot];
         ENT_VALUE[pivot]=ENT_VALUE[j];
         ENT_VALUE[j]=temp;
         quicksort(ENT_VALUE,first,j-1);
         quicksort(ENT_VALUE,j+1,last);

    }
}*/
