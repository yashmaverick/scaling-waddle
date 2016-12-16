#include<stdio.h>
void merg(int a[],int s,int e)
{
	if(s==e)
		return;
	int mid = (s+e)/2;
	int t1=s;
	int t2 = (s+e)/2+1;
	merg(a,s,mid);
	merg(a,t2,e);
	int temp[100000],t=0;
	while(t1<=mid || t2<=e)
	{
		if(t1>mid)
			temp[t++] = a[t2++];
		else if(t2>e)
			temp[t++] = a[t1++];
		else
		{
			if(a[t1]<a[t2])
				temp[t++] = a[t1++];
			else
				temp[t++] = a[t2++];
		}
	}
	int i;
	for(i=0;i<t;i++)
		a[s+i]=temp[i];
}
int main()
{


	int t,n,a[1000],k,i,l,r,f,j,i2,n0;
	long long int cs;
	char c[100];
	scanf("%d\n",&t);
		while(t--)
		{
			cs=0;
			f=0;
			n=0;
			scanf("%d %d",&n,&k);
				for(i2=0;i2<n;i2++)
				{
	//				printf("n %d\n",n);
					scanf("%s",c);
					scanf("%d",&a[i2]);
					cs += a[i2];
				}
				if(cs<k)
					printf("NO\n");
				else{
					merg(a,0,n-1);
					for(i=0;i<n-2;i++)
					{
						l = i+1;
						r = n-1;
					//	printf("i %d\n",i);
						while(l<r)
						{
						//	printf("l %d r %d sum %d\n",a[l],a[r],a[i]+a[l]+a[r]);
							if( a[i]+a[l]+a[r]==k)
							{
								f=1;
								printf("YES\n");
								break;
							}
							else if( a[i] + a[l] +a[r] < k)
								l++;
							else
								r--;
						}
						if(f==1)
							break;
					}
					if(f==0)
						printf("NO\n");
				}
			
		}
	return 0;
}
