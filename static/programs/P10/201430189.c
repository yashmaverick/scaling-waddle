#include<stdio.h>

void append();
void rem();
void list();
typedef struct node{
		char str[105];
}node;
//new is the pointer where new element is to be added
//older is pointer to oldest element
int N,old=-1,new=0;
node buff[10000];
int main(){
		scanf("%d" ,&N);
		char func[5];
		scanf("%s" ,func);
		while(func[0]!='Q'){
				if(func[0]=='A')
						append();
				else if(func[0]=='R')
						rem();
				else if(func[0]=='L')
						list();
				scanf("%s" ,func);
		}
		return 0;		
}


void append(){
		int n;
		scanf("%d" ,&n);
		if(n==0)
				return;
		while(n--){
				scanf("%s" ,(buff[new]).str);
				if(new==old || old==-1)
						old++;
				new++;
				if(old==N)
						old=0;
				if(new==N)
						new=0;
		}
		return;
}

void rem(){
		int n;
		scanf("%d" ,&n);
		if(n==0)
				return;
		old+=n;
		if(old>=N)
				old-=N;
		if(old==new){
				old=-1;
				new=0;
		}
		return;
}

void list(){
		if(old==-1)
				return;
		int i=old+1;
		if(i==N)
				i=0;
		printf("%s\n" ,(buff[old]).str);
		while(i!=new){
				printf("%s\n" ,(buff[i]).str);
				i++;
				if(i==N)
						i=0;
		}
		return;
}
