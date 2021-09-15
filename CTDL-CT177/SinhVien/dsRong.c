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

DanhSach dsRong(){
	DanhSach L;
	L.n = 0;
	return L;
}

int main(){
	DanhSach L=dsRong();
printf("%d ",L.n);
}
