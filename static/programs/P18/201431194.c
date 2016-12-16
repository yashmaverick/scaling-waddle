#include<stdio.h>
int a[1005][1005];
int b[1005][1005];
int win[1005];
int vis[1005];
int sum;
int ans;
void search(int i){
	int j;
	for(j=1;j<=b[i][0];j++){
		if(win[b[i][j]]==0){
			sum++;
			win[b[i][j]]=1;
			search(b[i][j]);
		}
	}
	return ;
}
void rev(int i){
	int j;
	for(j=1;j<=a[i][0];j++){
		if(vis[a[i][j]]==0){
			ans++;
			vis[a[i][j]]=1;
			rev(a[i][j]);
		}
	}
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,i,j,k,l,n,m;
		ans=0;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			a[i][0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d",&x);
				a[i][0]++;
				a[i][a[i][0]] = x;
				b[x][0]++;
				b[x][b[x][0]] = i;
			}
		}
		for(i=1;i<=n;i++){
			sum = 1;
			for(j=1;j<=n;j++)
				win[j] = vis[j] = 0;
			win[i] = 1;
			search(i);
			for(j=1;j<=n;j++)
				win[j] = vis[j] = 0;
			if(sum==n){
				ans=1;
				vis[i]=1;
				win[i]=1;
				rev(i);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
