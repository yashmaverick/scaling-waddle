#include<stdio.h>
int main()
{
	long long int a[1001],n,i,j,left,right,flag,test,temp;
	long long int sum,k;
	char s[1000];
//	freopen("input.txt", "r", stdin);
//	freopen("heroutput.txt", "w", stdout);
	scanf("%lld",&test);
	while(test)
	{
		test--;
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%lld",&a[i]);
		}
		for(i=1;i<n;i++)		//insertion sort
		{
			for(j=i;j>0;j--)
			{
				if(a[j]<a[j-1])
				{
					temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}
				else
				{
					break;
				}
			}
		}		
		flag=0;
		for(i=0;i<n;i++)	//sorted array, 2 pointers left and right
		{
			left=i+1;
			right=n-1;
			sum=a[left];
			temp=k-a[i];//from here find 2 elements such that sum is k-a[i]
			while(left<right)
			{
				sum=a[left]+a[right];
				if(sum>temp) //if sum is more then reduce right pointer
					right--;
				else if(sum<temp) //if sum is less then increment left pointer
					left++;
				else//if sum=k then break
				{
					flag=1;
					break;
				}
			}
			if(sum==temp)//in the case left==right and it didn't go to the above while loop
				flag=1;
			if(flag==1)
				break;
		}
		if(!flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}


