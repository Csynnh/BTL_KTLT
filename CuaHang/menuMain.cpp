#include "menuMain.h"
#include "header.h"
#include "myLib.h"
#include "KhachHang.h"
#include "NhanVien.h"
void menu_main()
{
    //dangnhap();
    int x = 50;
    int y = 4;
    int w = 20;
    int h = 2;
    int t_color = 14;
    int b_color_hl = 118;
    int n_cot = 3;
    ShowCur(0);
    gotoXY(45, 2);
    SetColor(15);
    printf("HE THONG QUAN LI CUA HANG ");
    SetColor(6);
    printf("C%cFFEE", char(167));
    gotoXY(43, 18);
    SetColor(15);
    //Footer
    printf("NHAN ");
    SetColor(6);
    printf("ESC");
    SetColor(15);
    printf(" DE THOAT KHOI CHUONG TRINH");
    //Control
    textcolor(6);
    n_box(x, y, w, h, t_color, n_cot);
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
            select_box(xcu, ycu, x, y, 6);
            xcu = xp;
            ycu = yp;
            select_box(xp, yp, x, y, b_color_hl);
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
                    yp -= 3;
                }
                else if (c == 80 && yp != y + h * (n_cot))
                {
                    yp += 3;
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
                select_menu(yp, y);
                kt_ENTER = !kt_ENTER;
                control_menu_main = false;
            }
        }
        else if (c == 27)
        {
            textcolor(15);
            system("cls");
            exit(0);
        }
    }
}
void select_menu(int yp, int y)//Chon ham theo toa do y

{

    if (yp == y)
        menu_KH();
    else if ((yp == y + 3))
        menu_DT();
    else if (yp == y + 6)
        menu_NV();
}
void n_box(int x, int y, int w, int h, int t_color, int n_cot)//Ve menu 
{
    for (int i = 0; i < n_cot; i++)
    {
        box(x, y + i * 3, w, h, t_color);
    }
    gotoXY(x + 1, y + 1);
    printf("     Khach Hang    ");
    gotoXY(x + 1, y + 4);
    printf("     Doanh Thu     ");
    //printf("      San Pham     ");
    gotoXY(x + 1, y + 7);
    printf("     Nhan Vien     ");
    //gotoXY(x + 1, y + 10);
}
void select_box(int xp, int yp, int x, int y, int b_color_hl)//Highlight box dang duoc chon
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (yp == y)
        printf("     Khach Hang    ");
    else if (yp == y + 3)
        printf("     Doanh Thu     ");
    else if (yp == y + 6)
        printf("     Nhan Vien     ");

}
