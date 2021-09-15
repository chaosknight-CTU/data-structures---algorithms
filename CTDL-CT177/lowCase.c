#include<stdio.h>
char lowCase(char c){
    if(c<="A" && c>="Z"){
        return c+32;
    } else {
    	return c;
	}
      
              
}

int main(){
	printf("%c\n", lowCase('Z'));
	return 0;
}
