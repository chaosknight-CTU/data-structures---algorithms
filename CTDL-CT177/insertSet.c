#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;


void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
}
int main(){
List L;
int i;
L.Last=0;
for(i=0;i!=5;i++)
    insertSet(2*i, &L);
insertSet(0,&L);
insertSet(8,&L);
for(i=0;i<L.Last;i++)
    {printf("%d ",L.Elements[i]);}
}
