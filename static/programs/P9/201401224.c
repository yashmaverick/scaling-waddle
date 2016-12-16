#include<stdio.h>
#include<stdlib.h>
void quicksort(int x[][2],int start,int end)
{
	int pivot,j,temp,i;
	if(start<end)
	{
		pivot=start;
		i=start+1;
		j=end;
		while(i<j)
		{
			while(x[i][1]<x[pivot][1]&&i<=end)
				i++;
			while((x[j][1]>=x[pivot][1])&&j>start)
				j--;
			if(i<j)
			{
				temp=x[i][1];
				x[i][1]=x[j][1];
				x[j][1]=temp;
				temp=x[i][0];
                                x[i][0]=x[j][0];
                                x[j][0]=temp;
			}
		}
		if((start+1)!=end||x[start][1]>x[end][1])
		{
			temp=x[pivot][1];
			x[pivot][1]=x[j][1];
			x[j][1]=temp;
			temp=x[pivot][0];
                	x[pivot][0]=x[j][0];
                	x[j][0]=temp;
		}
		quicksort(x,start,j-1);
		quicksort(x,j+1,end);
	}
}
int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
 	int *b[n];int c[n][2];int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=(int *)malloc((a[i]+1)*sizeof(int));
		c[i][0]=i;
		c[i][1]=0;
		for(j=0;j<a[i];j++)
		{
			scanf("%d",&b[i][j]);
			c[i][1]=(c[i][1]+b[i][j])%m;
		}
	}
//	for(i=0;i<n;i++)
//                  printf("%d\n",c[i][1]);
	quicksort(c,0,n-1);
//	for(i=0;i<n;i++)
  //              printf("%d\n",c[i][1]);
	for(i=0;i<n;i++)
	{
		printf("%d\n",c[i][1]);
		k=c[i][0];
		for(j=0;j<a[k];j++)
			printf("%d\n",b[k][j]);
		printf("\n");
	}
	return 0;
}

