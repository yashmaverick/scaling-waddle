#include<stdio.h>
int main(){
	int n,i,a[100009];
	scanf("%d",&n);
	while(n!=0){
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	long long int s[n+2][2],j=0,k;
	long long int max=0;
	s[0][1]=0;
	for(i=0;i<n;i++){
        if(j==0&&i==0){
        	s[j][0]=a[i];
        	s[j][1]=1;
    //    	j++;
        	if((s[j][0]*s[j][1])>max)
        		max=s[j][0]*s[j][1];
        }
        else if(a[i]<=s[j][0]){
        /*	s[j][0]=a[i];
        	s[j][1]+=1;
        	if((s[j][0]*s[j][1])>max)
        		max=s[j][0]*s[j][1];*/
        	int temp=s[j][1]+1,l=j;
        /*    if(l==0)
            	temp+=1;  */
        //    else{
        	     while(l>0&&(a[i]<=s[l-1][0])){
        		       temp+=s[l-1][1];
        		       l--;
        	        }
        //	    }
        	for(k=j-1;k>=l;k--){
               s[k][1]+=s[k+1][1];
              if((s[k][0]*s[k][1])>max)
        	      max=s[k][0]*s[k][1];
	        }
	        j=l;
        	s[j][0]=a[i];
        	s[j][1]=temp;
        	if((s[j][0]*s[j][1])>max)
        		max=s[j][0]*s[j][1];
        }
        else if(a[i]>s[j][0]){
        	j++;
        	s[j][0]=a[i];
        	s[j][1]=1;
        	if((s[j][0]*s[j][1])>max)
        		max=s[j][0]*s[j][1];
        }
	}
	for(i=j;i>0;i--){
        s[i-1][1]+=s[i][1];
        if((s[i][0]*s[i][1])>max)
        	max=s[i][0]*s[i][1];
	}
	if((s[0][0]*s[i][1])>max)
        	max=s[i][0]*s[i][1];
    printf("%lld\n",max);
    scanf("%d",&n);
    }
	return 0;
}