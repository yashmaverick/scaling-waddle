#include<stdio.h>

void quicksort(int *v,int left,int right);
void swap(int *v,int i,int j);

int main(){
	int a[1002],i,n,t,sum,p,q,r,flag=0,flag1=0;
	char s[1001];

	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d %d",&n,&sum);
		
			for(i=0;i<n;i++){
				scanf("%s %d",s,&a[i]);
			}
			
			quicksort(a,0,n-1);
		/*	for(i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");*/
			
			for(p=0;p<n-2;p++){
				q=p+1;
				r=n-1;
				while(q<r){
					if(a[p]+a[q]+a[r]==sum){
						if(flag==0)
						printf("YES\n");
						flag=1;
						break;
					}

					else if(a[p]+a[q]+a[r]<sum)
						q++;

					else if(a[p]+a[q]+a[r]>sum)
						r--;
				}

			}
			if(flag==0)//&&flag1==0)
				printf("NO\n");
	//		if(flag1=1)
	//			;
//		}
		
	}
	return 0;
}


void quicksort(int *v,int left,int right){
	int last,i,temp;

	last=left;

	if(left>=right)
		return;

	for(i=left+1;i<=right;i++){
		if(v[left]>v[i]){
			last++;
			swap(v,last,i);
		}
	}

	swap(v,left,last);

	/*	for(i=left;i<=right;i++)
		printf("%d ",v[i]);
		printf("\n");
	 */

	quicksort(v,left,last-1);
	quicksort(v,last+1,right);
}

void swap(int *v,int i,int j){
	int temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
