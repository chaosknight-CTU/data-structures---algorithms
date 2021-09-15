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

void chenCuoi(struct SinhVien s, DanhSach *pL){
	if(pL->n > 0 || pL->n <= 40){
		pL->A[pL->n] = s;
		pL->n++;
	}
}

DanhSach chepKhongDat(DanhSach L){
	DanhSach L1;
	dsRong(&L1);
	int i;
	for(i = 1 ; i<=L.n ; i++){
		if((L.A[i-1].DiemLT+L.A[i-1].DiemTH1+L.A[i-1].DiemTH2) < 4){
			chenCuoi(L.A[i-1] , &L1);
		}
	}
	return L1;
}






int main(){
	int i;
DanhSach L1;
DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
struct SinhVien s3 = {"B1818973","Dong Nghi", 0.5f, 1.25f, 1.0f}; 
L.A[1] = s1;
L.n++;
L.A[2] = s2;
L.n++;
L.A[3] = s3;
L.n++;
L1 = chepKhongDat(L);
printf("Khong dat:\n");
for(i=0;i<=L1.n-1;i++)
{
    printf("%s - %s - %.2f - %.2f - %.2f\n",L1.A[i].MSSV, L1.A[i].HoTen, L1.A[i].DiemLT, L1.A[i].DiemTH1, L1.A[i].DiemTH2);
}
	
}
