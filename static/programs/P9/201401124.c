#include<stdio.h>
#include<stdlib.h>
typedef struct bag{
	int *a;
	int weight;
	int m;
	
}bag;
int main()
{
	int i,j,n,MOD;
	scanf("%d %d",&n,&MOD);
	bag b[n];
	for(i=0;i<n;i++)
	{
		b[i].weight=0;
		scanf("%d",&b[i].m);
		b[i].a=(int *)malloc(b[i].m * sizeof(int));
		for(j=0;j<b[i].m;j++)
		{
			scanf("%d",&b[i].a[j]);
			b[i].weight=(b[i].weight+b[i].a[j])%MOD;
		}
				
	}

	int small1,temp1,fix,small3,temp3;

	int *small2,*temp2;
	for(i=0;i<n-1;i++)
	{
		/*small1=b[i].weight;
		small2=b[i].a;
		small3=b[i].m;
		fix=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j].weight < small1)
			{
				small1=b[j].weight;
				small2=b[j].a;
				small3=b[j].m;
				fix=j;
			}
		}
		temp1=b[i].weight;
		temp2=b[i].a;
		temp3=b[i].m;
		b[i].weight=small1;
		b[i].a=small2;
		b[i].m=small3;
		b[fix].weight=temp1;
		b[fix].a=temp2;
		b[fix].m=temp3;*/
		for(j=0;j<n-i-1;j++)
		{
			if(b[j].weight>b[j+1].weight)
			{
				temp1=b[j].weight;
				temp2=b[j].a;
				temp3=b[j].m;
				b[j].weight=b[j+1].weight;
				b[j].a=b[j+1].a;
				b[j].m=b[j+1].m;
				b[j+1].weight=temp1;
				b[j+1].a=temp2;
				b[j+1].m=temp3;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i].weight);
		for(j=0;j<b[i].m;j++)
			printf("%d\n",b[i].a[j]);
	//	if(i!=n-1)
			printf("\n");
				
				
				
	}
	return 0;
}
