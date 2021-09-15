#include<stdio.h>
#define MaxLength 40
typedef float Elements;
typedef int num;
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct{
	struct SinhVien A[MaxLength];
	num n;
}DanhSach;

int xoaTai(int p , DanhSach *pL ){
	if(p > 0 || p <= 40){
		int i;
		for(i = 1 ; i<=pL->n ; i++){
			pL->A[i-1] = pL->A[i];
		}
		pL->n--;
	}
	return p;
}



int main(){
	DanhSach L = {{{"B1806972","Hoang Minh", 5.5f, 2.5f, 2.0f}}, 1};
struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
int i;
L.A[1] = s;
L.n++;
for(i=0;i<L.n;i++)
{
    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
}
xoaTai(1, &L);
printf("\n");
for(i=0;i<L.n;i++)
{
    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
}
}
