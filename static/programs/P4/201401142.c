#include<stdio.h>
typedef long long int LL;
struct pair{
	int first;
	int second;
};
char x[100002];
struct pair state[100002];
int siz;
void puut(int J,int M,int R)
{
	state[siz].first = J - M;
	state[siz].second = J - R;
	siz++;
	//printf("%d %d\n",state[siz].first,state[siz].second);
	return;
}
int cmpfunc (const void * a, const void * b)
{
	const struct pair *x = (const struct pair *)a;
	const struct pair *y = (const struct pair *)b;
	const int x1 = x->first;
	const int y1 = y->first;
	if(x1!=y1)
		return x1-y1;
	else
		{
			const int x2 =	x->second;
			const int y2 = y->second;
			return x2-y2;
		}
}
int main()
{
	LL i,t,result,J,M,R,count;
	scanf("%lld",&t);
	while(t--)
	{
		J = M = R = 0;
		siz = 1;
		count = 0;
		state[0].first = 0;
		state[0].second = 0;
		scanf("%s",x);
		for(i=0;x[i]!='\0';i++)
		{
			if(x[i]=='J')
				J++;
			else if(x[i]=='R')
				R++;
			else
				M++;
			puut(J,M,R);
		}
		qsort(state,siz,sizeof(struct pair),cmpfunc);
		struct pair q;
		q.first = state[0].first;
		q.second = state[0].second;
		result = count = 0;
	//	for(i=0;i<siz;i++)
	//		printf("%d %d\n",state[i].first,state[i].second);
		for(i=0;i<siz;i++)
			{
			if(q.first==state[i].first && q.second == state[i].second)
				{
				count+=1;
				}
			else
				{
					result += ((count*(count-1))/2);
					count = 1;
					q = state[i];

				}
			}
			result += ((count*(count-1))/2);
		printf("%lld\n",result);
	}
	return 0;
}
