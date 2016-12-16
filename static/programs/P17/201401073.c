#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

int main()
{
	int n,i,j,*in,*pre,t,num1,num2,flag,start,end,index1,index2,minindex;
	gi(n);
	in = (int *)malloc(n*sizeof(int));
	pre = (int *)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		gi(pre[i]);
	for (i=0;i<n;i++)
		gi(in[i]);
	gi(t);
	while(t--)
	{
		flag = 0;
		minindex = n;
		gi(num1);
		gi(num2);
		for(i=0;i<n;i++)
		{
			if(in[i]==num1)
			{
				index1 = i;
				flag++;
			}
			if(in[i]==num2)
			{
				index2 = i;
				flag++;
			}
			if(flag == 2)
				break;
		}
		start = min(index1,index2);
		end = max(index1,index2);
/*		pi(start);
		tab;
		pi(end);
		endl;*/
		for(i=start; i<=end; i++)
		{
			for(j=0;j<minindex;j++)
			{
				if(in[i]==pre[j])
					if(j<minindex)
						minindex = j;
			}
			if(minindex == 0)
				break;
		}
		pi(pre[minindex]);
		endl;		
	}
	return 0;
}
