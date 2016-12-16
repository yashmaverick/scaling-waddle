#include<stdio.h>
#define MOD 1000000007
typedef long long int LL;
void insertmin_or_max(LL val,int ch);
LL deletemin_or_max(int ch);
void shuffle_down(LL x,int index,int ch);
LL minimum(LL a,LL b);
LL maximum(LL a,LL b);
void sum(int n);

LL heap[200003],maxh[200003];
int n1,n2;
int hl,hr;

int main(){
	int n,i,t;
	LL f,s,a,b,c,m,temp;
	scanf("%d",&t);
	while(t--){
	n1=0;
	n2=0;
	hl=0;
	hr=0;
	scanf("%lld %lld %lld %d",&a,&b,&c,&n);
	for(i=0;i<=200002;i++){
		heap[i]=0;
		maxh[i]=0;
		
	}
	f=1;
	s=1;
	hl++;
	insertmin_or_max(f,1);
	for(i=2;i<=n;i++){
		f=(a*maxh[1]+b*i+c)%MOD;
		s = s+f;
		//if(n2==0)
		//	insertmin_or_max(f,1);
		if(hl>hr){
			if(f<maxh[1]){
				m=deletemin_or_max(1);
				insertmin_or_max(m,0);
				insertmin_or_max(f,1);
			}
			else
				insertmin_or_max(f,0);
//			n1++;
			hr++;
		}
		else{
			temp = heap[1];
			if(f>temp){
				m=deletemin_or_max(0);
				insertmin_or_max(m,1);
				insertmin_or_max(f,0);
			}
			else
				insertmin_or_max(f,1);
//			n2++;
			hl++;
		}
		
	}
	printf("%lld\n",s);
	}
	return 0;
}

void insertmin_or_max(LL val,int ch){
	int i,par,done=1;
	LL temp;
	if(ch==0){
		n1++;
		heap[n1]=val;
		i=n1;
	}
	else{
		n2++;
		maxh[n2]=val;
		i=n2;
	}
	if((ch==0&&heap[i]>heap[i/2])||ch==1&&maxh[i]<maxh[i/2])
		done=0;
	else{
		while(i!=1 && done!=0){
			par=i/2;
			if(ch==0&&heap[i]<=heap[par]){
				temp=heap[par];
				heap[par]=heap[i];
				heap[i]=temp;
				i=par;
			}
			else if(ch==1&&maxh[i]>maxh[par]){
				temp=maxh[par];
				maxh[par]=maxh[i];
				maxh[i]=temp;
				i=par;
			}
			else
				done=0;
		}
	}
}
/*void sum(int n){
	 int i;
	 LL s=0;
	for(i=1;i<=n;i++){
		s+=f[i];
//		printf("%d ",f[i]);
	}
	printf("%lld\n",s);
}*/
LL deletemin_or_max(int ch){
	LL min_or_max;
	if(ch==0){
		min_or_max=heap[1];
		heap[1]=heap[n1];
		n1--;
		shuffle_down(heap[1],1,ch);
	}
	else if(ch==1){
		min_or_max=maxh[1];
		maxh[1]=maxh[n2];
		n2--;
		shuffle_down(maxh[1],1,ch);

	}
	return min_or_max;
}

void shuffle_down(LL x,int index,int ch){
	int i,minmaxindex,j;
	LL temp,min_or_max;
	i=index;
	if(ch==0){
		while(i<=n1/2&&(x>=heap[2*i]||x>=heap[2*i+1])){
			min_or_max=minimum(heap[2*i],heap[2*i+1]);
			if(min_or_max==heap[2*i])
				minmaxindex=2*i;
			else
				minmaxindex=2*i+1;
			j=i;
			i=minmaxindex;
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
		}
	}
	else if(ch==1){
		while(i<=n2/2&&(x<maxh[2*i]||x<maxh[2*i+1])){
			min_or_max=maximum(maxh[2*i],maxh[2*i+1]);
			if(min_or_max==maxh[2*i])
				minmaxindex=2*i;
			else
				minmaxindex=2*i+1;
			j=i;
			i=minmaxindex;
			temp=maxh[i];
			maxh[i]=maxh[j];
			maxh[j]=temp;
		}
	}
}

LL minimum(LL a,LL b){
	if(a<b)
		return a;
	else
		return b;
}

LL maximum(LL a,LL b){
	if(a>b)
		return a;
	else
		return b;
}
