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
