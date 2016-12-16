#include<stdio.h>
int n,k;
/*void swap(int a[],int e,int f){
  int c;
//printf("before swap a[e] = %d a[f] = %d \n",a[e],a[f]);
c=a[e];
a[e]=a[f];
a[f]=c;
//printf("after swap a[e] = %d a[f] = %d \n",a[e],a[f]);
}*/
void qsort(int a[],int w,int p){
	int b=w,e=p,i,j,c;
	if(w>=p){
		return;
	}
	for(i=b;i<=e-1;i++){
		if(a[p]>=a[i]){
			//swap(a,w,i);
			c=a[w];
			a[w]=a[i];
			a[i]=c;
			w++;
			//printf("now wall becomes = %d\n array is: ",w);
			/*for(j=0;j<n;j++)
			  printf("%d ",a[j]);
			  printf("\n");*/
		}
	}
	if(a[w]>=a[p]){
		//swap(a,p,w);

		c=a[p];
		a[p]=a[w];
		a[w]=c;
	}
	//printf("array is fin\n");
	/*for(i=0;i<n;i++)
	  printf("%d ",a[i]);*/
	//printf("\n");
	//	if(w>k-1)
	qsort(a,b,w-1);
	//	else if(w<k-1)
	qsort(a,w+1,e);
	//	else
	//		return;
}
int main(){
	int a[100005],t;
	int i;
	char s[100000];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%s",s);
			scanf("%d",&a[i]);
		}
		int w=0,p=n-1,b,e;
		qsort(a,w,p);
		/*	for(i=0;i<n;i++)
			printf("%d ",a[i]);
			printf("\n");*/
		//	printf("%d\n",a[k-1]);
		int fl=0,l,f;
		for(i=0;i<=n-3;i++){
			f=1+i;
			l=n-1;
			while(f<l){
				if(a[i]+a[f]+a[l]==k){
					fl=1;
					printf("YES\n");
					break;
				}
				else if(a[i]+a[f]+a[l]<k){   //if sum is less, we need to increase the element
					f++;
				}
				else{    //if sum is larger then we come to some less element
					l--;
				}
			}
			if(fl==1)
				break;
		}
		if(fl==0)
			printf("NO\n");
	}
	return 0;
}
