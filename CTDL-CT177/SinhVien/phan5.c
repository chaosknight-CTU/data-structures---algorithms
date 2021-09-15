#include<stdio.h>
#include<string.h>
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

int tim(char x[10], DanhSach L){
	int i;
	for(i = 1; i<=L.n+1 ; i++ ){
		if(strcmp(L.A[i-1].MSSV,x) == 0){
			return i;
		}		
	}
	return L.n+1;
}


void dsRong(DanhSach *pL){
	pL->n =0;
}
void chenCuoi(struct SinhVien s, DanhSach *pL){
	if(pL->n < 0 || pL->n >= 40){
		printf("Loi! Danh sach day!");
	}
	else {
		pL->A[pL->n] = s;
		pL->n++;
	}
	
}

void hienthi(DanhSach L){
	int i;
	
	for(i = 1 ; i<=L.n ; i++){
		printf("%s - %s - %.2f - %.2f - %.2f \n",L.A[i-1].MSSV,L.A[i-1].HoTen,L.A[i-1].DiemLT,L.A[i-1].DiemTH1,L.A[i-1].DiemTH2);
		
	}
}
DanhSach nhap(){
    DanhSach L;
    struct SinhVien sv;
    dsRong(&L);
    int i, n;
    scanf("%d", &n);
    char ms[10], ten[50];
    float a, b, c;
    for (i=1; i<=n; i++){
        scanf(" ");
        fgets(ms,10,stdin);
        if(ms[strlen(ms)-1]=='\n')
            ms[strlen(ms)-1]='\0';
        strcpy(sv.MSSV, ms);
        fgets(ten,50,stdin);
        if(ten[strlen(ten)-1]=='\n')
            ten[strlen(ten)-1]='\0';
        strcpy(sv.HoTen, ten);
        scanf("%f%f%f", &a, &b, &c);
        sv.DiemLT=a;
        sv.DiemTH1=b;
        sv.DiemTH2=c;
        if (tim(ms,L)==L.n+1){
            chenCuoi(sv,&L);
        }
    }
    return L;
}



DanhSach khongDat(DanhSach L){
	DanhSach L1;
	dsRong(&L1);
	int i;
	float tong;
	for(i = 1 ; i<=L.n ; i++){
		tong = L.A[i-1].DiemLT+L.A[i-1].DiemTH1+L.A[i-1].DiemTH2;
		if(tong < 4 ){
			chenCuoi(L.A[i-1],&L1);
		}
	}
	return L1;
}
int main(){
	DanhSach L;
	DanhSach L1;
	L = nhap();
	hienthi(L);
	printf("Sinh vien KHONG DAT \n");
	L1 = khongDat(L);
	hienthi(L1);
}
