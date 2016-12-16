#define max(a,b) ((a)>(b)?(a):(b))
#include<stdio.h>
int b[100001];
typedef struct pair pair;
struct pair{
	int depth;
	int val;
};
pair deepval(int i,int j,int t[]){
	if(j<i){
		pair p={-1,-1};
		return p;
	}
	if(i==j){
		pair m={0,t[i]};
		return m;
	}
	/*int l=j;
	  while(l>=i&&t[l]>=t[j]){
	  l--;}*/
	int l=b[j];
	if(l==-1){
		pair p2=deepval(i,j-1,t);
		p2.depth++;
		return p2;}
	else{
		pair p1=deepval(i,l,t);
		pair p2=deepval(l+1,j-1,t);
		pair ans=p1.depth>=p2.depth?p1:p2;
		ans.depth++;
		return ans;
	}
}
int main(){
	int n,te;
	int t[100001],s[100001];
	int top;
	scanf("%d",&te);
	while(te--){
		top=-1;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)scanf("%d",&t[i]);
		for(i=0;i<n;i++){
			if(top==-1){
				b[i]=-1;
				s[++top]=i;
			}
			if(t[i]>t[s[top]]){
				b[i]=s[top];
				s[++top]=i;
			}
			else if(t[i]<=t[s[top]]){
				while(top!=-1&&t[s[top]]>=t[i]){
					top--;
				}
				if(top==-1){
					b[i]=-1;
					s[++top]=i;
				}
				else{
					b[i]=s[top];
					s[++top]=i;
				}
			}
		}
		pair max=deepval(0,n-1,t);
		printf("%d %d\n",max.val,max.depth);
	}
	return 0;
}
