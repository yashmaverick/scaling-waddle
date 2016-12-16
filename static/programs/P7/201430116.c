#include<stdio.h>
#include<stdlib.h>
int comparefunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b);
}
int main(){
	int tc,sw;
	scanf("%d",&tc);
	for(sw=0;sw<tc;sw++){
	long long int n,i,total,l,k;
	scanf("%lld",&n);
	int a[n];
    for(i=0;i<n;i++){
    	scanf("%lld",&a[i]);
    }
    qsort(a, n, sizeof(int), comparefunc);
    //for(i=0;i<n;i++)printf("%d ",a[i]);
    //	printf("\n");
    k=0;
    l=1;
    total=0;
    for(i=1;i<n;i++){
    	if(a[i]==a[k]){
    		l++;
    	}
    	else {
    		k=i;
    		total+=(l*(l-1))/2;
    		l=1;
    	}
    } 
    total+=(l*(l-1))/2;
    printf("%lld\n",total);
}
	return 0;
}