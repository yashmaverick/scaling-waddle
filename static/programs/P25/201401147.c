#include<stdio.h>
int par[100005];
typedef struct base{
	int v1;
	int v2;
	int edge;
}base;
base a[1000005];
int N,M;
int comparator(const void *p,const void *q){
	int l=(((base*)p)->edge);
	int r=(((base*)q)->edge);
	return l-r;
}
/*void print(){
  int i;
  for(i=0;i<M;i++)
  printf("%d\t",a[i].edge);
  printf("\n");
  return ;
  }*/
int root(int i){
	if(par[i]==i)
		return i;
	else
		return par[i]=root(par[i]);
}
int disjoint=0;
void combine(int i,int j){
	par[root(i)]=root(j);
	disjoint++;
}
int main(){
	int i;
	scanf("%d%d",&N,&M);
	//a=(base *)malloc(M*sizeof(base));
	for(i=1;i<=N;i++)
		par[i]=i;
	for(i=0;i<M;i++){
		scanf("%d%d%d",&(a[i].v1),&(a[i].v2),&(a[i].edge));
	}
	//printf("%lu\n",sizeof(a)/sizeof(base));
	qsort(a,M,sizeof(base),comparator);
	//print();
	int start=0;
	long long int sum=0;
	base temp;
	while(start < M){
		temp=a[start++];
		if(root(temp.v1)!=root(temp.v2)){
			//printf("root of %d is %d and root of %d is %d\n",temp.v1,root(temp.v1),temp.v2,root(temp.v2));
			//printf("edge %d between %d and %d is added\n",temp.edge,temp.v1,temp.v2);
			combine(temp.v1,temp.v2);
			//printf("root of %d is %d and root of %d is %d\n",temp.v1,root(temp.v1),temp.v2,root(temp.v2));
			sum+=temp.edge;	
		}

		if(disjoint==N-1)
			break;
	}
	if(disjoint!=N-1)
		printf("-1\n");
	else
		printf("%lld\n",sum);
	return 0;
}

