#include<stdio.h>
int main(){
	int N,i,j,insert=0,old=0,size=0;
	scanf("%d",&N);
	char a[N][109],d,c;
	while((c=getchar())!='Q'){
		if(c=='A'){
			getchar();
            scanf("%d",&i);
            size=size+i;
            if(size>N)         //total size of array 
            	size=N;
    /*        if(old-(insert+i)>=0){      
            	old=(insert+i);
            	if(old>(N-1))
            		old=old%(N);
            }   */
            if((insert>old)&&(insert+i)>(N-1)){
            	if(((insert+i)%N)>old)
            	   old=(insert+i)%(N);            		
            }
            else if((insert<= old)&&(insert+i)>old){
              if((size-i)==0 &&size<=N)      // when size=0 first inserted is old
                old=insert;
              else 
            	  old=(insert+i)%N;
            }
         /*   if(old==0&&(insert+i)>N-1)       // correct
            	old=(insert+i)%(N);  */
            while(i--){
                scanf("%s",a[insert]);
                insert=(insert+1);
                if(insert>(N-1)){
                	insert=insert%(N);
                }
            }
		}
		else if(c=='R'){
			getchar();
			scanf("%d",&i);
			old=(old+i)%(N);
			size=size-i;
      if(size==0){
        insert=0;
        old=0;
      }
		}
		else if(c=='L'){
		/*	if(del<=insert){
               for(i=del+1;i<insert;i++){
               	printf("%s\n",a[i]);
               }
			}
			else{
				for(i=del+1;i<=N-1;i++){
					printf("%s\n",a[i]);
				}
				for(i=0;i<insert;i++){
					printf("%s\n",a[i]);
				}
			} */
			j=old;
            i=size;
            while(i--){
                  printf("%s\n",a[j]);
                  j=(j+1);
                  if(j>(N-1))
                  	j=j%(N);
            }
		} 
	}
	return 0;
}