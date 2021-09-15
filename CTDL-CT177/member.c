#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

int member(ElementType x, List L){
	int p;
	for(p=1 ; p<L.Last+1 ; p++){
		if(L.Elements[p-1] == x){
			return 1;
		}
	}
	return 0;
	
}
int main(){
	List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
    L.Elements[i] = 2*i;
L.Last=5;
if(member(0,L))
    printf("0 in L");
else printf("0 not in L");
}
