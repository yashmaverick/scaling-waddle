#include<stdio.h>

int b[2],flag,poi;

void push(int d[],int value)
{
	d[poi]=value;
	poi++;
}

void pop(int d[])
{
	poi=poi-1;
}



void depth(int a[],int c[],int start,int end,int level)
{
	if(start==end)
	{
		if(flag==0)
		{
			b[1]=a[start];
			b[0]=level;
			flag=1;
			return;
		}
		else
		{
			if(level>b[0])
			{
				b[1]=a[start];
				b[0]=level;
				return;
			}
			if(level==b[0])
			{
				if(b[1]>a[start])
				{
					b[1]=a[start];
				}
			}
		}
		return;
	}
	if(start<end)
	{
		if(start<=c[end])
			depth(a,c,start,c[end],level+1);
		if(c[end]+1<=end-1)
			depth(a,c,c[end]+1,end-1,level+1);
	}
	return;
}




int main()
{
	int t,h;
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		int n,i;
		flag=0,poi=0;
		scanf("%d",&n);
		int a[n],d[n],c[n];
//		c[0]=0;
		c[n-1]=-1;
		c[0]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=n-1;i>=0;i--)
		{
			if(poi==0)
			{
				push(d,i);
				continue;
			}
			else
			{
				if(poi>0)
				{
					if(a[i]>=a[d[poi-1]])
					{
						push(d,i);
//						printf("No %d\n",a[i]);
						continue;
					}
					else
					{
//						if(poi>0)
//						{
						while(a[i]<a[d[poi-1]])
						{
							c[d[poi-1]]=i;
 //							printf("%d\n",c[d[poi-1]]);
							pop(d);
							if(poi<=0)
								break;
						}
//						}
//						printf("Yes %d\n",a[i]);
//					}
						push(d,i);
					}
				}
			}
		}
//		for(i=0;i<n;i++)
//		{
//			printf("%d ",c[i]);
//		}
//		printf("\n");
		depth(a,c,0,n-1,0);
		printf("%d %d\n",b[1],b[0]);
	}
	return 0;
}
