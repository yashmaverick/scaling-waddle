#include<stdio.h>
#include<stdlib.h>

void traverse();
void built_hp();
void rebuild_hp();
void update_hp();

typedef long long int ll;

typedef struct list{
	ll destination;
	ll weight;
	struct list *next;
}list;

list *arr[600005],*temp;
ll *dist,m,hp[100005],size=0,b[100005],t;

// array b is keeping index of heap elements , hp is heap's array , dist is dstance array
void swap(ll *x,ll *y){
	ll temp;
	temp=*y;
	*y=*x;
	*x=temp;
}

// insert function to the list arrays
list *insert(list *root,ll node1, ll node2 )
{
	list *tp=(list *)malloc(sizeof(list));
	tp->destination=node1;
	tp->weight=node2;
	tp->next=root;
	return tp;
}

// traverse and update the distance if required
void traverse(list *head,ll s)
{

	while(head!=NULL)
	{
//		printf("%lld %lld %lld %lld\n",dist[head->destination],dist[s],head->destination,s);
		if(dist[head->destination]==1000000000000000)
		{
//			printf("initialize\n");
			dist[head->destination]=head->weight+dist[s];	
			built_hp(head->destination);
		}

		else if((dist[s]+head->weight)<dist[head->destination])
		{
//			printf("Update\n");
			dist[head->destination]=(dist[s]+head->weight);
			update_hp(b[head->destination]);
				
		}
		head=head->next;
	}

/*	if(hp[1]==t)
		{
//			printf("milgya\n");
			return;
		}
*/
	if(arr[s]!=NULL)
	{
		rebuild_hp();
//		printf("first traverse of %lld done \n",s);
		traverse(arr[hp[1]],hp[1]);
	}
}

void rebuild_hp(){
hp[1]=hp[size];
	size--;

	ll xi=size,i=1,y=2;

	while(i<xi && y<=xi)
	{	
		if(dist[hp[i]]>dist[hp[y]] || dist[hp[i]]>dist[hp[y+1]])
		{
			if(dist[hp[y]]>dist[hp[y+1]] && y<xi)
			{
				swap(&hp[i],&hp[y+1]);
				b[hp[i]]=i;
				b[hp[y]]=y;
				i=y+1;
				y=i*2;
			}
			else
			{
				swap(&hp[i],&hp[y]);
				b[hp[i]]=i;
				b[hp[y]]=y;		
				i=y;
				y=i*2;	
			}

			
		}
		else
			break;
	}
}

void built_hp(ll i){
	size++;
	hp[size]=i;
	b[i]=size;
	ll y=size;
	while((dist[hp[y]]<dist[hp[y/2]]) && y>1)
	{
		swap(&hp[y],&hp[y/2]);
		b[hp[y/2]]=y/2;
		b[hp[y]]=y;
		y=y/2;
	}
}

void update_hp(ll y){

	while((dist[hp[y]]<dist[hp[y/2]]) && y>1)
	{
		swap(&hp[y],&hp[y/2]);
		b[hp[y/2]]=y/2;
		b[hp[y]]=y;
		y=y/2;
	}
}

int main()
{		
	ll n,s,i,j;
	scanf("%lld %lld",&n,&m);

	// taking vars of edges in respective list
	for(j=0;j<m;j++) //taking input in sorting order
	{
		scanf("%lld%lld%lld",&i,&s,&t);

		arr[i]=insert(arr[i],s,t);
	}

/*	temp=arr[1];
	while(temp!=NULL)
	{
		printf("%lld %lld\n",temp->destination,temp->weight);
		temp=temp->next;
	}

return 0;
*/
	scanf("%lld%lld",&s,&t);
	n++;

	dist=(ll *)malloc(sizeof(ll)*n);

	n--;
	for(i=0;i<=n;i++)
		dist[i]=1000000000000000;

	dist[s]=0;

	size=1;
	hp[1]=s;
	traverse(arr[s],s);

	if(dist[t]!=1000000000000000)
		printf("%lld\n",dist[t]);
	else
		printf("NO\n");
	return 0;
}