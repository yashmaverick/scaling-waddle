#include<stdio.h>
#include<math.h>

int Stack1[100003],Nodes[100003],Stack2[100003];

#define cout(n) printf("%d\n",n)
#define cin(n) scanf("%d", &n)

int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test--)		
	{	
		int i,N,j,Top=-1,depth=-1,vikas=0,Element,maxdepth=-1,flag2=0;
		scanf("%d",&N);
			for (i = 0; i < N; i++)
				scanf("%d",&Nodes[i]);

			for(i=N-1;i>=0;i--)
			{
				while(Stack1[Top]>Nodes[i] &&  Top>=0)
				{
					depth=Stack2[Top]+1;
					vikas=depth;
					Top--;
				}
					Top++;
					Stack1[Top]=Nodes[i];
					Stack2[Top]=vikas;
					if(Stack2[Top]>=maxdepth)
					{
						maxdepth=Stack2[Top];
						Element=Stack1[Top];
						//printf("Element=%d\n",Element);
					}
				vikas++;	
			}
		printf("%d %d\n",Element,maxdepth);	
	}
	
	return 0;
}