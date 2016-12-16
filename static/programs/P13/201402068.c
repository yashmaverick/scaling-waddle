#include <stdio.h>
#define MAX 100005
#define INFINITE1 999999
#define INFINITE2 -999999
int stack[3][MAX];
int calc;
int depth;
int head=-1;
int elements=0;
void push(int r1,int r2,int r3);
void pop();
int main()
{ 
	int arr[MAX],n;
	int t;
	int lnode;
	int r1,r2,r3;
	int maxdepth;

	scanf("%d",&t);
	while(t--)
	{   head=-1;
		elements=0;
		depth=0;
		maxdepth=0;
		//printf("reset\n");
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int temp=n;
		lnode=arr[n-1];
		while(temp--)
		{
			// printf("temp=%d\n",temp);
			calc = arr[temp];
			if((temp)==(n-1))
			{
				r1=INFINITE2;
				r2=arr[temp];
				r3=INFINITE1;

				push(r1,r2,r3);
				depth--;
			}

			else 
			{
				if( calc<=stack[1][head] && calc>stack[0][head])
				{

					//range change
					r1=stack[0][head];
					int tremp=stack[1][head];
					r2=calc;
					r3=tremp;

					push(r1,r2,r3);
					//depth++;

				}
				else if(stack[1][head]<calc && calc<stack[2][head])
				{
					//rangechange
					r1=stack[1][head];
					r2=calc;
					r3=stack[2][head];


					push(r1,r2,r3);
					//depth++;
				}

				else
				{
					while(1)
					{
						pop();
						//depth--;
						if(elements==0)
							break;
						if( calc<=stack[1][head] && calc>stack[0][head])
						{

							//range change
							r1=stack[0][head];
							int tremp=stack[1][head];
							r2=calc;
							r3=tremp;

							push(r1,r2,r3);
							//depth++;
							break;

						}
						else if(stack[1][head]<calc && calc<stack[2][head])
						{
							//rangechange
							r1=stack[1][head];
							r2=calc;
							r3=stack[2][head];


							push(r1,r2,r3);
							//depth++;
							break;
						}
					}
				}
			}
			if(depth>maxdepth)
			{
				maxdepth=depth;
				lnode=calc;
			}
			else if(maxdepth==depth && lnode>calc)
				lnode=calc;
		}
		printf("%d %d\n",lnode,maxdepth);
		//printf("OVER\n");
	}



	return 0;

}
void push(int r1,int r2,int r3)
{
	if(elements==100005)
		return;
	else
	{
		depth++;
		elements++;
		stack[0][++head]=r1;
		stack[1][head]=r2;
		stack[2][head]=r3;
		//		   printf("STACK HEAD %d %d ",calc,head);
		//		   printf(" RANGE %d %d %d\n",stack[0][head],stack[1][head],stack[2][head]);

	}
}
void pop()
{
	if(elements==0)
	{
		return;
	}
	else

	{
		//		   printf("Before POP RANGE %d %d %d\n",stack[0][head],stack[1][head],stack[2][head]);
		//			printf("POP\n");
		elements--;
		head--;
		depth--;
		//		   printf("After POP RANGE %d %d %d\n",stack[0][head],stack[1][head],stack[2][head]);

	}
}
