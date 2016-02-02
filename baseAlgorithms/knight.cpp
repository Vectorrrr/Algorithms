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

/*Дана прямоугольная доска N*M  В левом верхнем  углу находится шахматный конь, которого
необходимо переместить в правый нижний угол доски.
Необходимо определить сколько существует различных маршрутов, ведущих из 
левого верхнего в правый нижний угол.
Пример 3 2
Ответ 1
Пример 31 34 Ответ 293930
*/


int main()
{
    ifstream cin("knight.in");
    ofstream cout("knight.out");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
    }
    v[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 1 && j > 0) {
                v[i][j] += v[i - 2][j - 1];
            }
            if (i > 0 && j > 1) {
                v[i][j] += v[i - 1][j - 2];
            }
        }
    }
    cout << v[n - 1][m - 1];
}