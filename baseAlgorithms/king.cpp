#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include"string"
#include<algorithm>
#include<map>
#include"queue"
#include"stdlib.h"
#include"stdio.h"
using namespace std;
/*Ќа каждой клетке шахмотной доски размеров 8*8 записано целое 
не отрицательное число.  ороль может переещатьс€ по шахматной доске из левого нижнего
угла в правый верхний, перемеща€сь только вправо, вверх или по диагонали вправо-вверх. ѕри
этом стоимость прохода черх данную клетку равна числу, записанному на этой клетке.
	ѕереместите корол€ из левого нижнего угла в правый верхний с наименьшей стоимостью прохода
	
	ѕример
	9 9 9 9 9 9 9 1 9
	9 9 9 9 9 9 1 9 2
	9 9 9 9 9 9 9 1 9
	9 9 9 9 9 9 9 9 9
	9 9 9 9 9 9 9 9 9
	9 9 9 9 9 9 9 9 9
	9 9 9 9 9 9 9 9 9
	0 9 9 9 9 9 9 9 9
	ќтвет 
	56
*/



int main()
{
    ifstream cin("king2.in");
    ofstream cout("king2.out");
    vector<vector<int>>v;
    v.resize(8);
    for (int i = 0; i < 8; i++) {
        v[i].resize(8);
        for (int j = 0; j < 8; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 7; i > -1; i--) {
        for (int j = 0; j < 8; j++) {
            int temp = 10000000;
            if (i != 7 && temp>v[i+1][j]) {
                temp = v[i + 1][j];
            }
            if (i != 7 && j != 0 && temp>v[i+1][j-1]) {
                temp = v[i + 1][j - 1];
            }
            if (j != 0 && temp > v[i][j - 1]) {
                temp = v[i][j - 1];
            }
            if (temp == 10000000) {
                temp = 0;
            }
            v[i][j] += temp;
        }
    }
    cout << v[0][7];
}