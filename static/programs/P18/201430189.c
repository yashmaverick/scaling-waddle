#include<stdio.h>
#include<stdlib.h>

typedef struct node{
		int visited;
		int curr;
		int M;
		int weak[1000],str[1000];
}node;

node * realm;
int count,N;

void dfsweak(int k){
		int i;
		realm[k].visited=1;
		count++;
		for(i=0;i<realm[k].curr;i++){
				if(realm[realm[k].weak[i]].visited==0)
						dfsweak(realm[k].weak[i]);
				if(count==N)
						break;
		}
		return;
}

int searchstrongest(){
		int i,j;
		for(i=1;i<=N;i++){				
				for(j=1;j<=N;j++)
						realm[j].visited=0;
				count=0;
				dfsweak(i);
				if(count==N)
						return i;
		}
		return 0;
}

void dfsstr(int k){
		int i;
		realm[k].visited=1;
//		printf("%d " ,k);
		count++;
		for(i=0;i<realm[k].M;i++){
				if(realm[realm[k].str[i]].visited==0)
						dfsstr(realm[k].str[i]);
				if(count==N)
						break;
		}
		return;


}

int main(){
		int t,num,temp,i,j;
		scanf("%d" ,&t);
		while(t--){
				scanf("%d" ,&N);
				realm=malloc((N+1)*sizeof(node));
				for(i=1;i<=N;i++){
						realm[i].visited=0;
						realm[i].weak[0]=0;
						realm[i].str[0]=0;
						realm[i].curr=0;
				}
				for(i=1;i<=N;i++){
						scanf("%d" ,&(realm[i].M));
						for(j=0;j<realm[i].M;j++){
								scanf("%d" ,&temp);
								realm[temp].weak[realm[temp].curr]=i;
								realm[temp].curr++;
								realm[i].str[j]=temp;
						}
				}
//				printf("Done scanning\n");
				num=searchstrongest();
				for(j=1;j<=N;j++)
						realm[j].visited=0;
				count=0;
	//			printf("%d\n" ,num);
				if(num==0)
						printf("0\n");
				else{
						dfsstr(num);
						printf("%d\n" ,count);						
				}

		}
		return 0;
}
