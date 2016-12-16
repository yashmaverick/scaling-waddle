#include<stdio.h>
int N,k;
int fun(int *A,int j)
{
 int mi,l,i;l=j;
 mi=*(A+j);
 for(i=0;i<k;i++)
{
	  if(*(A+j+i)<mi)
	   {
		   mi=*(A+j+i);
                   l=j+i;
	   }
}
	  return l;
}
int main()
{
	int i,t,mini,j;mini=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&N,&k);
		int A[N];
		for(j=0;j<N;j++)
		   scanf("%d",&A[j]);
		int min[N-k+1];
		mini=A[0];
		min[0]=0;
		for(j=0;j<=k-1;j++)
		{
			if(A[j]<mini)
			{
				mini=A[j];
				min[0]=j;
			}
		}
		for(j=1;j<N-k+1;j++)
		{
			if(min[j-1]<j)
			   min[j]=fun(A,j);
			else
			{
				if(A[min[j-1]]>A[j+k-1])
					min[j]=j+k-1;
				else
				min[j]=min[j-1];
			}
		}
		j=0;
		while(j<N-k+1)
		{
		  if(j==N-k)
		  {
		  printf("%d\n",A[min[j]]);
		  break;
		  }
		  printf("%d ",A[min[j]]);
		  j++;
		}
	}
	return 0;
}


