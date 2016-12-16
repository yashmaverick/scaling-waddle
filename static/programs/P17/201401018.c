#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,t,idxx,idxy,x,y,ans,j;
	int *A,*B;
	scanf("%d",&n);
	A=(int *)malloc(n*sizeof(int));
	B=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	scanf("%d",&t);
	while(t--)
	{
		int flag = 0;
		scanf("%d %d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(B[i]==x)
				idxx=i;
			if(B[i]==y)
				idxy=i;
		}
//		printf("%d %d \n", idxx , idxy);
		if(idxx>=idxy)
		{
			for(i=0;i<n && flag == 0;i++)
			{
				for(j=idxy;j<=idxx;j++)
				{
					if(B[j]==A[i])
					{
						ans=A[i];
						flag = 1;
						break;
					}
				}
			}
		}
		else
		{
			for(i=0;i<n && flag == 0;i++)
			{
				for(j=idxx;j<=idxy;j++)
				{
					if(B[j]==A[i])
					{
						ans=A[i];
						flag = 1;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
