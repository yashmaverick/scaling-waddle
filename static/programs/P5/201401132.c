#include<stdio.h>
int a[100005];
void quick_sort(int m,int n)
{
	int i,pivot,temp;
	if(m>=n)
	{
		return;
	}
	pivot=n;
	i=m;
	while(i<=pivot)
	{
		if(a[i]<a[pivot])
		{
			i++;
		}
		else
		{
			temp=a[i];
			a[i]=a[pivot-1];
			a[pivot-1]=a[pivot];
			a[pivot]=temp;
			pivot--;
		}
	}
	quick_sort( m, i-1);

	quick_sort( i+1, n);
}

int main(){
	char c;
	int t,n,s,i,l,r,flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&s);
		for(i=0;i<n;i++){
			c= getchar();
			while(c!=' '){
				c=getchar();
			}
			scanf("%d",&a[i]);
			getchar();
		}
		quick_sort(0,n-1);
		flag=0;
		for(i=0;i<n-2;i++){
			l=i+1;
			r=n-1;
			while(l<r)
			{
				if(a[i]+a[r]+a[l]==s)
				{
					flag=1;
					break;
				}
				else if(a[i]+a[r]+a[l]<s)
				{
					l++;
				}
				else
				{
					r--;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}




