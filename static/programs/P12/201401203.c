#include<stdio.h>
#define ll long long int
int a[500000],stack[500000];
ll f;
int main()
{
	int n,i,pos,j,c;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		else
		{
			f=0;
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			pos=0;
			for(i=0;i<n;i++)
			{
				if(pos==0||a[i]<=a[stack[pos-1]])//push
					stack[pos++]=i;
				else
				{
					 while(pos>0&&a[i]>a[stack[pos-1]])
					 {
						 j=pos;
						 f+=(ll)(n-1-i);
						 while(j>1&&a[stack[j-1]]==a[stack[j-2]])
							 j--;
						 if(j-2>=0)
							 f+=(ll)(j-2);//coz infront cant see and its back cant see
				//		 printf("i  %lld\n",f);
						 pos--;
					 }
					 stack[pos++]=i;
				}
			}
	/*	for(i=pos-1;i>=0;i--)
				printf("%d\n",a[stack[i]]);
*/
			while(pos>1)
			{
				c=0;
				while(pos>1&&a[stack[pos-1]]==a[stack[pos-2]])
				{
					c++;
					pos--;
				}
				if(pos-2>0)
					f+=(ll)((c+1)*(pos-2));//to avoid overlapping a<b>c only i.e only back
						 //printf("o %lld\n",f);
				pos--;
			}
		}
		printf("%lld\n",f);
	}
}
