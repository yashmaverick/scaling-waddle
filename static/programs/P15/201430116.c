#include<stdio.h>
int main(){
    int sw,z;
    scanf("%d",&sw);
    for(z=0;z<sw;z++){
	int n,k,i,top,j,last,temp;
    scanf("%d %d",&n,&k);
    int a[n+9][2],b[n+9];
    top=0;
    last=0;
    scanf("%d",&temp);
    a[top][0]=temp;
    a[top][1]=0;
    for(i=1;i<k;i++){
    	scanf("%d",&temp);
    	if(temp>=a[last][0]){
    		++last;
    		a[last][0]=temp;
            a[last][1]=i;
    	}
    	else{
    		while(last>=top&&temp<a[last][0])
    		last--;
    	    if(last<=top&&a[top][0]>temp){
               last=top;
               a[top][0]=temp;
               a[top][1]=i;
    	    }
    	    else{
    	    	last++;
    	    	a[last][0]=temp;
    	    	a[last][1]=i;
    	    }
    	}
    }
    b[0]=a[top][0];
    for(i=k,j=1;i<n;i++,j++){
    	scanf("%d",&temp);
    	while(top<=last&&a[top][1]<j)
    		top++;
    	if(top>=last&&a[top][0]>=temp){
           last=top;
            a[top][0]=temp;
            a[top][1]=i; 
    	}
    	else if(temp>=a[last][0]){
    		++last;
    		a[last][0]=temp;
            a[last][1]=i;
        }
        else{
    		while(last>=top&&temp<a[last][0])
    		last--;
    	    if(last<=top&&a[top][0]>temp){
               last=top;
               a[top][0]=temp;
               a[top][1]=i;
    	    }
    	    else{
    	    	last++;
    	    	a[last][0]=temp;
    	    	a[last][1]=i;
    	    }
    	}
    	b[j]=a[top][0];
    }
    for(i=0;i<j-1;i++)
         printf("%d ",b[i]);
      printf("%d\n",b[i]);
  }
	return 0;
}