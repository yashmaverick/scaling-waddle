#include<stdio.h>
#include<string.h>
void merge(int* a,int* b,int s,int e){
	if(s>=e)
		return ;
	int i,j,k,l,n;
	merge(a,b,s,(s+e)/2);
	merge(a,b,((s+e)/2+1),e);
	i=s;
	j=(s+e)/2+1;
	n=s;
	while(i<=(s+e)/2 || j<=e){
		if(a[i]<=a[j] && i<=(s+e)/2){
			b[n]=a[i];
			i++;
			n++;
		}
		else{
			if(a[i]>a[j] && j<=e){
				b[n]=a[j];
				j++;
				n++;
			}
			else{
				if(i>(s+e)/2){
					while(j<=e){
						b[n]=a[j];
						j++;
						n++;
					}
				}
				else{
					while(i<=(s+e)/2){
						b[n]=a[i];
						i++;
						n++;
					}
				}
			}
		}
	}
	for(i=s;i<=e;i++)
		a[i]=b[i];
	return ;
}
int main(){
	int t,n,i,j,k,l,a[100000],b[100000];
	char c[100000];
	scanf("%d",&t);
	while(t--){
		scanf("%s",c);
		n=strlen(c);
		a[0]=0;
		for(i=1;i<=n;i++){
			if(c[i-1]=='R')
				a[i]=a[i-1]+1;
			else if(c[i-1]=='J')
				a[i]=a[i-1]+100000;
			else
				a[i]=a[i-1]-100001;
		}
		merge(a,b,1,n);
//		for(i=1;i<=n;i++)
//			printf("%d ",a[i]);
//		printf("\n");
		int zeroes=0,sum=1;
		long long int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==0)
				zeroes++;
			if(a[i]==a[i+1])
				sum++;
			else{
				ans=ans+(sum*(sum-1))/2;
				sum=1;
			}
		}
		printf("%lld\n",ans+zeroes);
	}
	return 0;
}
