#include "KhachHang.h"
#include "header.h"
#include "myLib.h"
#include "menuMain.h"
using namespace std;
SanPham sanphamCuaHang[9];
KhachHang danhsachKH[100];
void menu_KH()
{
    menu_SanPham();
    khoiTaoGioHang(sttKH);
    textcolor(15);
    system("cls");
    chonhang();
}
void chonhang()
{
    menu_KH_oder();
    xemgiohang();
    ShowCur(0);
    int x = 5;
    int y = 10;
    int h = 3;
    int w = 20;
    int t_color = 15;
    int b_color_hl = 118;
    int n_cot = 3;
    int n_hang = 3;
    int stt = 0;
    int xp = x;
    int yp = y; // Toa do select_box
    int xcu = xp;
    int ycu = yp; // Toa do select_box cu
    bool kt = true;
    bool kt_ENTER = false;
    bool control_menu_main = true;
    while (true)
    {
        if (kt == true && control_menu_main == true)
        {
            gotoXY(xcu, ycu);
            select_menu_KH_oder(xcu, ycu, x, y, 14);

            xcu = xp;
            ycu = yp;

            select_menu_KH_oder(xp, yp, x, y, b_color_hl);
            kt = false;
        }
        // Dieu khien
        /*  Mui t�n sang tr�i: 75
            Mui t�n sang ph?i: 77*/
        char c = _getch();
        if (_kbhit())
        {
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72 && yp != y) // Len
                {
                    yp -= 6;
                }
                else if (c == 80 && yp != y + h * (n_cot + 1)) // Xuong
                {
                    yp += 6;
                }
                else if (c == 75 && xp != x) // Trai
                {
                    xp -= 25;
                }
                else if (c == 77 && xp != 55) // xp != xMax -> Phai
                {
                    xp += 25;
                }
            }
        }
        else if (c == 13)
        {
            kt_ENTER = !kt_ENTER;
            if (kt_ENTER)
            {
                select_object(xp, yp, x, y);
                kt_ENTER = !kt_ENTER;
                control_menu_main = false;
            }
        }
        else if (c == 9)
        {
            textcolor(15);
            system("cls");
            xoamotmathang();
        }
        else if (c == 27)
        {
            textcolor(136);
            for (int iy = 14; iy <= 18; iy++)
            {
                for (int ix = 22; ix <= 71; ix++)
                {
                    gotoXY(ix, iy);
                    printf(" ");
                }
            }
            textcolor(114);
            gotoXY(25, 15);
            printf("                                            ");
            gotoXY(25, 16);
            printf("        XAC NHAN DON HANG THANH CONG        ");
            gotoXY(25, 17);
            printf("                                            ");

            ghiDuLieuVaoFile(danhsachKH, sttKH);
            Sleep(2000);
            textcolor(15);
            system("cls");
            menu_main();
        }
    }
}
void select_menu_KH_oder(int xp, int yp, int x, int y, int b_color_hl)
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (xp == x && yp == y)
    {
        printf("  AMERICANO        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x + 25 && yp == y)
    {
        printf("  CAPPUCCINO       ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x + 50 && yp == y)
    {
        printf("  MACCHIATO        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x && yp == y + 6)
    {
        printf("   Tra Dao         ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x + 25 && yp == y + 6)
    {
        printf("   Tra Vai         ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x + 50 && yp == y + 6)
    {
        printf("   Tra Buoi        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x && yp == y + 12)
    {
        printf("   Tiramisu        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
    else if (xp == x + 25 && yp == y + 12)
    {
        printf(" Mousse Cacao      ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
    else if (xp == x + 50 && yp == y + 12)
    {
        printf(" Pho Mai Ca Phe    ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
}
void select_object(int xp, int yp, int x, int y)
{
    ShowCur(0);
    danhsachKH[sttKH].soluongSP++;
    for (int j = 0; j <= 12; j += 6)
    {
        for (int i = 0; i <= 50; i += 25)
        {
            if (xp == x + i && yp == y + j)
            {
                vitri_object[danhsachKH[sttKH].soluongSP] = i / 25 + j / 2;
                xacnhanGH();
            }
        }
    }
}
void check()
{
    int stt = danhsachKH[sttKH].soluongSP;
    strcpy_s(danhsachKH[sttKH].GH[stt].ten, sanphamCuaHang[vitri_object[danhsachKH[sttKH].soluongSP]].ten);
    danhsachKH[sttKH].GH[stt].gia = sanphamCuaHang[vitri_object[danhsachKH[sttKH].soluongSP]].gia;
    danhsachKH[sttKH].GH[stt].soluong = 1;
    danhsachKH[sttKH].GH[stt].loai = sanphamCuaHang[vitri_object[danhsachKH[sttKH].soluongSP]].loai;
    for (int i = 1; i < stt; i++)
    {
        if (strcmp(danhsachKH[sttKH].GH[stt].ten, danhsachKH[sttKH].GH[i].ten) == 0)
        {
            // Nếu sản phẩm đã tồn tại, tăng số lượng lên
            danhsachKH[sttKH].GH[i].soluong++;
            danhsachKH[sttKH].soluongSP--;
        }
    }
}
void xacnhanGH()
{
    check();
    int stt = danhsachKH[sttKH].soluongSP;
    textcolor(15);
    for (int i = 1; i <= stt; i++)
    {
        gotoXY(81, 11 + i);
        centerText(danhsachKH[sttKH].GH[i].ten, 14);
        gotoXY(101, 11 + i);
        printf("%d", danhsachKH[sttKH].GH[i].soluong);
        gotoXY(112, 11 + i);
        printf("%d$", danhsachKH[sttKH].GH[i].gia);
    }
    gotoXY(109, 26);
    textcolor(15);
    printf("%d $", tinhGH(sttKH));
    chonhang();
}
void xoamotmathang()
{
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
    printf("KHACH HANG");
    textcolor(6);
    box(50, 1, 21, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf("  Thu Hoi San Pham  ");
    // Esc
    gotoXY(1, 5);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" `0` ");
    textcolor(15);
    printf("DE QUAY LAI");
    // Hien Thi Gio Hang
    xemgiohang();
    box(75, 7, 5, 20, 15);
    gotoXY(80, 7);
    printf("%c", char(194));
    gotoXY(80, 7 + 20);
    printf("%c", char(193));
    gotoXY(76, 10);
    textcolor(11);
    printf("STT");
    for (int i = 1; i <= danhsachKH[sttKH].soluongSP; i++)
    {
        gotoXY(77, 11 + i);
        printf("%d", i);
    }
    // Nhap du lieu san pham can thu hoi
    int y;
    int stt = danhsachKH[sttKH].soluongSP;
    if (stt == 0)
    {
        ShowCur(0);
        textcolor(116);
        gotoXY(20, 13);
        printf("                                            ");
        gotoXY(20, 14);
        printf("    Ban khong co san pham trong gio hang!!  ");
        gotoXY(20, 15);
        printf("                                            ");

        Sleep(5000);
    }
    else
    {
        ShowCur(1);
        // Box
        box(20, 13, 35, 4, 15);
        // Du Lieu
        gotoXY(25, 15);
        printf("STT SAN PHAM THU HOI: ");
        gotoXY(48, 15);
        y = inputNumber(2);
        while (y < 1 || y > stt)
        {
            if (y == 0)
            {
                system("cls");

                chonhang();
            }
            textcolor(0);
            for (int iy = 13; iy <= 13 + 4; iy++)
            {
                for (int ix = 20; ix <= 55; ix++)
                {
                    gotoXY(ix, iy);
                    printf(" ");
                }
            }
            textcolor(116);
            ShowCur(0);
            gotoXY(25, 14);
            printf("                           ");
            gotoXY(25, 15);
            printf("  Loi!  vui long chon lai  ");
            gotoXY(25, 16);
            printf("                           ");
            Sleep(1500);
            box(20, 13, 35, 4, 15);
            // backspace
            textcolor(0);
            for (int iy = 13; iy <= 13 + 4; iy++)
            {
                for (int ix = 20; ix <= 55; ix++)
                {
                    gotoXY(ix, iy);
                    printf(" ");
                }
            }
            // Box
            box(20, 13, 35, 4, 15);
            // Du Lieu
            ShowCur(1);
            textcolor(15);
            gotoXY(25, 15);
            printf("STT SAN PHAM THU HOI: ");
            gotoXY(48, 15);
            y = inputNumber(2);
        }
        for (int i = y; i <= stt; i++)
        {
            danhsachKH[sttKH].GH[i] = danhsachKH[sttKH].GH[i + 1];
        }
        danhsachKH[sttKH].soluongSP--;
        xemgiohang();
        /// iN
        textcolor(0);
        for (int iy = 1; iy <= 10; iy++)
        {
            gotoXY(77, 11 + iy);
            printf(" ");
        }
        box(75, 7, 5, 20, 15);
        gotoXY(80, 7);
        printf("%c", char(194));
        gotoXY(80, 7 + 20);
        printf("%c", char(193));
        gotoXY(76, 10);
        textcolor(11);
        printf("STT");
        for (int i = 1; i <= danhsachKH[sttKH].soluongSP; i++)
        {
            gotoXY(77, 11 + i);
            printf("%d", i);
        }
        //
        ShowCur(0);
        // backspace
        textcolor(0);
        for (int iy = 13; iy <= 13 + 4; iy++)
        {
            for (int ix = 20; ix <= 55; ix++)
            {
                gotoXY(ix, iy);
                printf(" ");
            }
        }
        textcolor(114);
        gotoXY(20, 13);
        printf("                                   ");
        gotoXY(20, 14);
        printf("    Ban da xoa mat hang thu %d!     ", y);
        gotoXY(20, 15);
        printf("                                   ");
    }
    // Ham quay lai ham chonhang()
    textcolor(15);
    Sleep(1000);
    system("cls");
    chonhang();
}
void khoiTaoGioHang(int& sttKH)
{
    // Mở file để đọc dữ liệu
    layDuLieuTuFile(danhsachKH, sttKH);
    sttKH++;
    danhsachKH[sttKH].soluongSP = 0; // Khởi tạo số lượng sản phẩm trong giỏ hàng = 0
    for (int i = 0; i < 10; i++)
    {
        strcpy_s(danhsachKH[sttKH].GH[i].ten, " ");
        danhsachKH[sttKH].GH[i].soluong = 0; // Khởi tạo số lượng sản phẩm trong giỏ hàng là 0
        danhsachKH[sttKH].GH[i].gia = 0;     // Khởi tạo giá tiền của sản phẩm trong giỏ hàng là 0
    }
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
    printf("KHACH HANG");
    textcolor(6);
    box(50, 1, 23, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf(" Thong Tin Khach Hang ");
    // Box
    n_box_KH(41, 7, 41, 2, 14, 4);
    // Du Lieu
    ShowCur(1);
    textcolor(15);
    // Ten
    gotoXY(57, 8);
    inputString(danhsachKH[sttKH].ten, 30);
    // Ngay/Thang/Nam
    do
    {
        ShowCur(1);
        gotoXY(57, 11);
        danhsachKH[sttKH].ngaySinh = inputNumber(2);
        gotoXY(60, 11);
        danhsachKH[sttKH].thangSinh = inputNumber(2);
        gotoXY(63, 11);
        danhsachKH[sttKH].namSinh = inputNumber(4);
        if (isValidDate(danhsachKH[sttKH].ngaySinh, danhsachKH[sttKH].thangSinh, danhsachKH[sttKH].namSinh) == false)
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
    } while (isValidDate(danhsachKH[sttKH].ngaySinh, danhsachKH[sttKH].thangSinh, danhsachKH[sttKH].namSinh) == false);
    // Dia Chi
    gotoXY(57, 14);
    inputString(danhsachKH[sttKH].diachi, 50);
    // SDT
    
    do {
        gotoXY(57, 17);
        danhsachKH[sttKH].sdt = inputNumber(10);
        if (isValidPhoneNumber(danhsachKH[sttKH].sdt) == false)
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
    } while (isValidPhoneNumber(danhsachKH[sttKH].sdt) == false);
    ShowCur(0);
    textcolor(114);
    gotoXY(43, 20);
    printf("                                      ");
    gotoXY(43, 21);
    printf("       NHAP THONG TIN THANH CONG      ");
    gotoXY(43, 22);
    printf("                                      ");
    // Thanh Cong
    Sleep(1000);
}
void xemgiohang()
{
    // backspace
    SetColor(0);
    for (int i = 7; i < 7 + 13; i++)
    {
        for (int j = 80; j < 80 + 36; j++)
        {
            gotoXY(j, i);
            printf(" ");
        }
    }
    // Gio Hang
    box(80, 7, 35, 20, 15);
    gotoXY(90, 8);
    textcolor(15);
    printf("GIO HANG CUA BAN");
    gotoXY(87, 9);
    for (int i = 0; i < 22; i++)
    {
        textcolor(11);
        printf("%c", char(196));
    }
    gotoXY(82, 10);
    printf("TEN SAN PHAM |  SO LUONG  |  GIA");

    // Total
    textcolor(15);
    gotoXY(82, 25);
    for (int i = 0; i < 32; i++)
    {
        printf("%c", char(196));
    }
    gotoXY(102, 26);
    printf("Tong: ");

    // DU lieu
    int stt = danhsachKH[sttKH].soluongSP;
    textcolor(15);
    for (int i = 1; i <= stt; i++)
    {
        gotoXY(81, 11 + i);
        centerText(danhsachKH[sttKH].GH[i].ten, 14);
        gotoXY(101, 11 + i);
        printf("%d", danhsachKH[sttKH].GH[i].soluong);
        gotoXY(112, 11 + i);
        printf("%d$", danhsachKH[sttKH].GH[i].gia);
    }
    gotoXY(109, 26);
    textcolor(15);
    printf("%d $", tinhGH(sttKH));
}
void n_box_KH(int x, int y, int w, int h, int t_color, int n_cot)
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
    printf("     DIA CHI:                          ");
    gotoXY(x + 1, y + 10);
    printf("        SDT:                           ");
}
// void luuTTKH()
void luuTTKH()
{
    // Mở file để ghi dữ liệu vào
    FILE* f;
    fopen_s(&f, "khachhang.dat", "wb");
    if (f == NULL) {
        printf("Khong the mo file");
        return;
    }
    else {
        fwrite(&sttKH, sizeof(sttKH), 1, f);
        for (int i = 1; i <= sttKH; i++) {
            fwrite(&danhsachKH[i], sizeof(KhachHang), 1, f);
        }
        fclose(f);
    }
}
void inDuLieuTuFile()
{
    FILE* inFile = NULL;
    errno_t err = fopen_s(&inFile, "khachhang.dat", "rb");
    if (err != 0)
    {
        printf("Khong the mo file de doc du lieu!\n");
        return;
    }

    int sttKH;
    fread(&sttKH, sizeof(sttKH), 1, inFile);
    printf("So luong khach hang: %d\n", sttKH);

    KhachHang kh;
    while (fread(&kh, sizeof(kh), 1, inFile))
    {
        printf("Ten: %s\n", kh.ten);
        printf("Ngay sinh: %d/%d/%d\n", kh.ngaySinh, kh.thangSinh, kh.namSinh);
        printf("Dia chi: %s\n", kh.diachi);
        printf("So dien thoai: %.0f\n", kh.sdt);
        printf("So luong san pham: %d\n", kh.soluongSP);
        printf("==========================\n");
    }

    fclose(inFile);
}
//Nhap Xuat file
void ghiDuLieuVaoFile(KhachHang ds[], int n)
{
    FILE* f;
    errno_t err = fopen_s(&f, "khachhang.dat", "wb");
    if (err != 0)
    {
        printf("Khong the mo file de ghi du lieu!\n");
        return;
    }
    fwrite(&n, sizeof(n), 1, f);
    for (int i = 1; i <= n; i++)
    {
        fwrite(&ds[i], sizeof(KhachHang), 1, f);
    }
    fclose(f);
}
void layDuLieuTuFile(KhachHang ds[], int &n)
{
FILE *f;
errno_t err = fopen_s(&f, "khachhang.dat", "rb");
    if (err != 0)
    {
        printf("Khong the mo file de doc du lieu!\n");
        return;
    }
fread(&n, sizeof(n), 1, f);
for(int i = 1; i <= n; i++) 
{
 	fread(&ds[i], sizeof(KhachHang), 1, f);
}
fclose(f);
}
//Cua Hang
void menu_SanPham()
{
    strcpy_s(sanphamCuaHang[0].ten, "AMERICANO");
    strcpy_s(sanphamCuaHang[1].ten, "CAPPUCCINO");
    strcpy_s(sanphamCuaHang[2].ten, "MACCHIATO");
    strcpy_s(sanphamCuaHang[3].ten, "Tra Dao");
    strcpy_s(sanphamCuaHang[4].ten, "Tra Vai");
    strcpy_s(sanphamCuaHang[5].ten, "Tra Buoi");
    strcpy_s(sanphamCuaHang[6].ten, "Tiramisu");
    strcpy_s(sanphamCuaHang[7].ten, "Mousse Cacao");
    strcpy_s(sanphamCuaHang[8].ten, "Pho Mai Ca Phe");
    for (int i = 0; i < 9; i++)
    {
        if (i < 3)
        {
            sanphamCuaHang[i].loai = 1;
            sanphamCuaHang[i].gia = 5;
        }
        else if (i < 6 && i > 2)
        {
            sanphamCuaHang[i].loai = 2;
            sanphamCuaHang[i].gia = 4;
        }
        else
        {
            sanphamCuaHang[i].loai = 3;
            sanphamCuaHang[i].gia = 2;
        }
        sanphamCuaHang[i].soluong = 0;
    }
    ghiSanPhamVaoFile();
}
void ghiSanPhamVaoFile() {
    FILE* f;
    fopen_s(&f, "danhsachSP.dat", "wb");
    if (f == NULL) {
        printf("Khong the mo file");
        return;
    }
    else {
        for (int i = 0; i < 9; i++) {
            fwrite(&sanphamCuaHang[i], sizeof(SanPham), 1, f);
        }
        fclose(f);
    }
}
//Doanh Thu
void menu_DT()
{
    //Header
    ShowCur(0);
    textcolor(6);
    for (int ix = 0; ix <= 17; ix++)
    {
        gotoXY(ix, 0);
        printf("%c", char(196));
        gotoXY(ix, 2);
        printf("%c", char(196));
    }
    for (int iy = 0; iy <= 1; iy++)
    {
        gotoXY(17, iy);
        printf("%c", char(179));
    }
    gotoXY(17, 2);
    printf("%c", char(217));
    gotoXY(17, 0);
    printf("%c", char(191));
    gotoXY(1, 1);
    SetColor(15);
    printf("Cua Hang Coffee");
    //Box Doanh Thu
    box(15, 3, 85, 20, 15);
    gotoXY(16, 5);
    textcolor(8);
    char text1[20] = "DOANH THU CUA HANG";
    centerText(text1, 84);
    gotoXY(38, 7);
    textcolor(15);
    for (int i = 0; i < 40; i++)
    {
        printf("%c", char(196));
    }
    gotoXY(16, 9);
    textcolor(6);
    char text2[20] = "TONG TIEN THU DUOC";
    centerText(text2, 84);
    gotoXY(56, 10);
    printf("%d $", tinhTongDoanhThu());

    gotoXY(16, 12);
    char text4[30] = "TONG GIAO DICH THUC HIEN DUOC";
    centerText(text4, 84);
    gotoXY(56, 13);
    printf("%d", sttKH);

    gotoXY(38, 14);
    textcolor(15);
    for (int i = 0; i < 40; i++)
    {
        printf("%c", char(196));
    }
    box(31, 16, 16, 4, 15);
    box(49, 16, 16, 4, 15);
    box(67, 16, 16, 4, 15);
    gotoXY(33, 17);
    printf("Coffee");
    gotoXY(52, 17);
    printf("Tra");
    gotoXY(69, 17);
    printf("Banh Kem");
    //iN tong doanh thu
    gotoXY(41, 19);
    printf("%d$", tinhDT_SP(1));
    gotoXY(60, 19);
    printf("%d$", tinhDT_SP(2));
    gotoXY(77, 19);
    printf("%d$", tinhDT_SP(3));
    //ESC
    gotoXY(48, 24);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" ESC ");
    textcolor(15);
    printf("DE QUAY LAI");
    //Control
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == 27)
            {
                textcolor(15);
                system("cls");
                menu_main();
            }
        }
    }
}
int tinhTongDoanhThu() {
    int sum = 0;
    // Mở file để đọc dữ liệu
    layDuLieuTuFile(danhsachKH, sttKH);
    for (int i = 1; i <= sttKH; i++)
    {
        for (int j = 1; j <= danhsachKH[i].soluongSP; j++)
        {
            sum += danhsachKH[i].GH[j].gia * danhsachKH[i].GH[j].soluong;
        }
    }
    return sum;
}
int  tinhDT_SP(int loai)//Ham tinh doanh thu cua tung loai san pham
{
    int sum = 0;
    for (int i = 1; i <= sttKH; i++)
    {
        for (int j = 1; j <= danhsachKH[i].soluongSP; j++)
        {
            if (danhsachKH[i].GH[j].loai == loai)
                sum += danhsachKH[i].GH[j].gia * danhsachKH[i].GH[j].soluong;
        }
    }
    return sum;
}
int tinhGH(int a)//Tinh gio hang tai khach hang thu 'a'
{
    int sum = 0;
    for (int i = 1; i <= danhsachKH[a].soluongSP; i++)
    {
        sum += danhsachKH[a].GH[i].gia * danhsachKH[a].GH[i].soluong;
    }
    return sum;
}
void menu_KH_oder()
{
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
    printf("KHACH HANG");

    textcolor(6);
    box(50, 1, 20, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf("     Chon Hang     ");

    for (int j = 10; j <= 22; j += 6)
    {

        for (int i = 5; i <= 55; i += 25)
        {
            box(i, j, 20, 3, 6); // 5 10-- 55 22
        }
    }
    textcolor(15);
    gotoXY(2, 10 - 1);
    printf("Coffee");
    gotoXY(4, 16 - 1);
    printf("Tra");
    gotoXY(2, 22 - 1);
    printf("Banh Kem");
    //Coffee
    textcolor(14);
    gotoXY(5 + 1, 10 + 2);
    printf("  AMERICANO        ");
    gotoXY(5 + 1, 10 + 2);
    printf("          Gia: 5$  ");
    gotoXY(30 + 1, 10 + 1);
    printf("  CAPPUCCINO       ");
    gotoXY(30 + 1, 11 + 1);
    printf("          Gia: 5$  ");
    gotoXY(55 + 1, 10 + 1);
    printf("  MACCHIATO        ");
    gotoXY(55 + 1, 11 + 1);
    printf("          Gia: 5$  ");

    //Tra
    gotoXY(5 + 1, 16 + 1);
    printf("   Tra Dao         ");
    gotoXY(5 + 1, 16 + 2);
    printf("          Gia: 4$  ");
    gotoXY(30 + 1, 16 + 1);
    printf("   Tra Vai         ");
    gotoXY(30 + 1, 16 + 2);
    printf("          Gia: 4$  ");
    gotoXY(55 + 1, 16 + 1);
    printf("   Tra Buoi        ");
    gotoXY(55 + 1, 16 + 2);
    printf("          Gia: 4$  ");
    //Tra
    gotoXY(5 + 1, 22 + 1);
    printf("   Tiramisu        ");
    gotoXY(5 + 1, 22 + 2);
    printf("          Gia: 2$  ");;
    gotoXY(30 + 1, 22 + 1);
    printf(" Mousse Cacao      ");
    gotoXY(30 + 1, 22 + 2);
    printf("          Gia: 2$  ");
    gotoXY(55 + 1, 22 + 1);
    printf(" Pho Mai Ca Phe    ");
    gotoXY(55 + 1, 22 + 2);
    printf("          Gia: 2$  ");

    // Gio Hang
    box(80, 7, 35, 20, 15);
    gotoXY(90, 8);
    textcolor(15);
    printf("GIO HANG CUA BAN");
    gotoXY(87, 9);
    for (int i = 0; i < 22; i++) {
        textcolor(11);
        printf("%c", char(196));
    }
    gotoXY(82, 10);
    printf("TEN SAN PHAM |  SO LUONG  |  GIA");

    //Total
    textcolor(15);
    gotoXY(82, 25);
    for (int i = 0; i < 32; i++) {
        printf("%c", char(196));
    }
    gotoXY(102, 26);
    printf("Tong: ");

    //Esc
    gotoXY(1, 5);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" ESC ");
    textcolor(15);
    printf("DE LUU & THOAT");
    //Enter
    gotoXY(1, 6);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" ENTER ");
    textcolor(15);
    printf("DE CHON HANG");
    //Tab
    gotoXY(1, 7);
    textcolor(15);
    printf("NHAN");
    textcolor(6);
    printf(" TAB ");
    textcolor(15);
    printf("DE XOA MAT HANG");
}
//Xay dung ham thay doi cac gia tri tinhTongDoanhThu, tinhDT_SP tu file 