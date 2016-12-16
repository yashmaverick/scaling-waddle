#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
	int m;
	int n;
	int *array;
}link;
link *b;
int main()
{
	int N,Mod;
	scanf("%d%d",&N,&Mod);
	b=(link*)malloc(N*sizeof(link));
	int i,j;
	for(i=0;i<N;i++)
	{
		b[i].n=0;
		scanf("%d",&b[i].m);
		b[i].array=(int*)malloc(b[i].m*sizeof(int));
		for(j=0;j<b[i].m;j++)
		{
			scanf("%d",&b[i].array[j]);
			b[i].n=(b[i].n%Mod+b[i].array[j]%Mod)%Mod;
		}

		}
	/*	for(i=0;i<N;i++)
		{
		printf("%d\n",b[i].n);
		for(j=0;j<b[i].m;j++)
		{
		printf("%d ",b[i].array[j]);
		}
		printf("\n");
		}*/
	int a;
	int *S;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(b[i].n>b[j].n)
			{
				a=b[i].n;
				b[i].n=b[j].n;
				b[j].n=a;
				S=b[i].array;
				b[i].array=b[j].array;
				b[j].array=S;
				a=b[i].m;
				b[i].m=b[j].m;
				b[j].m=a;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d\n",b[i].n);
		for(j=0;j<b[i].m;j++)
		{
			printf("%d\n",b[i].array[j]);
		}
	printf("\n");	
	}

	return 0;
}



