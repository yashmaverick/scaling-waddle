#include<stdio.h>
#define ss(n) scanf("%s", &n)
#define sd(n) scanf("%d", &n)
#define ps(n) printf("%s\n", n)
#define N 100034
char a[N][102];
int i, j, n, size=0, front=-1, back=-1, temp;
int insert(){
	if(front==-1)front=back=0;
	else if(back==n-1)back=0;
	else back++;

	ss(a[back][0]); size++;
	if(size==n+1)size--,front=(front+1)%n;
	return 1;
}
int deleter(){
	//if(front==back)front=back=-1;
	//else front=(front+1)%N;
	size--;
	if(size==0)front=back=-1;
	else front=(front+1)%n;
	//if(size<=0)front=back=-1, size=0;
	return 1;
}
int show(){
	int i;
	if(size==0)return 0;
	if(front<=back){
		for(i=front; i<=back; i++)ps(a[i]);
		return 0;
	}
	for(i=front; i<n; i++)ps(a[i]);
	for(i=0; i<=back; i++)ps(a[i]);
}
int main(){
	char c;
	sd(n); 
	while(1){
		//cout<<size<<"-"<<endl;
		scanf("%c", &c);
		if(c=='A'){sd(temp); while(temp--)insert();}
		if(c=='R'){sd(temp); while(temp--)deleter();}
		if(c=='L')show();
		if(c=='Q')break;
	}
	return 0;
}
