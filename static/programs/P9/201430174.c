 #include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,md,i,j,tmp,*tp;
	scanf("%d%d",&n,&md);;
	int r[n],w[n],*h[n];
	for(i=0;i<n;i++)
	{
		int k;
		w[i]=0;
		scanf("%d",&r[i]);
		h[i]=(int*)malloc((sizeof(int))*r[i]);
		for(k=0;k<r[i];k++)
		{
			scanf("%d",&h[i][k]);
			w[i]=(w[i]+h[i][k])%md;
		}
		w[i]=w[i]%md;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(w[j]>w[j+1])
			{
				tmp=w[j];
				w[j]=w[j+1];
				w[j+1]=tmp;
				tmp=r[j];
				r[j]=r[j+1];
				r[j+1]=tmp;
				tp=h[j];
				h[j]=h[j+1];
				h[j+1]=tp;
			}
		}

    }
	for(i=0;i<n;i++)
	{
		printf("%d\n",w[i]);
		for(j=0;j<r[i];j++)
			printf("%d\n",h[i][j]);
        printf("\n");
	}
	return 0;
}



