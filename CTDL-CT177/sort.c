	#include<stdio.h>
	#define Maxlength 500
	typedef int ElementType;
	typedef int Position;
	typedef struct {
		ElementType Elements[500];
		Position Last;
	} List;
	
	
	void swap(int *x, int *y){
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	
	void sort(List *pL){
		int p;
		int q;
		for (p=1 ;p<=pL->Last ; p++){
			for(q=p+1; q<=pL->Last ;q++){
				if(pL->Elements[p-1] > pL->Elements[q-1] ){
					swap(&pL->Elements[p-1],&pL->Elements[q-1]);	
				}
			}
		}
	}
	int main(){
		List L;
	int i;
	L.Last = 0;
	for(i=5;i>=1;i--){
	    L.Elements[5-i] = 2*i;
	}
	L.Last = 5;
	sort(&L);
	
	for(i=0;i<L.Last;i++){
	    printf("%d ",L.Elements[i]);
	}
	}
