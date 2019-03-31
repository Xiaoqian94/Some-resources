#include <iostream>
#include <windows.h>
using namespace std;

int queen[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int _count = 0;

bool Is_meet(int row,int col) {
    for (int i = 0;i < row;i++) {
        if (col == queen[i])
            return 0;
        if ((row + col) == (i + queen[i]))
            return 0;
        if ((row - col) == (i - queen[i]))
            return 0;
    }
    queen[row] = col;
    return 1;
}

void display() {
    system("cls");
    cout << "八皇后问题动态演示:" << endl;
    for (int i = 0;i < 8;i++) {
        if (queen[i] == -1) {
            for (int j = 0;j < 8;j++)
                cout << ". ";
            cout << endl;
        }
        else {
            for (int j = 0;j < queen[i];j++) {
                cout << ". ";
            }
            cout << "# ";
            for (int k = queen[i] + 1;k < 8;k++) {
                cout << ". ";
            }
            cout << endl;
        }
    }
    Sleep(100);//停留时间可以自行更改
}

void findQueenPosition(int row) {
    for (int j_col = 0;j_col < 8;j_col++) {
        if (Is_meet(row, j_col)) {
            if (row == 7) {
                display();
                cout << "Case " << ++_count << "." << endl;
                Sleep(3000);//停留时间可以自行更改
                break;
            }
            else {
                display();
                findQueenPosition(row + 1);
            }
        }
    }
    queen[row] = -1;
    return;
}

int main() {
    findQueenPosition(0);
    cout << "The total case of eight queen problem is " << _count << endl;
    return 0;
}
