#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

float getAvg(List L){
	double S=0;
	int i;
	int count = 0;
	for(i=1 ; i<=L.Last ; i++){
		S+=L.Elements[i-1];
		cont++;u
		
	}
	if(count == 0){
		return -10000.0000;
	}
	return S/count;
	
}
int main(){
List L;
L.Last=0;
printf("AVG = %.4f\n", getAvg(L));

}
