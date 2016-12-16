#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
	return(*(int*)a-*(int*)b);
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int l,i;
long long int  c=0;
	char s[1000010];
	long long int  a[100001];
        long long int b[100001]; 
	scanf("%s",s);
	 l=strlen(s);
	 long long int sum=0;
         for(i=0;i<l;i++)
	 {
		 if(s[i]=='J')
		 sum+= 100000;
                else if(s[i]=='M')
			sum+=-1;
		 else
			 sum+=-99999;
		 b[i]=sum;
//	 printf("%lld\n",b[i]);
	 }

	 for(i=0;i<l;i++)
		 if(b[i]==0)
			 c++;
	 qsort(b,l,8,cmpfunc);
/*	 for(i=0;i<l;i++)
		  printf("%lld ",b[i]);
	 printf("\n");*/

long long int count=1;
long long int ans;
long long int su=0;
long long int temp=b[0];
for(i=1;i<l;i++)
{
if(b[i]==temp)
count++;
else
{su+=(count*(count-1))/2;
        count=1;
	temp=b[i];
}
}
ans=su+(count*(count-1))/2;
printf("%lld\n",ans+c);
//printf("ans %lld\n",ans);
//printf("c  %lld\n",c);
}
return 0;
}
