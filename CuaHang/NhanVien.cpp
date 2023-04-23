#include "NhanVien.h"
#include "header.h"
#include "myLib.h"
#include "menuMain.h"

NhanVien danhsachNV[10];
void menu_NV()
{
    // Header
    ShowCur(0);
    int x = 38;
    int y = 5;
    int w_box = 44;
    int h_box = 4;
    int h = 2;
    int t_color = 15;
    int b_color_hl = 118;
    int n_cot = 2;
    gotoXY(50, 3);
    textcolor(6);
    box(50, 1, 20, 2, 6);
    gotoXY(52, 2);
    SetColor(15);
    printf("    Nhan Vien    ");
    // Menu_NhanVien
    box(x, y, w_box, h_box, t_color);
    textcolor(6);
    gotoXY(48, y);
    printf("< Moi ban chon Dich Vu >");
    gotoXY(50, 13);
    SetColor(t_color);
    printf("NHAN ");
    SetColor(6);
    printf("ESC");
    SetColor(t_color);
    printf(" DE QUAY LAI");
    textcolor(14);
    gotoXY(x + 1, y + 1);
    printf("          Xem danh sach nhan vien          ");
    gotoXY(48, 7);
    for (int i = 10; i < 34; i++)
    {
        SetColor(t_color);
        printf("%c", char(196));
    }
    gotoXY(x + 1, y + 3);
    textcolor(14);
    printf("            Them nhan vien moi             ");
    
    int xp = x;
    int yp = y; // Toa do select_box
    int xcu = xp;
    int ycu = yp; // Toa do select_box cu
    bool kt = true;
    bool kt_ENTER = false;
    bool control_menu_main = true;
    // Control
    while (true)
    {
        if (kt == true && control_menu_main == true)
        {
            gotoXY(xcu, ycu);
            select_box_NV(xcu, ycu, x, y, 14);
            xcu = xp;
            ycu = yp;
            select_box_NV(xp, yp, x, y, b_color_hl);
            kt = false;
        }
        // Dieu khien
        char c = _getch();
        if (_kbhit())
        {
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72 && yp != y)
                {
                    yp -= 2;
                }
                else if (c == 80 && yp != y + h * (n_cot - 1))
                {
                    yp += 2;
                }
            }
        }
        else if (c == 13)
        {
            kt_ENTER = !kt_ENTER;
            if (kt_ENTER)
            {
                textcolor(15);
                system("cls");
                select_menu_NV(yp, y);
                kt_ENTER = !kt_ENTER;
                control_menu_main = false;
            }
        }
        else if (c == 27)
        {
            textcolor(15);
            system("cls");
            menu_main();
        }
    }
}
void select_box_NV(int xp, int yp, int x, int y, int b_color_hl) // Highlight box dang chon
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (yp == y)
        printf("          Xem danh sach nhan vien          ");
    else if (yp == y + 2)
        printf("            Them nhan vien moi             ");
}
void select_menu_NV(int yp, int y) // Chon menu
{
    if (yp == y)
    {
        textcolor(15);
        system("cls");
        //thongtinNV();
        xemNhanVien();
    }
    else if ((yp == y + 2))
    {
        textcolor(15);
        system("cls");
        themNhanVien(soluongNV);
    }
}

// void xoaNhanVien();
void thongtinNV()
{
    // Header
    box_header(0, 1, 11, 2, 6);
    box(50, 1, 24, 2, 6);
    textcolor(15);
    gotoXY(1, 2);
    printf("NHAN VIEN");
    gotoXY(51, 2);
    printf("  Thong Tin Nhan Vien ");
    gotoXY(5, 5);
    printf("Danh sach Nhan Vien");
    docTTNV(danhsachNV, soluongNV);
    for (int i = 1; i <= soluongNV; i++)
    {
        gotoXY(6, 6 + i); // in Danh Sach Ten Nhan Vien
        printf("%d. %s", i, danhsachNV[i].hoTen);
        printf("     %s", danhsachNV[i].diaChi);
    }
}
void themNhanVien(int& soluongNV)
{
    docTTNV(danhsachNV, soluongNV);
    soluongNV++;
    // Header
    textcolor(6);
    for (int ix = 0; ix <= 12; ix++)
    {
        gotoXY(ix, 1);
        printf("%c", char(196));
        gotoXY(ix, 1 + 2);
        printf("%c", char(196));
    }
    for (int iy = 1; iy <= 1 + 2; iy++)
    {
        gotoXY(12, iy);
        printf("%c", char(179));
    }
    gotoXY(12, 1 + 2);
    printf("%c", char(217));
    gotoXY(12, 1);
    printf("%c", char(191));
    gotoXY(1, 2);
    SetColor(15);
    printf("NHAN VIEN");
    textcolor(6);
    box(50, 1, 23, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf(" Them nhan vien moi ");
    // Box
    n_box_NV(41, 7, 41, 2, 14, 6);
    // Du Lieu
    ShowCur(1);
    textcolor(15);
    // Ten
    gotoXY(57, 8);
    inputString(danhsachNV[soluongNV].hoTen, 30);
    // Ngay/Thang/Nam
    do
    {
        ShowCur(1);
        gotoXY(57, 11);
        danhsachNV[soluongNV].ngay = inputNumber(2);
        gotoXY(60, 11);
        danhsachNV[soluongNV].thang = inputNumber(2);
        gotoXY(63, 11);
        danhsachNV[soluongNV].nam = inputNumber(4);
        if (isValidDate(danhsachNV[soluongNV].ngay, danhsachNV[soluongNV].thang, danhsachNV[soluongNV].nam) == false)
        {
            textcolor(14);
            gotoXY(57, 11);
            printf("__/__/____");
            ShowCur(0);
            textcolor(244);
            gotoXY(85, 10);
            printf("     Du lieu khong hop le!     ");
            gotoXY(85, 11);
            printf("       VUI LONG NHAP LAI       ");
            Sleep(1500);
            textcolor(15);
            gotoXY(85, 11);
            printf("                               ");
            gotoXY(85, 10);
            printf("                               ");
        }
    } while (isValidDate(danhsachNV[soluongNV].ngay, danhsachNV[soluongNV].thang, danhsachNV[soluongNV].nam) == false);
    // Dia Chi
    gotoXY(57, 14);
    inputString(danhsachNV[soluongNV].diaChi, 50);
    // SDT
    do{
        gotoXY(57, 17);
        danhsachNV[soluongNV].sdt = inputNumber(10);
        if(isValidPhoneNumber(danhsachNV[soluongNV].sdt) == false)
        {
            ShowCur(0);
            textcolor(244);
            gotoXY(84, 16);
            printf("     Du lieu khong hop le!     ");
            gotoXY(84, 17);
            printf("       VUI LONG NHAP LAI       ");
            Sleep(1500);
            textcolor(15);
            gotoXY(84, 16);
            printf("                               ");
            gotoXY(84, 17);
            printf("                               ");
            ShowCur(1);
            gotoXY(57, 17);
            printf("            ");
        }
    }while(isValidPhoneNumber(danhsachNV[soluongNV].sdt) == false);
    
    // GIOI TINH
    do
    {
        ShowCur(1);
        gotoXY(71, 20);
        inputString(danhsachNV[soluongNV].gioiTinh, 50);
        // neu du lieu sai thi in lai va thong bao
        if (isRight(danhsachNV[soluongNV].gioiTinh) == false)
        {
            ShowCur(0);
            textcolor(244);
            gotoXY(84, 21);
            printf("     Du lieu khong hop le!     ");
            gotoXY(84, 20);
            printf("       VUI LONG NHAP LAI       ");
            Sleep(1500);
            textcolor(15);
            gotoXY(84, 21);
            printf("                               ");
            gotoXY(84, 20);
            printf("                               ");
            ShowCur(1);
            gotoXY(71, 20);
            printf("        ");
        }
    } while (isRight(danhsachNV[soluongNV].gioiTinh) == false);
    // CHUC VU
    gotoXY(57, 23);
    inputString(danhsachNV[soluongNV].chucVu, 50);
    luuTTNV(danhsachNV, soluongNV); // Lưu Thông Tin Nhân Viên Vào file `nhanvien.dat`
    ShowCur(0);
    textcolor(114);
    gotoXY(43, 26);
    printf("                                      ");
    gotoXY(43, 27);
    printf("       NHAP THONG TIN THANH CONG      ");
    gotoXY(43, 28);
    printf("                                      ");
    // Thanh Cong
    Sleep(1000);
    textcolor(15);
    system("cls");
    menu_NV();
}


void xemNhanVien()
{
    
    docTTNV(danhsachNV, soluongNV);
    //Header
    box_header(0, 1, 11, 2, 6);
    // phần hướng dẫn 
        //Esc
    gotoXY(1, 5);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" ESC ");
    textcolor(15);
    printf("DE LUU & THOAT");
    //Tab
    gotoXY(1, 6);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" TAB ");
    textcolor(15);
    printf("DE XOA NHAN VIEN");

    // box thông tin NV
    box(48, 5, 24, 2, 6);
    textcolor(15);
    gotoXY(1, 2); printf("NHAN VIEN");
    gotoXY(49, 6); printf("  THONG TIN NHAN VIEN ");
    // box nội dung thông tin nhân viên
    box(10, 9, 100, 4 + soluongNV, 6);
    box(4, 9, 6, 4 + soluongNV, 6);
   
    textcolor(15);
    textcolor(6);
    gotoXY(10, 9);
    printf("%c", char(194));
    gotoXY(10, 13 + soluongNV);
    printf("%c", char(193));
    for (int iy = 10; iy <= 12 + soluongNV; iy++)
    {
        gotoXY(35, iy);
        printf("%c", char(124));
        gotoXY(48, iy);
        printf("%c", char(124));
        gotoXY(68, iy);
        printf("%c", char(124));
        gotoXY(85, iy);
        printf("%c", char(124));
        gotoXY(86 + 12, iy);
        printf("%c", char(124));
    }
    // in mục trong nội dung khung Nhan viên
    textcolor(15);
    gotoXY(6, 10);
    printf("STT");
    
    gotoXY(17, 10); printf("Ten Nhan Vien");
    gotoXY(37, 10); printf("Ngay Sinh");
    gotoXY(55, 10); printf("Dia Chi");
    gotoXY(73, 10); printf("Gioi Tinh");
    gotoXY(90, 10); printf("SDT");
    gotoXY(101, 10); printf("Chuc Vu");
    gotoXY(5, 11);
    textcolor(6);
    for(int i = 1; i < 106; i++)
    {
        printf("%c", char(196));
    }
    // hien thi thoong tin nhan vien tu viecj doc file
    textcolor(15);
    for(int i = 1; i <= soluongNV; i++)
    {
        gotoXY(7, 11 + i);
        printf("%d", i);
        gotoXY(11, 11 + i);
        centerText(danhsachNV[i].hoTen, 24);
        gotoXY(37, 11 + i);
        printf("%d/%d/%d", danhsachNV[i].ngay,danhsachNV[i].thang,danhsachNV[i].nam);
        gotoXY(49, 11 + i);
        centerText(danhsachNV[i].diaChi, 19);
        gotoXY(69, 11 + i);
        centerText(danhsachNV[i].gioiTinh, 16);
        gotoXY(87, 11 + i);
        printf("0%d", danhsachNV[i].sdt);
         gotoXY(99, 11 + i);
        centerText(danhsachNV[i].chucVu, 11);
        ShowCur(0);

    }
    // điều khiển để xóa nhan viên và thoát
    char c = _getch();
    if (c == 9)
    {
        textcolor(15);
        //system("cls");
        xoaNV();
    }
    else if (c == 27)
    {
        textcolor(15);
        system("cls");
        menu_NV();
    }
}
void xoaNV()
{
    gotoXY(1, 5);
    printf("                            ");
    gotoXY(1, 6);
    printf("                            ");
     // Esc
    gotoXY(1, 5);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" `0` ");
    textcolor(15);
    printf("DE QUAY LAI");

    if(soluongNV == 0)
    {
        ShowCur(0);
        textcolor(244);
        gotoXY(40, 15 + soluongNV);
        printf("                                              ");
        gotoXY(40, 16 + soluongNV);
        printf("    KHONG CO NHAN VIEN NAO TRONG DANH SACH    ");
        gotoXY(40, 17 + soluongNV);
        printf("                                              ");
        Sleep(1500);
        textcolor(15);
        gotoXY(40, 15 + soluongNV);
        printf("                                              ");
        gotoXY(40, 16 + soluongNV);
        printf("                                              ");
        gotoXY(40, 17 + soluongNV);
        printf("                                              ");
        xemNhanVien();
    }
    else{
        box(40, 15 + soluongNV, 40, 2, 6);
        textcolor(15);
        gotoXY(41, 16 + soluongNV); printf("    NHAP STT NHAN VIEN MUON XOA: ");
        ShowCur(1);
        int stt_xoa = inputNumber(2);
        while (stt_xoa < 1 || stt_xoa > soluongNV && stt_xoa)
        {
            if (stt_xoa == 0)
            {
                system("cls");
                xemNhanVien();
            }
            ShowCur(0);
            textcolor(116);
            gotoXY(40, 15 + soluongNV);
            printf("                                  ");
            gotoXY(40, 16 + soluongNV);
            printf("      LOI! vui long chon lai      ");
            gotoXY(40, 17 + soluongNV);
            printf("                                  ");
            gotoXY(41 + 33, 16 + soluongNV);
            textcolor(15);
            printf(" ");
            Sleep(1500);
            // backspace
            textcolor(0);
            for (int iy = 15 + soluongNV; iy <= 18 + soluongNV; iy++)
            {
                for (int ix = 40; ix <= 70; ix++)
                {
                    gotoXY(ix, iy);
                    printf(" ");
                }
            }
            // Box
            box(40, 15 + soluongNV, 40, 2, 6);
            textcolor(15);
            gotoXY(41, 16 + soluongNV); printf("    NHAP STT NHAN VIEN MUON XOA: ");
            ShowCur(1);
            stt_xoa = inputNumber(2);
        }
        for (int i = stt_xoa; i <= soluongNV; i++)
        {
            danhsachNV[i] = danhsachNV[i + 1];
        }
        soluongNV--;
        luuTTNV(danhsachNV, soluongNV);
        ShowCur(0);
        gotoXY(40, 16 + soluongNV);
        printf("                                         ");
        gotoXY(40, 17 + soluongNV);
        printf("                                         ");
        gotoXY(40, 18 + soluongNV);
        printf("                                         ");
        textcolor(116);
        gotoXY(40, 15 + soluongNV);
        printf("                                   ");
        gotoXY(40, 16 + soluongNV);
        printf("    Ban da xoa nhan vien thu %d!    ", stt_xoa);
        gotoXY(40, 17 + soluongNV);
        printf("                                   ");
        Sleep(1000);
        textcolor(15);
        system("cls");
        xemNhanVien();
    }
}



void n_box_NV(int x, int y, int w, int h, int t_color, int n_cot)
{
    for (int i = 0; i < n_cot; i++)
    {
        box(x, y + i * 3, w, h, t_color);
    }
    gotoXY(x + 1, y + 1);
    printf("     HO & TEN:                         ");
    gotoXY(x + 1, y + 4);
    printf("     DD/MM/YY: __/__/____              ");
    gotoXY(x + 1, y + 7);
    printf("      DIA CHI:                          ");
    gotoXY(x + 1, y + 10);
    printf("          SDT:                          ");
    gotoXY(x + 1, y + 13);
    printf("    GIOI TINH:                         ");
    gotoXY(x + 1, y + 16);
    printf("     CHUC VU :                         ");
    gotoXY(57, 20);
    textcolor(8);
    printf("(NAM/NU/KHAC)");
}
// ham kiem tra nhap gioi tinh
bool isRight(char gioitinh[5])
{
    if (_stricmp(gioitinh, "NAM") == 0 || _stricmp(gioitinh, "NU") == 0 || _stricmp(gioitinh, "KHAC") == 0)
    {
        return true;
    }
    else
        return false;
}


void docTTNV(NhanVien ds[], int& n)
{
    // Mở file để đọc dữ liệu
    FILE* f;
    errno_t err = fopen_s(&f, "nhanvien.dat", "rb");
    if (err != 0)
    {
        textcolor(244);
        gotoXY(50, 10);
        printf("                                               ");
        gotoXY(50, 11);
        printf("       Khong the mo file de doc du lieu!       ");
        gotoXY(50, 12);
        printf("                                               ");
        Sleep(2000);
        textcolor(15);
        system("cls");
        menu_NV();
        
    }
    fread(&n, sizeof(n), 1, f);
    for (int i = 1; i <= n; i++)
    {
        fread(&ds[i], sizeof(NhanVien), 1, f);
    }
    fclose(f);
}
void luuTTNV(NhanVien ds[], int n)
{
    FILE* f;
    errno_t err = fopen_s(&f, "nhanvien.dat", "wb");
    if (err != 0)
    {
        printf("Khong the mo file de ghi du lieu!\n");
        return;
    }
    fwrite(&n, sizeof(n), 1, f);
    for (int i = 1; i <= n; i++)
    {
        fwrite(&ds[i], sizeof(NhanVien), 1, f);
    }
    fclose(f);
}
bool isValidPhoneNumber(int phoneNum) {
    // Chuyển số điện thoại thành chuỗi ký tự
    char phoneStr[11]; // Độ dài của số điện thoại là 10 chữ số, cộng thêm 1 ký tự NULL kết thúc chuỗi
    sprintf_s(phoneStr, "%010d", phoneNum);
    
    // Kiểm tra tiền tố và độ dài của số điện thoại
    const char* prefixes[] = {"032", "033", "034", "035", "036", "037", "038", "039", "056", "058", "059", "070", "079", "077", "076", "078", "083", "084", "085", "081", "082"};
    int numPrefixes = sizeof(prefixes) / sizeof(prefixes[0]);
    int prefixMatched = 0;
    for (int i = 0; i < numPrefixes; i++) {
        if (strncmp(phoneStr, prefixes[i], 3) == 0) {
            prefixMatched = 1;
            break;
        }
    }
    bool isValidLength = (strlen(phoneStr) == 10);
    
    // Trả về kết quả
    return (prefixMatched && isValidLength);
}