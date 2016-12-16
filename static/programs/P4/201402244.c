#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int comp(const void* p1, const void* p2) {
	  int* arr1 = (int*)p1;
	    int* arr2 = (int*)p2;
	      int diff1 = arr1[0] - arr2[0];
	        if (diff1) return diff1;
		  return arr1[1] - arr2[1];
}

int main(){
	int t,l;
	char a[100009];
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		l = strlen(a);
		int * cj = (int *)calloc(l,sizeof(int));
		int * cm = (int *)calloc(l,sizeof(int));
		int * cr = (int *)calloc(l,sizeof(int));
		int i=0,jc=0,mc=0,rc=0;
		for(i=0;i<l;i++){
			if(a[i]=='J'){
				jc++;
			}
			else if(a[i]=='M'){
				mc++;
			}
			else if(a[i]=='R'){
				rc++;	
			}
			cj[i]=jc;
			cm[i]=mc;
			cr[i]=rc;
		}
		i = 0;
		int j  = 0;
		int count = 0;
		long long int ans = 0;
		int d[l][2];
		for(i=0;i<l;i++){
			d[i][0] =  cj[i]-cm[i];
			d[i][1] =  cj[i]-cr[i];
		}
		qsort(d,l,2*sizeof(int),comp);
		int p = 0;
		int p1,p2;
		p1 = 1000009;
		p2 = p1;
		for(p=0;p<l;p++){
			if(d[p][0]==p1 && d[p][1]==p2){
				count++;
				if(p==l-1){
					if(p1==0 && p2==0){
						ans += (count * (count+1))/2;
					}
					else{
						ans += (count * (count-1))/2;
					}
				}
			}
			else{
				if(p1==0 && p2==0){
					ans += (count * (count+1))/2;
				}
				else{
					ans += (count * (count-1))/2;
				}
				p1=d[p][0];p2=d[p][1];
				count = 1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
