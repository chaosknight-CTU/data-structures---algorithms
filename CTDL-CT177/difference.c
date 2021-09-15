#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

void makenullList(List *L){
	L->Last=0;	
}

int member(ElementType x, List L){
	int P;
	for(P=1 ; P<=L.Last ; P++){
		if(L.Elements[P-1] == x){
			return 1;			
		}
		
	}
	return 0;	
}

void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
}
void difference(List L1, List L2, List *pL){
	makenullList(pL);
	int P;
	for(P=1 ; P<=L1.Last ; P++){
		if(!member(L1.Elements[P-1], L2)){
			insertSet(L1.Elements[P-1],pL);	
		} 
		
	}
}

int main(){
	List L1,L2,L;
int i;

makenullList(&L1);
makenullList(&L2);

for(i=0;i<=5;i++){
    insertSet(2*i, &L1);
}
for(i=4;i<=8;i++){
    insertSet(2*i, &L2);
}

for(i=0;i<L1.Last;i++){
    printf("%d ",L1.Elements[i]);
}
printf("\n");
for(i=0;i<L2.Last;i++){
    printf("%d ",L2.Elements[i]);
}
printf("\n");
difference(L1,L2,&L);
for(i=0;i<L.Last;i++){
    printf("%d ",L.Elements[i]);
}
}
