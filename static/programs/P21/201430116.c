#include<stdio.h>
#include<stdlib.h>
# define max 10000000
struct list
{
	int data;
	int dist;
	struct list *nxt;
};
typedef struct list element;
typedef element *link;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void shuffledown(int hp[],int p,int end,int pos[],link a[])
{
     int i,j;
     i=2*p;
     while(i<end&&((a[hp[p]]->dist)>(a[hp[i]]->dist)||(a[hp[p]]->dist)>(a[hp[i+1]]->dist)))
     {
     	if((a[hp[i]]->dist)<(a[hp[i+1]])->dist){
     		swap(&hp[i],&hp[p]);
     		pos[hp[i]]=i;
     		pos[hp[p]]=p;
     		p=i;
     		i=2*p;
     	}
     	else{
     		swap(&hp[i+1],&hp[p]);
     		pos[hp[i+1]]=i+1;
     		pos[hp[p]]=p;
     		p=i+1;
     		i=2*p;
     	}
     }

}
void deletemin(int hp[],int *end,int pos[],link a[]){
	pos[hp[1]]=9;
	hp[1]=hp[(*end-1)];
	pos[hp[1]]=1;
	(*end)--;
    shuffledown(hp,1,(*end),pos,a);
}
/*void check(int hp[],int j,int pos[],link a[],int end)
{
	int left,right,temp;
	left=2*j;
	right=2*j+1;
	if((left<=end)&&(a[hp[left]]->dist)<(a[hp[j]]->dist))
		temp=left;
	if((right<=end)&&(a[hp[right]]->dist)<(a[hp[j]]->dist))
		temp=right;
	if(temp!=j)
	{
		swap(&hp[temp],&hp[j]);
		pos[hp[temp]]=temp;
     	pos[hp[j]]=j;
     	check(hp,temp,pos,a,end);
	}
}*/
int main()
{
//	int sw,z;
//	scanf("%d",&sw);
//	for(z=0;z<sw;z++)
//	{
	int vertices,edges,i;
	scanf("%d %d",&vertices,&edges);
	link *a;
	int *d,*pos,*hp;
	a=malloc((vertices+1)*sizeof(link));
//	d=malloc((vertices+1)*sizeof(int));
	pos=malloc((vertices+1)*sizeof(int));
	hp=malloc((vertices+1)*sizeof(int));
	for(i=1;i<=vertices;i++)
	{
		a[i]=malloc(sizeof(element));
		a[i]->data=i;
		a[i]->dist=max;
		a[i]->nxt=NULL;
//		d[i]=max;
		pos[i]=-1;
	}
	int v1,v2,w;
	for(i=1;i<=edges;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		link temp;
		temp=malloc(sizeof(element));
		temp->data=v2;
		temp->dist=w;
		temp->nxt=a[v1]->nxt;
		a[v1]->nxt=temp;
	}
//	link temp3;
/*	for(i=1;i<=vertices;i++)
	{
		temp3=a[i];
		while(temp3!=NULL){
			printf("%d ",temp3->data);
			temp3=temp3->nxt;
		}
		printf("\n");

	} */
	
	int s1,s2,end,k,j;
	scanf("%d %d",&s1,&s2);
//	d[s1]=0;
	a[s1]->dist=0;
	link temp2,min;
//	min=a[s1];
//	temp2=a[s1]->nxt;
	end=2;
	pos[s1]=1;
	hp[1]=a[s1]->data;
	while(end>1)
	{
//		printf("hp[1] %d\n",hp[1]);
			temp2=a[hp[1]]->nxt;
		//	if(hp[1]==s2)
		//		break;
		while(temp2!=NULL)
		{
			if(pos[temp2->data]==-1)
			{
				(a[temp2->data]->dist)=a[hp[1]]->dist+temp2->dist;
		//		printf("%d %d\n",temp2->data,a[temp2->data]->dist);
				hp[end]=temp2->data;
				pos[temp2->data]=end;
				end++;
				j=end-1;
       			k=j/2; // hp mei vrtx
       			while(k>0&&(a[hp[k]]->dist)>(a[hp[j]]->dist))
       			{
       	  			swap(&hp[j],&hp[k]);
       	  			pos[hp[j]]=j;
       	  			pos[hp[k]]=k;
          			j=k;
          			k=j/2;
       			}  
			}
			else if(pos[temp2->data]!=0) // 0 mean its have been deleted
			{
				if((a[temp2->data]->dist)>(a[hp[1]]->dist+temp2->dist))
				{
					a[temp2->data]->dist=a[hp[1]]->dist+temp2->dist;
					j=pos[temp2->data];
       				k=j/2; // hp mei vrtx
       				while(k>0&&(a[hp[k]]->dist)>(a[hp[j]]->dist))
       				{
       	  				swap(&hp[j],&hp[k]);
       	  				pos[hp[j]]=j;
       	  				pos[hp[k]]=k;
          				j=k;
          				k=j/2;
       				} 
				}  
				
			}
			temp2=temp2->nxt;
		}
	//	printf("hp%d\n", );
	/*	for(j=1;(j)<end;j++)
		{
			//check(hp,j,pos,a,end-1);
			printf("%d ",hp[j]);
		}
		printf("\n"); */
		deletemin(hp,&end,pos,a);
	}

	if(a[s2]->dist==max)
		printf("NO\n");
	else
		printf("%d\n",a[s2]->dist);
//	}	
	return 0;
}