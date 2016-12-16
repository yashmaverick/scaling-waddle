#include<stdio.h>

int main(){
	int old[10006],new[10006];
	int t,n,k,i,j,min;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&old[i]);
		min=old[1];
		for(i=1;i<=n-k+1;i++){

			if((min==old[i-1] && i>1) || i==1 ){
				min=old[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(old[j]<min)
						min=old[j];
				}
			}
			else if(old[i+k-1]<min)
				min=old[i+k-1];
			new[i]=min;
		}
		for(i=1;i<n-k+1;i++)
			printf("%d ",new[i]);
		printf("%d\n",new[n-k+1]);
	}
	return 0;
}

