#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>
#include<math.h>
#define PI M_PI
void update(int i);
int cmp(const void *a,const void *b);
int check(int i, int j);
struct node
{ 
	int b_a,c_b;
}array[1000001];
int a,b,c;
long long ans;
char s[1000001];
long long answer(int cnt)
{
	ans=ans+cnt*(cnt-1)/2;
	return ans;
}
int len;
int main()
{ 
	int i,j;
	int I,N;
	scanf("%d",&N);
	for(I=0;I<N;I++)
	{
		long long cnt=0;
		ans=0;
		scanf("%s",s);
		a=b=c=0;
		for(i=0;s[i];i++)
		{
			update(i);
		}
		array[i].b_a=b-a;
		array[i].c_b=c-b;
		len=i+1;

		qsort(array,len,sizeof(struct node),cmp);
		for(i=0;i<len;)
		{
			for(j=i+1;check(i,j);j++);
			cnt=j-i;
			ans=answer(cnt);
			i=j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
int check(int i, int j)
{
	if(j<len&&array[j].b_a==array[i].b_a&&array[j].c_b==array[i].c_b)
		return 1;
	else
		return 0;
}
void update(int i)
{
	array[i].b_a=b-a;
	array[i].c_b=c-b;
	if(s[i]=='J') 
		a++;
	else if(s[i]=='M')
		b++;
	else if(s[i]=='R')
		c++;
}
int cmp(const void *a,const void *b)
{       struct node *new=(struct node *)a;
	struct node *two=(struct node *)b;
	if(new->b_a==two->b_a) 
		return (new->c_b-two->c_b);
	else
		return (new->b_a-two->b_a);
}
