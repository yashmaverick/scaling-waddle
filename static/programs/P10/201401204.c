#include<stdio.h>
#include<string.h>
int main(){
	int i,n,d;
	char s[10002][102];
	scanf("%d",&n);
	int b=-1,e=-1,j=0;
	while(1){
		char c[2],g;
//		printf("enter a char ");
		scanf("%s",c);
		//printf("%s\n",c);
		//exit
		if(c[0]=='Q')
			return 0;

		if(c[0]=='A'){
			scanf("%d",&d);
			//	printf("%s\n",c);
			while(d--){
				e=(e+1)%n;
				//printf("inserting at %d ",e);
				scanf("%s",s[e]);
				g=getchar();
				if(e==0 && j==0){
					j=1;
					b++;
				}
				else if(e==b)
					b=(b+1)%n;
			}
	//		printf("b = %d e = %d\n",b,e);
		}
		//print
		if (c[0]=='L'){
			if(b==-1)
				continue;
			if(e>=b){
				for(i=b;i<=e;i++){
					printf("%s",s[i]);
					printf("\n");
				}
			}
			else{		

				for(i=b;i<n;i++){
					printf("%s",s[i]);
					printf("\n");
				}

				for(i=0;i<=e;i++){
					printf("%s",s[i]);
					printf("\n");
				}
			}
		}
		if(c[0]=='R'){
			scanf("%d",&d);
			if(d==0 || d>n)
				continue;
			if(b==e){
				b=-1;
				e=-1;
				j=0;	
			}
			else if(b<e){
				b=b+d;
				if(b-1==e){
					b=-1;
					e=-1;
					j=0;
				}
			}
			else{
				b=(b+d)%n;
				if(b-1==e){
					b=-1;
					e=-1;
					j=0;
				}
			}
			
		}
	//	printf("b=%d e=%d\n",b,e);
	}
	return 0;
}
