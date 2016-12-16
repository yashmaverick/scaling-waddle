#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
int flag=0;
int l_max,count=0,p;
struct node{
	int data;
	struct node *array[max];
}node;
struct node* root=NULL;
struct node* create(){
	int i;
	struct node *q=(struct node*)malloc(sizeof(struct node));

	for(i=0;i<max;i++)
		q->array[i]=NULL;

	q->data=-1;
	return q;
}

void insert(char key[]){
	int ht;
	int length=strlen(key);
	int index,ginti;
	if(root==NULL)
		root=create();

		ginti=0;
	struct node *q=root;
	for(ht=0;ht<length;ht++)
	{
//printf("%d\n",flag);
//printf("q->data:%d\n",q->data);

	if(q->data==-10)
		flag=1;
//printf("%d\n",flag);

		index=key[ht]-'0';
		if(q->array[index]!=NULL)
		ginti++;

		if(q->array[index]==NULL){
			q->array[index]=create();
//		printf("VIN");
		}
		
		q=q->array[index];
		
//		printf("ginti=%d\n",ginti);
	if( (count>1) && (ht+1==length) && (q->data==-1 || q->data==-10) && (ginti==length))
		{
//			printf("Vins\n");
			flag=1;
			}
//printf("q->data:%d\n",q->data);
	}
	q->data=-10;
}
/*void itoa(int n,char s[])
{
	if(n/10){
		itoa(n/10,s);
	}
	else{
		if(n<0)
			s[p++]='-';
	}
	s[p++]=abs(n)%10+'0';
	s[p]='\0';
}*/
int main(){
	int t,n,i,j,x,y,a;
	scanf("%d",&t);
	while(t--){
		l_max=0;
		scanf("%d",&n);
		count=0;
		p=0;
		flag=0;
		root=NULL;
		for(i=0;i<n;i++){
			char str[10];
			scanf("%s",str);
			p=0;
			count++;
			insert(str);
		}
		if(flag==1)
			printf("NO\n");

		else if(flag==0)
			printf("YES\n");
	}
	return 0;
}