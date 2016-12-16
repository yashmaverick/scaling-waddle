//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) prllif("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
//#define max(a,b) ((a)>(b)?(a):(b))
//#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#define l(x) 2*(x)
#define r(x) 2*(x)+1
#define p(x) (x)/2
//#define mod 1000000007
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef long long int lli;
lli mod=1000000007;
typedef struct node{
	lli val;
}node;
typedef struct heap{
	lli last;
	node* H;
}heap;
node mn(lli x){
	node n;
	n.val=x;return n;
}
void swap(node* a,node* b){
	node tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
heap* make(heap* h,int size){
	h=(heap*)malloc(sizeof(heap));
	h->last=0;
	h->H=(node*)malloc(size*sizeof(node));
	return h;
}
int is_empty(heap* h){
	return h->last==0?1:0;
}
heap* insert(heap* h,node x){
	h->H[++(h->last)]=x;
	lli k=h->last;
	while(k!=1&&h->H[k].val<h->H[k/2].val){
		swap(&h->H[k],&h->H[k/2]);
		k=p(k);
	}
	return h;
}
heap* delete(heap* h){
	if(h->last==0)return h;
	h->H[1]=h->H[(h->last)--];
	lli k=1,t;
	while(k<=h->last){
		if(l(k)>h->last)break;
		if(r(k)>h->last){
			if(h->H[k].val>h->H[l(k)].val){swap(&h->H[k],&h->H[l(k)]);k=l(k);}
			else break;
		}
		else{
			if(h->H[k].val<=h->H[l(k)].val&&h->H[k].val<=h->H[r(k)].val)break;
			else{
				t=h->H[l(k)].val<h->H[r(k)].val?l(k):r(k);
				swap(&h->H[k],&h->H[t]);
				k=t;
			}
		}
	}
	return h;
}
lli top(heap* h){
return h->H[1].val;
}
void print(heap* h){
	if(h->last==0)return;
	lli i;
	loop(1,h->last+1)
		printf("%lld ",h->H[i].val);
	printf("\n");
	return;
}
lli median(heap** min,heap** max,lli x,lli n){
	if(n%2==1){
		if(x<=top(*min))*max=insert(*max,mn(-1*x));
		else{
			*max=insert(*max,mn(-1*top(*min)));
			*min=delete(*min);
			*min=insert(*min,mn(x));
		}
	}
	else{
		if(!is_empty(*max)&&x<=(-1*top(*max))){
			*min=insert(*min,mn(-1*top(*max)));
			*max=delete(*max);
			*max=insert(*max,mn(-1*x));
		}
		else{
			*min=insert(*min,mn(x));
	
		}
	}
	return top(*min);
}
int main(){
	int t;
	si(t);
	while(t--){
	lli i;
	lli sum=1;
	lli a,b,c,n;
	lli v1,v2,v3,v;
	int size=200005;
	heap* min;
	heap* max;
	min=make(min,size);
	max=make(max,size);
	sll(a);
	sll(b);
	sll(c);
	sll(n);
	lli m=median(&min,&max,1,1);
	loop(2,n+1){
		///v=0;
		//v1=((a%mod)*(m%mod))%mod;
		/*v1=a%mod;
		v1*=m;
		v1%=mod;
		v+=v1;
		v%=mod;
		v2=((b%mod)*(i%mod))%mod;
		v+=v2;
		v%=mod;
		v3=c%mod;
		v+=v3;*/
		v=a*m+b*i+c;
		v%=mod;
		sum+=v;
		//sum%=mod;
		m=median(&min,&max,v,i);
	}
	printf("%lld\n",sum);
	}
	return 0;
}
