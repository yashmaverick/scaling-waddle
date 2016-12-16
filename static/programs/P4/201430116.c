#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpfunc (const void *a, const void *b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
    int tc,sw;
    scanf("%d",&tc);
    getchar();
    for(sw=0;sw<tc;sw++){
    char c;
    int a[100009],i,n,j,total,k;
    char b[100009];
    i=1;
   scanf("%s",b);
    if(b[0]=='J')
      a[0]=100000+2;
    else if(b[0]=='M')
      a[0]=-100000-1;
    else
      a[0]=-1;
	k=strlen(b);
    while(i<k){
    	   if(b[i]=='J'){
        	  a[i]=a[i-1]+100000+2;
    		  }
    	   else if(b[i]=='M'){
        	   a[i]=a[i-1]+(-100000-1);
    		   }
    	   else if(b[i]=='R'){
        	   a[i]=a[i-1]-1;
    		   }
    	i++;
    }

    qsort(a,k,sizeof(int),cmpfunc);
        
        int rou=0;
        n=1;
        total=0;
        if(a[0]==0)
            total=1;
        for(j=1;j<k;j++){
            if(a[j]==0)
                total++;
            if(a[j]==a[rou]){
               n++;
             }
            
            else{
                   rou=j;
                   total+=(n*(n-1))/2;
                   n=1;
                }
        }
        total+=(n*(n-1))/2;
    printf("%d\n",total);
    }
	return 0;
}
