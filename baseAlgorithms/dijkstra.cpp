
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "vector"
#include "fstream"

using namespace std;
/*
Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной
заданной вершины до другой. Если расстояния нет, то вывести -1000

Тест 
3 1 2
0 -1 2
3 0 -1000-1 4 0

Ответ:
6
*/


int main() {
    int n, s, f;
    ifstream cin("dijkstra.in");
    ofstream cout("dijkstra.out");
    cin >> n >> s >> f;
    vector<vector<int >> v;
    s--;

    f--;
    vector<int> used;
    used.resize(n);
    //откуда и какое расстояние
    vector<pair<int, int>> siz;
    siz.resize(n);
    for (int i = 0; i < n; i++) {
        siz[i] = make_pair(i, 100000000);
    }

    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int temp = s;
    siz[s].second = 0;
    used[s] = 1;
    while (temp != -1) {
        for (int i = 0; i < n; i++) {
            if (v[temp][i] != -1 && used[i] != 1 && siz[i].second>siz[temp].second + v[temp][i]) {
                siz[i].second = siz[temp].second + v[temp][i];
                siz[i].first = temp;
            }
        }
        used[temp] = 1;
        int min = 100000000;
        for (int i = 0; i < n; ++i) {
            if (used[i] != 1 && siz[i].second < min) {
                min = siz[i].second;
                temp = i;
            }
        }
        if (min == 100000000) {
            temp = -1;
        }
    }
    if (siz[f].second == 100000000) {
        cout << -1;
    }
    else {
        cout << siz[f].second;
    }
}