#include<stdio.h>
void print(int a[][2],int n) {
	int i;
	for(i=0;i<n;i++)
	printf("%d %d\n",a[i][0],a[i][1]);
}
int main()
{
	int t,n,a[100005][2],st[100005],i,j,b,cnt,ans,max,val;
	scanf("%d",&t);
  while(t--)
	{
		scanf("%d",&n);
	  st[0]=0;
		j=0;
		a[0][0]=0;
		a[0][1]=0;
		for(i=0;i<n;i++)
		{
	   scanf("%d",&b);
		 cnt=0;
		 while(j>0 && st[j]>b)
		 {
			 cnt++;
			 a[st[j]][0]=b;
			 a[st[j]][1]=cnt;
			 j--;
		 }
		 j++;
		 st[j]=b;
		}
		a[st[j]][0]=0;
		a[st[j]][1]=0;
	  // print(a,n+1);
		cnt=0;
		for(i=j-1;i>0;i--)
		{
			 cnt++;
			 a[st[i]][0]=st[j];
			 a[st[i]][1]=cnt;
		}
		//print(a,n+1);
		max=0;
		for(i=1;i<n+1;i++)
		{
       a[i][0]=a[a[i][0]][0]+a[i][1];
			 val=a[i][0];
			// printf("%d\n",val);
			 if(val>max)
				 {
					 max=val;
					 ans=i;
				 }
		}
		printf("%d %d\n",ans,max);
	}	 
	return 0;
}
