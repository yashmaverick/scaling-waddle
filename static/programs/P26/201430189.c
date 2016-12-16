#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
		int num;
		struct linknode *next;
}linknode;

typedef struct node{
		int visited,dist;
		struct linknode *adj;
}node;

node map[9998];
int que[1000],st=0,end=0;

void insert(int i ,int j){
		linknode *temp1,*temp2;
		temp1=malloc(sizeof(linknode));
		temp1->num=j;
		temp1->next=map[i].adj;
		map[i].adj=temp1;
		temp2=malloc(sizeof(linknode));
		temp2->num=i;
		temp2->next=map[j].adj;
		map[j].adj=temp2;
		return;
}

int prime[9999];

void makemap(){
		int i,j;
		for(i=4;i<9999;i+=2)
				prime[i]=0;
		for(i=3;i<9999;i+=2){
				prime[i]=1;
		}
		prime[2]=1;
		for(i=3;i<100;i+=2){
				if(prime[i]==1){
						for(j=3*i;j<9999;j=j+i){
								prime[j]=0;
						}
				}
		}
		for(i=1001;i<9999;i=i+2){
				if(prime[i]==1){
						for(j=i+2;j<9999;j=j+2){
								if(prime[j]==1){
										if(i%1000==j%1000)
												insert(i,j);
										else if(i/1000==j/1000 && i%100==j%100)
												insert(i,j);
										else if(i/100==j/100 && i%10==j%10)
												insert(i,j);
										else if(i/10==j/10)
												insert(i,j);
								}
						}
				}
		}
		return;
}

void push(int k){
		que[end]=k;
		end++;
		return;
}

void pop(){
		st++;
		if(st==end){
				st=0;
				end=0;
		}
		return;
}

int top(){
		return que[st];
}



void inimap(){
		st=end=0;
		int i;
		for(i=1001;i<9998;i++){
				map[i].visited=0;
				map[i].dist=-1;
		}
}

void mindis(int S , int T){
		map[S].dist=0;
		map[S].visited=1;
		if(T==S){
				printf("0\n");
				return;
		}
		push(S);
		while(st!=0 || end!=0){
				int i;
				linknode *temp=map[top()].adj;
				while(temp!=NULL){
						if(temp->num==T){
								printf("%d\n" ,(map[top()].dist+1));
								return;
						}
						if(map[temp->num].visited==0){
								push(temp->num);
								map[temp->num].visited=1;
								map[temp->num].dist=map[top()].dist+1;
						}
						temp=temp->next;
				}
				pop();
		}
		printf("Impossible\n");
		return;
}


int main(){
		int i,S,T;
		for(i=1001;i<9998;i++)
				map[i].adj=NULL;
		makemap();
/*		for(i=1001;i<9998;i++){
				if(prime[i]==1){
						printf("%d : " ,i);
						linknode *pt=map[i].adj;
						while(pt!=NULL){
								printf("%d " ,pt->num);
								pt=pt->next;
						}
						printf("\n");
				}
		}*/
		int test;
		scanf("%d" ,&test);
		while(test--){
				inimap();
				scanf("%d %d" ,&S,&T);
				mindis(S,T);		
		}
		return 0;
}
