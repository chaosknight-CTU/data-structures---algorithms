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

void insertList(int x, int p, List *pL){
	if(pL->Last==Maxlength){
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

void copyEvenNumbers(List L1 , List *pL2){
	int i;
	makenullList(pL2);
	for(i=1 ; i<=L1.Last ; i++){
		if(L1.Elements[i-1] % 2==0){
			insertList(L1.Elements[i-1] ,pL2->Last+1 , pL2 );
			
		}
						
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
