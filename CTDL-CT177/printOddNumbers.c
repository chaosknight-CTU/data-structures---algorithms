#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

void printOddNumbers(List L){
	int i;
	for(i=1 ; i<=L.Last ; i++){
		if(L.Elements[i-1] % 2 != 0){
			printf("%d ",L.Elements[i-1]);
		}
	}
	
}

int main(){
	List L;
L.Elements[0] = -1;
L.Elements[1] = 2;
L.Elements[2] = 9;
L.Elements[3] = -1;
L.Elements[4] = -10;
L.Last=5;
printOddNumbers(L);
	
}
