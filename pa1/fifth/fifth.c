#include "fifth.h"
#define LINE_SIZE 100
int main(){

FILE *fp;
char filename[50];
char line[LINE_SIZE];
fgets(filename, 50, stdin);

//remove newline fron string
int len = strlen(filename);
if(len>0&&filename[len-1]=='\n'){
	filename[len-1]='\0';
	len = strlen(filename);
}

//make sure filename exists
if((fp = fopen(filename, "r")) == NULL){
	printf("error\n");
//	fclose(fp);
	return 0;
}

//make sure something in file
if(fgets(line, LINE_SIZE, fp)==NULL){
	printf("error\n");
	fclose(fp);
	return 0;
}
//end file validation
fclose(fp);

//extracting just m and n from file
fp = fopen(filename, "r");
int m, n, counter=0;
int num = 0;
char m_str[11], n_str[11];

fgets(line, LINE_SIZE, fp);

while(line[counter]!=9){
	m_str[counter] = line[counter];
	counter++;
}

m = atoi(m_str);

counter++;

int counter2 = 0;

while((line[counter]>47)&&(line[counter]<58)){
	n_str[counter2] = line[counter];
	counter2++;
	counter++;
}

n = atoi(n_str);
fclose(fp);

//first matrix
//
int **arr = (int **)malloc(m * sizeof(int *));

for(int i=0;i<m;i++){
	arr[i] = (int *)malloc(n * sizeof(int));
}

char tempchar[11];
int ctr1 = 0, ctr2 = 0, cellnum;
fp = fopen(filename, "r");

//burn up first line
//
fgets(line, LINE_SIZE, fp);

for(int i=0;i<m;i++)
{
	fgets(line, LINE_SIZE, fp);
	ctr1 = 0;
	for(int j=0;j<n;j++){
		ctr2 = 0;

		while(((line[ctr1]>47)&&(line[ctr1]<58))||(line[ctr1]=='-'))//added 'or -' 9.22.2015********
		{
			tempchar[ctr2] = line[ctr1];
			ctr1++;
			ctr2++;
		}
		ctr1++;
		cellnum = atoi(tempchar);
		arr[i][j] = cellnum;
		//null out tempchar
		//
		for(int c=0;c<11;c++){
			tempchar[c] = 0;
		}
	}//end inner for loop
}//end outer for loop

//second matrix
//
//
//
fgets(line, LINE_SIZE, fp);//burn up empty line

int **arr2 = (int **)malloc(m * sizeof(int *));
for(int i=0;i<m;i++){
	arr2[i] = (int *)malloc(n * sizeof(int));
}

ctr1 = 0, ctr2 = 0;//reset ctrs

for(int i = 0;i<m;i++)
{
	fgets(line, LINE_SIZE, fp);
	ctr1 = 0;
	for(int j = 0;j<n;j++){
		ctr2 = 0;
		while(((line[ctr1]>47)&&(line[ctr1]<58))||(line[ctr1]=='-'))//added 'or -' 9.22.2015
		{
			tempchar[ctr2] = line[ctr1];
			ctr1++;
			ctr2++;
		}
		ctr1++;
		cellnum = atoi(tempchar);
		arr2[i][j] = cellnum;
		//null out tempchar
		//
		for(int c = 0;c<11;c++){
			tempchar[c]=0;
		}
	}//end inner loop
}//end outer loop

//add two matrices and print
//
//
for(int i = 0;i<m;i++){

	for(int j=0;j<n-1;j++){
		printf("%d\t", arr[i][j]+arr2[i][j]);
	}
	printf("%d\n", arr[i][n-1]+arr2[i][n-1] );//prints newline at end of row
}

free(arr);
free(arr2);

return 0;

}
