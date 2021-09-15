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

void readSet(List *pL){
	makenullList(pL);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1 ; i<=n ; i++){
		int x;
		scanf("%d",&x);
		if(member(x,*pL) == 0){
			insertSet(x,pL);
		}
		
		
		
	}
}
int main(){
	List L;
int i;
readSet(&L);
for(i=0;i<L.Last;i++){
    printf("%d ",L.Elements[i]);
}

}
