//STACKS
#include<stdio.h>
#include<stdlib.h>
/*
struct node{
    long long int d;
    struct node*next;
};
typedef struct node node;
node*push(node*head,long long int k){
    node*temp=(node*)malloc(sizeof(node));
    temp->d=k;
    temp->next=head;
    head=temp;
    return head;
}
node*pop(node*head){
    if(head==NULL){
	//		printf("Erroro\n");
	return head;
    }
    node*temp=(node*)malloc(sizeof(node));
    temp->d=head->d;
    temp->next=NULL;
    head=head->next;
    free(temp);
    return head;
}
int top(node*head){
    if(head==NULL){
	//		printf("Errort\n");
	return 0;
    }
    return head->d;
}
*void print(node*head){
  if(head==NULL){
//		printf("Errorp\n");
return;
}
while(head!=NULL){
printf("%d ",head->d);
head=head->next;
}
printf("\n");
return;
}*/
/*int isempty(node*head){
    if(head==NULL)
	return 0;
    else
	return 1;
}*/
long long int st[1000005];
int main(){
    while(1){
//	node*head=NULL;
	//head=(node*)malloc(sizeof(node));
	long long int a[1000005];
	long long int stt,i,n,b,r,l,area=0;
	scanf("%lld",&n);
	if (n==0)
	    return 0;
	for(i=0;i<n;i++){
	    scanf("%lld",&a[i]);
	}
	long long int top=0;
	st[top]=0;
	top++;
	for(i=1;i<n;i++){
	    //		printf("current element=%d\nat start ",a[i]);
	    //		print(head);
	    while(top>0){
		if(a[i]>=a[st[top-1]]){
		    st[top]=i;
		    top++;
		    break;
		}
		else{                           //coz whenever element less than a[top stack] occurs, then we start calculating max area possible with previous larger elements or their combinations. Also,there is no possibility of their combination with further elements as some less number (current element) has already occured between them. As soon as element lesser than that occurs or stack empties, we push the current one and break;because lesser elements can again combine with coming elements to make a bigger rectangle and it is sure that the elements popped were larger than current element. 
		    stt=a[st[top-1]];
		    top--;
		    if(top==0){//means that you are at the minimum element occured till now. Here,'till now' justifies r to be i.
			l=0;
			r=i;
		    }

		    else{//
			l=st[top-1];
			r=i-1;
		    }
		    /*if(st==a[i])
		      r=i;
		      else
		      r=i-1;*/
		    //				printf(" %d*(%d-%d)\n",st,r,l);
		    b=stt*(r-l);
		    if(area<b)area=b;
		}
	    }
	    if(top==0){			//Whenever stack becomes empty we start afresh with max area upto that level already calculated.
		st[top]=i;
		top++;
	    }
	    //		printf("area=%d\n",area);
	    //		printf("at end ");
	    //		print(head);

	}
	//if elements are left in stack, it means there was no element greater than a[top(stack)]
	//elements left are in increasing order i.e. top(head) is max out of them 
	while(top!=0){

	    stt=a[st[top-1]];
	    top--;

	    if(top==0){
		l=0;
		r=i;
	    }
	    else{
		l=st[top-1];
		r=i-1;
	    }
	    //		printf("o%d*(%d-%d)\n",st,r,l);
	    b=stt*(r-l);
	    if(area<b)	area=b;
	}

	//	printf("earea=%d\n",area);
	printf("%lld\n",area);
    }
    return 0;
}
