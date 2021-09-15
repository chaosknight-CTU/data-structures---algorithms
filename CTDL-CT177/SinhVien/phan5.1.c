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

int xoaTai(int p , DanhSach *pL ){
	if(p > 0 || p <= 40){
		int i;
		for(i = p ; i<=pL->n ; i++){
			pL->A[i-1] = pL->A[i];
		}
		pL->n--;
	}
	return p;
}
void xoaSinhVien(char x[10], DanhSach *pL){
	int p;
	p = tim(x,*pL);
	if(p > 0 && p<=40){
		xoaTai(p,pL);
	}
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
void timSV(char x[10],DanhSach *pL){
	int i,p;
	p = tim(x,*pL);
	if(p > 0 && p <= 40){
		for(i = 1 ; i<=pL->n ; i++){
			if(i != p){
				xoaTai(i,pL);
				
			}	
		}
	}
}
int main(){
	DanhSach L;
	
	L = nhap();
	char x[10];
	fflush(stdin);
	scanf(" ");
	
	fgets(x,10,stdin);
	if(x[strlen(x)-1] == '\n'){
		x[strlen(x)-1] = '\0';
	}
	hienthi(L);
	int a;
	a= tim(x, L);
	timSV(x, &L);
	if(a<=L.n){
		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", x);	
		hienthi(L);
	}
	
	else{
		printf("Khong tim thay sinh vien %s", x);
	}		
}
