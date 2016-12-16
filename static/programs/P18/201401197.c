#include<stdio.h>
void dfs(int,int,char);
int stat[1003],n,cnt;
char mat[1003][1003];
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			stat[i]=-1;
			for(j=0;j<n;j++){
				mat[i][j]=0;
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&j);
			while(j--){
				scanf("%d",&k);
			mat[k-1][i]=1;
			}
		}
		for(i=0;i<n;i++){
			if(stat[i]==-1){
				cnt=0;
				dfs(i,i,'s');
				if(cnt==n){
					break;
				}
			}
		}
		cnt=0;
		if(i!=n){
			dfs(i,n,'r');
		}
		printf("%d\n",cnt);
	}
	return 0;
}

void dfs(int node,int fl,char mode){
	int i;
	if(stat[node]==fl){
		return ;
	}
	stat[node]=fl;
	cnt++;
	for(i=0;i<n;i++){
		if((mode=='s'&&mat[node][i])||(mode=='r'&&mat[i][node])){
			dfs(i,fl,mode);
		}
	}
}
