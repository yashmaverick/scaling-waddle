#include <stdio.h>
int a[1002][1002];
int b[1002];
int c[1002];
int vis[1002];
int count;
int n,m;
void dfs(int x){
    vis[x]=1;
    int i=1;
    count=count+1;
    int j=1;
    for (i=1; i<=b[x]; i++) {
        while (a[x][j]!=1) {
                j++;
        }
        if(vis[j]!=1){
            dfs(j);
        }
        j++;
    }
}
void revdfs(int x){
    vis[x]=1;
    int i=1;
    ++count;
    int j=1;
    for (i=1; i<=c[x]; i++) {
        while (a[j][x]!=1) {
            j++;
        }
        if(vis[j]!=1){
            revdfs(j);
        }
        j++;
    }
}
void run(){
    int i,j,sum=0;
    for (i=0; i<1002; i++) {
        b[i]=0;
    }
    for (i=0; i<1002; i++) {
        c[i]=0;
    }
    for (i=0; i<1002; i++) {
        vis[i]=0;
    }
    for (i=0; i<1002; i++) {
        for (j=0; j<1002; j++) {
            a[i][j]=0;
        }
    }
    int ite;
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        scanf("%d",&m);
        c[i]=m;
        for(j=0;j<m;j++){
            int temp;
            scanf("%d",&temp);
            a[temp][i]++;
            b[temp]++;
        }
    }
    for (i=1; i<=n; i++) {
        count=0;
        for (ite=0; ite<1002; ite++) {
            vis[ite]=0;
        }
        dfs(i);
        if (count==n){
            sum++;
            break;
        }
    }
    for (ite=0; ite<1002; ite++) {
        vis[ite]=0;
    }
    count=-1;
    revdfs(i);
    sum+=count;
    printf("%d\n",sum);
    return;
}

int main() {
    int n,i;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        run();
    }
    return 0;
}
