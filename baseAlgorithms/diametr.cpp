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

/*��� ������� ���������� ����������������� ����.
���������� ���� ������, ���������� ����� ���� ���������� ��������� �����
���������������� ������� v ���������� ������������ ���������� �� ������� v �� ������
������ �����. �������� ����� ���������� ���������� �� ���������������� ������. ������� ������� � ������ �����
*/

 vector < vector < int >> VVI;
bool used[100];

 const int INF = 1000000000;
 vector<int> d(100,INF);

 int main(){
     ifstream fin("diameter.in");
     ofstream fout("diameter.out");
     int n;
     fin >> n;
     VVI.resize(n);
     for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){
             int x;
             fin >> x;
             VVI[i].push_back(x);
         }
     }
     int maxDi = 0;
     int maxRad = INF;
     for (int i = 0; i < n; i++){
        
         for (int k = 0; k < n; k++){
             used[k] = false;
             d[k] = INF;
         }
         d[i] = 0;

         for (int j = 0; j < n; j++){
             int v = -1;
             for (int k = 0; k < n; k++){
                 if (!used[k] && (v == -1 || d[k] < d[v])){
                     v = k;
                 }
             }
             if (d[v] == INF)
                 break;
             used[v] = true;
             for (int k = 0; k < n; k++){
                 if (VVI[v][k] != -1 && d[v] + VVI[v][k] < d[k])
                     d[k] = d[v] + VVI[v][k];


             }
         }
         int m=-1;
         for (int k = 0; k < n; k++){
             if (m < d[k] )
                 m = d[k];
         }
         if (maxDi < m)
             maxDi = m;
         if (maxRad>m)
             maxRad = m;
     }
     fout << maxDi << "\n";
     fout << maxRad;
    
 }