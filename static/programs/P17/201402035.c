#include<stdio.h>
int main(){
	int n,t,i,J,S,k,root,count;
	int h,j,l,x,y,r,ans;
	int pre[10000];
	int in[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
for(i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
scanf("%d",&t);
while(t--){
	 int flag=0;
scanf("%d%d",&J,&S);

for(i=0;i<n;i++){
if(in[i]==J)
	x=i;

if(in[i]==S)
	y=i;
}
if(x>y)
{
k=x;
x=y;
y=k;
}
	for(i=0;i<n;i++){
		for(j=x;j<=y;j++){
		if(pre[i]==in[j])
		{
		ans=pre[i];
		flag=1;
		break;
		}
		
		}
	if(flag==1)
		break;
		}

printf("%d\n",ans);
}
return 0;
}
