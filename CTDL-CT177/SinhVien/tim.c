#include<stdio.h>
#include<string.h>
#define MaxLength 40
typedef int num;
struct SinhVien {
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};


typedef struct{
    struct SinhVien A[40];
	num n;
}DanhSach;

int tim(char x[10], DanhSach L){
	int i;
	for(i = 1; i<=L.n+1 ; i++ ){
		if(strcmp(L.A[i-1].MSSV,x) == 0){
			return i;
		}		
	}
	return L.n+1;
}

int main(){
	DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
int p,i;
L.A[1] = s;
L.n++;
for(i=0;i<L.n;i++)
{
    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
}

p = tim("B1806979", L);
if (p > L.n)
  printf("Tim khong thay");
else printf("Tim thay o vi tri %d",p);
}
