#include <stdio.h>
#include <stdlib.h>

#define MaxLength 50
typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List; 

List L;

void MakeNullList(List *L) {
	L->Last=0;
}

int EmptyList(List L) { 
	return (L.Last==0);
}

void InsertList(ElementType X,Position P, List *L) {
	if (L->Last==MaxLength)
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

void DeleteList(Position P,List *L) { 
	if ((P<1) || (P>L->Last))
		printf("Vi tri khong hop le");
	else if (EmptyList(*L))
	    printf("Danh sach rong!");
		else {
			Position Q;
			for(Q=P-1;Q<L->Last-1;Q++)
				L->Elements[Q]=L->Elements[Q+1];
			L->Last--;
		}
} 

Position Locate(ElementType X, List L) {
	Position P;
	int Found = 0;
	P = First(L);

	while ((P != EndList(L)) && (Found == 0))
		if (Retrieve(P,L) == X) Found = 1;
		else P = Next(P, L);
	return P;
} 
 
ElementType Retrieve(Position P, List L) {
	return L.Elements[P-1];
} 

Position First(List L) {	
	return 1; 
} 

Position EndList(List L) {
	return L.Last+1;
}
 
Position Next(Position P, List L) {	
	return P+1;
}

void PrintList(List L) {
	Position P;
	P = First(L);
	while (P != EndList(L)) {
		printf("%d ",Retrieve(P,L));
		P = Next(P, L);
	}
	printf("\n");
}

void ReadList(List *L) {	
	int i,N;
	ElementType X;
	MakeNullList(L);
	printf("So phan tu danh sach N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		InsertList(X,EndList(*L),L);
	}
}

ElementType maxList(List L){
	int i,max=L.Elements[0];
	for(i = 2 ; i<=L.Last ; i++){
		if(L.Elements[i-1] > max){
			max = L.Elements[i-1];
		}
	}
	return max;
}

int main(){
	ReadList(&L);
	PrintList(L);
	int a = maxList(L);
	printf("%d ",a );
	return 0;
	
}

