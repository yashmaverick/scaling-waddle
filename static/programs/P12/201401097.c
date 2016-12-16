#include<stdio.h>
typedef struct node
{
	long long int no;
	long long int count;
}nide;

int main ()
{
	long long int i,n=1,a,top=-1,count=0;
       	nide node[500005];
	while(n!=0)
	{
		count=0;
		top=-1;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
	
        
	
		
		if(top==-1)
		{
			node[++top].no=a;
			node[top].count=0;
		}
		else if(node[top].no>=a)
		{
			if(node[top].no==a)
			{
					
					node[top+1].count=node[top].count+1;

				count=count+node[top+1].count;
				top++;
				node[top].no=a;
			}
			
                         else
			 {
	                node[top+1].count=1;
                        node[++top].no=a;
				count=count+node[top].count;	
			 }
		}
		else if(node[top].no<a)
		{
			
			while((node[top].no<a)&&(top!=-1))
		{
						
				count++;
		
			--top;
		}
		//	printf("%lldcount\n",count);
			if(top==-1)
		       {
                              	node[++top].no=a;
				node[top].count=0;


		       }

			else if((node[top].no==a)&&(top!=-1))
			{
					
					node[top+1].count=node[top].count+1;

				count=count+node[top+1].count;
				top++;
				node[top].no=a;
			}
			else if (top!=-1)
			{
				node[++top].no=a;
				node[top].count=1;
				count=count+node[top].count;
			}
			
		}
	}
/*	while(top!=-1)
	{
		if(node[top].no==node[top-1].no)
		{

		}
		--top;

	}
*/
/*for(i=0;i<=top;i++)
	printf("%lld\n",node[top].no);*/
	if(n!=0)
	{
//	printf("%lldways can see \n",count);
		count=((n*(n-1))/2)-count;

		printf("%lld\n",count);
	}

	}
		return 0;
}
