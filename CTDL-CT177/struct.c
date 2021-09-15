#include<stdio.h>
#define Maxlength 500
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[500];
	Position Last;
} List;

struct SinhVien{
	char MaSoSv[10];
	char HovTen[50];
	float LT , TH1, TH2;
};

typedef struct{
	struct SinhVien A[40];
	int n;
}List;
