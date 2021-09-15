#include<stdio.h>
void Delete(int p , int A[] , int *pn){
	int i;
	int n=*pn;
	for(i=p+1 ; i<=n-1 ; i++){
		 A[i-1] = A[i];
		
			
	}
	n--;	
	(*pn)=n;
		
}
int main(){
	int a[] = {1, 5, 20, 0};
int n =sizeof(a)/sizeof(int);
int o,p,i;
p=2;
for(i=0;i<=n-1;i++)
    printf("%d ",a[i]);
Delete(p,a, &n);
printf("\n");
for(i=0;i<=n-1;i++)
    printf("%d ",a[i]);
}
