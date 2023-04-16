#pragma once
struct SanPham {
    char ten[30];
    int gia;
    int soluong;
    int loai;// 1 = cf; 2 = tra; 3 = bake
};
struct KhachHang {
    char ten[30];
    int tuoi;
    int ngaySinh;
    int thangSinh;
    int namSinh;
    char diachi[50];
    double sdt;
    SanPham GH[100];
    int soluongSP;
};
//int sttKH = 0;


void khoiTaoGioHang(int& sttKH);
void chonhang();
void xoamotmathang();
void menu_KH();
void select_menu_KH_oder(int xp, int yp, int x, int y, int b_color_hl);
void check();
void select_object(int xp, int yp, int x, int y);
void xacnhanGH();
void xemgiohang();
void n_box_KH(int x, int y, int w, int h, int t_color, int n_cot);
void menu_KH_oder();

void luuTTKH();
void inDuLieuTuFile();
void ghiDuLieuVaoFile(KhachHang ds[], int n);
 void layDuLieuTuFile(KhachHang ds[], int &n);
//Daonh THu
void menu_DT();
int tinhGH(int a);
int tinhDT_SP(int loai);
int tinhTongDoanhThu();
//Cua Hang
void menu_SanPham();
void ghiSanPhamVaoFile();
//int vitri_object[9];