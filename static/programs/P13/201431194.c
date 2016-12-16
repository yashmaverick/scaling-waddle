#include<stdio.h>
int a[100001],s[100001],b[100001];
int max=0;
int rem;
void count(int now,int s,int e){
//	printf("%d %d %d\n",s,e,now);
//	if(now>max)
//		max=now;
	if(s>e){
		return ;
	}
	if(now>=max){
		if(now>max){
			max=now;
			rem=a[e];
		}
		else
			if(a[e]<rem){
				rem=a[e];
				max=now;
			}
	}
	count(now+1,s,b[e]);
	count(now+1,b[e]+1,e-1);
	return;
}
int main(){
	int t,i,j,k,l,n,m;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	b[0]=0;
	l=0;
	s[0]=0;
	for(i=0;i<n;i++){
		if(a[i]>a[s[l]]){
			b[i]=s[l];
			l++;
			s[l]=i;
		}
		else{
			while(a[i]<a[s[l]] && l>0)
				l--;
			if(l==0){
				if(a[i]>a[0]){
					b[i]=0;
					l++;
					s[l]=i;
				}
				else{
					b[i]=-1;
					l++;
					s[l]=i;
				}
			}
			else{
				b[i]=s[l];
				l++;
				s[l]=i;
			}
		}
	}
//	for(i=0;i<n;i++)
//		printf("%d ",b[i]);
	count(0,0,n-1);
	printf("%d %d\n",rem,max);
	max=0;
	}
	return 0;
}

