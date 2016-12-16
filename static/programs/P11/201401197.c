#include<stdio.h>
#include<stdlib.h>

struct stak{
	int ind;
	int h;
	struct stak *next;
};

int pushin(int,int);
void freestak();
struct stak *head,*temp,*todel;
int main(){
	int n,i,j,k,lef[100005],rig[100005],ar[100005];
	long long maxarea,area;
	head=(struct stak *)malloc(sizeof(struct stak));
	head->next=NULL;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		for(i=0;i<n;i++){
			lef[i]=pushin(i,ar[i]);
		}
		freestak();
		for(i=n-1;i>=0;i--){
			rig[i]=pushin(i,ar[i]);
			if(rig[i]==-1){
				rig[i]=n;
			}
		}
		freestak();
		for(i=0,maxarea=0;i<n;i++){
			area=(long long)ar[i]*(long long)(rig[i]-lef[i]-1);
			if(area>maxarea){
				maxarea=area;
			}
		}
		printf("%lld\n",maxarea);
	}
	return 0;
}

int pushin(int ind,int h){
	temp=head;
	while(temp->next!=NULL&&temp->next->h>=h){
		todel=temp->next;
		temp->next=todel->next;
		free(todel);
	}
	todel=(struct stak *)malloc(sizeof(struct stak));
	todel->ind=ind;
	todel->h=h;
	todel->next=temp->next;
	temp->next=todel;
	if(todel->next==NULL){
		return -1;
	}
	else{
		return todel->next->ind;
	}
}

void freestak(){
	while(head->next!=NULL){
		todel=head->next;
		head->next=todel->next;
		free(todel);
	}
}
