#include<stdio.h>
#define mod 1000000007
typedef long long int llu;
llu max[1000010],min[1000010];
void mininsert(llu a[],llu x,llu index)
{llu t;

	a[index]=x;
	while(1)
	{if(x>=a[(index)/2])
		{a[(index)]=x;
			break;
		}
		if(x<a[(index)/2])
		{
			t=a[(index)];
			a[(index)]=a[(index)/2];
			a[(index)/2]=t;
			index=(index)/2;
		}
	}
}
void mindelete(llu a[],llu in,llu n)
{llu t;
	t=a[in];
	a[in]=a[n];
	a[n]=t;
	a[n]=1000000000000010;
	while(in<=(n-1)/2)
	{if(a[in]<=a[2*in]&&a[in]<=a[(2*in)+1])
		break;
		else
		{
			if(a[2*in]<=a[(2*in)+1])
			{ //swap(a[2in a[in]])
				t=a[2*in];
				a[2*in]=a[in];
				a[in]=t;
				in=2*in;
			}
                        else
			if(a[2*in+1]<a[2*in])
			{   //swap(a[2in+1]a[in])
				t=a[(2*in)+1];
				a[(2*in)+1]=a[in];
				a[in]=t;
				in=(2*in)+1;
			}

		}
	}
}
void maxinsert(llu a[],llu x,llu index)
{llu t;
	a[index]=x;

	while(1)
	{if(x<=a[(index)/2])
		{a[(index)]=x;
			break;
		}
		if(x>a[index/2])
		{        t=a[index];
			a[index]=a[index/2];
			a[index/2]=t;
			index=index/2;
		}
	}
	return;
}
void maxdelete(llu a[],llu in,llu n)
{llu t;
	t=a[in];
	a[in]=a[n];
	a[n]=t;
	a[n]=-1;
	while(in<=(n-1)/2)
	{if(a[in]>=a[2*in]&&a[in]>=a[(2*in)+1])
		break;
		else
		{
			if(a[2*in]<=a[(2*in)+1])
			{ //swap(a[2in a[in]])
				t=a[2*in+1];
				a[2*in+1]=a[in];
				a[in]=t;
				in=(2*in)+1;
			}
			else if(a[2*in+1]<a[2*in])
			{   //swap(a[2in+1]a[in])
				t=a[(2*in)];
				a[(2*in)]=a[in];
				a[in]=t;
				in=(2*in);
			}

		}
	}
}
int main()
{llu t,a,b,c,n,f,sum,i,tmp,j;
	scanf("%lld",&t);
	while(t--)
	{llu topa=1,topb=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		min[0]=0;
		max[0]=1000000000000010;
		mininsert(min,1,topa);
		topa++;
		f=1;
		sum=1;
		tmp=1;
		llu count=0;
		for(i=2;i<=n;i++)
		     { // printf("a\n");
			//tmp=min[topa-1];
			//topa--;
			f=(a*tmp)+(b*i)+c;
			f=f%mod;
			//printf("f=%lld\n",f);
			sum=(sum+f);
		        if(count%2==0)
			{
				maxinsert(max,f,topb);
				topb++;
				mininsert(min,max[1],topa);
				topa++;
				maxdelete(max,1,topb-1);
				topb--;
				if(topa-1>topb-1)
					tmp=min[1];
				else
					tmp=max[1];
				count++;

			}
			else
				if(count%2==1)
				{
				mininsert(min,f,topa);
				topa++;
				maxinsert(max,min[1],topb);
				topb++;
				mindelete(min,1,topa-1);
				topa--;
				if(topa-1>topb-1)
					tmp=min[1];
				else
					tmp=max[1];
				count++;
			}
		/*printf("count=%lld\n",count);
		 printf("tmp=%lld\n",tmp);   
		for(j=1;j<topa;j++)
		       printf("minheap=%lld\n",min[j]);
		for(j=1;j<topb;j++)
			printf("maxheap=%lld\n",max[j]);
			*/
         	}

		printf("%lld\n",sum);
              }
return 0;
}
