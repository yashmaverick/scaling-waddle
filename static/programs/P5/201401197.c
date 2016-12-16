#include<stdio.h>
#include<stdlib.h>
void swap(int,int);
void heapify(int);
int binsear(int,int,int);
char possible(int,int,int);
int *ar,arlen;
int main(){
	int t,n,reqval,i,j,k;
	char s[200],fl;
	scanf("%d",&t);
	while(t--){
		fl=0;
		scanf("%d %d",&n,&reqval);
		arlen=n;
		ar=(int *)malloc(sizeof(int)*(n+1));
		for(i=1;i<=n;i++){
			scanf("%s %d",s,ar+i);
		}
		for(i=arlen>>1;i>0;i--){
			heapify(i);
		}
		while(arlen>1){
			swap(1,arlen);
			arlen--;
			heapify(1);
		}
		arlen=n;
		for(i=1;i<n;i++){
			for(j=i+1;j<=n&&ar[i]+ar[j]<=reqval;j++){
				k=binsear(reqval-(ar[i]+ar[j]),1,arlen);
				if(k>0&&possible(k,i,j)){
					fl=1;
					break;
				}
			}
			if(fl){
				break;
			}
		}
		if(fl){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}

void swap(int a,int b){
	int tmp;
	tmp=ar[a];
	ar[a]=ar[b];
	ar[b]=tmp;
}

void heapify(int ind){
	if(ind<<1>arlen){
		return ;
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

int binsear(int val,int start,int stop){
	int mid;
	mid=(start+stop)>>1;
	if(start>stop){
		return -1;
	}
	else if(val==ar[start]){
		return start;
	}
	else if(val==ar[stop]){
		return stop;
	}
	else if(ar[start]<val&&val<ar[stop]){
		if(val<=ar[mid]){
			return binsear(val,start+1,mid);
		}
		else{
			return binsear(val,mid+1,stop-1);
		}
	}
	else{
		return -1;
	}
}

char possible(int req,int low,int high){
	if(req!=low&&req!=high){
		return 1;
	}
	else if(ar[low]==ar[high]){
		if(low+1==high){
			if((low>1&&ar[low]==ar[low-1])||(high<arlen&&ar[high]==ar[high+1])){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			if((low>1&&ar[low]==ar[low-1])||ar[low+1]==ar[low]||(high<arlen&&ar[high]==ar[high+1])||ar[high]==ar[high-1]){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	else if(req==low){
		if((low>1&&ar[low]==ar[low-1])||ar[low+1]==ar[low]){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if((high<arlen&&ar[high]==ar[high+1])||ar[high]==ar[high-1]){
			return 1;
		}
		else{
			return 0;
		}
	}
}
