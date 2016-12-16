#include<stdio.h>


long long stack[500005],a[500005],top;


int main()
{
	while(1)
	{
		long long i,equal;
		long long pq;
		long long n;
		top=0;
		scanf("%lld",&n);

		if(n==0)
			break;

		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);



		i=0;
	       	long long finalcount=0;
		top=0;

		while(i<n)
		{

			if(top==0 || a[i] <= a[stack[top-1]])
			{	
				stack[top]=i; top++;
				i++;
//				print(); 
//				printf("fin=%lld\n",finalcount);	
			}

			else
			{
				if (top==1)
				{	top--;
					finalcount++;
				}

				else
				{
					pq=top-1;
					finalcount++;

					while( pq>0 && a[stack[top-1]] == a[stack[pq-1]])
					{
						finalcount++; pq--;
				
					}
				
					if(pq>0)
						finalcount++;


					top--;  
//					print();
//					printf("fin=%lld\n",finalcount);	
				}

			}

		}


		while(top>0)
		{

			pq=top-1;

			while(pq>0 &&  a[stack[top-1]] == a[stack[pq-1]])
			{
				finalcount++; pq--;
			}

			if(pq>0)
				finalcount++;

//				print();
//				printf("fin=%lld\n",finalcount);	
			top--;
		
						
		}



		
		long long  out = (n*(n-1))/2;
		out -= finalcount;
		printf("%lld\n",out);
	}



	return 0;
}

