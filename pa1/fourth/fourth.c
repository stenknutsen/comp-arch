#include "fourth.h"
#define SIZE_ARR 1000

int zero_exist = 0;

//prototype list
void insert(int table[], int num);
void search(int table[], int num);


void insert(int table[], int num){
	int hashnum = num%SIZE_ARR;
	//this part handles hashing negative ints
	//
	//
	//
	if(hashnum<0){
		hashnum = hashnum + SIZE_ARR;
	}
	//printf("from top insert num is %d and table[hashnum] is %d\n", num, table[hashnum]);
	//check if num is zero
	//
	if(num==0){
		if(zero_exist==0){
			zero_exist = 1;
			printf("inserted\n");
			return;
		}else{

			printf("duplicate\n");
			return;

		}
	}
	//if num is already in hash at original spot
	//
	if(table[hashnum]==num){
		printf("duplicate\n");
		return;
	}

	//if original hash spot empty, insert and return
	//
	if(table[hashnum]== 0){
		table[hashnum]=num;
		printf("inserted\n");
		return;
	}
	
	//if orignal hash spot has another number (not samenum and not 0) starts searching
	//first until end of array
	//
	//
	for(int i = hashnum+1;i<SIZE_ARR;i++){
		//if finds empty, insert
		//
		if(table[i]== 0){
			table[i]=num;
			printf("inserted\n");
			return;
		}
		//if finds same, duplicate
		//
		if(table[i]==num){
		printf("duplicate\n");
		return;
	}


	}//for loop to end of array

	//now, starts search from beginning of array to just before hash point
	//
	//
	//
	for(int i = 0;i<hashnum;i++){
		if(table[i]== 0){
			table[i]=num;
			printf("inserted\n");
			return;
		}
		//if finds same, duplicate
		//
		if(table[i]==num){
		printf("duplicate\n");
		return;
	}

	}//end for loop from beginning of array up to hashpoint
	
	return;
}//end insert

//search function
//
//
//
void search(int table[], int num){
	int hashnum = num%SIZE_ARR;
	//this handles hasing negative ints
	//
	//
	//
	if(hashnum<0){
		hashnum = hashnum+SIZE_ARR;
	}
	//printf("hashnum is %d\n", hashnum);
	//if num is zero
	///
	if(num == 0){
		if(zero_exist==1){
			printf("present\n");
			return;
		}else{
			printf("absent\n");
			return;
		}
	}


	//if num is in hash at hashpoint
	//
	if(table[hashnum]==num){
		printf("present\n");
		return;
	}

	//if not present, searches until end of array first . . . . .	
	//
	//
	for(int i = hashnum+1;i<SIZE_ARR;i++){
		//if finds same present message
		//
		if(table[i]==num){
		printf("present\n");
		return;
	}
}//end search til end of array

	//now if not present in end of array, searches from beginning
	//
	//
	for(int i = 0;i<hashnum;i++){
		
		//if finds same, present
		//
		if(table[i]==num){
		printf("present\n");
		return;
	}

}//end end of begging of array loop

//didnt match at hash, not foun in end, not found in beginning
printf("absent\n");
return;

}//end search function



//main method
//
//
//
int main(){

	//create array and zero out
	int *table = (int *)malloc(sizeof(int)*SIZE_ARR);

	for(int i =0;i<SIZE_ARR;i++){
		table[i] = 0;
	}


	FILE *fp;
	char filename[50];
	char line[50];

	fgets(filename, 50, stdin);

	//remove newline from filename
	int len = strlen(filename);
	if(len>0&&filename[len-1]=='\n'){
		filename[len-1]='\0';
		len = strlen(filename);
	}
//start validation of file
//
//	
	//make sure valid filename
	if((fp = fopen(filename, "r"))==NULL){
		printf("error\n");
		//fclose(fp);
		return 0;
	}

	//check if file empty----added 9.24.2015***************
	//
	//
	//
	if(fgets(line, 50, fp)==NULL){
		printf("\n");
		return 0;
	}	

	//fclose(fp);//this might be bad

	//end of validation of file

	fp = fopen(filename, "r");
	char io;
	char charnum[30];
	int num;

	while(fgets(line, 50, fp)!=NULL){
		io = line[0];//this determines if insert or search or other
		//clear charnum?
		
		for(int i=2, j=0;i<30;i++, j++){
			charnum[j]=line[i];
		}

		num = atoi(charnum);
		//printf("printing num from main loop: %d", num);

		/*if((io != 'i')||(io != 's')){
			printf("error\n");
			continue;
		}*/


		if(io == 'i'){
			insert(table, num);
		}else if(io == 's'){
			search(table, num);
		}else{
			printf("error\n");
		}



	}//end while


//begin printer
//for(int i =0;i<SIZE_ARR;i++){
//		printf("%d ", table[i]);
		

//	}


//	printf("\n");
//end printer

free(table);

return 0;

}




