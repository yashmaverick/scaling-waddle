#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,depth[100011],stack[100011],i,temp,temp2,top,a[100011],stack2[100010],top2,max,minelement;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		stack[0] = a[n-1];
		top=0;
		i=n-2;
		depth[a[n-1]] = 0;
		while(a[i]>a[n-1]){
			i--;
		}
		temp2 = i;
		//printf("temp2 is %d\n",temp2);
		for(i=n-2;i>temp2;i--){
			if(a[i]>stack[top]){
				depth[a[i]]=depth[stack[top]]+1;
				top+=1;
				stack[top]=a[i];
			}
			else{
				//temp = top;
				while(a[i]<stack[top] && top>=0){
					//stack[temp+1]=stack[temp];
					temp = depth[stack[top]];
					top--;
				}
				//top = temp;
				//stack[temp+1] = a[i];
				top+=1;
				stack[top] = a[i];
				depth[a[i]] = temp + 1;
				//depth[a[i]] = depth[stack[temp+2]]+1;
			}
			//printf("Depth of %d is %d\n",a[i],depth[a[i]]);
		}
		depth[a[temp2]] = 1;
		top2 = 0;
		stack2[0] = a[temp2];
		for(i=temp2-1;i>=0;i--){
			if(a[i]>stack2[top2]){
				depth[a[i]]=depth[stack2[top2]]+1;
				top2+=1;
				stack2[top2] = a[i];
			}
			else{
				//temp = top2;
				//printf("Top of stack 2 is %d\n",top2);
				while(a[i]<stack2[top2] && top2>=0){
					//stack2[temp+1]=stack2[temp];
					temp = depth[stack2[top2]];
					top2--;
				}
				//printf("Top of stack 2 is %d\n",top2);
				//printf("Temp is %d\n",temp);
				//top2 = temp;
				//stack2[temp+1] = a[i];
				top2+=1;
				stack2[top2] = a[i];
				depth[a[i]] = temp+1;
				//printf("Depth of %d is %d\n",a[i],depth[a[i]]);
			}
			//printf("Depth of %d is %d\n",a[i],depth[a[i]]);
		}
		max=-1;
		minelement = 1000002;
		for(i=0;i<n;i++){
			//printf("Depth of %d is %d\n",a[i],depth[a[i]]);
			if(depth[a[i]] > max){
				max = depth[a[i]];
				minelement = a[i];
			}
			else if(depth[a[i]] == max){
				if(a[i] < minelement){
					minelement = a[i];
				}
			}
		}
		printf("%d %d\n",minelement,max);
	}
	return 0;
}