#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

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
void normalize(List *pL){
	int p = 1;
	int q;
	while(p != pL->Last+1){
		q = p + 1;
		while(q !=pL->Last+1){
			if(pL->Elements[p-1] == pL->Elements[q-1]){
				deleteList(q,pL);
				
			}
			else{
				q = q+1;
			}
		}
		p++;	
	}
}
int main(){
	List L;
int i;
L.Last = 6;
L.Elements[0] = 0;
L.Elements[1] = 14;
L.Elements[2] = 10;
L.Elements[3] = -100;
L.Elements[4] = 14;
L.Elements[5] = 14;
normalize(&L);
for(i=0;i<L.Last;i++)
{
    printf("%d ",L.Elements[i]);
}
}
