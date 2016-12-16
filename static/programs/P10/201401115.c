#include<stdio.h>
typedef struct buffer{
	char str[100];
}node;
int main(){
	int t,p,n,first=0,current=-1,total=0,num=0,i,j;
	char input;
	scanf("%d",&n);
	node a[n];
	while(1){
		scanf("%c",&input);
		if(input=='A'){
			scanf("%d",&t);
			i=0;
			num=num+t;
			if(num>n)
				num=n;
			while(i<t){
				current = (current + 1)%n;
				scanf("%s",a[current].str);
				if(current==first && total!=0){
					first=(first+1)%n;
				}
				total+=1;
				i++;
			}
		}
		else if(input=='R'){
			scanf("%d",&p);
			num = num - p;
			first = (first+p)%n;
			if(num==0){
				current = first-1;
				total=0;
			}
		}
		else if(input=='L'){
			if(num==0){
			}
			else{
				//printf("Num = %d\n",num);
				if(first==current)
					printf("%s\n",a[first].str);
				else if(first>current){
					for(j=first;j<n;j++){
						printf("%s\n",a[j].str);
					}
					for(j=0;j<=current;j++){
						printf("%s\n",a[j].str);
					}
				}
				else{
					for(j=first;j<=current;j++){
						printf("%s\n",a[j].str);
					}
				}
			}
		}
		else if(input=='Q'){
			break;
		}
	}
	return 0;
}