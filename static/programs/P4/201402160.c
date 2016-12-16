#include<string.h>
#include<stdio.h>
//#include<iostream>
//#include<algorithm>
#define cout(n) printf("%lld\n",n)
#define cin(n) scanf("%lld", &n)
#define N 100012
#define Jn 100001
#define Rn 1
#define Mn -100002
#define ll long long int
#define endla printf("\n")
//using namespace std;
ll t, i, j, n, a[N], counte, sum;
char s[N];
int qusort(int start, int end){
	if(start >= end)return 0;
	int pivot, wall;
	ll te;
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
int main(){
	cin(t);
	while(t--){
		scanf("%s",&s);//cin(s);
		n = strlen(s)+1;
		a[0] = 0;
		for(i=1;i<n;i++)
		a[i] = a[i-1] + (s[i-1]=='J'?Jn:(s[i-1]=='R'?Rn:Mn));
		//for(i=0;i<n;i++)cout(a[i](" "; cout(endl;
		sum = 0; counte = 1;
		qusort(0, n-1);
		//for(i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
		for(i=1;i<n;i++){
			//cout(counte(" "(a[i-1](" "(a[i](endl;
			if(a[i]==a[i-1])counte++;
			else{
				//cout(sum(endl;
				sum += counte*(counte-1)/2;
				counte = 1;
			}
		}
		//counte += (a[n-1]==a[n-2]);
		sum +=counte*(counte-1)/2;
		cout(sum); //endla;
	}
}
	

