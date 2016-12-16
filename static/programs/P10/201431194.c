#include<stdio.h>
int main(){
	int flag,i,j,k,l,n,m,t,tail,head;
	char a[10001][105],x;
	scanf("%d",&n);
	tail=-1;
	head=0;
	flag=1;
	while(flag==1){
		scanf(" %c",&x);
		if(x=='A'){
			scanf("%d",&t);
			for(l=0;l<t;l++){
				if(tail<n-1){
					if((tail != head-1) || tail==-1)
						tail++;
					else{
						tail++;
						if(head<n-1)
							head++;
						else
							head=0;
					}
				}
				else{
					if(head==0){
						tail=0;
						head=1;
					}
					else
						tail=0;
				}
				scanf(" %s",a[tail]);
			}
		}
		else if(x=='R'){
			scanf("%d",&t);
			head = (head+t)%n;
			if(head!=0){
				if(head==tail+1 && t!=0){
					tail = -1;
					head = 0;
				}
			}
			else{
				if(tail==n-1 && t!=0){
					tail = -1;
					head = 0;
				}
			}
		}
		else if(x=='L'){
			if(tail != -1){
				if(tail>=head)
					for(l=head;l<=tail;l++)
						printf("%s\n",a[l]);
				else{
					for(l=head;l<n;l++)
						printf("%s\n",a[l]);
					for(l=0;l<=tail;l++)
						printf("%s\n",a[l]);
				}
			}
		}
		else if(x=='Q')
			break;
//		printf("%d %d\n",head,tail);
	}
	return 0;
}
