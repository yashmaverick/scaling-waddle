#include <stdio.h>
#include <stdlib.h>
void qusort(int a[],int b[],int c[],int first,int last);
int main()
{
	int m,n,mod;
	int i=0;
	//int **a;
	int* a[10005];
	scanf("%d%d",&n,&mod);
	//a=malloc(sizeof(int *)*n);
	//int a[n];
	int w[n];
	int index[n];
	int size[n];
	int counter=n;
	while(counter--)
	{
		scanf("%d",&m);
		a[i]=(int *)malloc(sizeof(int)*m);
		w[i]=0;
		size[i]=m;
		index[i]=i;
		int j;
		for(j=0;j<m;j++)
		{scanf("%d",&a[i][j]);
			w[i]=(w[i]%mod+a[i][j]%mod)%mod;
		}
		/*	for(j=0;j<m;j++)
			printf("%d\n",a[i][j]);
			*/
		i++;
	}
	qusort(w,index,size,0,n-1);
	counter=n;
	i=0;
	while(counter--)
	{printf("%d\n",w[i]);
		int j;
		for(j=0;j<size[i];j++)
			printf("%d\n",a[index[i]][j]);
		printf("\n");
		i++;
	}


	return 0;
}
void qusort(int a[],int b[],int c[],int first,int last)
{
	int pivot,i,j,temp,temp2,temp3;

	if(first<last)
	{    
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j && a[i]!=a[j] )
			{
				temp=a[i];
				temp2=b[i]; 
				temp3=c[i];
				c[i]=c[j];
				c[j]=temp3;
				b[i]=b[j];
				b[j]=temp2;
				a[i]=a[j];
				a[j]=temp;
			}
		}
		if(a[pivot]!=a[j])
		{
			temp=a[pivot];
			a[pivot]=a[j];
			a[j]=temp;
			temp2=b[pivot];
			b[pivot]=b[j];
			b[j]=temp2;
			temp3=c[pivot];
			c[pivot]=c[j];
			c[j]=temp3;}
		qusort(a,b,c,first,j-1);
		qusort(a,b,c,j+1,last);
	}    
}
