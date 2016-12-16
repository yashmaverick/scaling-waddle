#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//void binsearch(int a[],int start,int end,int e,int d[],int i);

int main()
{
int t,p,q,r,i,j,start,end,a[1000002],b[1000000],c[1000000],d[1000000],mid,fl;
long long int e[1000002];

scanf("%d",&t);

while(t--)
	{
	scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
	
	scanf("%d",&q);
                for(i=0;i<q;i++)
                        scanf("%d",&b[i]);
	
	scanf("%d",&r);
                for(i=0;i<r;i++)
                        scanf("%d",&c[i]);
	for(i=0;i<p;i++)
		{ fl=0;
		start=i;end=q-1;
		 if(b[start]>=a[i]) {mid=start; fl=1; goto end;}

		while(start<=end)
			{
			mid=(start+end)/2;
			if(b[mid]==a[i])
				{
				if(b[mid-1]<a[i])
					{fl=1;break;}
				else
					end=mid-1;
				}
			else if(b[mid]>a[i])
				{
				if(b[mid-1]<a[i])
					{fl=1;break;}
				else
					end=mid-1;
				}
			else
				{
				if(b[mid+1]>=a[i])
					{mid++; fl=1; break;}
				else
					start=mid+1;
				}
			
			}
		end:;
		if(fl==1)
			d[i]=mid;
		else
			d[i]=-1;

//		printf("a");
		}

//	for(i=0;i<p;i++)
//		printf("%d ",d[i]);
//	printf("\n");

	for(i=0;i<q;i++)
                {fl=0;
                start=i;end=r-1;
		if(c[start]>=b[i]) { fl=1; mid=start; goto end1;}
		
                while(start<=end)
                        {
                        mid=(start+end)/2;
                        if(c[mid]==b[i])
                                {
                                if(c[mid-1]<b[i])
                                       {fl=1; break;}
                                else
                                        end=mid-1;
                                }
                        else if(c[mid]>b[i])
                                {
                                if(c[mid-1]<b[i])
                                       {fl=1; break;}
                                else
                                        end=mid-1;
                                }
                        else
                                {
                                if(c[mid+1]>=b[i])
                                        {mid++; fl=1; break;}
                                else
                                        start=mid+1;
                                }
			
                        }
	end1:;
	if(fl==1)	
                e[i]=r-mid;

	else
		e[i]=0;
                }

//        for(i=0;i<q;i++)
//                printf("%d ",e[i]);
//	printf("\n");

	for(i=q-2;i>=0;i--)
		{
		
		e[i]+=e[i+1];
		}

	long long int sum=0;
	for(i=0;i<p&&d[i]!=-1;i++)
		sum+=e[d[i]];

		

	printf("%lld\n",sum);


	}

return 0;
}



