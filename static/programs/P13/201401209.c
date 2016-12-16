#include<stdio.h>
long long int fanswer=1000001,max=0,n;
void finddepth(long long int* left,long long int* leftg,long long int* a,long long int root,long long int ul,long long int depth)
{
//	printf("%lld %lld %lld %lld\n",a[root],a[ul],depth,max);
	if(depth>max)  { max=depth; fanswer=a[root];}
	if(depth==max) if(a[root]<=fanswer) { fanswer=a[root];   }
	if(root==ul) return;
	if(left[root]>=ul)   finddepth(left,leftg,a,left[root],ul,depth+1);
	if(leftg[root]>=ul && left[root]+1>=ul)   finddepth (left,leftg,a,leftg[root],left[root]+1,depth+1);
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		long long int i;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		fanswer=a[n-1];max=0;
		long long int stack[n],sp=-1;
		long long int left[n];
		left[0]=-1;
		sp++;stack[sp]=0;
		for(i=1;i<n;i++)
		{
			while(1)
			{
				if(sp==-1) break;
				if(a[stack[sp]]>=a[i]) sp--;
				else break;
			}
			if(sp==-1) left[i]=-1;
			else left[i]=stack[sp];
			sp++; stack[sp]=i;
		}
	//	for(i=0;i<n;i++) printf("%lld ",left[i]); printf("\n");
		sp=-1;
		long long int leftg[n];
		leftg[0]=-1;
		sp++; stack[sp]=0;
		for(i=1;i<n;i++)
		{
			while(1)
			{
				if(sp==-1) break;
				if(a[stack[sp]]<=a[i]) sp--;
				else break;
			}
			if(sp==-1) leftg[i]=-1;
			else leftg[i]=stack[sp];
			sp++; stack[sp]=i;
		}
	//	for(i=0;i<n;i++) printf("%lld ",leftg[i]); printf("\n");
		finddepth(left,leftg,a,n-1,0,0);
		printf("%lld %lld\n",fanswer,max);
	}
	return 0;
}
