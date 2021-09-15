#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}

void addFirst(ElementType x, List *pL){
	Position P;
	P=(struct Node*)malloc(sizeof(struct Node));
	P->Element=x;
	P->Next=(*pL)->Next;
	(*pL)->Next=P;
}

int member(ElementType x, List L){
	Position P;
	P=L;
	while(P->Next!=NULL){
		if(P->Next->Element==x)
			return 1;
		P=P->Next;
	}
	return 0;
}
void append(ElementType x, List *pL){
	Position P = (*pL);
	Position A=(struct Node*)malloc(sizeof(struct Node));
	while(P->Next!=NULL){
		P=P->Next;
	}
	A->Element=x;
	A->Next=NULL;
	P->Next=A;
}
List unionSet(List L1,List L2){
	List L;
	makenullList(&L);
	Position p = L1;
	Position q = L2;
	while(p->Next != NULL){		
			append(p->Next->Element,&L);
		p = p->Next;
	}
	while(q->Next !=NULL){
		if(!member(q->Next->Element,L)){
			append(q->Next->Element,&L);
		}
		q = q->Next;
	}
	return L;	
}

void deleteList(Position P, List *pL){
	Position Temp;
	if(P->Next!=NULL){
		Temp=P->Next;
		P->Next=Temp->Next;
		free(Temp);
	}
}
List readSet(){
	List L;
	makenullList(&L);
	int n, i;
	ElementType x;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		if(!(member(x, L)))
			addFirst(x, &L);
	}
	return L;
}
Position locate(ElementType x, List L){
	Position p = L;
	while(p->Next != NULL){	
		if(p->Next->Element == x){
			break;
		}
		else {
			p= p->Next;
		}
	}
	return p;
}





List difference(List L1, List L2){
	List L;
	makenullList(&L);
	Position p=L1;
	while(p->Next!=NULL){
		if (!member(p->Next->Element, L2))
			append(p->Next->Element, &L);
		p=p->Next;
	}
	return L;
}
List intersection(List L1, List L2){
	List L;
	makenullList(&L);
	Position p = L1;
	while(p->Next != NULL){
		if(member(p->Next->Element,L2)){
			append(p->Next->Element,&L);
			
		}
		p = p->Next;
	}
	return L;
	
}

void swap(int *x, int *y){
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	
void sort(List *pL){
	Position p = *pL;
	Position q;
	while(p->Next != NULL){
		q = p->Next;
		while(q->Next != NULL){
			if(p->Next->Element > q->Next->Element){				
				swap(&p->Next->Element,&q->Next->Element);
			}
			q = q->Next;
		}
		p = p->Next;
	}
}



void printList(List L){
	Position p;
	p=L;
	while(p->Next!=NULL){
		printf("%d ", p->Next->Element);
		p=p->Next;
	}
	printf("\n");
}
void readList(List *pL){
	int n;
	scanf("%d",&n);
	makenullList(pL);
	int i;
	for(i = 1 ; i<=n ; i++){
		int x;
		scanf("%d",&x);
		append(x,pL);
	}
}
void copyEvenNumbers(List L1,List *pL2){
	makenullList(pL2);
	Position p = L1;
	while(p->Next != NULL){
		if(p->Next->Element % 2 ==0){
			append(p->Next->Element,pL2);
		}
		p = p->Next;
	}
}
float getAvg(List L){
	Position p;
	p = L;
	float s = 0;
	int count = 0;
	while(p->Next != NULL){
		s = s+p->Next->Element;
		count++;
		p = p->Next;
	}
	if(count  == 0){
		return -10000.0;
	}
	else {
		return s/count;
	}		
}

int main (){
	List L,L1;
	readList(&L);
	printList(L);
	copyEvenNumbers(L,&L1);	
	printList(L1);
	printf("%.3f",getAvg(L1));
	return 0;
}

