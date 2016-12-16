#include<stdio.h>
int main()
{
	int N,n,i,j;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d\n",&n);
		int A[n], m1=0, m2=0, profit=0;
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		m1=A[0];
		for(i=0;i<n-1;i++)
		{
			/*for(j=0;j<i;j++)
			  {
			  if(A[i]-A[j]>m1)
			  m1=A[i]-A[j];
			  }
			  if(m1>m2)
			  m2=m1;	
			  }
			  printf("%d\n",m2);
			  }
			  return 0;<-- time complexity nlogn */
			if(A[i]<=m1)
				m1=A[i];
			if(A[i+1]-m1>=m2)
				m2=A[i+1]-m1;
}
printf("%d\n",m2);
}
return 0;
}

