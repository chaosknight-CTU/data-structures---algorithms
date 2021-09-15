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

void dsRong(DanhSach *pL){
	pL->n=0;
}

void hienthi(DanhSach L){
	int i;
	float tong;
	for(i = 1 ; i<=L.n ; i++){
		tong = L.A[i-1].DiemLT+L.A[i-1].DiemTH1+L.A[i-1].DiemTH2;
		if(tong >= 4 ){
			printf("%s - %s - %.2f - %.2f - %.2f - %.2f \n",L.A[i-1].MSSV,L.A[i-1].HoTen,L.A[i-1].DiemLT,L.A[i-1].DiemTH1,L.A[i-1].DiemTH2,tong);
		}
	}
}

int main(){
	DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
L.A[1] = s;
L.n++;
hienthi(L);
}
