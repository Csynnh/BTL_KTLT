﻿#include "myLib.h"
#include "header.h"
#include"danhsachNV.h"
#include "NhanVien.h"
using namespace std;

int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void box(int x, int y, int w, int h, int t_color)
{

	SetColor(t_color);
	if (h < 2 || w < 2)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		printf("%c", char(196));
		gotoXY(ix, y + h);
		printf("%c", char(196));
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		printf("%c", char(179));
		gotoXY(x + w, iy);
		printf("%c", char(179));
	}
	gotoXY(x, y);
	printf("%c", char(218));
	gotoXY(x + w, y + h);
	printf("%c", char(217));
	gotoXY(x + w, y);
	printf("%c", char(191));
	gotoXY(x, y + h);
	printf("%c", char(192));
}
void centerText(char* str, int length)
{
	int str_len = strlen(str);
	int padlen = (length - str_len) / 2;
	for (int i = 0; i < padlen; i++)
	{
		printf(" ");
	}
	printf("%s", str);
	for (int i = 0; i < (length - str_len - padlen); i++)
	{
		printf(" ");
	}
}
bool isValidDate(int day, int month, int year)
{
	// Kiểm tra năm
	if (year < 1 || year > 2023)
	{
		return false;
	}

	// Kiểm tra tháng
	if (month < 1 || month > 12)
	{
		return false;
	}

	// Tính số ngày tối đa của tháng
	int maxDays;
	switch (month)
	{
	case 2:
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			maxDays = 29;
		}
		else
		{
			maxDays = 28;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDays = 30;
		break;
	default:
		maxDays = 31;
		break;
	}

	// Kiểm tra ngày
	if (day < 1 || day > maxDays)
	{
		return false;
	}

	// Ngày tháng năm hợp lệ
	return true;
}
long int inputNumber(int n) // Ham Nhap so khong nhan Enter, Space, Tab o ky tu dau tien va khong nhan cu cai
{
	long int number = 0;
	char ch;
	bool digitEntered = false; // Flag to check if a digit has been entered
	int count = 0;             // Count the number of digits entered

	while (true)
	{
		ch = _getch();

		if (ch == '\r' || ch == '\n' || ch == '\t' || ch == ' ')
		{ // Enter, Tab or Space
			if (digitEntered)
			{
				break;
			}
		}
		else if (ch == '\b')
		{ // Backspace
			if (number > 0)
			{
				number /= 10;
				digitEntered = true; // A digit has been entered
				putchar('\b');
				putchar(' ');
				putchar('\b');
				count--;
			}
		}
		else if (ch >= '0' && ch <= '9')
		{ // Digit
			if (count < n)
			{
				number = number * 10 + (ch - '0');
				digitEntered = true; // A digit has been entered
				putchar(ch);
				count++;
			}
		}
		else
		{ // Other character
			if (digitEntered)
			{
				break;
			}
		}
	}

	cout << endl;

	return number;
}
void inputString(char str[], int n) // Ham Nhap Chuoi khong nhan Enter, Space, Tab o ky tu dau tien
{
	char ch;
	int count = 0;
	bool charEntered = false; // Flag to check if a non-digit character has been entered

	while (true)
	{
		ch = _getch();

		if (count == 0 && (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || (ch >= '0' && ch <= '9')))
		{
			// Do nothing if the first character entered is a space, tab, enter or digit
		}
		else if (ch == '\r' || ch == '\n')
		{ // Enter
			if (charEntered)
			{
				break;
			}
		}
		else if (ch == '\b')
		{ // Backspace
			if (count > 0)
			{
				count--;
				charEntered = true; // A non-digit character has been entered
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
		}
		else
		{ // Other character
			if (count < n)
			{
				str[count] = ch;
				count++;
				charEntered = true; // A non-digit character has been entered
				putchar(ch);
			}
		}
	}
	str[count] = '\0';
	cout << endl;
}

void box_header(int x, int y, int w, int h, int t_color)
{

	SetColor(t_color);
	if (h < 2 || w < 2)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		printf("%c", char(196));
		gotoXY(ix, y + h);
		printf("%c", char(196));
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x + w, iy);
		printf("%c", char(179));
	}
	gotoXY(x + w, y + h);
	printf("%c", char(217));
	gotoXY(x + w, y);
	printf("%c", char(191));
}
bool isValidPhoneNumber(int phoneNum) {
	// Chuyển số điện thoại thành chuỗi ký tự
	char phoneStr[11]; // Độ dài của số điện thoại là 10 chữ số, cộng thêm 1 ký tự NULL kết thúc chuỗi
	sprintf_s(phoneStr, "%010d", phoneNum);

	// Kiểm tra tiền tố và độ dài của số điện thoại
	const char* prefixes[] = { "032", "033", "034", "035", "036", "037", "038", "039", "056", "058", "059", "070", "079", "077", "076", "078", "083", "084", "085", "081", "082" };
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

void dangnhap() {
	sttKH = 0;
	
	bool isValue = false;
	docTTNV(danhsachNV, soluongNV);
	do {
		box(45, 7, 30, 2, 6);
		gotoXY(47, 6);
		textcolor(8);
		printf("NHAN VIEN DANG NHAP");
		gotoXY(47, 8);
		textcolor(8);
		printf("UserName: ");
		ShowCur(1);
		gotoXY(57, 8);
		textcolor(15);
		char a[50];
		inputString(a, 30);
		ShowCur(0);
		a[strcspn(a, "\n")] = '\0';  // xóa ký tự newline khi đọc chuỗi
		for (int i = 1; i <= soluongNV; i++)
		{
			if (strcmp(a, danhsachNV[i].hoTen) == 0) {
				isValue = true;
				break;
			}
		}
		if (isValue == false) {
			system("cls");
			textcolor(244);
			gotoXY(50, 10);
			printf("                                   ");
			gotoXY(50, 11);
			printf("      Khong ton tai nhan vien      ");
			gotoXY(50, 12);
			printf("                                   ");
			Sleep(3000);
			textcolor(15);

			gotoXY(50, 10);
			printf("                                   ");
			gotoXY(50, 11);
			printf("                                   ");
			gotoXY(50, 12);
			printf("                                   ");
		}
		} while (isValue == false);
		system("cls");
		textcolor(242);
		gotoXY(50, 10);
		printf("                                ");
		gotoXY(50, 11);
		printf("      Dang Nhap Thanh Cong      ");
		gotoXY(50, 12);
		printf("                                ");
		Sleep(2000);
		textcolor(15);
		gotoXY(50, 10);
		printf("                                ");
		gotoXY(50, 11);
		printf("                                ");
		gotoXY(50, 12);
		printf("                                ");
	}
