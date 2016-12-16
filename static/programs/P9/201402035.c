#include<stdio.h>
#include<stdlib.h>
int n;
int flag[10000]={0};
long long int M;
long long int **arr;
void scan(){
	int i,j,x;

	for(i=0;i<n;i++){
		scanf("%d",&x);

		arr[i]=(long long int *)malloc((x+2)*sizeof(long long int));
		arr[i][0]=x;


		for(j=2;j<=x+1;j++){
			scanf("%lld",&arr[i][j]);
		}

	}
}
void sum(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=2;j<=arr[i][0]+1;j++){
			arr[i][1]=(arr[i][1]+arr[i][j])%M;
		}
		arr[i][1]=arr[i][1]%M;
		//printf("sum is:%lld\n",arr[i][1]);
	}
}

void print(int m_i){
	int i,j;
	for(j=1;j<=arr[m_i][0]+1;j++){
		printf("%lld\n",(arr[m_i][j]));
	}
	printf("\n");
}

void sort(){
	int i,j;
	long long int min,m_i;
	for(i=0;i<n;i++){
		min=1000000009;
		for(j=0;j<n;j++){
			if(min>arr[j][1] && flag[j]!=1){
				min=arr[j][1];
				m_i=j;
			}
//			printf("The min sum is %lld At %lld\n",min,m_i);
		}
		flag[m_i]=1;
		print(m_i);
	}
}

int main(){
	scanf("%d%lld",&n,&M);
	arr=(long long int **)malloc(n*sizeof(long long int *));
	scan();
	sum();
	sort();
	return 0;
}
