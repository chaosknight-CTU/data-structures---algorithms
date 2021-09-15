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
void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
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

void realList(List *pL){
	int n;
	int i;
	ElementType x;
	makenullList(pL);
	scanf("%d",&n);
	for(i=1 ; i<=n ; i++){
		scanf("%d",&x);
		insertList(x,pL->Last+1,pL);			
	}
}

void printList(List L){
	int i;
	for(i=1 ; i<=L.Last; i++){
		printf("%d ",L.Elements[i-1]);
	}
	printf("\n");
}

int emptyList(List L){
	return L.Last==0;
}

void deleteElements(int x, List *pL){
	int i;
	int j;
	for(i=1 ; i<=pL->Last ; i++){
		if(pL->Elements[i-1] == x){
			for(j=i-1 ; j<=pL->Last ; j++){
				pL->Elements[j] = pL->Elements[j+1];
		}
		pL->Last--;
		i--;		
		}
		 		
	}
}	



int main(){
	List L;
	int x;
	realList(&L);
	scanf("%d",&x);
	printList(L);
	deleteElements(x,&L);
	printList(L);
	return 0;
					
}
