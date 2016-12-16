#include<stdio.h>
int minheap[1000006],maxheap[1000006],mins,maxs,MOD=1000000007;
void insertmax(int);
void insertmin(int);
void delmax();
void delmin();
int main(){
	int n,a,b,c,t,i,j,k,t1,t2,t3,t4;
	long long ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&a,&b,&c,&n);
		mins=0;maxs=0;
		ans=1;
		maxheap[1]=1;
		maxs=1;
		mins=0;
		for(i=2;i<=n;i++){
			k=(int)((((long long)a*(long long)(maxheap[1]))%MOD+((long long)b*(long long)i)%MOD+c)%MOD);
			ans+=(long long)k;
			if(maxs>mins){
				if(k>=maxheap[1]){
					insertmin(k);
				}
				else{
					insertmin(maxheap[1]);
					delmax();
					insertmax(k);
				}
			}
			else{
				if(k<=minheap[1]){
					insertmax(k);
				}
				else{
					insertmin(k);
					insertmax(minheap[1]);
					delmin();
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

void insertmax(int k){
	int t1,t2;
	maxs++;
	maxheap[maxs]=k;
	t1=maxs;
	while(t1>1&&maxheap[t1]>maxheap[t1>>1]){
		t2=maxheap[t1];
		maxheap[t1]=maxheap[t1>>1];
		maxheap[t1>>1]=t2;
		t1=t1>>1;
	}
}

void insertmin(int k){
	int t1,t2;
	mins++;
	minheap[mins]=k;
	t1=mins;
	while(t1>1&&minheap[t1]<minheap[t1>>1]){
		t2=minheap[t1];
		minheap[t1]=minheap[t1>>1];
		minheap[t1>>1]=t2;
		t1=t1>>1;
	}
}

void delmax(){
	int ind,i,t1;
	maxheap[1]=maxheap[maxs];
	maxs--;
	ind=1;
	while((ind<<1)<maxs){
		i=ind<<1;
		if(maxheap[i]<maxheap[i+1]){
			i++;
		}
		if(maxheap[i]>maxheap[ind]){
			t1=maxheap[i];
			maxheap[i]=maxheap[ind];
			maxheap[ind]=t1;
			ind=i;
		}
		else{
			break;
		}
	}
	if(ind<<1==maxs&&maxheap[ind<<1]>maxheap[ind]){
		t1=maxheap[ind];
		maxheap[ind]=maxheap[ind<<1];
		maxheap[ind<<1]=t1;
	}
}

void delmin(){
	int ind,i,t1;
	minheap[1]=minheap[mins];
	mins--;
	ind=1;
	while(ind<<1<mins){
		i=ind<<1;
		if(minheap[i]>minheap[i+1]){
			i++;
		}
		if(minheap[i]<minheap[ind]){
			t1=minheap[i];
			minheap[i]=minheap[ind];
			minheap[ind]=t1;
			ind=i;
		}
		else{
			break;
		}
	}
	if(ind<<1==mins&&minheap[ind<<1]<minheap[ind]){
		t1=minheap[ind];
		minheap[ind]=minheap[ind<<1];
		minheap[ind<<1]=t1;
	}
}

