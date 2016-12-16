#include<stdio.h>
#include<stdlib.h>
void swap(int,int);
void heapify(int);
int custlen(char *);
int arlen;
long long *ar;
int main(){
	int t,len,i,js,ms,rs;
	long long ans,pre;
	char s[100001];
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%s",s);
		len=custlen(s);
		ar=(long long *)malloc(sizeof(long long)*(len+1));
		for(i=len-1,js=0,ms=0,rs=0;i>=0;i--){
			if(s[i]=='J'){
				if(js==0&&ms&&rs){
					ms--;
					rs--;
				}
				else{
					js++;
				}
			}
			else if(s[i]=='M'){
				if(ms==0&&js&&rs){
					js--;
					rs--;
				}
				else{
					ms++;
				}
			}
			else if(s[i]=='R'){
				if(rs==0&&js&&ms){
					js--;
					ms--;
				}
				else{
					rs++;
				}
			}
			else{
				printf("Gone Bad\n");
			}
		//	printf("ar[%d]=%d %d %d\t",i,js,ms,rs);
			ar[i+1]=js+((long long)1<<17)*ms+((long long)1<<34)*rs;
		//	printf("%lld\n",ar[i+1]);
		}
		arlen=len;
		for(i=len>>1;i>0;i--){
			heapify(i);
		}
		while(arlen>1){
			swap(1,arlen);
			arlen--;
			heapify(1);
		}
		for(i=2,pre=1;i<=len;i++){
			if(ar[i]==ar[i-1]){
				pre++;
			}
			else{
				ans+=(pre*(pre-1))/2;
				pre=1;
			}
		}
		ans+=(pre*(pre-1))/2;
		for(i=1;ar[i]==0;i++);
		ans+=i-1;
		printf("%lld\n",ans);
		free(ar);
	}
	return 0;
}

int custlen(char *str){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

void swap(int a,int b){
	long long t;
	t=ar[a];
	ar[a]=ar[b];
	ar[b]=t;
}

void heapify(int ind){
	if(ind<<1>arlen){
		return;
	}
	else if(ind<<1==arlen){
		if(ar[ind]<ar[ind<<1]){
			swap(ind,ind<<1);
		}
	}
	else{
		int i;
		i=ar[ind<<1]>ar[(ind<<1)+1]?ind<<1:(ind<<1)+1;
		if(ar[ind]<ar[i]){
			swap(ind,i);
			heapify(i);
		}
	}
}
