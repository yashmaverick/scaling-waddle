#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//int cmpfunc (const void * a, const void * b)
//{
//   return ( *(long long int *)a - *(long long int *)b );
//}
void qcksrt(long long int a[],long long int first,long long int last){
	if(first<=last){
        long long int wall=first,pivot=first,i,temp;
        for(i=first;i<=last;i++){
            if(a[i]<a[pivot]){
            	wall++;
            	temp=a[wall];
            	a[wall]=a[i];
            	a[i]=temp;
            }
        }
        temp=a[wall];
        a[wall]=a[pivot];
        a[pivot]=temp;
        qcksrt(a,first,wall-1);
        qcksrt(a,wall+1,last);
    }
}
long long int bs(long long int arr[],long long int low,long long int high,long long int num)
{
	if(high < low)
	{
		return -1;
	}
	if(high==low)
	{
		if(arr[high]==num)
			return 1;
		else
			return -1;
	}
	long long int mid=(low+high)/2;
	if(num==arr[mid])
	{
		return arr[mid];
	}
	if(num > arr[mid])
	{
		return bs(arr,mid+1,high,num);
	}
	else
		return bs(arr,low,mid-1,num);

}
int main()
{
	long long int test;
	scanf("%lld",&test);
	long long int g,i,j;
	for(g=0;g<test;g++)
	{
		long long int num,k,ww,flag=0;
		scanf("%lld",&num);
		long long int a[num],b[num],stack[11];
		for(i=0;i<num;i++)
		{
			scanf("%lld",&a[i]);
		}
		//qsort(a,num,sizeof(long long int),cmpfunc);
		qcksrt(a,0,num-1);
		/*for(i=0;i<num;i++)
			printf("%lld ",a[i]);
		printf("\n");*/
		for(i=num-1;i>0;i--)
		{
			long long int p=a[i];
			long long int top=0;
			flag=0;
			while(p>0)
			{
				stack[top]=p%10;
				top++;
				p=p/10;
			}
			long long int eee=0;
			top=top-1;
			long long int love=stack[top];
			while(flag==0)
			{
				top--;
				long long int www=bs(a,0,i-1,love);
				if(www!=-1)
				{
					//printf("hello world\n");
					flag=1;
				}
				if(top==-1)
					break;
				love=love*10+stack[top];
			}
			//printf("%lld\n",flag);
			if(flag==1)
				break;
		}
		//printf("hello world\n");
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}