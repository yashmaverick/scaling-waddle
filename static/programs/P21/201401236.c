#include<stdio.h>
#include<stdlib.h>
long long int min(long long int f,long long int u)
{
	if(f<u)
		return f;
	else
		return u;
}
typedef struct arra
{
	struct link *new;
	struct link *itr;
	struct link *head,*r;
}arra;
typedef struct link
{
	long long int vl;
	struct link *next;
	long long int wei;

}link;
arra *jo;
long long int b[100004],top=2,dis[100004],visited[100004]={0},arvis[100004]={0},des;

void heapsort(long long int i)
{
	long long int y,c;
	top++;
	b[top]=i;
	y=top;
	while(y!=1&&dis[b[y]]<dis[b[y/2]])
	{
		c=b[y]; 
		b[y]=b[y/2];    
		b[y/2]=c;
		y=y/2;
	}
}
void heapdel()
{
	long long int y,c,tu;
	b[1]=b[top];
	top--;
	//j=j<<1;
	for(y=1;y*2<=top;y=tu)
	{

		tu=2*y; 
		if(tu<top&&dis[b[tu]]>dis[b[tu+1]])
			tu+=1;
		if(dis[b[y]]>dis[b[tu]])
		{
			c=b[y];
			b[y]=b[tu];
			b[tu]=c;
		}
}
}	
/*void heapsort(long long int a)
	  {
	  if(top<=0)
	  top=1;
	  array[top]=a;
	  long long int h,c;
	  h=top;
	  while(top>1)
	  {		
	  if(dis[array[top]]<dis[array[top/2]])
	  {
	  c=array[top/2];
	  array[top/2]=array[top];
	  array[top]=c;
	  top=top/2;	
	  }
	  else
	  break;

	  }	
	  top=h+1;
	  }	
	  void heapdel()
	  {
	  long long int g,c,e;
	  g=1;
	  top--;
	  array[g]=array[top];
	  while(g<top)
	  {
	//e=min(dis[array[2*g]],dis[array[2*g+1]]);
	if(dis[array[2*g]]>dis[array[2*g+1]])
	{
	if(dis[array[g]]>dis[array[2*g+1]])
	{
	c=array[g];
	array[g]=array[2*g+1];
	array[2*g+1]=c;
	}

	g=2*g+1;
	}	
	else 		
	{			
	if(dis[array[g]]>dis[array[2*g]])
	{
	c=array[g];
	array[g]=array[2*g];
	array[2*g]=c;
	}

	g=g*2;
	}		
	}

	}	*/
	void dijkstra(long long int i)
	{
		int r,k;
		if(visited[i]==0)
		{
			visited[i]=1;
			heapdel();
			//	for(r=1;r<top;r++)
			//	printf("del:%d ",array[r]);		
			//	printf("%d",top); 
			//	printf("\n");
			while(jo[i].head!=NULL)
			{
				if(visited[jo[i].head->vl]==0)
				{
					if(dis[jo[i].head->vl]>jo[i].head->wei+dis[i])
						dis[jo[i].head->vl]=jo[i].head->wei+dis[i];
					if(arvis[jo[i].head->vl]==0)
					{
						heapsort(jo[i].head->vl);
						//		for(k=1;k<top;k++)
						//		printf("insert :%d ",array[k]);				
						//		printf("\n");
						arvis[jo[i].head->vl]=1;
					}
				}
				jo[i].head=jo[i].head->next;
			}	
			//prlong long intf("array :%d\n",array[1]); 
			dijkstra(b[1]);
		}	
	}
	long long int count=0,ans=0;
	int main()
	{
		long long int test;
		//	scanf("%d",&test);
		//	while(test--)
		//	{
		long long int  x,y,i,n,m,j,we,so;
		for(i=1;i<100004;i++)
		{
			visited[i]=0;
			dis[i]=1000000000000000000;	

		}
		dis[0]=1000000000000000000;
		scanf("%lld %lld",&n,&m);
		jo=malloc(sizeof(arra)*100004);
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&x,&y,&we);
			jo[x].new=malloc(sizeof(link));
			jo[x].new->vl=y;
			jo[x].new->wei=we;
			if(jo[x].head==NULL)
			{
				jo[x].head=jo[x].new;
				jo[x].itr=jo[x].new;
				jo[x].r=jo[x].new;
			}
			else
			{
				jo[x].itr->next=jo[x].new;
				jo[x].itr=jo[x].itr->next;

			}
		}
		for(i=0;i<100005;i++)
			arvis[i]=0;
		scanf("%lld %lld",&so,&des);
		dis[so]=0;
		dijkstra(so);
		if(dis[des]==1000000000000000000)
			printf("NO\n");
		else
			printf("%lld\n",dis[des]);
		//	}
		return 0;
	}
