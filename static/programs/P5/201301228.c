#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	int a,b,c,d,e,f,g,h,t,A[1005],i,j,k;
	char B[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&b,&c);i=0;
		for(i=0;i<b;i++)
		{
			scanf("%s %d",B,&A[i]);
		}
		qsort(A, b, sizeof(int), cmpfunc);		
		f=b-1;i=0;e=0;
		//for(i=0;i<b;i++)
		//	printf("%d ",A[i]);
		for(i=0;i<(b-2) && e==0;i++)
		{	j=i+1;f=b-1;
			while(j!=f)
			{	d=A[i]+A[j]+A[f];
				if(d==c)
				{
					printf("YES\n");
					e=1;
					break;
				}
				else if(d>c)
				{
					f--;
				}       
				else if(d<c)
					j++;

		
			}
			if(e==1)
				break;
		}
		if(e!=1)
			printf("NO\n");
	}
	return 0;
}
