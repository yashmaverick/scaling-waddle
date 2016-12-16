#include <stdio.h>
#include <stdlib.h>
struct stack{
	int value;
	int index;
};
int main(){

	while(1){
			
			int n;
			scanf("%d",&n);
			if(n == 0){
				break;
			}
			int i = 0;
			int * a = (int *)malloc(sizeof(int)*n);
			struct stack * new = (struct stack *)malloc(sizeof(struct stack)*n);
			
		
			for(i=0;i<n;i++){
				scanf("%d",&a[i]);
			}

			new[0].value = a[0];
			new[0].index = 0;

			int st_pointer = 0;
			int equalcase = 0;
			long long int  count = 0;
			for(i=1;i<n;i++){
				if(a[i] > new[st_pointer].value){
					count += n - 1 - i;
					st_pointer --;
					while(1){
						
						if(a[i] > new[st_pointer].value && st_pointer!=-1){
							count += n - 1 - i;
							st_pointer --;
						}

						if(st_pointer == -1){
							break;
						}

						if(a[i] <= new[st_pointer].value){
							if(a[i]==new[st_pointer].value){
								int temp1 = st_pointer;
								while(temp1 >= 0){
									if(new[temp1].value!=a[i]){
										break;
									}
									else
										temp1--;
								}
								if(temp1 > 0){
									count += temp1;
								}
								break;								
							}
							count += st_pointer;
							break; 
						}
					}
				}
				else if( (a[i] < new[st_pointer].value) ){
					count += st_pointer;
				}
				else{
					int temp = st_pointer;
					while(temp >= 0){
						if(new[temp].value!=a[i]){
							break;
						}
						else
							temp--;
					}
					if(temp > 0){
						count += temp;
					}
				}	
				st_pointer ++;
				new[st_pointer].value = a[i];
				new[st_pointer].index = i;
			}

			printf("%lld\n",count);
	}
	return 0;
}
