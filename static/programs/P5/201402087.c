#include<stdio.h>
void qs(int start,int end);
static int ev[100000];
int main()
{
		int t,n,k,i,j,m,d1,d2,d3,flag;
		char a[100000];
		scanf("%d",&t);
		for(i=0;i<t;i++)
		{
				scanf("%d %d",&n,&k);
				for(j=0;j<n;j++)
				{
						scanf("%s %d",a,&ev[j]);
				}
				qs(0,n-1);
			//	for(j=0;j<n;j++)
				//		printf("%d\n",ev[j]);
				flag=0;
				for(d1=0;d1<n-2;d1++)
				{
						d2=n-1;
						d3=d1+1;
						while(d3<d2)
						{
							//	printf("%d	%d %d %d\n",ev[d1]+ev[d2]+ev[d3],d1,d2,d3);
								if(ev[d1]+ev[d2]+ev[d3]==k)
								{
										flag=1;
										break;
								}
								else if(ev[d1]+ev[d2]+ev[d3]>k)
										d2--;
								else
										d3++;
						}
						if(flag==1)
								break;
				}
				if(flag==1)
						printf("YES\n");
				else
						printf("NO\n");
		}
		return 0;
}
void qs(int start,int end)
{
		int pivot,a,b,temp;
		if(start<end)
		{
				pivot=start;
				a=start;
				b=end;
				while(a<b)
				{
						while(ev[a]<=ev[pivot]&&a<end)
						{
								a++;
						}
						while(ev[b]>ev[pivot])
						{
								b--;
						}
						if(a<b)
						{
								temp=ev[a];
								ev[a]=ev[b];
								ev[b]=temp;
						}
				}
				temp=ev[pivot];
				ev[pivot]=ev[b];
				ev[b]=temp;
				qs(start,b-1);
				qs(b+1,end);
		}
}
