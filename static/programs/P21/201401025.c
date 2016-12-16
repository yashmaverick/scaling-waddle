#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
	long long int value;
	long long int length;
	struct node *next;
}node;

node * arr[100001];

node * insert(int value,node* root,int length)
{
	node* temp=(node *)malloc(sizeof(node));
	temp->value=value;
	temp->length=length;
	temp->next=root;
	return temp;
}

typedef struct heap
{
	long long int value;
	long long int dist;
}heap;

heap min_heap[1000001];

long long int min_end=0;
long long int checked[100001];


void min_insert(long long int value,long long int dist)
{
	min_end++;

	min_heap[min_end].value=value;
	min_heap[min_end].dist=dist;

	long long int c,f;
	heap temp;

	c=min_end;
	f=c/2;
	while(min_heap[f].dist>min_heap[c].dist)
	{
		if(f<1)
			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[c];
		min_heap[c]=temp;

		c=f;
		f=c/2;
	}
}


void insert_new(long long int value,long long int dist)
{
	min_end++;

	min_heap[min_end].value=value;
	min_heap[min_end].dist=dist;

}

void delete_min()
{

	//cout<<"in delete ------"<<min_heap[min_end].value<<endl;
	checked[min_heap[1].value]=-1;

	min_heap[1]=min_heap[min_end];

	min_end--;

	long long int f,c1,c2,small,tmp;
	heap temp;

	f=1;
	c1=f*2;
	c2=f*2+1;

	if(c2>min_end)
		min_heap[c2].dist=INT_MAX;

	while(min_heap[f].dist > min_heap[c1].dist || min_heap[f].dist > min_heap[c2].dist )
	{
		if(c1>min_end)
			break;

		//if(c2<=min_end)
		//		{
		if(min_heap[c1].dist > min_heap[c2].dist )
			small=c2;
		else
			small=c1;
		//		}
		//		else if(min_heap[f].dist > min_heap[c1].dist )
		//			small=c1;
		//		else
		//			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[small];
		min_heap[small]=temp;

		f=small;
		c1=f*2;
		c2=f*2+1;
		if(c2>min_end)
			min_heap[c2].dist=INT_MAX;

	}
}


void djk(node* u,long long int x,long long int distance[])
{
	long long int u_value,u_length;

	while(u)
	{
		u_value=u->value;

	//	cout<<"u_value  :"<<u_value<<endl;
		u_length=u->length;

		if(checked[u_value]!=-1)
		{


			//		cout<<"in djk min_heap[1]:"<<min_heap[1].dist<<"   u_value:"<<u_value<<"    u_length"<<u_length<<"   min_heap[u_value].dist:"<<min_heap[u_value].dist<<endl<<endl;

	//		cout<<"initial   :  ";
	//		cout<<"min_heap.dist"<<distance[u_value]<<endl;

	//		cout<<"u_length : "<<u_length<<"min_heap[1].dist  : "<<distance[x]<<endl;

			if( distance[x] + u_length  <  distance[u_value] )
			{
				distance[u_value] = distance[x] + u_length;

	//			cout<<"updated  : "<<distance[u_value]<<endl;

				min_insert(u_value,distance[u_value]);
			}

	//		cout<<"after   :  ";
	//		cout<<"  u_value :"<<u_value<<"    min_heap.dist"<<distance[u_value]<<endl;
		}
		//cout<<"val"<<u_value<<" ";
		//cout<<"len"<<u_length<<" ";
		u=u->next;
	}
}


int main()
{
	long long int n,i,j,t,x,y,w,m;
	long long int a,distance[100001];

	//cin>>n>>m;
	scanf("%lld%lld",&n,&m);

	a=1;

	for(i=1;i<=m;i++)
	{
		//cin>>x>>y>>w;
		scanf("%lld%lld%lld",&x,&y,&w);

		arr[x]=insert(y,arr[x],w);
	//	arr[y]=insert(x,arr[y],w);
	}

	//cin>>x;
	scanf("%lld%lld",&x,&y);

	distance[x]=0;

	for(i=1;i<=n;i++)
	{
		if(i!=x)
			distance[i]=INT_MAX;
	}

	insert_new(x,0);

	for(i=1;i<=n;i++)
	{
		if(i!=x)
			insert_new(i,INT_MAX);
	}

	long long int count=1;


	//	for(i=1;i<=n;i++)
	//		cout<<"val"<<min_heap[i].value<<"      "<<"dist"<<min_heap[i].dist<<endl;

	while(count!=n)
	{
		count++;

		x=min_heap[1].value;

	//	cout<<endl<<"calling djk x:"<<x<<endl;

		//	cout<<"x"<<x<<" "<<"min_heap[x].dist"<<min_heap[1].dist<<endl;

		djk(arr[x],x,distance);
	//	cout<<endl;

//		cout<<"deleted heap:"<<min_heap[1].value<<"	"<<min_heap[1].dist<<endl;
		a++;
		
		if(min_heap[1].value==y)
			break;
		delete_min();
//		cout<<"YES"<<endl;
	}
	if(distance[y]==2147483647)
		printf("NO\n");
	else
	{
		printf("%lld\n",distance[y]);
	}


//	for(i=1;i<=n;i++)
//		cout<<"val :"<<min_heap[i].value<<"      "<<"dist"<<min_heap[i].dist<<endl;

//	cout<<"@!!!!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
//	for(i=1;i<=n;i++)
//		cout<<distance[i]<<endl;
	return 0;
}
