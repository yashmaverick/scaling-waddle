#include<stdio.h>
long int binary_searcha(long int a[],long int no,long int fi,long int la);
long int binary_searchc(long int a[],long int no,long int fi,long int la);
int main()
{ int t;
	scanf("%d",&t);
	while(t--)
	{ long int a[100001],b[100001],c[100001],p,q,r,i,j,k,cnt=0;
		scanf("%ld",&p);
		for(i=0;i<p;i++)
		{ scanf("%ld",&a[i]);
		}
		scanf("%ld",&q);
		for(i=0;i<q;i++)
		{ scanf("%ld",&b[i]);
		}
		scanf("%ld",&r);
		for(i=0;i<r;i++)
		{ scanf("%ld",&c[i]);
		}
		if(q>r)
		{ q=r;
		  if(p>q)
			  p=q;
		}
		for(i=0;i<q;i++)
		{ j=binary_searcha(a,b[i],0,i);
		  k=binary_searchc(c,b[i],i,r-1);
		//  printf("%ld %ld\n",j,k);
		  if(j==0 && k!=-1)
			cnt+=1*(r-k);
		  else if(j!=-1 && k!=-1)
			  cnt+=(j+1)*(r-k);
		}
		printf("%ld\n",cnt);
	}
return 0;
}
long int binary_searchc(long int a[],long int no,long int fi,long int la)
{ long int mid,posi=-1;
	while(fi<=la)
	{ mid=(fi+la)/2;
		if(a[mid]<no)
			fi=mid+1;
		else
		{	la=mid-1;
			posi=mid;
		//	printf("%ld ",posi);
		}
	}
	//printf(" %ld\n",posi);
return posi;
}
long int binary_searcha(long int a[],long int no,long int fi,long int la)
{ long int mid,posi=-1;
	while(fi<=la)
	{ mid=(fi+la)/2;
	  if(a[mid]>no)
	  	la=mid-1;
	  else
	  {    fi=mid+1;
		posi=mid;
	  }
	}
return posi;
}  	  
