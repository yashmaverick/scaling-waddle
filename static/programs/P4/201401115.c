#include<stdio.h>
#include<string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char a[100000];
		long long int c=0,ans=0,b[100000],i,len,count;
		scanf("%s",a);
		len = strlen(a);
		if(a[0]=='J')
			b[0] = 100001;
		else if(a[0]=='M')
			b[0] = 1;
		else
			b[0] = -100002;
		for(i=1;i<len;i++){
			if(a[i]=='J')
				b[i] = 100001;
			else if(a[i]=='M')
				b[i] = 1;
			else
				b[i] = -100002;
			b[i] = b[i-1] + b[i];
			if(b[i]==0)
				c++;
		}
		if(b[0]==0)
			c++;
		qsort(b,len,sizeof(long long int),cmpfunc);
		/*for(i=0;i<len;i++){
			printf("%lld\n",b[i]);
		}*/
		for(i=0;i<len-1;i++){
			count = 1;
			while(i<len-1 && b[i]==b[i+1]){
				count++;
				i++;
			}
			ans+=((count)*(count-1))/2;
		}
		ans += c;
		printf("%lld\n",ans);
	}
	return 0;
}