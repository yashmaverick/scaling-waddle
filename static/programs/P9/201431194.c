#include<stdio.h>
#include<stdlib.h>
struct thaila{
	int weight;
	int no;
	int* a;
};
struct thaila t[1000],u[1000];
void merge(struct thaila* t,struct thaila* u,int s,int e){
	if(s>=e)
		return ;
	int i,j,k,l,n,m;
	merge(t,u,s,(s+e)/2);
	merge(t,u,((s+e)/2)+1,e);
	i = s;
	j = ((s+e)/2)+1;
	n = s;
	while(i<=(s+e)/2 || j<=e){
		if(t[i].weight <= t[j].weight && i<=(s+e)/2){
			u[n].weight = t[i].weight;
			u[n].no = t[i].no;
			u[n].a = t[i].a;
			i++;
			n++;
		}
		else{
			if(t[i].weight >= t[j].weight && j<=e){
				u[n].weight = t[j].weight;
				u[n].no = t[j].no;
				u[n].a = t[j].a;
				j++;
				n++;
			}
			else{
				if(j>e){
					while(i<=(s+e)/2){
				        	 u[n].weight = t[i].weight;
        	                        	 u[n].no = t[i].no;
                	                	 u[n].a = t[i].a;
                        	        	 i++;
                                		 n++;
					}
				}
				else{
					while(j<=e){
						u[n].weight = t[j].weight;
					        u[n].no = t[j].no;
					        u[n].a = t[j].a;
					        j++;
					        n++;
					}
				}
			}
		}
	}
	for(i=s;i<=e;i++){
		t[i].weight = u[i].weight;
		t[i].no = u[i].no;
		t[i].a = u[i].a;
	}
	return ;
}
int main(){
	int i,j,k,l,n,m,mod,no;
	struct thaila t[1000],u[1000];
	scanf("%d%d",&n,&mod);
	for(i=0;i<1000;i++)
		t[i].weight=0;
	for(i=0;i<n;i++){
		scanf("%d",&(t[i].no));
		(t[i].a) = (int*)malloc((t[i].no)*sizeof(int));
		for(j=0;j<t[i].no;j++){
			scanf("%d",&(t[i].a[j]));
//			printf("%d ",t[i].a[j]);
			t[i].weight = (t[i].weight + t[i].a[j])%mod;
//			printf("%d %d %d\n",i,j,t[i].weight);
		}
	}
	merge(t,u,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\n",t[i].weight);
		for(j=0;j<t[i].no;j++)
			printf("%d\n",t[i].a[j]);
		printf("\n");
	}
	return 0;
}
