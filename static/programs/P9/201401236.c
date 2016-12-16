#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int a;
	int *b;
}link;
int main()
{
	int  ju,n,u,i,j,bal,weit,c,k,mod,pp;
	int *kk;	
	link*array  ;
	scanf("%d %d",&n,&mod);
	array=(link *)malloc(sizeof(link)*n);
	j=0;	
	int axis[n];
int king=n;
         while(n--)
	{

		scanf("%d",&bal);
		{
			i=0;
			array[j].b=malloc(sizeof(int)*bal);
			while(bal--)
			{
				scanf("%d",&weit);
				//printf("%d\n",array[0].b[2]);				
				////array->*b={0}; 
				//printf("%d\n",array[j].b[i]);
				array[j].b[i]=weit;
				//                   	printf("%d  \n",array[0].b[i]);		
				array[j].a=((array[j].a)%mod+weit%mod)%mod;
				//  printf("%d   \n",array[0].a);	
				i++;
			}
			axis[j]=i-1;
			//			
			//			printf("%d \n",array[0].a);
			j++;
		}
	}


		for(i=0;i<king;i++)
      {				
      for(k=0;k<king-1;k++)
 			{
			        pp=k+1;	
                           if((array[pp].a)<(array[k].a))
			{
	                            				
             

                                   	    c=array[pp].a;
						array[pp].a=array[k].a;
						array[k].a=c;
						kk=array[k].b;
						array[k].b=array[pp].b;				
						array[pp].b=kk; 
						c=axis[pp];				
						axis[pp]=axis[k];
						axis[k]=c;

					//	printf("jaffa\n");


				}
			}
      }	
	//  printf("%d  ",j);
	ju=0;
	for(u=0;u<j;u++)
	{
		i=0;
		printf("%d\n",array[u].a);			
		 
		while(axis[ju]!=-1)
		{
			printf("%d\n",array[u].b[i]);
			i++;
			axis[ju]--;		
		}
		ju++;	//	printf("\n");
 		printf("\n");
	

}
	return 0;
}	


