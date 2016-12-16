#include<stdio.h>
#include<stdlib.h>
#define size 200005
#define mod 1000000007

int min[size],max[size],lend=0,rend=0;

void show(int a[],char c)
{
    int i,end;
    if(c=='l')
	end=lend;
    else
	end=rend;
    for(i=1;i<=end;i++)
        printf("  %d\n",a[i]);
    printf("\n");
}

void rin(int number)
{   
    min[++rend]=number;
    int cur=rend,temp;
    while((cur/2)>=1 && min[cur/2] > number)
    {
	temp=min[cur];
        min[cur]=min[cur/2];
	min[cur/2]=temp;
        cur/=2;
    }
//    printf("minheap - \n");
//    show(min,r);
}

void lin(int number)
{   
    max[++lend]=number;
    int cur=lend,temp;
    while((cur/2)>=1 && max[cur/2] < number)
    {
	temp=max[cur];
        max[cur]=max[cur/2];
	max[cur/2]=temp;
        cur/=2;
    }
//    printf("maxheap - \n");
//    show(max,l);
}

void rdel()
{
//    printf("deleting %d\n",min[1]);
    min[1]=min[rend];
    rend--;
    int cur=1;
    while(cur<=rend/2 && (min[cur]>min[cur*2] || min[cur]>min[(cur*2)+1]))
    {
	int index,temp;
	if((cur*2)+1>rend)
	    index=cur*2;
	else
	    index=min[cur*2]<=min[(cur*2)+1]?cur*2:((cur*2)+1);
	//printf("swp ind -  %d<---> %d\n",cur,index);
	temp=min[cur];
	min[cur]=min[index];
	min[index]=temp;
//	cur*=2;
	cur=index;
    }
}

void ldel()
{
//    printf("deleting %d\n",max[1]);
    max[1]=max[lend];
    lend--;
    int cur=1;
    while(cur<=lend/2 && (max[cur]<max[cur*2] || max[cur]<max[(cur*2)+1]))
    {
	int index,temp;
	if((cur*2)+1>lend)
	    index=cur*2;
	else
	    index=max[cur*2]>=max[(cur*2)+1]?cur*2:((cur*2)+1);
//	printf("swp ind -  %d<---> %d\n",cur,index);
	temp=max[cur];
	max[cur]=max[index];
	max[index]=temp;
//	cur*=2;
	cur=index;
    }
}

void check()
{
//    printf("in chk() lend=%d, rend=%d\n",lend,rend);
    if(lend==rend)
    {
//	printf("equal\n");
	return;
    }
    else
    {
	if(rend==lend+1)//right is one more
	{
//	    printf("r=l+1\n");
	    int temp;
	    temp=min[1];
	    rdel();
	   // printf("lin(%d)\n",temp);
	    lin(temp);
	}
	else if(lend==rend+2)
	{
//	    printf("l=r+2\n");
	    int temp;
	    temp=max[1];
	    ldel();
	   // printf("rin(%d)\n",temp);
	    rin(temp);
	}
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
	lend=0;rend=0;
	long long int a,b,c,n,mi,i;
	long long int sum;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	if(n==1)
	{
	    printf("1\n");
	    continue;
	}
	mi=1;
	sum=1;
	lin(1);
	for(i=2;i<=n;i++)
	{
//	    printf("%lld %lld\n",i,mi);
	  //  show(max,'l');
	    //show(min,'r');
	    long long int number;
	    long long int one,two,three;
	    one=(a*mi)%mod;
	    two=(b*i)%mod;
	  //  printf("b*i=%lld\n",(b*i));
	    three=c%mod;
	  //  printf("one=%lld two=%lld three=%lld\n",one,two,three);
	    number=((one+two)%mod+three)%mod;
//	    number=((a*mi)%mod+(b*i)%mod+c%mod)%mod;//F[i]
	//    printf("number=%lld\n",number);
	    sum+=number;
	    if(max[1]>=number)
	    {
	//	printf("adding to left\n");
	//	printf("lin\n");
		lin(number);
	    }
	    else
	    {
	//	printf("adding to right\n");
		//printf("rin\n");
		rin(number);
	    }
	    check();
	    mi=max[1];
	}
	printf("%lld\n",sum);
    }
    return 0;
}
