/*
 * i
 *  trie.cpp
 *  2015 umeshksingla <umeshksingla@umeshksingla-SVF15215SNW>
 */

//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
#include<string.h>

//using namespace std;
struct node{
	char d;
	int fl;
	struct node*s[15];
};

typedef struct node node;

char n[100];
int l;
/*
void print(node*root){
	if(root==NULL){
		return;	
	}
	//	cout<<root->d<<" ";
	//	cout<<root->fl<<" ";
	//	cout<<endl;
	for(int j=0;j<15;j++){
		if(root->s[j]){
			print(root->s[j]);
		}
	}
}*/
int ans=0;
void insert(int i,node*root){
	/*
	   node*temp=head;
	   for(int i=0;n[i]!='\0';i++){
	   temp->s[n[i]-'0']=(node*)malloc(sizeof(node));
	   temp->s[n[i]-'0']->d=n[i];
	   cout<<temp->s[n[i]-'0']->d<<endl;
	   temp=temp->s[(n[i]-'0')];
	   }
	   */
	if(i==l){
		//int c=root->fl;
		root->fl=1;
		//cout<<"c "<<c<<endl;
		//cout<<root->fl<<endl;
		return;
	}
	if(root->s[n[i]-'0']==NULL){
		root->s[n[i]-'0']=(node*)malloc(sizeof(node));
	}
	else{
		if(i==l-1)
		{
			//		cout<<"YES\n";
			ans=1;
			return;
		}
	}
	root->s[n[i]-'0']->d=n[i];
	if(root->s[n[i]-'0']->fl==1){
		//	cout<<"yes\n";
		ans=1;
		return;
	}
	root->s[n[i]-'0']->fl=0;
	insert(i+1,root->s[n[i]-'0']);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		node*head;
		head=(node*)malloc(sizeof(node));
		head->d='-';
		head->fl=0;
		int k;
		scanf("%d",&k);
		while(k--){
			scanf("%s",n);
			l=strlen(n);
			insert(0,head);
			//		print(head);
		}
		//printf("ans=%d\n",ans);
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
		head=NULL;
	}
	return 0;
}
