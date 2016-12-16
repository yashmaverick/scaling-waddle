#include<stdio.h>
#include<string.h>
long long int count[1000001],ans[1000001];
int main(){
	while(1){
		long long int k,maxelement,n,top,stack[100002],a[100002],i,j,max=-1,temp;
		scanf("%lld",&n);
		if(n==0)
			break;
		maxelement = -1;
		top = 0;
		stack[0] = -1;
		/*for(i=0;i<1000001;i++){
			count[i]=0;
			ans[i]=0;
		}*/
		memset(count,0,sizeof(count));
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]>maxelement){
				maxelement = a[i];
			}
		}
		for(i=0;i<n;i++){
			if(i==0){
				stack[0]=a[i];
				count[a[i]]=1;	
			}
			else{
				if(a[i]>stack[top]){
					for(j=0;j<=top;j++){
						count[stack[j]]++;
					}
					top++;
					stack[top] = a[i];
					count[a[i]]=1;
				}
				else{
					while(top!=-1 && a[i]<stack[top]){
						temp = (count[stack[top]])*(stack[top]);
						//printf("Answer for %lld is %lld\n",stack[top],temp);
						if(temp > ans[stack[top]])
							ans[stack[top]] = temp;
				//		printf("Answer for %d is %d\n",stack[top],ans[stack[top]]);
						top--;
					}
					for(k=0;k<=top;k++){
						count[stack[k]]++;
					}
					/*if(top!=(-1) && stack[top]==a[i]){
						count[a[i]]++;
					}*/
					if(stack[top]!=a[i]){
						top+=1;
						count[a[i]] = count[stack[top]] + 1;
						stack[top] = a[i];
						//printf("Stack top is %lld\n",stack[top]);
						//count[a[i]]++;
					}
				}
			}
			/*for(j=0;j<=top;j++){
				printf("Stack %lld\n",stack[j]);
			}*/
			//printf("Count of %lld is %lld\n",a[i],count[a[i]]);
			//printf("Answer of %lld is %lld\n",a[i],ans[a[i]]);
		}
		for(i=0;i<=top;i++){
			temp = (count[stack[i]])*(stack[i]);
			if(temp > ans[stack[top]])
				ans[stack[top]] = temp;
		}
		//printf("Answer of %lld is %lld\n",a[i],ans[a[i]]);
		for(i=0;i<=maxelement;i++){
			if(ans[i]>max){
				max = ans[i];
			}
		}
		//printf("count of 6 is %lld\n",count[6]);
		printf("%lld\n",max);
	}
	return 0;
}