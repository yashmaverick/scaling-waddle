#include<stdio.h>
#define N 1003
#define cin(n) scanf("%lld", &n)
#define int long long int
//using namespace std;
int a[N], k, n, i, j;
int binsearch(int start, int end, int val){
	if(start>=end) return (a[start]==val)?1:0;
	int mid = (start + end)/2;
	if(a[mid]==val)return 1;
	if(a[mid]<val)return binsearch(mid+1, end, val);
	return binsearch(start, mid, val);
}
int qusort(int start, int end){
	if(start >= end)return 0;
	int pivot, wall;
	int te;
	te=a[(start+end)/2];
	a[(start+end)/2]=a[end];
	a[end]=te;
	pivot = end; wall=start;
	for(i=start; i<pivot; i++){
			//	cout<<wall<<" "<<a[i]<<" "<<a[pivot]<<endl;
			if(a[i] <= a[pivot]){
				te=a[i];
				a[i]=a[wall];
				a[wall]=te;
				wall++;
			}
	}
	//wall++;
	te=a[wall];
	a[wall]=a[pivot];
	a[pivot]=te;
	qusort(start, wall-1);
	qusort(wall+1, end);
	return 0;
}
char s[100];
int main(){
	int t, f;
	cin(t);
	while(t--){
		f=0;
		cin(n); cin(k);
		for(i=0;i<n;i++){scanf("%s", &s); cin(a[i]);}
		//for(i=0;i<n;i++)printf("%lld ", a[i]);
		qusort(0, n-1);
		for(i=0;i<n-1;i++)
		for(j=i+1;j<n-1;j++)
		if(binsearch(j+1, n-1, k-a[i]-a[j])){
			f=1; //printf("YES\n");//cout<<"YES";//<<binsearch(j+1, n-1, k-a[i]-a[j]);
			
		}
		if(f==0)printf("NO\n");//cout<<"NO";
		else printf("YES\n");
	}
	return 0;
}
