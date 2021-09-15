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
void insertList(ElementType X,Position P, List *L) {
	if (L->Last==Maxlength)
		printf("Danh sach day");	
	else if ((P<1) || (P>L->Last+1))
	    printf("Vi tri khong hop le");
		else {
			Position Q;
			for(Q=(L->Last-1)+1;Q>=P;Q--)
				L->Elements[Q]=L->Elements[Q-1];
			L->Elements[P-1]=X;
			L->Last++;
		}
} 
void copyEvenNumbers(List L1 , List *pL2){
	int i;
	makenullList(pL2);
	for(i=1 ; i<=L1.Last ; i++){
		if(L1.Elements[i-1] % 2==0){
			insertList(L1.Elements[i-1] ,pL2->Last+1 , pL2 );
			
		}
						
	}
}

Position locate(ElementType x, List L){
	int P = 1;
	while(P!=L.Last+1){
		if(L.Elements[P-1] == x){
			return P;
		}
		else {
			P= P+1;
		}				
	}
	return P; 	
}

int emptyList(List L){
	return L.Last==0;
}
void deleteList(Position P , List *pL){
	if((P < 1) || (P > pL->Last)){
		printf("Vi tri khong hop le");
		
	}
	else if(emptyList(*pL)){
		printf("Danh sach rong!");
	}
	else{
		Position Q;
		for(Q=P ; Q<pL->Last;Q++){
			pL->Elements[Q-1] = pL->Elements[Q];
		}
		pL->Last--;
	}
}

void removeAll(int x, List *pL){
	int P = locate(x,*pL);
	if(P < pL->Last+1) {
		deleteList(P, pL);
		removeAll(x, pL);
	}
}

int main(){
	 List L1,L2;
int i;
makenullList(&L1);
for(i=0;i<=5;i++){
    insertList(i, L1.Last+1, &L1);
}
copyEvenNumbers(L1, &L2);
for(i=0;i<L1.Last;i++){
    printf("%d ",L1.Elements[i]);
}
printf("\n");
for(i=0;i<L2.Last;i++){
    printf("%d ",L2.Elements[i]);
}

}
