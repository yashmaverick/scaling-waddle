#define loop(n) for(i=0;i<n;i++)
#include<stdio.h>
void qs(int a[],int low,int high){
	if(low>=high)
		return;
	int pivot=a[high];
	int wall=low-1,i=low;
	int t;
	while(i<=high){
		if(a[i]>pivot)
			i++;
		else{
			t=a[i];
			a[i]=a[wall+1];
			a[wall+1]=t;
			wall++;
			i++;
		}
	}
	int pos=wall;
	if(pos==low){
		qs(a,pos+1,high);
	}
	if(pos==high){
		qs(a,low,pos-1);
	}
	else{
		qs(a,low,pos-1);
		qs(a,pos+1,high);
	}
}
int main(){
	int a[1000],i,n,sum,s,t;
	char b[1000];
	scanf("%d",&t);
	while(t--){
	scanf("%d %d",&n,&sum);
	loop(n){
		//scanf("%*c");
		scanf("%s",b);
		scanf("%d",&a[i]);
	}
	qs(a,0,n-1);
	/*loop(n){
		printf("%d ",a[i]);
	}
	printf("\n");*/
	int j,k,flag=0;
	loop(n){
		if(flag)
			break;
		s=sum-a[i];
		if(s<=0)
			break;
		//printf("%d\n",s);
		j=i+1;
		k=n-1;
		while(j<k){
			if(a[j]+a[k]==s){
				flag=1;
				break;}
			else if(a[j]+a[k]>s)
				k--;
			else
				j++;
		}
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	}
	return 0;
}
