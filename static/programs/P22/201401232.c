#include<stdio.h>
long long int size1,size2;
long long int heap1[1000001],heap2[1000001];
#define MOD 1000000007
void mincrt(long long int m);
long long int mincmprs();
void maxcrt(long long int m);
long long int maxcmprs();
long long int func(long long int answer);
long long int main()
{
	long long int test,answer,j;
	scanf("%d",&test);
	for(j=1;j<=test;j++){
		answer=0;
		answer=func(answer);
		printf("%lld\n",answer);
	}
	return 0;
}
void mincrt(long long int m)
{
	size1++;
	heap1[size1]=m;
	long long int j,temp;
	j=size1;
	while(j!=1 && heap1[j] < heap1[j>>1]){
		temp=heap1[j];
		heap1[j]=heap1[j>>1];
		heap1[j>>1]=temp;
		j=j>>1;
	}
}
long long int mincmprs()
{
	long long int tmp1,tmp0;
	tmp0=heap1[1];
	heap1[1]=heap1[size1];
	size1--;
	long long int tmp,size,j;
	for(j=1;(j<<1)<=size1;j=tmp){
		tmp=j<<1;
		if(tmp<size1&&heap1[tmp]>heap1[tmp+1]){
			tmp=tmp+1;
		}
		if(heap1[j]>heap1[tmp]){
			tmp1=heap1[j];
			heap1[j]=heap1[tmp];
			heap1[tmp]=tmp1;
		}
	}
	return tmp0;

}
void maxcrt(long long int m)
{
	size2++;
	heap2[size2]=m;
	long long int j=size2;
	long long int temp;
	while(j!=1 && heap2[j] > heap2[j>>1]){
		temp=heap2[j];
		heap2[j]=heap2[j>>1];
		heap2[j>>1]=temp;
		j=j>>1;
	}
}
long long int maxcmprs()
{
	long long int size1,tmp0;
	tmp0=heap2[1];
	heap2[1]=heap2[size2];

	size2--;
	long long int j,tmp,size,tmp1;
	for(j=1;(j<<1)<=size2;j=tmp){
		tmp=j<<1;
		if(tmp < size2 && heap2[tmp] < heap2[tmp+1]){
			tmp=tmp+1;
		}
		if(heap2[j] < heap2[tmp]){
			tmp1=heap2[j];
			heap2[j]=heap2[tmp];
			heap2[tmp]=tmp1;
		}
	}
	return tmp0;
}
long long int func(long long int answer)
{
	size2=size1=0;
	long long int top,pointer;
	top=1;
	long long int size,temp2,j,m,temp;
	long long int a,b,c,n,pp;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
	pointer=1;
	while(pointer<n){
		size=size1-size2;
		if(size1!=0 || size2!=0){
			temp=top;
				temp2=heap1[1];
			if(size==0){
				if(temp<temp2){
					maxcrt(temp);
				}
				else{
					mincrt(temp);
				}
			}
			else if(size==1){
				if(temp<temp2)
					maxcrt(temp);
				else{
				pp=mincmprs();
					mincrt(temp);
					maxcrt(pp);
				}
			}
			else{
				temp2=heap2[1];
				if(temp>=temp2){
					mincrt(temp);
				}

				else{
					pp=maxcmprs();
					maxcrt(temp);
					mincrt(pp);
				}
			}
		}
		else{
			mincrt(1);}
		size=size1-size2;
		pointer=pointer+1;
		if(size!=1){
		top = ((a*heap2[1])%MOD+(b*pointer)%MOD+c)%MOD;
		}
		else{
		top = ((a*heap1[1])%MOD+(b*pointer)%MOD+c)%MOD;
		}
		answer+=top;
		j++;
	}
	answer++;
	return answer; 
}



