#include<stdio.h>
#include<string.h>
#include<math.h>
int c[10009]={0};
void sieve()
{
	int i,j;
	for( i=2;i<=100;i++)
	{
		if(c[i]==0)
		{
			for( j=i*i;j<=10000;j+=i)
				c[j] = 1;
		}
	}
}

/*int power;
  int get(int num,int i){
  return num % (power * 10) / (power); 
  }
  int changenum(int num,int i,int d){
  power = (int)pow(10,i-1);
  return (num - get(num, i)*(power)) + d * power ;
  }*/
int main()
{
	//printf("%d\n",setDigit(4012,3,5));
	int n,p[10010],q[10010],r[10010],vi[10010],dist[10010],i,prime,top,tail,j,pop,inter,source,target,t,flag=0,s[5],w,k,npop;
	//scanf("%s",s);
	n = 9999;
	//memset(p,0,sizeof(p));
	//	memset(vi,0,sizeof(vi));
	//	memset(dist,0,sizeof(dist));
	prime = 2;
	int count = 0;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=n;i++)
			vi[i]=0;
		for(i=0;i<=n;i++)
			dist[i]=-1;
		scanf("%d%d",&source,&target);
		top = 0;
		tail =-1;
		dist[source]=0;
		q[++tail] = source;
		vi[source] = -1;
		flag=0;
		do
		{
			pop = q[top];
			if (pop == target)
			{
				dist[target] = dist[pop];
				printf("%d\n",dist[target]);
				break;
			}
			//npop = pop;
			//printf("%d",pop);
			/*w=3;
			while(npop)
			{
				s[w--] = npop%10;
				npop/=10;
			}*/
			for(i=3; i>=0;i--)
			{
				npop = pop;
				w = 3;
				while(npop)
				{
					s[w--] = npop%10;
					npop/=10;
				}
				//for(j=0;j<4;j++)
				//	printf("%d",s[j]);
				for(j=0;j<=9;j++)
				{
					if(j==0 && i==0)
						continue;
					s[i]=j;
					//	while(k<4){
					inter = s[0]*1000 + s[1]*100 + s[2]*10 + s[3];
					//	k++;
					//}
					//printf("%d ",inter);
					if (inter == target)
					{
						dist[target] = dist[pop]+1;
						printf("%d\n",dist[target]);
						flag=1;
						break;
					}
					if(vi[inter]==0 && c[inter]==0 && inter!=pop && dist[inter]==-1 && inter>=1000 )
					{
						vi[inter]=-1;
						q[++tail]=inter;
						dist[inter] = dist[pop] + 1;
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			top++;
			if(flag==1)
				break;
		}while(top<tail);
		if(dist[target]==-1  && source!=target)
			printf("Impossible\n");
	}
	return 0;
}

