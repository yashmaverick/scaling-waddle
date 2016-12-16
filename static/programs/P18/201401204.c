#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int d;
	struct node*next;
};
typedef struct node node;
node*head[1005]={NULL};
node*rev[1005]={NULL};
int visited[1005]={0};
int dfsdone[1005]={0};
void inserth(int x,int y){
	node*temp=NULL;
	if(head[x]==NULL){
		head[x]=(node*)malloc(sizeof(node));
		head[x]->d=y;
		head[x]->next=NULL;
		return;
	}
	temp=(node*)malloc(sizeof(node));
	temp->d=y;
	temp->next=head[x];
	head[x]=temp;
	return;	
}
void insertr(int x,int y){
	node*temp=NULL;
	if(rev[x]==NULL){
		rev[x]=(node*)malloc(sizeof(node));
		rev[x]->d=y;
		rev[x]->next=NULL;
		return;
	}
	temp=(node*)malloc(sizeof(node));
	temp->d=y;
	temp->next=rev[x];
	rev[x]=temp;
	return;	
}
/*void printh(int x){
	node*temp=head[x];
	while(temp!=NULL){
		printf(" %d",temp->d);
		temp=temp->next;
	}
	printf("\n");
	return;
}
void printr(int x){
	node*temp=rev[x];
	while(temp!=NULL){
		printf(" %d",temp->d);
		temp=temp->next;
	}
	printf("\n");
	return;
}*/
int count=0;
//int last;
int l=0;
void dfsh(int e){
//	last=e;
	if(visited[e]!=1){
		count++;
//		printf("%d ",e);
		visited[e]=1;
		l++;
		node*temp=NULL;
		temp=head[e];
		while(temp){
			dfsh(temp->d);
			temp=temp->next;
		}
	}
	else
		return;
}
void dfsr(int e){
//	last=e;
	if(visited[e]!=1){
		count++;
//		printf("%d ",e);
		visited[e]=1;
		node*temp=NULL;
		temp=rev[e];
		while(temp){
			dfsr(temp->d);
			temp=temp->next;
		}
	}
	else
		return;
}
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,q,m;
		scanf("%d",&n);
		int k=1,c=0,j;
		while(k<=n){
			scanf("%d",&q);
			if(q==0)
				c++;
			while(q--){
				scanf("%d",&m);
				inserth(k,m);
				insertr(m,k);
			}
			k++;
		}
/*		for(i=1;i<=n;i++){
			printh(i);
		}
		printf("done\n");
		for(i=1;i<=n;i++){
			printr(i);
		}
*/		
		for(i=1;i<=n;i++){
			count=0;
			for(j=0;j<1005;j++){
				visited[j]=0;
			}
//			printf("dfs on %d\n",i);
			dfsr(i);
/*			printf("\n");
			printf("visited array\n");
			for(j=0;j<1005;j++){
				if(visited[j]!=0)
					printf("%d ",j);
			}
			printf("done visited\n");
			*/
			if(count==n){
//				printf("i%d \n",i);
				break;
			}
			count=0;
		}
		
		for(j=0;j<1005;j++){
			visited[j]=0;
		}
//		int l=0;
//		printf("l = %d firstly on %d\n",l,i);
		if(i<=n){
			visited[i]=1;
			l++;
		}
		if(count==n){
			//printf("entered\n");
			node*temp=head[i];
			while(temp){
			//	printf("head i %d\n",temp->d);
				count=0;
			//	printf("dfs on %d\n",temp->d);
				dfsh(temp->d);
				count=0;
				temp=temp->next;
			}
			/*for(m=0;m<1005;m++)
				if(visited[m]==1){
					l++;
			//		printf("index %d l = %d\n",m,l);
				}*/

		}
		printf("%d\n",l);
		for(i=0;i<1005;i++){
			head[i]=NULL;
			rev[i]=NULL;
			visited[i]=0;
		}
		count=0;
		c=0;
		l=0;
//		printf("\ncase over\n\n");
	}
	return 0;
}
