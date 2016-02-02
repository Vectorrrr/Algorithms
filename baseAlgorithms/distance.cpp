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
Дан неориентированный взвеенный граф. Найти вес минимального
пути между двумя вершинами. Если пути не существует вывести -1

Пример
4 4 1 3
1 2 1
3 4 5
3 2 2 
4 1 
*/



 vector < vector < int >> VVI;
bool used[5000];

 const int INF = 1000000000;
 vector<pair<int, int> > d;

 int main(){
     ifstream fin("distance.in");
     ofstream fout("distance.out");
     int n, m,s,f;
     fin >> n >> m>>s>>f;
     VVI.resize(n);
     for (int i = 0; i < n; i++)
         VVI[i].resize(n);
     for (int i = 0; i < m; i++){
         int x, y, ves;
         fin >> x >> y >> ves;
         VVI[x-1][y-1] = ves;
         VVI[y-1][x-1] = ves;
     }
     d.resize(n);
     for (int i = 0; i < n; i++){
         d[i].first = INF;
         used[i] = false;
     }
     d[s - 1].first = 0;
     d[s - 1].second = -1;
     for (int i = 0; i < n; i++){
         int  v = -1;
         for (int j = 0; j < n; j++)
         if (!used[j] && (v == -1 || d[j].first < d[v].first))
             v = j;

         if (d[v].first == INF)
             break;
         used[v] = true;
         for (int k = 0; k < n; k++)
         if (VVI[v][k] != 0 && d[v].first + VVI[v][k] < d[k].first){
             d[k].first = d[v].first + VVI[v][k];
             d[k].second = v;
         }
         
     }
     if (d[f - 1].first == INF)
         fout << -1;
     else{
         fout << d[f - 1].first << "\n";
         vector<int> obh;
         obh.push_back(f);
         int  t = d[f - 1].second;
         while (t != -1){
             obh.push_back(t + 1);
             t = d[t].second;
         }
        
         for (int it = obh.size() - 1; it > -1; it--)
             fout << obh[it] << " ";

     }
    
 }