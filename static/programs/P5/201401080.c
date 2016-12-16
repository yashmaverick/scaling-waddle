#include<stdio.h>
void quicksort(int x[1000],int low,int high){
	int p,j,m,i;

	if(low<high){
		p=low;
		i=low;
		j=high;

		while(i<j){
			while(x[i]<=x[p]&&i<high)
				i++;
			while(x[j]>x[p])
				j--;
			if(i<j){
				m=x[i];
				x[i]=x[j];
				x[j]=m;
			}
		}

		m=x[p];
		x[p]=x[j];
		x[j]=m;
		quicksort(x,low,j-1);
		quicksort(x,j+1,high);

	}
}
int main()
{
	int t,i,n,k,j,w,s,l,u,x,flag,mid,c;

	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char x[1000];
		flag=0;
		scanf("%d",&n);
		scanf("%d",&k);
		int a[n];
		int p=1;
		for(j=0;j<n;j++)
		{
			scanf("%s",x);

			scanf("%d",&a[j]);}
		quicksort(a,0,n-1);
		for(j=0;j<n-2;j++)
		{
			for(w=j+1;w<=n-2;w++)
			{
				s=k-a[j]-a[w];
				l=w+1,u=n-1;
				while(l<=u){
					mid=(l+u)/2;
					if(s==a[mid]){
						flag=1;
						break;
					}
					else if(s<a[mid]){
						u=mid-1;
					}
					else
						l=mid+1;
				}
				if(flag==0)
					continue;
				else
					break;
				
			}
		if(flag==1)
			break;
	}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");;
		 	
	}
return 0;
}


				




