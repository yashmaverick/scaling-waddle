#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct graph
{
	int value;
	int weight;
	struct graph *next;
}node;
node *p[100001];
long int dist[100001];
int visited[100001];
long int c[100010];
long int twod [100001][2];
int z;
void swap( long int  *a , long int *b)
	
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
void insertminheap (  int  y,int x)

{
	 int  k;
        z++;
	k=z;
	twod [z][0]=y;
	twod [z][1]=x;
	c[x]=z;
	while(k > 1)
	{
		if(twod [k/2][0] > twod[k][0])
		{
			swap(& twod [k][0],&twod[k/2][0]);
			swap(& twod [k][1] , &twod[k/2][1]);
			swap(& c[twod [k][1]] , & c[twod[k/2][1]]);

			k=k/2;
		}
		else
			break;
	}
}
int  deleteminheap()
{
	 int  e= twod [1][1];
	swap(&twod [1][0],&twod[z][0]);

	swap(&twod [1][1],&twod[z][1]);
	swap(&c[twod [1][1]],&c[twod[z][1]]);
	 int  k=1;
       twod [z][0]=10000000000000009;
       twod [z][1]=100001;
        c[twod[z][1]]=100001;
	z--;
	while(2*k<=z)
	{
		if(twod [2*k][0] < twod[2*k+1][0])
		{
			if(twod [2*k][0] < twod[k][0])
			{
				swap(&twod [2*k][0],&twod[k][0]);

				swap(&twod [2*k][1],&twod[k][1]);
				swap(&c[twod [2*k][1]],&c[twod[k][1]]);
				k=k*2;
				     if(k > z)
				              break;
			}
			else
				break;
		}
		else if(twod [2*k+1][0]< twod[k][0])
		{
			swap(&twod [2*k+1][0],&twod[k][0]);

			swap(&twod [2*k+1][1],&twod[k][1]);
			swap(&c[twod [2*k+1][1]],&c[twod[k][1]]);

			k=2*k+1;
                        if(k > z)
				break;
		}
		else
			break;

	}
	return e;
}
void heapify(int x ,int y)
{

	 int  k;
//	z++;
	k=c[y];
	twod [k][0]=x;
	twod [k][1]=y;
//	c[x]=z;
	while(k > 1)
	{
		if(twod [k/2][0] > twod[k][0])
		{
			swap(& twod [k][0],&twod[k/2][0]);
			swap(& twod [k][1] , &twod[k/2][1]);
			swap(& c[twod [k][1]] , & c[twod[k/2][1]]);

			k=k/2;
		}
		else
			break;
	}
}





node* insert(int x,int y,node* root)
{
	node *tmp=malloc(sizeof(node));
	tmp->value=x;
	tmp->weight=y;
	tmp->next=root;
	return tmp;
}

int main()
{
	int t,i,j,k,l,m,n,v,e,u,a,b,w;
//	scanf("%d",&t);
//	while(t--)
//	{
		z=0;
		scanf("%d%d",&n,&e);
		for(i=1;i<=n;i++)
			p[i]=NULL;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			p[u]=insert(v,w,p[u]);
		}
		for(i=1;i<=n;i++)
		{
			node *tmp=malloc(sizeof(node));
			tmp->value=i;
			tmp->next=p[i];
			p[i]=tmp;
		}
		scanf("%d%d",&a,&b);
		for(i=1;i<=n;i++)
		{
			if(i!=a)

				dist[i]=10000000000000009;
			else
				dist[i]=0;
		}
		k=a;
		l=a;
		//		printf("%d\n",l);
		memset(visited , 0 , sizeof(int)*100001);

			memset(c , -1 , sizeof(long int)*100001);
	//	int cnt=0;
		while(1)
		{
	//		int fl=0;
	//		node *start=(node*)malloc(sizeof(node));
	//		start=p[k];
			while(p[k]->next!=NULL)
			{
			//	fl=1;
				p[k]=p[k]->next;
				if(p[k]!=NULL)
				{
					if(visited[p[k]->value]==0)
					{
						if(dist[k]+p[k]->weight < dist[p[k]->value])
						{
							dist[p[k]->value]=p[k]->weight + dist[k];
							//		printf("dist %d:%d\n",p[k]->zalue,dist[p[k]->value]);
							if(c[p[k]->value]==-1)
							{
								insertminheap(dist[p[k]->value],p[k]->value);

							}
							else if(c[p[k]->value]!=-1)
							{
								heapify(dist[p[k]->value] , p[k]->value);
							}

						}
					}
				}
			}

			j=deleteminheap();
	//		printf("%d\n",z);
			if(z==-1 ||  j==100001)
				break;

			visited[l]=1;
	//		printf("%d\n",dist[l]);
		//	cnt++;
			if(visited[b] == 1)
				break;
	//		if(min==1000000)
	//			break;
			//			if(fl==0)
			//				break;
			k=j;
			l=j;
			//			printf("fuck\n");
		}
		//	if(zisited[b]==0)
		//		printf("NO\n");
		if(dist[b]==10000000000000009)
			printf("NO\n");
		else

			printf("%ld\n",dist[b]);


//	}
	return 0;
}
