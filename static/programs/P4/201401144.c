#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find();

int main(){
	int tt,tb;
	scanf("%d",&tb);
	for(tt=0;tt<tb;tt++){
		find();
	}
	return 0;
}
int find()
{
	int b[10001];
	char a[10001],n;
	int size=0,i;
	int sum=0;
	n=getchar();
	//printf("checking1\n");
	/*while((n=getchar())!='\n'){
		a[size]=n;
		size++;
	}*/
	scanf("%s",a);
	//printf("%c\n", a[0]);
	size=strlen(a);
	int min=400000000,max=-400000000;
	//printf("%d",size);
	for(i=0;i<size;i++){
		if(a[i]=='J'){
			sum+=1;
		//	printf("j\n");
		}
		else if(a[i]=='M'){
			sum+=101;
		//	printf("m\n");
		}
		else if(a[i]=='R'){
			sum+=-102;
		//	printf("r\n");
		}
		b[i]=sum;
		if(sum>max){
			max=sum;
		}
		else if(sum<min){
			min=sum;
		}
	}
	/*for(i=0;i<size;i++){
		printf("%d ",b[i]);
	}*/
	//int l[1000000];
	short* l=(short*)malloc(10000000*sizeof(short));
	for(i=0;i<10000000;i++){
		l[i]=0;
	}
	l[5000000]=1;
	for(i=0;i<size;i++){
		//printf("%d\n", 50000+b[i]%100000);
		l[5000000+b[i]%10000000]++;
	}
	
	int tot=0;
	int tempmax=max+5000000+1;
	for(i=min+5000000;i<tempmax;i++){
		tot+=l[i]*(l[i]-1)/2;
	}
	printf("%d\n", tot);
	free(l);
	return 0;
}