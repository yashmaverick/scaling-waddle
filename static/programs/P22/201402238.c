#include<stdio.h>
typedef long long int ll;
ll a,b,c,f[200005],min[200005],max[200005],last_median,xi=1,ni=0;

/* To be care actually min_heap=root==min max_heap=root==max , here we use opposite notation
*/
void swap(ll *x,ll *y){
	ll temp;
	temp=*y;
		*y=*x;
		*x=temp;

}
void rebuild_maxheap();
void rebuild_minheap();
void insert_maxheap();
void insert_minheap();



void weired(ll i){
	ll y=i-1;

	if(f[y]>=last_median)
	{	insert_maxheap(f[y]);
		if((xi-ni)>1)
		{
			
			insert_minheap(max[1]);	
			rebuild_maxheap();
			last_median=min[1];
//			printf("\n%lld %lld %lld\n",i,xi,ni);
		}
		else if(xi==ni)
			last_median=min[1];
		else
			last_median=max[1];
	}
	else
	{	insert_minheap(f[y]);
		if((ni-xi)>1)
		{
			insert_maxheap(min[1]);	
			rebuild_minheap();
			last_median=min[1];

		}
		else if(xi==ni)
			last_median=min[1];
		else
			last_median=min[1];	
	}
	f[i]=(a*last_median+(b*i)+c)%1000000007;
/*	printf("last_median of %lld = %lld\n",f[i],last_median );
*/
}

void insert_maxheap(ll i){
	xi++;
	ll y=xi/2,x=xi,temp;

	max[x]=i;
	while(max[x]<max[y] && x<=xi && y<xi)
	{
		swap(&max[y],&max[x]);	
		x=y;
		y=x/2;
	}
/*				printf("\nmax_heap :");
			ll u=1;
	while(u<=xi)
	printf("%lld ",max[u++] );
	printf("\nxi=%lld ni=%lld\n",xi,ni );
*/
}

void insert_minheap(ll i){
	ni++;
	ll y=ni/2,x=ni,temp;

	min[x]=i;
	while(min[x]>min[y] && x<=ni && y>=1 )
	{
		swap(&min[y],&min[x]);
		x=y;
		y=x/2;
	}
/*	printf("\nmin_heap :");
	
	ll u=1;
	while(u<=ni)
	printf("%lld ",min[u++] );
printf("\nxi=%lld ni=%lld\n",xi,ni );
*/
}

void rebuild_maxheap(){
	max[1]=max[xi];
	xi--;
	ll i=1,y=2;

	while(i<xi && y<=xi)
	{	
		if(max[i]>max[y] || max[i]>max[y+1])
		{
			if(max[y]>max[y+1] && y<xi)
			{
				swap(&max[i],&max[y+1]);
				i=y+1;
				y=i*2;
			}
			else
			{
				swap(&max[i],&max[y]);		
				i=y;
				y=i*2;	
			}

			
		}
		else
			break;
	}
/*	printf("\nre-max_heap :");
			ll u=1;
	while(u<=xi)
	printf("%lld ",max[u++] );
		printf("\nxi=%lld ni=%lld\n",xi,ni );
*/
}
void rebuild_minheap(){
	min[1]=min[ni];
	ni--;
	ll i=1,y=2;

	while(i<ni && y<=ni)
	{	
		if(min[i]<min[y] || min[i]<min[y+1])
		{
			if(min[y]>min[y+1])
			{
				swap(&min[i],&min[y]);
				i=y;
				y=i*2;
			}
			else
			{
				swap(&min[i],&min[y+1]);		
				i=y+1;
				y=i*2;	
			}
	
/*printf("\nre-mean_heap :");
			ll u=1;
	while(u<=ni)
	printf("%lld ",min[u++] );
		printf("\nxi=%lld ni=%lld\n",xi,ni );
*/
		}
		else
			break;
	}
}


int main()
{	ll t,n,y,sum,i;
	scanf("%lld",&t);
	while(t--)
	{	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		sum=0;
		last_median=max[1]=f[1]=1;
		f[2]=(a*max[1]+(b*2)+c)%1000000007; 

		i=3;
		xi=1;ni=0;
		while(i<=n)
			weired(i++);

//		printf("\n");
		for(y=1;y<=n;y++)
		{     //  printf("%lld ",f[y]);
//		        m[y]=0;        
			sum+=f[y];
		}
		printf("%lld\n",sum);	
		}	
return 0;
}