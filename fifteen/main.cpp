#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
#define HORIZONT "\t\t\t\t\t\t"
#define VERTICAL "\n\n\n\n\n\n\n\n\n"

void Menu( int h = 11);
void Mix(int filed[][4], int rows, int cols);
void PrintField(int field[][4], int rows, int cols);
bool check(int field[][4], int rows, int cols);
void Move(int field[][4], int rows, int cols);
void Up(int field[][4], int rows, int cols);
void Down(int field[][4], int rows, int cols);
void Left(int field[][4], int rows, int cols);
void Right(int field[][4], int rows, int cols);
void Win();
void Lod();


int main()
{
	setlocale(LC_ALL, "ru");
	const int rows = 4;
	const int cols = 4;
	int field[rows][cols] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15 };
	Menu(11);
	Lod();
	//Mix(field, rows, cols);
	PrintField(field, rows, cols);
	return 0;
}

void Menu(int h)
{
	cout << VERTICAL << HORIZONT << " ÏßÒÍÀØÊÈ" << endl << endl;
	cout << HORIZONT << "íîâàÿ èãðà" << endl;
	cout << HORIZONT << "   Âûõîä" << endl;
	DWORD l;
	COORD point;
	point.X = 48, point.Y = h;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputAttribute(hout, 4, 10, point, &l);
    char k = _getch();
	if (k == 80 && h < 12) {
		h++;
		FillConsoleOutputAttribute(hout, 4, 10, point, &l);
	}
		if (k == 72 && h > 11) {
			h--;
			FillConsoleOutputAttribute(hout, 4, 10, point, &l); 
		}
		system("cls");
	if (k == 13 && point.Y == 11)return;
	if (k == 13 && point.Y == 12)exit(0);
	else Menu(h);
}
void PrintField(int field[][4], int rows, int cols)
{
	setlocale(LC_ALL, "C");
	cout << VERTICAL << HORIZONT << char(218) << char(196) << char(196) <<char(196) << char(196) << char(194)
		                         << char(196) << char(196) << char(196) << char(196) << char(194)
		                         << char(196) << char(196) << char(196) << char(196) << char(194)
		                         << char(196) << char(196) << char(196) << char(196) << char(191) << endl;
	for (int i = 0; i < rows; i++) {
		cout << HORIZONT;
		for (int j = 0; j < cols; j++) {
			
			if (j != cols-1) {
				if (field[i][j] < 10 && field[i][j]) cout << char(179) << "  " << field[i][j] << char(32);
				if (!field[i][j]) cout << char(179) << "  " << char(32) << char(32);
				if (field[i][j] > 9 && field[i][j]) cout << char(179) << char(32) << field[i][j] << char(32);
			}
			else {
				if (field[i][j] < 10 && field[i][j]) cout << char(179) << "  " << field[i][j] << char(32) << char(179);
				if (!field[i][j]) cout << char(179) << "  " << char(32) << char(32) << char(179);
				if (field[i][j] > 9 && field[i][j]) cout << char(179) << char(32) << field[i][j] << char(32) << char(179);
			}
		}
		cout << endl;
		if (i != rows-1) cout <<HORIZONT << char(195) << char(196) << char(196) << char(196) << char(196) << char(197)
			                             << char(196) << char(196) << char(196) << char(196) << char(197)
			                             << char(196) << char(196) << char(196) << char(196) << char(197)
		                                 << char(196) << char(196) << char(196) << char(196) << char(180) << endl;
    }
	cout << HORIZONT << char(192) << char(196) << char(196) << char(196) << char(196) << char(193)
		             << char(196) << char(196) << char(196) << char(196) << char(193)
		             << char(196) << char(196) << char(196) << char(196) << char(193)
		             << char(196) << char(196) << char(196) << char(196) << char(217);
	cout << endl;
	cout << endl;
	check(field, rows, cols)? Win() : Move(field, rows, cols);
}
void Mix(int field[][4], int rows, int cols)
{
	int temp;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			if (j % 2 == 0 && field[i][j] != 0 && field[i][j + 1] != 0) {
				temp = field[i][j + 1];
				field[i][j + 1] = field[i][j];
				field[i][j] = temp;
			}
			if(i % 2 != 0 && field[i][j] != 0 && field[i][j + 1] != 0){
				temp = field[i - 1][j + 1];
				field[i - 1][j + 1] = field[i][j];
				field[i][j] = temp;
			}
		}
	}
}

void Up(int field[][4], int rows, int cols)
{
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		if (temp)break;
		for (int j = 0; j < cols; j++) {

			if (!field[i][j] && i != 0) {
				temp = field[i - 1][j];
				field[i - 1][j] = field[i][j];
				field[i][j] = temp;
				break;
			}
		}
	}
}
void Down(int field[][4], int rows, int cols) 
{
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		if (temp)break;
		for (int j = 0; j < cols; j++) {

			if (!field[i][j] && i != rows-1) {
				temp = field[i + 1][j];
				field[i + 1][j] = field[i][j];
				field[i][j] = temp;
				break;
			}
		}
	}
}
void Left(int field[][4], int rows, int cols)
{
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		if (temp)break;
		for (int j = 0; j < cols; j++) {

			if (!field[i][j] && j != 0) {
				temp = field[i][j-1];
				field[i][j-1] = field[i][j];
				field[i][j] = temp;
				break;
			}
		}
	}
}
void Right(int field[][4], int rows, int cols)
{
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		if (temp)break;
		for (int j = 0; j < cols; j++) {

			if (!field[i][j] && j != cols - 1) {
				temp = field[i][j+1];
				field[i][j+1] = field[i][j];
				field[i][j] = temp;
				break;
			}
		}
	}
}
bool check(int field[][4], int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols - 1; j++) {
			if (field[i][j] > field[i][j + 1] )return false;
			if (i == rows - 1 && field[i][cols - 2] == 15)break;
		}
    }
	return true;
}
void Move(int field[][4], int rows, int cols)
{
	switch (_getch())
	{
	case 50:
		Down(field, rows, cols);
		break;
	case 52:
		Left(field, rows, cols);
		break;
	case 54:
		Right(field, rows, cols);
		break;
	case 56:
		Up(field, rows, cols);
		break;
	case 27:
		return;
	default:
		Move(field, rows, cols);
	}
	system("cls");
    PrintField(field,rows,cols);
}
void Win()
{
	setlocale(LC_ALL, "ru");
	cout << HORIZONT << "  ÂÛ ÑÏÐÀÂÈËÈÑÜ!!!" << endl;
}
void Lod()
{
	int x = 30, k = 0;
	cout << VERTICAL << HORIZONT << "Please wait. Loding" << endl;
	cout << "\t\t\t\t   ";
	setlocale(LC_ALL, "C");
	while (x)
	{
		k = 1 + rand() % 700;
		if (x == 10) {
			cout << char(178) << char(178) << char(178) << char(178);
			Sleep(1000);
		}
		if (x == 19) {
			cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178);
		}
		cout << char(178);
		Sleep(k);
		x--;
	}
	system("cls");
}




