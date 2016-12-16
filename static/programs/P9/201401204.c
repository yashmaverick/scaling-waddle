#include<stdio.h>
int n;
void swap(int a[][100002],int e,int f){
	int c,d;
	//	printf("before swap a[e] = %d a[f] = %d \n",a[e],a[f]);
	c=a[0][e];
	d=a[1][e];
	a[0][e]=a[0][f];
	a[1][e]=a[1][f];
	a[0][f]=c;
	a[1][f]=d;
	//	printf("after swap a[e] = %d a[f] = %d \n",a[e],a[f]);
}
void qsort(int a[][100002],int w,int p){
	int b=w,e=p,i,j;
	if(w>=p){
		return;
	}
	for(i=b;i<=e-1;i++){
		if(a[0][p]>=a[0][i]){
			swap(a,i,w);
			w++;
	//	printf("now wall becomes = %d\n array is: ",w);
	/*	for(j=0;j<n;j++)
			printf("%d ",a[j]);
		printf("\n");
	*/
		}
	}
	if(a[0][w]>=a[0][p]){
		swap(a,p,w);
	}
	//	printf("array is fin\n");
	/*	for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
	//	printf("\n");
	qsort(a,b,w-1);
	qsort(a,w+1,e);
}
int main(){
	int q[1000002];
	int a[2][100002],t;
	int i,j,mod;
	int size=1;
	//scanf("%d",&t);
	//while(t--){
		scanf("%d",&n);		//no. of bags
		scanf("%d",&mod);	//mod value
		int c=1,d;
		int total=0;
		for(i=0;c<=n;){
			scanf("%d",&q[i]);
			d=i;
			total++;
			for(j=1;j<=q[d];j++){
				scanf("%d",&q[++i]);
				total++;
			}
			i++;
			c++;
		}
		q[i]=-1;
		/*for(i=0;q[i]!=-1;i++)
			printf("%d ",q[i]);
		printf("\n");*/
		int u=0;
		for(i=0;i<total;i++){
			d=i;
			a[1][u]=i;
			for(j=1;j<=q[d];j++){
				a[0][u]=(a[0][u]%mod+q[++i]%mod)%mod;
			}
			u++;
		}	
		/*for(i=0;i<2;i++){
			for(j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}*/
		int w=0,p=n-1,b,e,k,l;
		qsort(a,w,p);
		for(i=0;i<n;i++){
			u=a[1][i];
			k=q[u];
			c=1;
			printf("%d\n",a[0][i]);
			for(l=u+1;c<=k;l++){
				printf("%d\n",q[l]);
				c++;
			}
			/*if (i<n-1)*/
				printf("\n");
		}
	//}
	return 0;
}
