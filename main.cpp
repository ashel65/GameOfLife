
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

bool checkAround(int data[][83], int &neighbors, int i, int j) {
	
	if ((neighbors == 2 || neighbors == 3) && data[i][j] == 1) {
		return true;
	}
	else if (neighbors == 3 && data[i][j] == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int i, j;
	int data[83][83];
	int next[83][83];
	srand(time(NULL));

	for (int i = 2; i <= 77; i++) {
		for (int j = 2; j <= 29; j++) {
			
			data[i][j] = 0;

			if (i > 1 && i < 78 && j > 1 && j < 30) {
				if (rand() % 6 == 1) {
					data[i][j] = 1;
					
					gotoxy(i, j);
					cout << "0";
				}
			}
			
		}
	}
	while (true) {
		for (int i = 2; i <= 77; i++) {
			for (int j = 2; j <= 29; j++) {
				gotoxy(i, j);
				if (data[i][j] == 1) {

					cout << "0";
				}
				else
					cout << " ";
			}
		}

		for (int i = 2; i <= 77; i++) {
			for (int j = 2; j <= 29; j++) {

				next[i][j] = data[i][j];
				int neighbors = data[i - 1][j] + data[i][j - 1] + data[i + 1][j] + data[i][j + 1] +
					data[i + 1][j + 1] + data[i - 1][j + 1] + data[i + 1][j - 1] + data[i - 1][j - 1];
				
				if (checkAround(data, neighbors, i, j)) {
					next[i][j] = 1;
				}
				else
					next[i][j] = 0;
			}
		}

		for (int i = 2; i <= 77; i++) {
			for (int j = 2; j <= 29; j++) {
				data[i][j] = next[i][j];
				
			}
		}
		system("pause");
	}
	

	return 0;
}