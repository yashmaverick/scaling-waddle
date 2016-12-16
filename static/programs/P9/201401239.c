#include<stdio.h>
#include<stdlib.h>
int partition(int c[][2],int low,int high)
{
int pivot,pivotvalue;
pivot=high;
pivotvalue=c[pivot][1];
c[pivot][1]=c[pivot][1]+c[high][1]-(c[high][1]=c[pivot][1]);
//c[pivot][0]=c[pivot][0]+c[high][0]-(c[high][0]=c[pivot][0]);
int i,w,u;
u=low;
for(i=low;i<pivot;i++)
{
if(c[i][1]<=pivotvalue)
{
c[i][1]=c[i][1]+c[u][1]-(c[u][1]=c[i][1]);
c[i][0]=c[i][0]+c[u][0]-(c[u][0]=c[i][0]);
u=u++;
}
}
c[u][1]=c[u][1]+c[high][1]-(c[high][1]=c[u][1]);
c[u][0]=c[u][0]+c[high][0]-(c[high][0]=c[u][0]);
return u;
}
void quicksort(int c[][2],int low,int high)
{
int p;
if (low<high)
{
p=partition(c,low,high);
quicksort(c,low,p-1);
quicksort(c,p+1,high);
}
}
int main()
{
		int n,mod,i;
		scanf("%d %d",&n,&mod);
		int a[n],c[n][2],j,k;
		int *b[n];
		for(i=0;i<n;i++)
		{
			k=0;
			scanf("%d",&a[i]);
			c[i][0]=i+1;
			b[i]=(int *)malloc((a[i]+1)*(sizeof(int)));
			b[i][0]=i+1;
			for(j=0;j<a[i];j++)
			{
				scanf("%d",&b[i][j+1]);
				c[i][1]=(k+b[i][j+1])%mod;
				k=c[i][1];
				//printf("%d",k);

			}
		}
		/*int o,l;
		for(o=0;o<n-1;o++)
		{
			for(l=o;l<n-1;l++)
			{
				if(c[l][1]>c[l+1][1])
				{
					c[l][1]=c[l][1]+c[l+1][1]-(c[l+1][1]=c[l][1]);
					c[l][0]=c[l][0]+c[l+1][0]-(c[l+1][0]=c[l][0]);
				}
			}
		}*/
		quicksort(c,0,n-1);
		int p,m;
		for(i=0;i<n;i++)
		{
			printf("%d\n",c[i][1]);
			p=c[i][0];
			for(m=0;m<a[p-1];m++)
			{
				printf("%d\n",b[p-1][m+1]);
			}
printf("\n");
		}
	return 0;
}








