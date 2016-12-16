#include<stdio.h>
#include<stdlib.h>
struct node{
	long long int data;
	long long int from;
	long long int to;
};
long long int a[100005]={0};
struct node b[1000005]={0};
long long int partition(long long int l,long long int r)
{
	long long int i,j;
	i=l;
	j=l-1;
	while(i<r)
	{
		if(b[i].data<b[r].data)
		{
			j++;
			struct node sw;
			sw=b[i];
			b[i]=b[j];
			b[j]=sw;
		}
		i++;
	}
	j++;
	struct node sw;
	sw=b[i];
	b[i]=b[j];
	b[j]=sw;
	return j;
}
void quicksort(long long int l,long long int r)
{
	long long int q;
	if(l>=r)
	{
		return ;
	}
	else
	{
		q=partition(l,r);
		quicksort(l,q-1);
		quicksort(q+1,r);
	}
}
long long int check(long long int ww)
{
	long long int x,y;
	x=b[ww].from;
	y=b[ww].to;
	if(a[x]==a[y])
	{
		return 0;
	}
	return 1;
}
long long int parent(long long int to)
{
	long long int l;
	if(a[to]==to)
	{
		return to;
	}
	return parent(a[to]);
}
void mst(long long int nn,long long int yy)
{
	long long int m,n;
	long long int w,ww,x,xx,zz;
	long long int y;
	w=0;
	ww=0;
	y=0;
	while(ww<yy)
	{
	//	if(w==nn-1)
	//	{
	//		break;
	//	}
		if(check(ww))
		{
			//printf("%lld\n",ww);
			a[b[ww].from]=parent(a[b[ww].to]);
			y=y+b[ww].data;
			w++;
		}
		if(w==nn-1)
		{
			break;
		}
		ww++;
	}
	if(w==nn-1)
	{
		printf("%lld\n",y);
	}
	else
	{
		printf("-1\n");
	}
	return ;
}
int main()
{
	long long int m,n;
	long long int mm,nn;
	long long int w,ww,x,xx,y,yy,z,zz;
	long long int u,uu,v,vv;
	//scanf("%lld",&n);
	//m=0;
	//while(m<n)
	//{
	//printf("YES\n");
	scanf("%lld%lld",&nn,&yy);
	u=0;
	while(u<=nn)
	{
		a[u]=u;
		u++;
	}
	xx=0;
	while(xx<yy)
	{
		scanf("%lld%lld%lld",&w,&x,&y);
		b[xx].data=y;
		b[xx].from=w;
		b[xx].to=x;
		xx++;
	}
	//printf("YES\n");
	quicksort(0,yy-1);
//	printf("---------\n");
//	for(xx=0;xx<yy;xx++){
//		printf("%lld %lld %lld\n",b[xx]);
//	}1
	//printf("YES\n");
//	mst(nn,yy);
	//m++;
	//}
	long long int father[100005],fl,sum=0,count=0,flag=0;
	for(fl=1;fl<=nn;fl++)
		father[fl]=fl;
	for(fl=0;fl<yy;fl++){
		a[fl]=fl+1;
		if(father[b[fl].from]!=father[b[fl].to]){
			sum=sum+b[fl].data;
			a[fl]=fl;
			count++;
			long long int adit,kk;
			adit=father[b[fl].from];
			a[fl]=a[fl]+1;
			for(kk=1;kk<=nn;kk++){
				if(father[kk]==adit)
					father[kk]=father[b[fl].to];
			}
		//	for(kk=1;kk<=nn;kk++){
		//		printf("%lld ",father[kk]);
		//	}
		//	printf("\n%lld %lld\n",sum,count);
		}
		if(count==nn-1){
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
