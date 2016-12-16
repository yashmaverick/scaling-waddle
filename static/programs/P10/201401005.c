#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct buffer{
	char s[1001];
	struct buffer *next;
} Buffer;

Buffer *front = NULL;
Buffer *rear = NULL;
int count = 0;

void print(){
	Buffer *current;
	current = front;
	int i;
	while(current != NULL){
		printf("%s\n", current->s);
		current = current->next;
	}
}

void add_buffer(char *str, int n){
	int i;
	Buffer *temp, *head;
	temp = (Buffer*)malloc(sizeof(Buffer));
	strcpy(temp->s, str);
/*	i = 0;
	while(str[i] != '\0'){
		temp->s[i] = str[i];
		i++;
	}
	temp->s[i+1] = '\0';
*/	temp->next = NULL;

	if(n == 0)
		return ;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		count++;
	}
	else if(count < n){
		rear->next = temp;
		temp->next = NULL;
		rear = temp;
		count++;
	}
	else{
		rear->next = temp;
		temp->next = NULL;
		rear = temp;
		head = front;
		front = front->next;
		free(head);
	}
}

void rem_buffer(){
	Buffer *temp;
	if(front==NULL && rear==NULL){
		count = 0;
		return ;
	}
	else if(front==rear && front!=NULL && rear!=NULL){
		temp = front;
		front = NULL;
		rear = NULL;
		free(temp);
		count = 0;
	}
	else{
		temp = front;
		front = front->next;
		free(temp);
		count--;
	}
}

int main(){
	int n, x, i;
	char c, str[1001];
	scanf("%d", &n);
	
	while(1){
		scanf("%c", &c);
		if(c == 'A'){
			scanf("%d", &x);
			for(i=0; i<x; i++){
				scanf("%s", str);
				add_buffer(str, n);
			}
		}
		else if(c == 'R'){
			scanf("%d", &x);
			for(i=0; i<x; i++){
				rem_buffer();
			}
		}
		else if(c == 'L')
			print();
		else if(c == 'Q')
			return 0;
	}
	return 0;
}
