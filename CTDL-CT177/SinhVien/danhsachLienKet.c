#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
	Position p = *pL;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->Next = NULL;
}
int member(int x,List L){
	Position p;
	p = L;
	while(p->Next != NULL){
		if(p->Next->Element == x){
			return 1;
		} 
		p = p->Next;
							
	}
	return 0;
	
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

void deleteList(Position p , List *pL){
	Position a;
	if(p->Next != NULL){
		a = p->Next;
		p->Next = a->Next;
		free (a);
	}
}

void append(int x,List *pL){
	Position p = (*pL);
	Position a = (struct Node*)malloc(sizeof(struct Node));
	while(p->Next != NULL){
		p = p->Next;
	}
	a->Element = x;
	a->Next = NULL;
	p->Next = a;	
}

void printOddNumbers(List L){
	Position p = L;
	while(p->Next != NULL){
		if(p->Next->Element %2 != 0){
			printf("%d ",p->Next->Element);
		} 
		p = p->Next;
	}
	printf("\n");
}

void addFirst(int x,List *pL){
	Position p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->Element = x;
	p->Next = (*pL)->Next;
	(*pL)->Next = p;
	
}

List readSet(){
	List L;
	makenullList(&L);
	int n,i,x;
	scanf("%d",&n);
	for(i = 1 ; i<=n ; i++){
		scanf("%d",&x);
		if(!member(x,L)){
			addFirst(x,&L);
		}
	}
	return L;
}
void removeAll(int x, List *pL){
	while(locate(x,*pL)->Next != NULL){
		deleteList(locate(x,*pL),pL);
					
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
void normalize(List*pL){
	Position p = *pL;
	Position q;
	while(p->Next != NULL){
		q = p->Next;
		while(q->Next != NULL){
			if(p->Next->Element == q->Next->Element){
				deleteList(q,pL);
				
			} else {
				q = q->Next;
			}
		}
		p = p->Next;
	}	
}
void erase(int x, List *pL){
	Position p  = locate(x,*pL);
	if(p->Next != NULL){
		deleteList(p,pL);
	}
	else {
		printf("Not found %d\n",x);
	}
	
}
void insertList(int x,Position p, List *pL){
	Position T;
	T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = p->Next;
	p->Next = T;
	
}
List difference(List L1, List L2){
	List L;
	makenullList(&L);
	Position p = L1;
	while(p->Next != NULL){
		if(!member(p->Next->Element,L2)){
			append(p->Next->Element,&L);		
		} 
		p = p->Next;	
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
void deleteX(ElementType x,List *pL){
	Position p;
	p = *pL;
	while(p->Next !=NULL){
		if(p->Next->Element == x){
			deleteList(p,pL);
		} 
		else {
			p = p->Next;
			
		}
		
	}
}
void printList(List L){
	Position p;
	p = L;
	while(p->Next != NULL){
		printf("%d ",p->Next->Element);
		p = p->Next;
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



int main(){
	List L1,L2;
	L1 = readSet();
	L2 = readSet();
	normalize(&L1); 
	normalize(&L2);
	printList(L1);
	printList(L2);
	return 0;
	
}
