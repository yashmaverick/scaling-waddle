#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	long long int *a;
	long long int count;
	//	int top;
}stack;
stack s1;
int front()
{
	return s1.a[s1.count];
}
void push(int b)
{
	s1.count++;
	s1.a[s1.count]=b;
}
void pop()
{
//	s1.a[s1.count]=-1;
	s1.count--;
}
int empty()
{
	if(s1.count==-1)
		return 1;
	else return 0;
}

int main()
{
	long long int n,i,j,temp,*array;
	long long maxarea,temparea;
//	s1=malloc((sizeof(stack)));
	while(1)
	{
		s1.count=-1;
		temparea=0;
		maxarea=0;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		else
		{
			s1.a=malloc(sizeof(long long int)*n);
		//	for(i=0;i<n;i++)
		//		s1.a[i]=-1;
			array=malloc(sizeof(long long int)*n);
			for(i=0;i<n;i++)
				scanf("%lld",&array[i]);
			i=0;
			while(i<n)
			{

				if(empty()==1 || array[i]>=array[front()] )
				{
					push(i);
					i++;
				}
//				else if(array[i]==array[front()])
//				{
//					i++;
//				}
				else
				{
					temp=front();
					//	printf("tempfor area=%d\n",temp);
					pop();
					if(empty()==1)
						temparea=array[temp]*i;
					else temparea=array[temp]*(i-front()-1);
					//		printf("temparea when i=%d is =%d\n",i,temparea);
					if(temparea>maxarea)
					{
						//			printf("maxarea=%d\n",maxarea);
						maxarea=temparea;
					}
				}
			}
			//			printf("front=%d\n",front());
			//			for(i=0;i<=s1.count;i++)
			//				printf("%d ",s1.a[i]);
//			printf("\n");
			while(empty()!=1)
			{
				temp=front();
				//		printf("tempfor area=%d\n",temp);
				pop();
				if(empty()==1)
					temparea=array[temp]*i;
				else temparea=array[temp]*(i-front()-1);
				//			printf("temparea for temp=%d =%d\n",temp,temparea);
				if(temparea>maxarea)
				{
					//printf("maxareawhen front=%d is=%d\n",front(),maxarea);

					maxarea=temparea;
					//				printf("maxareawhen front=%d array[temp]=%d is=%d\n",front(),array[temp],maxarea);
				}
			}

		}
		printf("%lld\n",maxarea);
		free(array);
		free(s1.a);
	}

	
}





