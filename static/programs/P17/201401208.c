#include<stdio.h>

int pre[100001],in[100001],hash[100001];

int main(){
	int t,n,p,q,i,j,k,fl,fl1,fl2,fl3,fl4,l,m,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	while(t--){
		fl=0;
		fl1=0;
		fl2=0;
		fl3=0;
		fl4=0;
		for(i=0;i<=n;i++)
			hash[i]=0;
		scanf("%d %d",&p,&q);
		if(p==q){
			printf("%d\n",p);
			fl=1;
		}
		else if(pre[0]==q){
			printf("%d\n",q);
			fl=1;
		}
		else if(pre[0]==p){
			printf("%d\n",p);
			fl=1;
		}
		k=0;		
		if(fl!=1){
			while(pre[k]!=p&&pre[k]!=q){
				hash[pre[k]]=1;
				k++;
			}
			hash[pre[k]]=1;
			ans=pre[k];
			k=n-1;

			while(in[k]!=p&&in[k]!=q)
				k--;
			l=k;
			m=k;
			if(in[l]==p){
				l--;
				if(in[l]==q){
					printf("%d\n",ans);
					fl1=1;
				}
				if(fl1==0){
					l++;
					while(in[l]!=q){
						if(hash[in[l]]==1){
							printf("%d\n",in[l]);
							fl2=1;
							break;
						}
						l--;
					}
					if(fl2==0&&hash[in[l]]==1){
						printf("%d\n",in[l]);
						fl3=1;
					}	
					if(fl2==0&&fl3==0)
						printf("%d\n",ans);
				}
			}
			if(in[m]==q){
				m--;
				if(in[m]==p){
					printf("%d\n",ans);
					fl1=1;
				}
				if(fl1==0){
					m++;
					while(in[m]!=p){
						if(hash[in[m]]==1){
							printf("%d\n",in[m]);
							fl2=1;
							break;
						}
						m--;

					}
					if(fl2==0&&hash[in[m]]==1){
						printf("%d\n",in[m]);
						fl3=1;
						}
					if(fl2==0&&fl3==0)
						printf("%d\n",ans);
				}
			}
		}
	}

	return 0;
}
