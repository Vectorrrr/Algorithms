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
Полный ориентированный взвещенный граф задан матрицей смежности.
Постройте матрице кратчайших между его вершинами. Гарантируется, что в графе нет
циклов отрицательного веса.
Пример
4
0 5 9 100
100 0 2 8
100 100 0 7
4 100 100 0

Ответ
0 5 7 13
12 0 2 8
11 16 0 7
4 9 11 0

	
*/

 vector < vector < int >> VVI;
bool used[100];

 const int INF = 1000000000;
 vector<int> d(100, INF);

 int main(){
     ifstream fin("floyd.in");
     ofstream fout("floyd.out");
     int n;
     fin >> n;

     VVI.resize(n);
     for (int i = 0; i < n; i++){
         VVI[i].resize(n);
         for (int j = 0; j < n; j++){
             fin >> VVI[i][j];
         }
     }

     for (int i = 0; i < n; i++){
        
         for (int k = 0; k < n; k++){
             used[k] = false;
             d[k] = INF;
         }

         d[i] = 0;

         for (int f = 0; f < n; f++){
             int v = -1;
             for (int k = 0; k < n; k++)
             if (!used[k] && (v == -1 || d[k] < d[v]))
                 v = k;
            
             if (d[v] == INF)
                 break;

             used[v] = true;
             for (size_t it = 0; it < VVI[v].size(); it++){
                 if (d[v] + VVI[v][it] < d[it]){
                     d[it] = d[v] + VVI[v][it];
                 }
             }
         
         }
         for (int it = 0; it < n; it++){
             fout << d[it] << " ";
         }
         fout << "\n";
     }

 }