//to check if a number is prefix to another in list
//if number is prefix to another print NO

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
		int end;
		struct node *(next[10]);
}node;

int main(){
		long long t,N,i,j,last,ans,k;
		char num[11];
		scanf("%lld" ,&t);
		while(t--){
				node * head;
				node * temp;
				head=malloc(sizeof(node));
				head->end=0;
				for(i=0;i<10;i++)
						head->next[i]=NULL;
				scanf("%lld" ,&N);
				ans=1;
				while(N--){
						scanf("%s" ,num);
						if(ans==1){
								temp=head;
								for(i=0;num[i]!='\0';i++){
										k=(int)num[i]-'0';
										if(temp->next[k]==NULL){
												temp->next[k]=malloc(sizeof(node));
												temp=temp->next[k];
												temp->end=0;
												for(j=0;j<10;j++)
														temp->next[j]=NULL;
												last=0;
										}
										else{
												if((temp->next[k])->end==1)
														ans=0;
												else{
														temp=temp->next[k];
												}
												last=1;
										}
								}
								if(last==1)
										ans=0;
								temp->end=1;
						}
				}
				if(ans==0)
						printf("NO\n");
				else
						printf("YES\n");
		}
		return 0;
}
