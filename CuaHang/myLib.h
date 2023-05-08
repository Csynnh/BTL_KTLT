#pragma once
#include <windows.h>
#define KEY_NONE -1
int whereX();
int whereY();
void gotoXY(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
int inputKey();
void textcolor(int x);
void box(int x, int y, int w, int h, int t_color);
bool isValidDate(int day, int month, int year);
long int inputNumber(int n);
void inputString(char str[], int n);
void box_header(int x, int y, int w, int h, int t_color);
void centerText(char* str, int length);
bool isValidPhoneNumber(int phoneNum);
void dangnhap();
