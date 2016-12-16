#include<stdio.h>
#include<string.h>
void insert();
void del();
void printq();
char a[10005][105];
int front=-1,back=-1;
int SIZE;
int main(){
	int n,i,j,d;
	long long int t;
	char q;
	scanf("%d",&SIZE);
	while(1){
		scanf("%c",&q);
		if(q=='A'){
			scanf("%lld",&t);
			for(j=0;j<t;j++){
				insert();
			}
		}
		else if(q=='L'){
			if(front!=-1)
			printq();
			else;
			}
		else if(q=='R'){
			scanf("%d",&d);
			for(j=0;j<d;j++){
				del();
			}
		}
		else if(q=='Q')
			break;

	}
	return 0;
}

void insert(){
	if(front==-1)
		front=0;
	back=(back+1)%SIZE;
	if(a[back][0]!='\0')
		front=(front+1)%SIZE;
	scanf("%s",a[back]);
	//	printf("f:%d b:%d\n",front,back);

}
void del(){
	a[front][0]='\0';
	front=((front+1)%SIZE);
	//		printf("front is:%d\n",front);

}
void printq(){
	int i;
	i=front;
	while(i!=back){
		if(a[i][0]!='\0')
			printf("%s\n",a[i]);
		i=(i+1)%SIZE;
	}
	if(a[back][0]!='\0')
		printf("%s\n",a[back]);

}
