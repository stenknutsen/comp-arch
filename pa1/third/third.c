#include "third.h"

//list of prototypes
struct node * new_node(int num);
void add(struct node *new);
void print_node(struct node *ptr);
void print_ll(struct node *ptr);
void insert(struct node *new);
void delete(int target);

//node struct
struct node {
	int data;
	struct node *next;
}*front = NULL, *curr = NULL;

//creates new node
struct node * new_node(int num){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL){
		return(struct node*) NULL;
	}else{
		ptr->data = num;
		ptr->next = NULL;
		return ptr;
	}
}

//print data from single node
void print_node(struct node *ptr){

printf("%d",ptr->data);
return;
}

//traverses to print entire list
void print_ll(struct node *ptr){
if(ptr==NULL){
printf("\n");
return;
}

print_node(ptr);

ptr = ptr->next;

while(ptr!=NULL){
	printf("\t");//print tab
	print_node(ptr);
	ptr = ptr->next;
	}
	return;
}

void insert(struct node *new){
	struct node *ptr, *prev;
	//if ll is empty, point fron to new node
	if(front==NULL){

		front=new;
		curr=new;
		return;
	}

	//point pointer at front of list
	ptr = front;

	//ifdata in first node is name as new data, then return
	if(ptr->data == new->data){
		return;
	}
	//if data in first node > data in new, make new first
	if(ptr->data > new->data){
		new->next = front;
		front = new;
		return;
	}

	//so now data isnt >= to first node. adv ptr, assign prev
	ptr = ptr->next;
	prev = front;

	while(ptr!=NULL){
		if(new->data <= ptr->data){
		//if data already in ll, return
		if(new->data == ptr->data){
			return;
		}else{
			//insert new node
			prev->next = new;
			new->next = ptr;
			return;
		}
	}

	ptr = ptr->next;
	prev = prev->next;
	}
	//insert at end
	
	prev->next = new;
	new->next = NULL;
	return;
}//end insert

void delete(int target)
{
	struct node *ptr, *prev;

	//if ll already empty, nothing to delete
	if(front==NULL){
		return;
	}

	//set ptr to front
	ptr = front;

	//if value of front in ll is target, point frontbat next item in ll
	if(ptr->data == target){
		front = ptr->next;
		return;
	}

	//so its not the first:lets start looking. . . . 
	//advance ptr, assign prev
	ptr = ptr->next;
	prev = front;


	while(ptr!=NULL){
		if(ptr->data == target){
			prev->next = ptr->next;
			return;
		}
		ptr = ptr->next;
		prev = prev->next;
	}
	return;

}

int main()
{
	FILE *fp;
	char filename[50];
	char line[50];
	
	fgets(filename, 50, stdin);

	//this removes newline from string
	int len = strlen(filename);
	if(len>0 && filename[len-1]=='\n'){
		filename[len-1]='\0';
		len = strlen(filename);
	}


	//make sure filename exists
	if((fp = fopen(filename, "r")) == NULL){
		
		printf("error\n");
	//	fclose(fp);possibly causing segmenttion error
		
		return 0;
	}

	//make sure thereis something in first line of file, else error
	if(fgets(line, 50, fp)==NULL){
		printf("error\n");
		return 0;
	}

	fclose(fp);

	fp = fopen(filename, "r");

	//validat file is in correct form
	while(fgets(line, 50, fp)!=NULL){
	//printf("printing line %s", line);
	//printf("printing char only %c\n",line[0]);

	if(line[0]!=105&&line[0]!=100){
		printf("error\n");
		return 0;
	}
	if(line[1]!=9){
		printf("error\n");
		return 0;
	}	
	}//end while loop


	fclose(fp);
//end file validation

	fp = fopen(filename, "r");
	char io;
	char charnum[30];
	int node_number;
	struct node *ptr;
	
	while(fgets(line, 50, fp)!=NULL){
		io = line[0];
		for(int i = 2, j = 0;i<30;i++,j++){
			charnum[j] = line[i];
		}
		node_number = atoi(charnum);
		if(io == 'i'){
			ptr = new_node(node_number);
			insert(ptr);
		}else{
			delete(node_number);
		}
	}
	fclose(fp);

	print_ll(front);
	printf("\n");
	//free all nodes in ll**added 9.23.2015***
	//
	//
	while(front!=NULL){
		ptr=front;
		front=front->next;
		free(ptr);
	}


	return 0;
}

