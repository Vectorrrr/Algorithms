 #include "iostream"
#include"vector"
#include"string"
#include <algorithm>
#include"string"
#include"deque"
#include "fstream"
#include"queue"
#include <stdio.h>
#include <iomanip>
#include <set>
using namespace std;
/*
Дан связный граф. Требуется найти сумму расстояний между всеми парами вершин.
Пример
5 5 
1 2 
2 3
3 4
5 3
1 5

Ответ 
16
	
*/


 vector < vector < int >> VVI;
bool used[1000];

 const int INF = 1000000000;
 vector<int> d(1000);

 int main(){
     ifstream fin("sumdist.in");
     ofstream fout("sumdist.out");
     int n,m;
     fin >> n>>m;
     VVI.resize(n);
     for (int i = 0; i < m; i++){
         int x, y;
         fin >> x >> y;
         VVI[x-1].push_back(y-1);
         VVI[y-1].push_back(x-1);
     }

     queue<int>q;
     long long rez = 0;
     for (int i = 0; i < n - 1; i++){
         q.push(i);
         for (int k = 0; k < n; k++){
             d[k] = 0;
             used[k] = false;
         }
         d[i] = 0;
         used[i] = true;
         while (!q.empty()){
             int temp = q.front();
             q.pop();

             for (int k = 0; k < VVI[temp].size(); k++){
                 if (!used[VVI[temp][k]]){
                     used[VVI[temp][k]] = true;
                     d[VVI[temp][k]] = d[temp] + 1;
                     q.push(VVI[temp][k]);
                 }
             }
         }
    
         for (int k = 0+i; k < n; k++){
             rez += d[k];
         }
     }
     fout << rez;

 }