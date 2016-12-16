#include<stdio.h>
#include<stdlib.h>
typedef struct element{
	int total;
	int count;
	int *weights;
}node;
int main()
{
	int N,MOD;
	scanf("%d%d",&N,&MOD);
	node bags[1000];
	int i,j,m;
	for(i=0;i<N;i++)
	{
		scanf("%d",&(bags[i].count));
		m=bags[i].count;
		bags[i].weights=malloc(m*sizeof(int));
		bags[i].total=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&(bags[i].weights[j]));
			bags[i].total+=(bags[i].weights[j])%MOD;
			bags[i].total=(bags[i].total)%MOD;
		}
	}
	node temp;
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(bags[j].total<bags[i].total){
				temp=bags[i];
				bags[i]=bags[j];
				bags[j]=temp;
			}
	for(i=0;i<N;i++){
		printf("%d\n",bags[i].total);
		for(j=0;j<bags[i].count;j++)
			printf("%d\n",bags[i].weights[j]);
		printf("\n");
	}
	return 0;
}

