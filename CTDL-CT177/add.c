#include<stdio.h>
int add(int a,int b){
	return a+b;
}
int main (){
	printf("%d\n", add(15, add(7, -10)));
}

