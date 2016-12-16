#include<stdio.h>
int main()
{
	int n,A[100000],B[100000],C[100000],a,b,c,i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		int count=0;
		scanf("%d",&a);
		for(i=1;i<=a;i++)
			scanf("%d",&A[i]);
		scanf("%d",&b);
		for(i=1;i<=b;i++)
			scanf("%d",&B[i]);
		scanf("%d",&c);
		for(i=1;i<=c;i++)
			scanf("%d",&C[i]);
		for(i=a;i>0;i--)
		{

			for(j=b;j>=i;j--)
			{        
				if(A[i]>B[j])
					break;
				
					k=j;
					while(k<=c)
					{
						if(B[j]>C[k])
							break;
						if(B[j]<=C[k])
						{
							count=count+c-j+1;
							break;
						}
					}
				
			}
	        }
		printf("%d\n",count);
	}

	return 0;
}
