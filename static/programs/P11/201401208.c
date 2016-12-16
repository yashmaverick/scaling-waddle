#include<stdio.h>

long long int a[100000],fence[100000];
void push(long long int value);
void pop();
int TOP();
void pr_stack(long long int n);

int top=-1;

int main(){
	long long int n,i,j,len,x,y,z,tp;
	long long int ar,max;
	while(1){
		top=-1;
		max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			a[i]=0;
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&fence[i]);

		i=0;
		while(i<n){
			if(top==-1||fence[TOP()]<=fence[i]){
				push(i);
				i++;
			}
			else{
				tp=TOP();
				pop();
				if(top!=-1){
					ar=fence[tp]*(i-a[top]-1);
					//					printf("tp is:%d ar is %d\n",tp,ar);
					if(ar>max)
						max=ar;
				}
				else{
					ar=fence[tp]*i;
					//					printf("top is -1;tp is:%d ar is %d\n",tp,ar);
					if(ar>max)
						max=ar;
				}
			}

		}
		while(top!=-1){
			tp=TOP();
			pop();
			if(top!=-1){
				ar=fence[tp]*(i-a[top]-1);
				//					printf("tp is:%d ar is %d\n",tp,ar);
				if(ar>max)
					max=ar;
			}
			else{
				ar=fence[tp]*i;
				//					printf("%d,%d\n",fence[tp],i);
				//					printf("top is -1;tp is:%d ar is %d\n",tp,ar);
				if(ar>max)
					max=ar;
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}

void push(long long int value){
	a[++top]=value;
}

void pop(){
	a[top]=0;
	top--;
}

int TOP(){
	return a[top];
}

void pr_stack(long long int n){
	long long int i;
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}
