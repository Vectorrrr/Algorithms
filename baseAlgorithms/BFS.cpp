#include"fstream"
#include <queue> 
#include"stdio.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"
#include"vector"
using namespace std;
/* ОБХОД В ШИРИНУ
   Дан неориентированный граф. В нём необходимо найти 
   расстояние от одной  заданной вершины до другой.
   Если расстояния не существует, вывести 0
   
   ТЕСТ
   4 4 3
   0 1 1 1 
   1 0 1 0
   1 1 0 0
   1 0 0 0
   
   Ответ
	2
*/

vector< vector <int> > g;
queue<int> q;
vector<int>d;

int tek = 0;
int n, m;

int main(){

	int N,S,F;
	
	ifstream fin("bfs.in");
	fin >> N >> S>>F;
	vector<bool>used(N);
	g.resize(N);
	d.resize(N);
	for (int i = 0; i < N; i++){
		g[i].resize(N);
		for (int j = 0; j < N; j++)
			fin >> g[i][j];
	}
	q.push(S-1);
	used[S-1] = true;
	int z = -1;
	while (!q.empty()){
		int v = q.front();
		if (z != -1)
			break;
		q.pop();
		for (int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if (!used[i]&& to!=0){
				used[i] = true;
				q.push(i);
				d[i] = d[v] + 1;
			
			}
			if (i == F-1&& to==1){
				z = 0;
				break;
			}
		}
	
	}
	ofstream fout("bfs.out");
	fout << d[F-1];
	fout.close();

	return 0;
}