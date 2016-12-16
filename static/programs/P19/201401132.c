#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[10];
int flag,i;

typedef struct node{
	int count;
	struct node *a[10];
}node;
node *head;
void insert(int l,node* head)
{
	node *temp=head;
	int k,d;
	for(d=0;d<l;d++)
	{
		if (temp->a[s[d]-'0']==NULL)
		{
			node *newnode=(struct node *)malloc(sizeof(struct node));
			newnode->count=0;
			for(k=0;k<10;k++){
				newnode->a[k]=NULL;
			}

			temp->a[s[d]-'0']=newnode;
			temp->count=temp->count+1;
			//printf("i=%dcount=%d\n",i,newnode->count);
			temp=temp->a[s[d]-'0'];

		}
		else
		{
			temp->count=temp->count+1;
			temp=temp->a[s[d]-'0'];
		}
	}
	return;
}
void check(node* head)
{
	int j,p=0;
	if(head==NULL)
		return;

	for(j=0;j<10;j++)
	{

		if(head->a[j]!=NULL)
		{
			p=p+head->a[j]->count;
			if(head->a[j]->count==0){
				p=p+1;
			}
	//		printf("g");
		}
	}
	if(head->count!=p)
	{
		flag=1;
	}
	for(j=0;j<10;j++){

		check(head->a[j]);
	}

/*	for(j=0;j<10;j++){
			check(head->a[i]);
	

	}*/
}
int main(){
	int t,l,k;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		head=NULL;
		head=(struct node *)malloc(sizeof(struct node));
		head->count=0;
		for(k=0;k<10;k++){
			head->a[k]=NULL;
		}
		while(n--){
			scanf("%s",s);
			l=strlen(s);
			insert(l,head);
		}
		flag=0;
		check(head);
		if(flag==1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}


