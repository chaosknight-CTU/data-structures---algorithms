void Delete(int p, int A[], int *pn){
	int i;
	for(i=0 ; i<p ; i++){
		A[i]=A[i+1];
		p = p-1;
		return(A,p);
		
		
	}
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
