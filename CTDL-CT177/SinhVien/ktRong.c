#include<stdio.h>
#define MaxLength 40
typedef float Elements;
typedef int num;
typedef struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct{
	SinhVien A[MaxLength];
	num n;
}DanhSach;

int ktRong(DanhSach L){
	
		if(L.n == 0){
			return 1;
		} else {
			return 0;
		}
	
	
}

int main(){
	DanhSach L;
L.n=0;
printf("%d ",ktRong(L));

}
