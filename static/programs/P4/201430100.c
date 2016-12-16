#include<stdio.h>
#include<stdlib.h>

int compare_function(const void *a,const void *b)
{
	return (*(long long int *)a-*(long long int *)b);
}

int main()
{
	int t,z;
	scanf("%d",&t);
	getchar(); //for \n

	for(z=0;z<t;z++)
	{
		char c;
		long long int a[100005];
		int count=0;
		long long int temp=0;
		while((c=getchar())!='\n' && (c!=EOF))
		{
			if(c=='J')  temp+=100001; 
			else if(c=='M')  temp+=1;
			else if(c=='R')  temp-=100002;
			a[count]=temp;
			count++;	
		}
	
		qsort(a,count,sizeof(long long int),compare_function);	

		int i;
		long long int check=a[0],ans=0;
		int number=1;
		for(i=1;i<count;i++)
		{
			if(a[i]==check) { number++;  }
			else
			{
				if(check==0) ans+=number;
				ans+=(number*(number-1))/2;
				check=a[i];
				number=1;
			}
		}
		ans+=(number*(number-1))/2;

		printf("%lld\n",ans);
	}


	return 0;
}