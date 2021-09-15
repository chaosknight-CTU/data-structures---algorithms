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

void readList(List *pL){
	makenullList(pL);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1 ; i<=n ; i++){
		int x;
		scanf("%d",&x);
		insertList(x,pL->Last+1,pL);
	}
}
int main(){List L;
int i;
readList(&L);
for(i=0;i<L.Last;i++)
    {printf("%d ",L.Elements[i]);}
}
