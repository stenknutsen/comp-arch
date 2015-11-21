#include "count.h"
#define LINE_SIZE 50
#define ARR_SIZE 1000//CHANGE THIS!!!!!!!!!!!!!!!!!!!!!!

long finalCount = 0;

//prototype list
//
struct node * create_node(unsigned long long num);
void insert(unsigned long long num);


struct node{
	unsigned long long data;
	struct node *next;
};

struct hash{
	struct node *head;
};

//intitialize pointer hashTable to NULL
struct hash *hashTable = NULL;

struct node * create_node(unsigned long long num){
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr == NULL){
		return(struct node *) NULL;
	}else{
		ptr->data = num;
		ptr->next = NULL;
		return ptr;
	}
}//end create_node

//takes dec, hashes: if already exists->nada; othrwise pleaces in ll and advances finalCount
//
//
void insert(unsigned long long num){
	
	int index;
	unsigned long long thingy = ARR_SIZE;
	index = num%thingy;
	
	if(hashTable[index].head == NULL){

		struct node *newnode = create_node(num);
		hashTable[index].head = newnode;
		finalCount++;
		return;
	}
	//not the first insertion; so iterate over ll and make sure no duplicates
	//
	//
	struct node *ptr;//create ptr
	ptr = hashTable[index].head;//point ptr at indexed head
	while(ptr!=NULL){
		if(ptr->data == num){
			return;//return without advancing count
		}
		ptr = ptr->next;//advance ptr
	}
	
	//at this point, no dups have been found, so go ahead and place node/advance finalCt
	//
	//
	struct node *newnode = create_node(num);
	newnode->next = hashTable[index].head;
	hashTable[index].head = newnode;
	finalCount++;//advance finalct for unique insertion
	
	return;

}//end insert

int main(int argc, char * argv[]){
	

	//open and validate file. . . . . . .
	//
	//
	FILE *fp;
	char filename[25];
	char line[LINE_SIZE];
	int x=0, y=0;
	
	//zero out filename array
	//
	for(x=0;x<25;x++){
		filename[x]=0;
	}

	
	//if no arguments taken at command line, print error
	//
	if ( argc != 2 ){
        printf( "error\n");
        return 0;
    }

	//copy filename in argv 1 to filename
	while((argv[1][y])!=0){

	filename[y]=argv[1][y];
		y++;
	
	}
	
		
	
	
	//start validation of file. . . . . 
	//
	//	
	//make sure valid filename. if not, print empty and return.
	if((fp = fopen(filename, "r"))==NULL){
		printf("error\n");
		
		return 0;
	}

	//check if file empty. if it is, print 0 and return.
	//
	if(fgets(line, LINE_SIZE, fp)==NULL){
		printf("0\n");
		return 0;
	}	
	//end of opening and validation of file. . . . . . . 

	//validation complete, open file
	fp = fopen(filename, "r");

	int hexnum[16];//array where hex chars converted to individual int values are stored
	int i, j, k;//just for loops and stuf
	unsigned long long dec;//will store the decimal equivalent that will be passed2table


	//allocate array of pointers and set all to null
	//
	//
	hashTable = (struct hash *) calloc(ARR_SIZE, sizeof(struct hash));
	for(i=0;i<ARR_SIZE;i++){
		hashTable[i].head = NULL;

	}

	//start reading. . . . . 
	//
	//
while(fgets(line, LINE_SIZE, fp)!=NULL)
{
	if(valid(line)==-1){
		//printf("error\n");
		;

	}else{
		
		//remove the 0x and pad with 000's to get 64-bit form
		stripandpad(line, valid(line));
		
		//take each character in line and convert to hex equivalent
		//
		//
		for(k=0;k<16;k++){
				hexnum[k]=convert(line[k]);
		}
		
		dec = todecimal(hexnum);
		
		insert(dec);
	}//end else

}//end while loop
	
	printf("%li\n", finalCount);

	
	//cleanup. . . . .
	//
	// 
	struct node *ptr;

	for(i=0;i<ARR_SIZE;i++){
		while(hashTable[i].head!=NULL){
			ptr=hashTable[i].head;
			hashTable[i].head=hashTable[i].head->next;
			free(ptr);
		}
	}

	free(hashTable);
	//end cleanup
	
	return 0;
}









