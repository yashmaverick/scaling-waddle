#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	int i = 0;
	int marker = 0;
	long long int  sum = 0;
	int useless;
	while(scanf("%d",&n)!=0){
			
			if(n == 0){
				break;
			}
			int * a = (int *)calloc(sizeof(int),n);
			int * b = (int *)calloc(sizeof(int),n);
			i = 0;
			marker = 0;
			sum = 0;

			while(i < n){
				scanf("%d",&a[i]);
				i++;
			}

			b[0] = a[0];
		
			
			
			for(i=1;i<n;i++){
				
				if(a[i] > b[marker]){
					marker --;
					sum += n - 1 - i;
					
					while(1){

						if(marker == -1){
							break;
						}
						
						if(a[i] > b[marker]){
							marker --;
							sum += n - 1 - i;
						}

						if(marker == -1){
							break;
						}

						if(a[i] <= b[marker]){
							if(a[i]==b[marker]){
								useless = marker;
								while(useless >= 0){
									if(b[useless]!=a[i]){
										break;
									}
									else
										useless--;
								}
								if(useless > 0){
									sum += useless;
								}
								break;								
							}
							sum += marker;
							break; 
						}
					}
				}
				else if(a[i] == b[marker]){
					useless = marker;
					while(useless >= 0){
						if(b[useless]!=a[i]){
							break;
						}
						else
							useless--;
					}
					if(useless > 0){
						sum += useless;
					}
				}
				else{
					sum += marker;
				}
					
				marker ++;
				b[marker] = a[i];
			}

			printf("%lld\n",sum);
	}
	return 0;
}
