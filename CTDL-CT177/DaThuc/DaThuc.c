#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct {
    double he_so;
    int bac;
} DonThuc;

struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

void inDaThuc(DaThuc d){
	Position P = d;
	while (P->Next != NULL){
		printf("%.3f^%d",P->Next->e.he_so,P->Next->e.bac);
		if(P->Next->Next == NULL){
			printf(" + ");
		}
		P = P->Next;
			
	}	
}

DaThuc khoitao()
{
    DaThuc D = (DaThuc)malloc(sizeof(DaThuc));
    D->Next = NULL;
    return D;
}

void chenDonThuc(DonThuc x, DaThuc *pD)
{
    Position P = *pD;
    while (P->Next != NULL)
    {
        if (P->Next->e.bac == x.bac)
        {
            P->Next->e.he_so = P->Next->e.he_so + x.he_so;
            return;
        }
        if (P->Next->e.bac < x.bac)
        {
            Position T = (Position)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    Position T = (Position)malloc(sizeof(struct Node));
    T->e = x;
    P->Next = T;
}
DaThuc nhapDaThuc()
{
    int n;
    double hs;
    int bac;
    DonThuc d;
    DaThuc D = khoitao();
    scanf("%d", &n);
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%lf %d", &hs, &bac);
        d.he_so = hs;
        d.bac = bac;
        chenDonThuc(d, &D);
    }
    return D;
}

DaThuc tinhDaoHam(DaThuc D){
	DaThuc L = khoitao();
	Position P = D;
	while(P->Next != NULL){
		DonThuc A;
		A.bac = P->Next->e.bac-1;
		A.he_so = P->Next->e.he_so*P->Next->e.he_so;
		chenDonThuc(A,&L);
		P = P->Next;
	}	
	return L;
}

DaThuc nhanDaThuc(DaThuc D1,DaThuc D2){
	DaThuc L = khoitao();
	DaThuc P = D1,Q;
	DonThuc A;
	while(P->Next != NULL){
		Q = D2;
		while(Q->Next != NULL){
			A.he_so = P->Next->e.he_so*Q->Next->e.he_so;
			A.bac = P->Next->e.bac + Q->Next->e.bac;
			chenDonThuc(A,&L);
			Q = Q->Next;
		}
		P = P->Next;
	}
	return L;
}

DaThuc congDaThuc(DaThuc D1,DaThuc D2){
	DaThuc L = khoitao();
	Position P = D1;
	while(P->Next != NULL){
		chenDonThuc(P->Next->e,&L);
		P = P->Next;				
	}
	P = D2;
	while(P->Next != NULL){
		chenDonThuc(P->Next.e,&D);
		P = P->Next
	}
	return L;
	
}




int main(){
	DaThuc d1=nhapDaThuc();		
DaThuc d2=nhapDaThuc();		
DaThuc d = nhanDaThuc(d1,d2);
inDaThuc(d);
}
