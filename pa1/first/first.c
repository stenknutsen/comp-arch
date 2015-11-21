#include "first.h"

int main()
{
char buf[11];
unsigned int i;

fgets(buf, 11, stdin);

i = atoi(buf);

if(i==0){
printf("error\n");
return 0;
}
if(i%2==0){
printf("even\n");
}else{
printf("odd\n");
}
return 0;
}
