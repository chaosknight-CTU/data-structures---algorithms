#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

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




void erase(int x,List *pL){
	Position P;
	P = locate(x,*pL);
	if(P > 1 ||P <= pL->Last){
		deleteList(P,pL);
	}
	
}
int main(){
List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
   { L.Elements[i] = 2*i;}
L.Last=5;
erase(8,&L);
for(i=0;i<L.Last;i++)
 {   printf("%d ",L.Elements[i]);}

}
