#include<stdio.h>
#include<string.h>
void qsort(int abhi[1000008],int start,int end);
int main()
{
	int test,abhi[1000008],i,j,k,n,sum;
	char c[100000];
	scanf("%d",&test);
	while(test--)
	{
		int flag=0;
		scanf("%d %d",&n,&sum);
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&abhi[i]);
		}
		qsort(abhi,0,n-1);
			//write geeks for geeks sum of triplets in a array code
	//	for(i=0;i<n-2;i++)
	//	{
	//		for(j=i+1;j<n-1;j++)
	//		{
	//			for(k=j+1;k<n;k++)
	//			{
	//				if(abhi[i]+abhi[j]+abhi[k]==sum)
	//					printf("YES\n");
	//				else
	//					printf("NO\n");
	//			}
	//		}
	//	}	
		for(i=0;i<n-2;i++)
		{
			int l=i+1;
			int r=n-1;
			while(l<r)
			{
				if(abhi[i]+abhi[l]+abhi[r]==sum)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				else if(abhi[i]+abhi[l]+abhi[r]<sum)
					l++;
				else
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}
void qsort(int abhi[1000008],int start,int end)
{
	int q,i,j,tmp;
	if(start<end){
		q=start;
		i=start;
		j=end;
		while(i<j){
			while(abhi[i]<=abhi[q] && i<end)
				i++;
			while(abhi[j]>abhi[q])
				j--;
			if(i<j){
				tmp=abhi[i];
				abhi[i]=abhi[j];
				abhi[j]=tmp;
			}
		}
		tmp=abhi[q];
		abhi[q]=abhi[j];
		abhi[j]=tmp;
		qsort(abhi,start,j-1);
		qsort(abhi,j+1,end);
	}
}
