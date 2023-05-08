#pragma once
#include "danhsachNV.h"

//typedef struct  {
//    char hoTen[30];
//    char gioiTinh[4];
//    int ngay;
//    int thang;
//    int nam;
//    char diaChi[17];
//    int sdt;
//    char chucVu[20];
//    int DoanhThu;
//
//}NhanVien;
//int soluongNV = 0;
void menu_NV();
void select_box_NV(int xp, int yp, int x, int y, int b_color_hl);
void select_menu_NV(int yp, int y);
void thongtinNV();
void themNhanVien(int &soluongNV);
void n_box_NV(int x, int y, int w, int h, int t_color, int n_cot);
bool isRight(char gioitinh[5]);
void docTTNV(NhanVien ds[], int &n);
void luuTTNV(NhanVien ds[], int n);
void xemNhanVien();
void xoaNV();
