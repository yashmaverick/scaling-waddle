#include<stdio.h>
#include<stdlib.h>
struct structurebag{
		long long int items,bagnum;
		long long *wts;
		long long totalwt;
		long long int bagequal;
};
struct structurebag *bag;
//void mergesortbags(long long int s, long long int e);

int main(){
		long long int i,j;
		long long tempwt;
		long long int N,Mod;
		scanf("%lld%lld" ,&N,&Mod);
		bag=malloc(N*sizeof(struct structurebag));
		i=0;
		//scanning and finding total weight
		while(i<N){
				((bag[i]).bagnum)=i;
				scanf("%lld" ,&((bag[i]).items));
				((bag[i]).wts)=malloc(((bag[i]).items)*sizeof(long long));
				((bag[i]).totalwt)=0;
				j=0;
				while(j<((bag[i]).items)){
						scanf("%lld" ,&tempwt);
						((bag[i]).totalwt)=(((bag[i]).totalwt)+tempwt)%Mod;				
						(((bag[i]).wts)[j])=tempwt;
						j++;
				}
				i++;		
		}
		//mergesort the array of total wts;
		//mergesortbags(0,N-1);

		//bubblesort

		for(i=0;i<N;i++)
				for(j=i+1;j<N;j++)
						if(((bag[j]).totalwt)<((bag[i]).totalwt)){
								struct structurebag swap;
								swap=bag[i];
								bag[i]=bag[j];
								bag[j]=swap;
						}


		//printing the bags now
		i=0;
		while(i<N){
				printf("%lld\n",(bag[i]).totalwt);
				j=0;
				while(j<((bag[i]).items)){
						printf("%lld\n" ,(((bag[i]).wts)[j]));
						j++;
				}
				printf("\n");
				i++;
		}
		return 0;

}

/*
void mergesortbags(long long int s, long long int e){
		
		struct structurebag swap;
		if(e-s<1)
				return;
		else if(e-s==1){
				if(((bag[s]).totalwt)>(((bag[e]).totalwt))){
						swap=bag[s];
						bag[s]=bag[e];
						bag[e]=swap;
				}
				return;				
		}
		mergesortbags(s,(s+e)/2);
		mergesortbags((s+e+2)/2,e);
		
		struct structurebag *duplicate;
		duplicate=malloc((e-s+1)*sizeof(struct structurebag));
		//merge the two arrays
		long long int i=s,j=(s+e+2)/2,k=0;
		while(i!=(s+e+2)/2 && j!=(e+1)){
				if(((bag[i]).totalwt)<=((bag[j]).totalwt)){
						duplicate[k]=(bag[i]);
						i++;
				}
				else if(((bag[i]).totalwt)>((bag[j]).totalwt)){
						duplicate[k]=(bag[j]);
						j++;
				}
				k++;
		}

		long long int kcopy=k;
		if(j==e+1){
				while(i!=(s+e+2)/2){
						bag[s+kcopy]=bag[i];
						kcopy++;
						i++;
				}
		}
		kcopy=0;
		while(kcopy!=k){
				bag[s+kcopy]=duplicate[kcopy];				
				kcopy++;
		}
		return;
}
*/
