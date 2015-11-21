#include "second.h"

int main(){

char buf[11];
unsigned int i;

fgets(buf, 11, stdin);

i = atoi(buf);

if(i==0){
printf("error\n");
return 0;
}

if(i==1){
printf("no\n");
return 0;
}

for(int j = i-1;j>1;j--){
if(i%j==0){
printf("no\n");
return 0;
}
}
printf("yes\n");
return 0;
}

