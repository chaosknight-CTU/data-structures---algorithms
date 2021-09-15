#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

void makenullList(List *pL){
	pL->Last=0;
}

int main(){
		
List L;

L.Last=5;
printf("%d ",L.Last);
makenullList(&L);
printf("%d ",L.Last);
}
