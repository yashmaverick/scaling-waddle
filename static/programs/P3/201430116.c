#include<stdio.h>
int main(){
	int tc,s;
	scanf("%d",&tc);
	for(s=0;s<tc;s++){
	   int n;
	   scanf("%d",&n);
	   int a[n+1],i,d[n],sum,max;
       for(i=0;i<n;i++)
    	   scanf("%d",&a[i]);
       for(i=0;i<n-1;i++)
    	   d[i]=a[i+1]-a[i];
       sum=max=0;
       for(i=0;i<n-1;i++){
    	   sum+=d[i];
    	  if(sum>max)
    		 max=sum;
    	  if(sum<0)
    		 sum=0;
       }
       printf("%d\n",max);
    }
	return 0;
}