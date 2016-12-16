#include<stdio.h>
#include<stdlib.h>
int main()
{
	//scanning
	long long int f;
	long long int i,j,n;
	long long int mod;
	long long int *w,*num,*m;
	scanf("%d%d",&n,&mod);
	long long int *a[n];
	w=malloc(n*sizeof(long long int));
	num=malloc(n*sizeof(long long int));
        m=malloc(n*sizeof(long long int));
        for(f=0;f<n;f++)
	{
		w[f]=0;
		num[f]=f;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m[i]);
		


		a[i]=(long long int *)malloc((m[i])*sizeof(long long int));



              	for(j=0;j<m[i];j++)
		{
			scanf("%lld",&a[i][j]);
				w[i]=(w[i]+a[i][j])%mod;

		}
	}
	//sorting
	long long int x,y,t,e;
	for(x=0;x<n-1;x++)
	{
		for(y=0;y<n-1;y++)
		{
			if(w[y]>w[y+1])
			{
				t=w[y];
				w[y]=w[y+1];
				w[y+1]=t;

				e=num[y];
				num[y]=num[y+1];
				num[y+1]=e;
			}
		}
	}
	//printing
	long long int z,r,s,tmp;
        for(z=0;z<n;z++)
	{
		printf("%lld\n",w[z]);
		r=num[z];
		s=0;
		tmp=0;
		while(tmp<m[r] )
		{
//printf("r is %d s is %d\n",r,s);

			printf("%lld\n",a[r][s]);
				tmp=tmp+1;
			s=s+1;
		}
         printf("\n");  
	}
	return 0;
}
