#include<stdio.h>
#include<stdlib.h>

struct buff{
	char s[105];
	struct buff *next;
};

int main(){
	int n,i,j,size;
	char c,buffing;
	struct buff *start,*end,*tmp;
	scanf("%d",&n);
	start=(struct buff *)malloc(sizeof(struct buff));
	end=start;
	for(i=1;i<n;i++){
		end->next=(struct buff *)malloc(sizeof(struct buff));
		end=end->next;
	}
	end->next=start;
	end=start;
	buffing=1;
	size=0;
	while(buffing){
		scanf("%c",&c);
		switch(c){
			case 'A':
					scanf("%d",&i);
					while(i--){
						if(size==n){
							start=start->next;
						}
						else{
							size++;
						}
						scanf("%s",end->s);
						end=end->next;
					}
					break;
			case 'L':
					for(i=0,tmp=start;i<size;i++){
						printf("%s\n",tmp->s);
						tmp=tmp->next;
					}
					break;
			case 'R':
					scanf("%d",&i);
					size-=i;
					while(i--){
						start=start->next;
					}
					break;
			case 'Q':
					buffing=0;
					break;
		}
	}
	return 0;
}
