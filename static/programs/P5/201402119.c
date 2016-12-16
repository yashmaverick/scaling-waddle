#include<stdio.h>
#include<string.h>
int m[10001];
int*  merge(int a[], int b[] ,int d[] ,int m ,int n)
{
	int i,j,k;
	i=0;j=0;k=0;
	while(i<m && j<n)
	{
		if(a[i]>=b[j])
		{
			d[k]=b[j];
			k++;j++;
		}
		else
		{
			d[k]=a[i];
			k++;i++;
		}
	}
	while(i<m)
	{
		d[k]=a[i];
		k++;i++;
	}
	while(j<n)
	{
		d[k]=b[j];
		k++;j++;
	}
	return d;
}
int merge_sort(int c[], int n)
{
	int i;
	int left[n],right[n];
	if(n<=1){
		return;
	}
	for(i=0;i<n/2;i++){
		left[i]=c[i];}
	for(i=n/2;i<n;i++){
		right[i-n/2]=c[i];}
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,c,n/2,n-n/2);
	return;
}
int  main()
{
	//	int m,c[100],i;
	//	scanf("%d",&m);
	//	for(i=0;i<m;i++){
	//		scanf("%d",&c[i]);}
	//	merge_sort(c,m);
	//	for(i=0;i<m;i++){
	//	printf("%d ", c[i]);}
	char c;
int i,k,t,a,n,tmp1,tmp2,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;)
		{
			c=getchar();
			if(c == ' '|| c == '	')
			{
				scanf("%d",&m[i]);
				i++;
			}
//			scanf("%s",&c);
//			scanf("%d",&m[i]);
//			i++;
		}

		merge_sort(m,n);cnt=0;
		for(i=0;i<n-2;i++)
		{

			a=m[i];
			tmp1=i+1;
			tmp2=n-1;
			while(tmp1 < tmp2)
			{
				if(a + m[tmp1] + m[tmp2] > k)
					tmp2--;
				else if(a + m[tmp1] + m[tmp2] < k)
					tmp1++;
				else if(a + m[tmp1] + m[tmp2] == k)
				{
					cnt++;
					break;
				}
			}
			if(cnt)
				break;
		}
		if(cnt)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
