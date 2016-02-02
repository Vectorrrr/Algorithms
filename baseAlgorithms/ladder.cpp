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
/* Лестница
 У лестницы n ступенек, пронумерованных числами 1,2,....n 
 На каждой ступеньке написано число. Начиная с подножия лестницы(ступенька с номером 0), требуется взобраться на самый верх
 (ступенька с номером n). За один шаг можно подниматься на одну или на две ступеньки.
 После подъема числа записанные на посещенных стуеньках, складываются. Нужно подняться по лестнице так, чтобы сумма этих чисел была как можно больше.

 Пример
 2
 1 2
 Ответ 3
 
 Пример
 2
 2 -1
 Ответ 1
 
 Пример
 3
 -1 2 1
 Ответ 3
 */


int main()
{
    ifstream cin("ladder.in");
    ofstream cout("ladder.out");
    
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> ans;
    ans.resize(n + 1);
    ans[0] = 0;
    ans[1] = v[0];
    for (int i = 2; i <= n; i++) {
        ans[i] = max(ans[i - 1], ans[i - 2]) + v[i - 1];
    }
    cout << ans[n];
}