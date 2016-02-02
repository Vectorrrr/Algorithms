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
/*
	В одном из горнолыжных курортов Италии проводятся соревнования
	по горнолыжному спску. Каждому спортсмену предстоит скатиться с горы на лыжах. На любом
	этапе спуска участник получает определенное число очков. После прохождения трассы очки 
	суммируются. Участник набирающий наибольшее количество очков, выигрывает. Гора представляет собой треугольник, 
	в качестве элементов которого выступают целые числа - очки за прохождения этапа. На каждом уровне
	спортсмену предоставляется выбор - двигаться вниз влево или вниз вправо. Начало спуска - в самой высокой точке горы, конец в одной из самых низких.
	Требуется найти максимальное количество очков, которое может набрать спотсмен.
	Пример
	4
	1
	4 3
	5 6 7
	8 9 0 9
	Ответ 
	20
*/


int main()
{

    int n;
    cin >> n;
    vector<vector<int>>v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = -1000;
            if (j != i) {
                temp = v[i - 1][j];
            }
            if (j != 0 && temp < v[i - 1][j - 1]) {
                temp = v[i - 1][j - 1];
            }
            v[i][j] = v[i][j] + temp;
        }
    }
    int ma = -1000000;
    for (int i = 0; i < n; i++) {
        if (v[n - 1][i]>ma)
        {
            ma = v[n - 1][i];
        }
    }
    cout << ma;
}