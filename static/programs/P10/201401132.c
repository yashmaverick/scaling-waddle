#include<stdio.h>
#include<string.h>
int i=0;
char a[100001][101];
char b[100001][101];
void add(int N);
void list();
void rem();
int main()
{
	int N;
	char c;
	scanf("%d",&N);
	while(1){
		scanf("%c",&c);
		if(c=='A'){
			add(N);
		}	
		if(c=='R'){
			rem();
		}
		if(c=='L'){
			list();
		}
		if(c=='Q'){
			break;
		}
	}
	return 0;
}
void add(int N){
	int n,j,f,k,z,x;
	char g,c;
	scanf("%d",&n);
	getchar();
	if(n<=N-i){
		f=0;
		for(j=i;j<i+n;j++){
			scanf("%s",a[j]);

			f++;
		}
		i=i+f;
	}
	else if((n<N)&&(n>N-i))
	{	
		x=n-N+i;
		for(z=0;z<(i-x);z++)
		{
			strcpy(a[z],a[z+x]);
		}
		for(j=N-n;j<N;j++){
			scanf("%s",a[j]);

		}
		i=N;
	}
	else if(n>=N)
	{
		for(z=0;z<(n-N);z++){
			scanf("%s",b[z]);
		}
		for(j=0;j<N;j++){
			scanf("%s",a[j]);
		}
		i=N;
	}
	//printf("ip=%d\n",i);
}
void list()
{
	int j,z;
	for(j=0;j<i;j++){
		printf("%s\n",a[j]);
	}
	//printf("il=%d\n",i);
}
void rem()
{	int r,z;
	scanf("%d",&r);
	//	printf("ir1=%d\n",i);
	if(r==i){
		i=0;
	}
	if(r<i){
		for(z=0;z<i-r;z++){
			strcpy(a[z],a[z+r]);
		}
		i=i-r;
	}
	//printf("ir2=%d\n",i);
}









