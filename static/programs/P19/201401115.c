#include<stdio.h>
#include<stdlib.h>
int power(int p){
	int ans=1,i;
	for(i=0;i<p;i++){
		ans = ans * 10;
	}
	return ans;
}
typedef struct node{
	int digit;
	int end;
	struct node *next[10];
}node;
long long int reverse(long long int input){
	int arr[11],i=0;
	long long int num,n = input;
	while(n>0){
		arr[i] = n%10;
		n = n/10;
		i++;
	}
	i--;
	num = 0;
	int yo = i,k;
	for(k=0;k<=i;k++){
		num += arr[k] * power(yo);
		yo--;
	}
	return num;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int N,final=0;
		scanf("%d",&N);
		node *root = (node *)malloc(sizeof(node));
		node *current;
		while(N--){
			int arr[11],j,a,flag,i=0,k;
			long long int n,num,t;
			node *temp;
			scanf("%lld",&t);
			n=t;
			while(n>0){
				arr[i] = n%10;
				n = n/10;
				i++;
			}
			//num = reverse(t);
			//n = num;
			flag = 1;
			for(j=i-1;j>=0;j--){
				a = arr[j];
				if(root->next[a]==NULL && flag==1){
					current = (node *)malloc(sizeof(node));
					root->next[a] = current;
					current->digit = a;
					flag=0;
					//printf("If loop\n");
				}
				else if(root->next[a]!=NULL && flag==1){
					current = root->next[a];
					if(current->end==1){
						final = 1;
					}
					flag=0;
					//printf("First else if loop\n");
				}
				else if(current->next[a]==NULL){
					if(current->end==1){
						final = 1;
					}
					temp = (node *)malloc(sizeof(node));
					temp->digit = a;
					current->next[a] = temp;
					current = temp;
					//printf("Second else if loop\n");
				}
				else if(current->next[a]!=NULL){
					if(current->end==1){
						final = 1;
					}
					current = current->next[a];
					//printf("Third else if loop\n");
				}
				//n = n/10;
				//printf("value of final when %d is inserted is %d\n",a,final);
			}
			current->end = 1;
			for(i=0;i<10;i++){
				if(current->next[i]!=NULL){
					final = 1;
				}
			}
			//printf("Digit %d End %d\n",current->digit,current->end);
			/*n = num;
			current = root;
			while(current!=NULL && n>0){
				a = n%10;
				printf("%d-->",current->next[a]->digit);
				current = current->next[a];
				n = n/10;
			}*/
		}
		if(final==1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}