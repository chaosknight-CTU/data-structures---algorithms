#include<stdio.h>
int isSquareNumber(int n){
	int i = 0;
    while(i*i <= n){
        if(i*i == n){
            
            return 1;
        } else 
        return 0;
        
	
} 
int main(){
printf("%d",isSquareNumber(100));
}
