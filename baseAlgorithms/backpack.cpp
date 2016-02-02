#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "vector"
#include "stdlib.h"
#include "stdio.h"
/*
Грабитель, проникший в банк, обнаружил в сейфе k золотых слитков,
массами w1, w2, ..., wk килограмм. При этом грабитель может
унести не более W килограмм. Определите набор слитков, который
должен взять грабитель, чтобы унести как можно больше золота.
Пример  	
5
6 5
4 3
3 1
2 3
5 6
Ответ 15
*/

 
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> mas;
    vector<int> cost;
   
    mas.resize(n+1);
    cost.resize(n+1);
 
    vector<vector<int>> ans;
    ans.resize(n+1);
    for (int i = 1; i <= n; ++i)
    {
        ans[i].resize(m+1);
        scanf("%d", &mas[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
 
        scanf("%d", &cost[i]);
    }
    ans[0].resize(m+1);
    for (int i = 0; i <= m; ++i) {
        ans[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans[i][j] = ans[i - 1][j];
            if (j >= mas[i] && ans[i][j] < (ans[i - 1][j - mas[i]] + cost[i])) {
                ans[i][j] = ans[i - 1][j - mas[i]] + cost[i];
            }
        }
    }
    cout << ans[n][m];
}
