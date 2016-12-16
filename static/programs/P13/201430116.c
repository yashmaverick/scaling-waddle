#include<stdio.h>
int a[100009];
int gb,min;
void depth(int si,int minele,int maxele,int dp,int value){
/*	if(nofele==1){
		if(dp>gb){
			gb=dp;
			min=a[si];
		}
		else if(dp==gb&&a[si]<min)
		    a[si]=min;			
	}
	else{
         
	}  */
	if(minele==maxele){
		if(dp>gb){
			gb=dp;
			min=minele;          // minele minimum element maxele is max element
		}                        // min overall min deepest mode
		else if(dp==gb&&minele<min)
		    min=minele;;			
	}
	else{
		int nomin,nomax;        //nomin is no of min element
		nomin=value-minele;
		nomax=maxele-value;
		if(nomin==0)
			depth(si,value+1,maxele,dp+1,a[si+nomax-1]);
		else if(nomax==0)
			depth(si,minele,value-1,dp+1,a[si+nomin-1]);
		else{
			depth(si,minele,value-1,dp+1,a[si+nomin-1]);
			depth(si+nomin,value+1,maxele,dp+1,a[si+nomin+nomax-1]);
		}
	} 
}
int main(){
	int sw,j;
	scanf("%d",&sw);
	for(j=0;j<sw;j++){
	int i,n;
	scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    gb=-1;
    min=100009;
    depth(1,1,n,0,a[n]);
    printf("%d %d\n",min,gb);
    }
	return 0;
}