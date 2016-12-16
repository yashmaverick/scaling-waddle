#include<stdio.h>
#include<string.h>
/*void merge(long long int a[], int low, int mid, int high)
{
	long long int b[1000000];
	long long int i = low, j = mid + 1, k = 0;

	while (i <= mid && j <= high) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];

	while (j <= high)
		b[k++] = a[j++];

	k--;
	while (k >= 0) {
		a[low + k] = b[k];
		k--;
	}
}

void mergesort(long long int a[], int low, int high)
{
	if (low < high) {
		long long int m = (high + low)/2;
		mergesort(a, low, m);
		mergesort(a, m + 1, high);
		merge(a, low, m, high);
	}
}*/

void merge(long long int a[],int l1,int h1,int l2,int h2);
void ms(long long int a[],int low,int high){
	if(high<=low)
		return;
	long long int mid;
	mid=(low+high)/2;
	ms(a,low,mid);
	ms(a,mid+1,high);
	merge(a,low,mid,mid+1,high);
}
void merge(long long int a[],int l1,int h1,int l2,int h2){
	long long int s=h2-l1+1;
	long long int tmp[1000000];
	long long int i,j,k;
	i=l1,j=l2,k=0;
	while(i<=h1 && j<=h2){
		if(a[i]<a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	}

	while(j<=h2){
		tmp[k++]=a[j++];

	}

	while(i<=h1){
		tmp[k++]=a[i++];
	}

	long long int p=l1,b=0;
	while(p<=h2){
		a[p++]=tmp[b++];
	}
}
int main(){
	char s[100000];
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%*c");
	scanf("%s",s);
	long long int j,m,r,val;
	long long int count=1,ans=0,i;
	j=100000 + 2;
	m=2;
	r=-100000-4;
	long long int a[1000000];
	a[0]=0;
	long long int l=strlen(s);
	for(i=0;i<l;i++){
		if(i==0){
			if(s[i]=='J')
				a[i]=j;
			else if(s[i]=='M')
				a[i]=m;
			else
				a[i]=r;
		}
		else{
			if(s[i]=='J')
				val=j;
			else if(s[i]=='M')
				val=m;
			else{
				val=r;}
			a[i]=val+a[i-1];
		}
	}
	a[l]=0;
	/*for(i=0;i<=l;i++)
		printf("%lld ",a[i]);
	printf("\n");*/
	ms(a,0,l);
	/*for(i=0;i<=l;i++)
		printf("%lld ",a[i]);
	printf("\n");*/
	for(i=1;i<=l+1;i++){
		//count=1;
		if(a[i]==a[i-1] && i!=(l+1))
			count++;
		else{
			ans+=((count)*(count-1))/2;
			count=1;
		}
	}
	printf("%lld\n",ans);
	}
	return 0;
}
