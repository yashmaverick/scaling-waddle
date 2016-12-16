#include<stdio.h>
void swap(long long int* x,long long int* y){
	long long int tmp = *x;
	*x = *y;
	*y = tmp;
}
long long int a[3][1000001];
long long int mic=0;
long long int parent[100005];
long long int ans=0;
long long int jod=0;
long long int troot(long long int x){
	if(parent[x]==x)
		return x;
	parent[x] = troot(parent[x]);
	return parent[x];
}
void inserth(long long int x,long long int y,long long int z){
	mic++;
	long long int tmp = mic,i;
	a[0][mic] = x;
	a[1][mic] = y;
	a[2][mic] = z;
	tmp = mic;
	while(a[2][tmp/2]>a[2][tmp]){
		for(i=0;i<3;i++)
			swap(&a[i][tmp/2],&a[i][tmp]);
		tmp = tmp/2;
	}
	return ;
}
void delete(){
	long long int i,tmp;
	for(i=0;i<3;i++)
		a[i][1] = a[i][mic];
	mic--;
	tmp = 1;
	while((a[2][tmp]>a[2][2*tmp] && 2*tmp<=mic) || (a[2][tmp]>a[2][2*tmp+1] && 2*tmp+1 <=mic)){
		if(a[2][2*tmp+1] < a[2][2*tmp] && 2*tmp+1<=mic){
			for(i=0;i<3;i++)
				swap(&a[i][2*tmp+1],&a[i][tmp]);
			tmp =2*tmp+1;
		}
		else{
			for(i=0;i<3;i++)
				swap(&a[i][2*tmp],&a[i][tmp]);
			tmp = 2*tmp;
		}
	}
	return ;	
}
void func(long long int v){
	while(mic!=0){
		if(troot(a[0][1])!=troot(a[1][1]))
		{
			parent[troot(a[0][1])] = troot(a[1][1]);
			ans+=a[2][1];
			jod++;
		}
		delete();
	}
	if(jod==v-1)
		printf("%lld\n",ans);
	else
		printf("-1\n");
	return;
}
int main(){
	long long int i,j,k,l,n,m,x,y,z,tmp,v,e;
	a[2][0] = -1;
	scanf("%lld%lld",&v,&e);
	for(i=1;i<=v;i++)
		parent[i] = i;
	for(i=0;i<e;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		inserth(x,y,z);
	}
	func(v);
	return 0;
}
