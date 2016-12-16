#include<stdio.h>
#include<math.h>
#define MAX 200009
#define mod 1000000007
#define rep(i,s,n) for(i=s;i<=n;i++)
#define LL long long int
void in(LL *address){
	scanf("%lld",address);
}
void out(LL *pointer){
	printf("%lld\n",*pointer);
}
void swap(LL *a, LL *b)
{
	LL temp;

	temp = *b;
	*b   = *a;
	*a   = temp;   
}
LL heap1[MAX],heap2[MAX],size2=0,size1=0;
void mininsert( LL value){
	LL i=size1+1,p,temp;
	heap1[i]=value;
	while(i>1 ){
		p=i/2;
		if(heap1[p]>heap1[i]){
			swap(&heap1[i],&heap1[p]);
			i=p;
		}
		else break;
	}
	size1++;
}
void shuffledown( LL pos){
	LL i=pos,temp,p;
	while(i<=size1/2 && (heap1[i]>heap1[2*i]|| heap1[i]>heap1[2*i+1])){
		if(heap1[2*i]<heap1[2*i+1]) p=2*i;
		else p=2*i+1;
		swap(&heap1[p],&heap1[i]);
		i=p;    
	}
	return ;
}
LL delmin(){
	LL min=heap1[1];
	heap1[1]=heap1[size1];
	size1--;
	shuffledown(1);
	return min;
}
void maxinsert( LL value){
	LL i=size2+1,p,temp;
	heap2[i]=value;
	while(i>1 ){
		p=i/2;
		if(heap2[p]<heap2[i]){
			swap(&heap2[p],&heap2[i]);
			i=p;
		}
		else break;
	}
	++size2;
	return ;
}
void heap2ify( LL value){
	LL i=1,p,temp;
	while(i<=size2/2 && (value<heap2[2*i]||value<heap2[2*i+1])){
		if(heap2[2*i]>heap2[2*i+1]) p=2*i;
		else p=2*i+1;
		swap(&heap2[p],&heap2[i]);
		i=p;
	}
	return ;
}
LL delmax(){
	LL max=heap2[1];
	heap2[1]=heap2[size2--];
	heap2ify(heap2[1]);
	return max;
}
int main()
{
	LL t,k;
	LL a,b,c,med,f,i,j,n;
	LL sum=0;
	in(&t);
	rep(k,1,t){
		size2=size1=sum=0;
		maxinsert(1);
		sum+=1;
		med=heap2[1];
		in(&a);
		in(&b);
		in(&c);
		in(&n);
		rep(i,2,n){
			f=((a*med)%mod+(b*i)%mod+c)%mod;
			sum+=f;
			if(f>med)mininsert(f);
			else maxinsert(f);
			if(size1==size2+2) maxinsert(delmin());
			else if(size2==size1+2) mininsert(delmax());
			if(size2>=size1) med=heap2[1];
			else med=heap1[1];
		}
		out(&sum);
	}
	return 0;
}
