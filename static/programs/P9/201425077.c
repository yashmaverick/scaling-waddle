#include<stdio.h>
#include<stdlib.h>

int w[1000],a[1000];

int main()
{

int * pp[1000];
int n,mod,i,j;

	scanf("%d %d",&n,&mod);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

		pp[i]=(int *)malloc(a[i]*sizeof(int));

		for(j=0;j<a[i];j++)
		{
			scanf("%d",&pp[i][j]);

			w[i]+=pp[i][j]; w[i]%=mod;
				
		}


	}

/*	for(i=0;i<n;i++)
		for(j=0;j<a[i];j++)
			printf("%d ",pp[i][j]);
		
	printf("\n");

	
	for(i=0;i<n;i++)
		printf("w%d ",w[i]);
	printf("\n");

*/
	//bubblesort

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(w[i]>w[j])
				{
					int temp=w[i]; w[i]=w[j]; w[j]=temp;
			
					temp=a[i]; a[i]=a[j]; a[j]=temp;
					//if(a[i]>a[j])
					//	te[j]+(a[i]-a[j])*sizeof(int)
		
					int *te=pp[i]; pp[i]=pp[j]; pp[j]=te;
				}

	
	for(i=0;i<n;i++)
	{
		printf("%d\n",w[i]);

		for(j=0;j<a[i];j++)
			printf("%d\n",pp[i][j]);
		printf("\n");
	}
	
/*	for(i=0;i<n;i++)
		printf("w%d ",w[i]);
	printf("\n");
*/
	return 0;
}
