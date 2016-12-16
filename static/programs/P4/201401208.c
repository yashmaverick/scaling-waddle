#include<stdio.h>
#include<string.h>
void sort(int *a,int left,int right);
void merge(int *a,int left,int mid,int right);
int main(){
	int t,n,i,j,a[100001],b[100001],ans,flag=0,nc=0,count=0,flag1=0;
	char s[100001];

	scanf("%d",&t);
	while(t--){
		flag=0;
		flag1=0;
		nc=0;
		count=0;
		scanf("%s",s);
		n=strlen(s);
		for(i=0;i<n;i++){
			if(s[i]=='J')
				a[i]=-100002;
			else if(s[i]=='M')
				a[i]=1;
			else if(s[i]=='R')
				a[i]=100001;
		}
		b[0]=a[0];	
		for(i=1;i<n;i++)
			b[i]=b[i-1]+a[i];

		sort(b,0,n-1);

	//	for(i=0;i<n;i++)
	//	  printf("%d ",b[i]);
	//	  printf("\n");	

		if(b[0]==0)
			count++;
			flag=0;
		for(j=1;j<n;j++){
			
	//		printf("nc in iteration %d is: %d\n",j-1,nc);	
			if(b[j]==b[j-1]&&flag==0){
				nc++;
	//			printf("nc is(middle) :%d\n",nc);
				}
			else if(b[j]!=b[j-1]&&flag==0){
				flag=1;
			}
			

			if(flag==1){
				
	//			printf("nc is(final) :%d\n",nc);
				count+=(((nc+1)*(nc))/2);
	//			printf("current count is(after (n+1)c2): %d\n",count);
				nc=0;				
			}
			
			if(b[j]==b[j-1]&&flag==1){
				flag=0;
				nc++;
	//			printf("nc is(start) :%d ; flag is %d\n",nc,flag);
					if(j==n-1){
						nc++;
	//					printf("nc is(end case) :%d\n",nc);
						count+=(((nc)*(nc-1))/2);
	//					printf("end case count is:%d\n",count);
						flag1=1;
						}	
				}
			
			if(b[j]==b[j-1]&&b[j]==0&&j==n-1){
					
				count+=(((nc+1)*(nc))/2);	
				}
				
			if(j==n-1&&flag==0&&b[j]==b[j-1]&&b[j]!=0&&flag1==0){
				count+=(((nc+1)*(nc))/2);
			}		
			

			if(b[j]==0){
				count++;
	//			printf("current count is(adding zeroes): %d\n",count);
}
		}

		printf("%d\n",count);
	}
	return 0;
}

/*void quicksort(int *v,int left,int right){
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

	quicksort(v,left,last-1);
	quicksort(v,last+1,right);
}

void swap(int *v,int i,int j){
	int temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}*/



void sort(int *a,int left,int right){
	int mid;
	if(left>=right)
		return;

	else{
		mid=(left+right)/2;
		sort(a,left,mid);
		sort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

void merge(int *a,int left,int mid,int right){
	int b[100000],i,j,k,m;
	j=left;
	m=mid+1;
	for(i=left;j<=mid&&m<=right;i++){
		if(a[j]<a[m]){
			b[i]=a[j];
			j++;
		}
		else{
			b[i]=a[m];
			m++;
		}
	}

	if(j>mid){
		for(k=m;k<=right;k++){
			b[i]=a[k];
			i++;
		}
	}

	else{
		for(k=j;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}

	for(k=left;k<=right;k++)
		a[k]=b[k];

}
