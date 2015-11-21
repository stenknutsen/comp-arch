#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//prototype list
//
//
int valid(char line[]);
void stripandpad(char line[], int num);
int convert(char hex);
unsigned long long todecimal(int hexnum[]);



int valid(char line[]){
	//first char must be 0
	if(line[0]!='0'){
		return -1;
	}
	//second char must be x or h
	if(line[1]!='x'&&line[1]!='h'){
		return -1;
	}
	//must be valid character after 0x
	if(!(line[2]>47&&line[2]<58)&&!(line[2]>96&&line[2]<103)){
		return -1;
	}

	//now loop thu rest of string, validating and counting chars until non-char found
	//
	int count = 1;
	int i;
	for(i = 3;i<19;i++){
		//if reach non-character, break for loop
		if(line[i]>=0&&line[i]<33){
			break;
		}
		//if a-f or 0-9, advance count; else not a valid char, return -1
		if((line[i]>47&&line[i]<58)||(line[i]>96&&line[i]<103)){
			count++;
		}else{
			return -1;
		}

	}//end for loop
	//if there are 16 or less chars counted, return that count; else -1
	if(count<17){
		return count;
	}else{
		return -1;
	}
	return 0;
}//end valid function


void stripandpad(char line[], int num){
	
	char hexnum[16];
	
	int i,j;
	
	
	for(i=0;i<16;i++){
		hexnum[i]='0';
	}

	for(i=num+1, j=15;i>1;i--,j--){
		hexnum[j]=line[i];

	}

	for(i=0;i<16;i++){
		line[i]=hexnum[i];
	}
	return;
}//end stripandpad function

int convert(char hex){
	if(hex=='0'){
		return 0;
	}
	if(hex=='1'){
		return 1;
	}
	if(hex=='2'){
		return 2;
	}
	if(hex=='3'){
		return 3;
	}
	if(hex=='4'){
		return 4;
	}
	if(hex=='5'){
		return 5;
	}
	if(hex=='6'){
		return 6;
	}
	if(hex=='7'){
		return 7;
	}
	if(hex=='8'){
		return 8;
	}
	if(hex=='9'){
		return 9;
	}
	if(hex=='a'){
		return 10;
	}
	if(hex=='b'){
		return 11;
	}
	if(hex=='c'){
		return 12;
	}
	if(hex=='d'){
		return 13;
	}
	if(hex=='e'){
		return 14;
	}
	if(hex=='f'){
		return 15;
	}
	return 0;
}//end convert function


unsigned long long todecimal(int hexnum[]){
	int i, n;
	unsigned long long total = 0;
	n = 0;
	for(i=15;i>=0;i--){
		//note: pow is evidenlty double, so cast to unsigned long
		total = total + (hexnum[i]*((unsigned long)(pow(16, n))));
		n++;
	}

	return total;
}














