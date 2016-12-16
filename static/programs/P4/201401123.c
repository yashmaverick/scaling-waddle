#include<stdio.h>
typedef int lll;
#define s(n) scanf("%d",&n)
/*
int cmp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
*/
   void merge(lll *a, lll start, lll mid, lll end){
   lll i=0,ll=mid-start+1, lr=end-mid, lmax=ll+lr, j=0,k=0, left[ll], right[lr];
   for(i=0;i<ll;i++)
   left[i]=a[i+start];//copy the values indexed from start to mid to left
   for(i=0;i<lr;i++)
   right[i]=a[i+mid+1];//copy the values indexed from mid to end to right
   i=start;  //reinitialising
   while(j<ll && k<lr){
   if(left[j]<=right[k])
   a[i++]=left[j++];
   else
   a[i++]=right[k++];
   }
//to copy the remnants to array a:
while(j<ll)
a[i++]=left[j++];
while(k<lr)
a[i++]=right[k++];
}
void mergesort(lll *a, lll start, lll end){
lll mid;
if(start<end)
{
mid=start + (end-start)/2;//to avoid overflow 
mergesort(a,start,mid);//left
mergesort(a,mid+1,end);//right
merge(a,start,mid,end);//left+right
}
}

int main(){
	lll c,t;
	lll count[100001],j;
	s(t);
	lll T=t;
	while(t)
	{
		if(t==T)//for second + t's
			getchar();//to prevent first \n after scanning t
		lll i = 1;
		count[0]=0;
	       	//initialisation of zero-th index 
		char s[100001];
	//	while((c=getchar())!='\n')
		scanf("%s",s);
		for(i=1;s[i-1]!='\0';i++)
		{
			if(s[i-1]=='J')
				count[i]=count[i-1]+100000;//random values attached, they need to be well spaced so rarely they may 'collide'
			else if(s[i-1]=='M')
				count[i]=count[i-1]+1;
			else if(s[i-1]=='R')
				count[i]=count[i-1]-100001;
		}
	//	for(j=0;j<i;j++)
	//		printf("%d ",count[j]);
	//	putchar('\n');
	mergesort(count,0,i-1);
//		qsort(count,i,sizeof(int),cmp);
	//	for(j=0;j<i;j++)
	//		printf("%d ",count[j]);
	//	putchar('\n');
		lll ans = 0;
		lll repeat_count=1;//start counter from 1, |||ly as zero-th index was init-ed to 0
		count[i]=0;
		for(j=0;j<i;j++)
		{
			if(count[j+1]==count[j])
				repeat_count++;
			if(repeat_count>1 && count[j+1]!=count[j])
			{
				ans = ans + ( repeat_count*(repeat_count-1) )/2;//nC2
				repeat_count=1;
			}
		}
		printf("%d\n",ans);t--;
	}return 0;
}
