#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[1000001][11],temp[1000001][11];
//int q,w,e,r,t,y,u,o,p;
typedef struct node node;
struct node{
	int c;
	struct node *b[10];
};
node *head[11];
node *create(int c)
{
	int r;
	node *temp=(node *)malloc(sizeof(node));
	temp->c=c;
	for(r=0;r<10;r++)
		temp->b[r]=NULL;
	return temp;
}
void mergeSort(int low,int mid,int high);
void partition(int low,int high);
void partition(int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(low,mid);
		partition(mid+1,high);
		mergeSort(low,mid,high);
	}
}

void mergeSort(int low,int mid,int high){
	int i,m,k,l;
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high)){
		if((strcmp(a[l],a[m]))<=0){
			strcpy(temp[i],a[l]);
			l++;
		}
		else{
			strcpy(temp[i],a[m]);
			m++;
		}
		i++;
	}
	if(l>mid){
		for(k=m;k<=high;k++){
			strcpy(temp[i],a[k]);
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			strcpy(temp[i],a[k]);
			i++;
		}
	}
	for(k=low;k<=high;k++){
		strcpy(a[k],temp[k]);
	}
}
/*int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}*/
node *insert(node *root,char a[])
{
	int i,j,k,l,h;
	int length=strlen(a)-1;
	node *temp=root;
	if(temp==NULL)
	{
		if(length==0)
		{
			return NULL;
		}
		root=create(a[0]-'0');
		temp=root;
		for(i=1;i<length;i++)
		{
			h=a[i]-'0';
			root->b[h]=create(h);
			root=root->b[h];
		}
		return temp;
	}
	for(i=1;i<length;i++)
	{
		h=a[i]-'0';
		if(root->b[h]==NULL)
			root->b[h]=create(h);
		root=root->b[h];
	}
	return temp;
}

int search(node *root,char api[])
{
	if(root==NULL)
		return 0;
	node *temp=root;
	int pk,jk=0;
	while(temp!=NULL)
	{
		pk=(int)api[jk]-'0';
		if(temp->c==pk)
		{
			jk++;
			if(api[jk]=='\0')
			{
				break;
			}
			pk=(int)api[jk]-'0';
			temp=temp->b[pk];
		}
		else{
			while(1){
				jk=213;
			}
			return 0;
		}
	}
	if(api[jk]=='\0')
	{
		return 1;
	}
	else
		return 0;
}


int main()
{
	int q;
	scanf("%d",&q);
	int i;
	while(q>0)
	{
		int w;
		scanf("%d",&w);
		int e;
		for(e=0;e<10;e++)
		{
			head[e]=NULL;
		}
		e=0;
		while(e!=w)
		{
			scanf("%s",a[e]);
			head[a[e][0]-'0']=insert(head[a[e][0]-'0'],a[e]);
			e=e+1;
		}
		q=q-1;
		partition(0,w-1);
		e=0;
		for(i=0;i<w-1;i++)
		{
			if((strcmp(a[i],a[i+1]))==0)
			{
				e=1;
				break;
			}
		}

		if(e!=1)
		{
			for(i=0;i<w;i++)
			{
				e=search(head[(int)a[i][0]-'0'],a[i]);
				if(e==1)
					break;
			}
		}
		if(e==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
