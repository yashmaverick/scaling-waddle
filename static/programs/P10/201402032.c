#include<stdio.h>
char st[10005][105];
int first=0,current=-1;
int total=0,num=0,i,j;
int t,p,n;
char input;
void b_append()
{
	scanf("%d",&t);
	i=0;
	num=num+t;
	if(num>n)
		num=n;
	while(i<t){
		current = (current + 1)%n;
		scanf("%s",st[current]);
		if(current==first && total!=0){
			first=(first+1)%n;
		}
		total+=1;
		i++;
	}

}
void b_remove()
{
	scanf("%d",&p);
	num = num - p;
	first = (first+p)%n;
	if(num==0){
		current = first-1;
		total=0;
	}
}
void b_list()
{
	if(num==0){
	}
	else{
				
		if(first==current)
			printf("%s\n",st[first]);
		else if(first>current){
			for(j=first;j<n;j++){
				printf("%s\n",st[j]);
			}
			for(j=0;j<=current;j++){
				printf("%s\n",st[j]);
			}
		}
		else{
			for(j=first;j<=current;j++){
				printf("%s\n",st[j]);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	while(1){
		scanf("%c",&input);
		if(input=='A'){
			b_append();
		}
		else if(input=='R'){
			b_remove();
		}
		else if(input=='L'){
			b_list();
		}
		else if(input=='Q'){
			break;
		}
	}
	return 0;
}