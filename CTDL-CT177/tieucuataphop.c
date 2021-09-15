#include <stdio.h>
#include <stdlib.h>

#define MaxLength 50
typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List; 

void makenullList(List *L){
	L->Last==0;
}
int emptyList(List L){
	return L.Last==0;
}

void insertList(int x, int p, List *pL){
	if(pL->Last==MaxLength){
		printf("Danh sach day");
		
	}
		else if(p < 1 || (p >(pL->Last+1))) {
			printf("Vi tri khong hop le");
		
		} else {
			Position Q;
			for (Q=pL->Last ; Q>=p;Q--){
				pL->Elements[Q] = pL->Elements[Q-1];
			}
			pL->Elements[p-1]=x;			
			pL->Last++;
		}
		
}

List readList(){
	List L;
	
	scanf("%d",&L.Last);
	int i;	
	for(i=1 ; i<=L.Last ; i++){	
		scanf("%d",&L.Elements[i-1]);
	}
	return L;
}
void printList(List L){
	int i;
	for(i=1 ; i<=L.Last; i++){
		printf("%d ",L.Elements[i-1]);
	}
	printf("\n");
}


void deleteList(Position p , List *pL){
	if((p < 1) || (p > pL->Last)){
		printf("Vi tri khong hop le");		
	}
	else if(emptyList(*pL)){
		printf("Danh sach rong!");
	}
	else{
		Position Q;
		for(Q=p ; Q<pL->Last;Q++){
			pL->Elements[Q-1] = pL->Elements[Q];
		}
		pL->Last--;
	}
}

void loai(List *pL){
	int p,q;
	for(p = 1 ; p<=pL->Last ; p++){
		for(q =p+1 ; q<=pL->Last ; q++ ){
			if(pL->Elements[p-1] == pL->Elements[q-1]){
				deleteList(q,pL);
			}
		}
	}
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

List difference(List L1, List L2){	
	int P;
	int q;
	for(P=1 ; P<=L2.Last ; P++){
		for(q =1 ; q<=L1.Last ; q++){
			if(L1.Elements[q-1] == L2.Elements[P-1])
				deleteList(q,&L1);		
		}							
	}
	return L1;
}
int main(){
	List L1,L2,L3;
	L1 = readList();
	L2 = readList();
	loai(&L1);
	loai(&L2);
	printList(L1);
	printList(L2);
	L3 = difference(L1,L2);
	printList(L3);
	return 0;
		
}

