#include "iostream"
#include"vector"
#include"string"
#include <algorithm>
#include"string"
#include"deque"
#include "fstream"

using namespace std;
/*Дана последовательность, требуется найти длину ее наибольшей возрастающей

подпоследовательности.
Пример
6
3 29 5 5 28 6

Ответ 
3
*/


int main(){
    int n;
    ifstream fin("lis.in");
    ofstream fout("lis.out");
    fin >> n;
    int a[10000];
    int d[10000];
    for (int i = 0; i < n; i++)fin >> a[i];
    d[0] = 1;
    for (int i = 1; i < n; i++){
        d[i] = 1;
        for (int j = 0; j<i; j++){
            if (a[i] > a[j] && d[i] < d[j]+1){
                d[i] = d[j] + 1;
            }
            
        }
    }
    int ma = d[0];
    for (int i = 0; i < n; i++){
        if (ma < d[i])
            ma = d[i];
    }
    fout << ma;
}