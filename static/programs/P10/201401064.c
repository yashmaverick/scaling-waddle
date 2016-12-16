#include <stdio.h>
#include <stdlib.h>

struct node {
	char value[1000];
	struct node *next;
};

void display(struct node *list, int current_size){
	//struct node *temp = list;
	//printf("now list %d \n", current_size);
	while(list != NULL){
		printf("%s\n", list->value);
		list = list -> next;
	}
	//printf("\n");
}

struct node *append(struct node *last){
	struct node * temp=(struct node *) malloc(sizeof(struct node));
	scanf("%s", temp->value);
//	printf("str = %s\n",temp->value);
//	&temp->value = value;
	temp->next = NULL;
	last->next = temp;
	return temp;
}

struct node *pop(struct node *root, int n){
	struct node *temp;

	while(n--){
	//	printf("poping value = %s\n",root->value );
		temp = root->next;
		free(root);
		root = temp;
		//free(root);
	}
	return root;
}



int main(int argc, char const *argv[])
{
	/* code */
	int size, flag=0, len;
	int current_size = 0;
	char str[1000];
	struct node *root;
	struct node *last;
	//root=(struct node *) malloc(sizeof *root);
	last=(struct node *) malloc(sizeof(struct node));
	char constraint, waste;
	scanf("%d",&size);
	//printf("n=%d\n",n );
	scanf("%c", &waste);
	while(1){
		scanf("%c", &constraint);
		switch(constraint){
			case 'A' :
				//printf("Append\n" );
				scanf("%c", &waste);
				scanf("%d", &len);
				scanf("%c", &waste);
				while(len--){
					if(current_size == size){
						current_size = current_size - 1;
						root = pop(root, 1);
					}
					last=append(last);
					if(flag == 0){
						flag = 2;
						root = last;
					}
					if(size>=current_size){
						current_size = current_size + 1;
					}
				}
				//printf("%s\n",root->value);
				//display(root, current_size);
				scanf("%c", &waste);
				break;
			case 'R' :
				//printf("pop\n" );
				scanf("%c", &waste);
				scanf("%d", &len);
				scanf("%c", &waste);
				if(len<=current_size){
					//	scanf("%s", &str);
					current_size = current_size - len;
					root=pop(root, len);
				}
				//printf("%s\n",root->value);
				//display(root, current_size);
				break;
			case 'L' :
				//printf("Display\n" );
				scanf("%c", &waste);
				display(root, current_size);
				break;
			case 'Q' :
				scanf("%c", &waste);
				flag = 1;
				//printf("Prefect input....GoodBye :)\n" );
				break;
			default :
				//printf("hehe =%c",constraint );
				printf("Invalid entry\n" );
		}
		if(flag==1)
			break;
	}

	return 0;
}


