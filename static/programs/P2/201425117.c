#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int p,q,r,i;
		scanf("%d",&p);
		int A[p];
		for(i=0;i<p;i++)
			scanf("%d",&A[i]);
		scanf("%d",&q);
		int B[q];
		for(i=0;i<q;i++)
			scanf("%d",&B[i]);
		scanf("%d",&r);
		int C[r];
		long long int D[1000000]={0};
		for(i=0;i<r;i++)
			scanf("%d",&C[i]);
		int a=0,b=0,c=0;
		while(a<p && b<q)
		{
			if(A[a]<=B[b] && a<=b)
			{
				a++;
			}
			else{
				D[b]=a;
				++b;
			}
		}
		while(b<q){
			if(p<q)
				D[b]=p;
			else 
				D[b]=q;
			b++;
		}
		for(i=0;i<q-1;i++)
		{
			D[i+1]+=D[i];
		}
		b=0;
		long long landuri=0;
		while(b<q && c<r)
		{
			if(B[b]<=C[c] && b<=c)
			{
				b++;
			}
			else{
				if(b>0)
					landuri+=D[b-1];
				c++;
			}
		}
		while(c<r){
			if(q<r)
				landuri+=D[q-1];
			else
				landuri+=D[r-1];
			c++;
		}
		printf("%lld\n",(long long)landuri);
	}
	return 0;
}
