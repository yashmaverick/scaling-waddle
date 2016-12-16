#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	char *a;
}link;
int main()
{
	link *array;
	int i=0,n,end=0,sum=0,N,start=0;
	char c,*s;
	scanf("%d",&N);
	array=malloc(sizeof(link)*1000000);
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&n);
			
				
 					//printf("%d\n",sum);
					while(n--)
				{
					
          				if(sum<N)
 					{
					sum++;
					array[end].a=malloc(sizeof(char)*100);
					scanf("%s",array[end].a);
					//printf("%s\n",array[0].a);
					end++;
					}
				else if(sum>=N)
				{
			    	start++;	
                        	free(array[start-1].a);
				sum--; 
				s=malloc(sizeof(char)*100);
				scanf("%s",s);
				array[end].a=s;
				end++;
				sum++;				
}
		}
}		
		if(c=='R')
		{
			scanf("%d",&n);
			while(n--)
			{
				start++;
				free(array[start-1].a);
				sum--;
			}
		}
		if(c=='L')
		{
			for(i=start;i<end;i++)
			{
				printf("%s\n",array[i].a);
			}
		}
		if(c=='Q')
			break;
	}
	return 0;
}





