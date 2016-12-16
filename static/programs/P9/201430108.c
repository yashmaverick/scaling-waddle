#include<stdio.h>
#include<stdlib.h>
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n,mod,i,j;
	int *a;
	
	scanf("%d%d",&n,&mod);
	int *b[n];
	int no=n;
	a=(int *)malloc(n*sizeof(int));
	//b=(int **)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		a[i]=0;
	i=0;
	int k;
	while(no--)
	{
		int m;
		j=1;
		scanf("%d",&m);
		int mo=m;
		b[i]=(int *)malloc((m+2)*sizeof(int));		
		b[i][m+1]=-1;
		b[i][0]=0;
		while(mo--)
		{
			int temp;
			scanf("%d",&temp);
			b[i][j]=temp;
			b[i][0]=(b[i][0]+temp)%mod;
			a[i]=(a[i]+temp)%mod;
			//b[i][0]%=mod;
			//a[i]%=mod;
			j++;				
		}
		b[i][0]%=mod;
		a[i]%=mod;	
		i++;
		//printf("%d %d\n",b[0][0],a[0]);	
	}
	
	
	qsort(a,i,sizeof(int),cmpfunc);
	
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
		{	
			if(a[i]==b[j][0])
			{		
			printf("%d\n",a[i]);
				k=1;
				while(b[j][k]!=-1)
				{	
					printf("%d\n",b[j][k]);
					k++;
				}
				printf("\n");
				b[j][0]=-1;
				break;		
		}
	}
		
	return 0;
}