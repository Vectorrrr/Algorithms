


#include"fstream"
#include <queue> 
#include"stdio.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"
#include"vector"
using namespace std;
/*
 РАССТОЯНИЕ ДО КОРНЯ.
	В Заданном корневом дереве найти вершины, максимально 
	удаленные от корня. Расстояние между вершинами счиается кол-во ребер в пути.
	
	Формат выходного файла. 
	В первой строке выведите максимальное расстояние от корня до остальных вершин.
	Во второй строке выведите, сколько вершин дерева находятся от корня на таком расстояниии.
	В третьей строке выведите номера этих вершин через пробел в порядке возрастания.
	
	ТЕСТ 
	3 1 1 
	Ответ
	1
	2
	2 3
	
	Тест
	3
	1 
	2
	Ответ
	2
	1
	3
	
	
*/
vector< int > g;
queue<int> q;
vector<int>d;

int tek = 0;
int n, m;

int main(){

	int N;
	int per;
	ifstream fin("rootdist.in");
	fin >> N;
	vector<bool>used(N);
	g.resize(N);
	d.resize(N);
	g[0]= 0;
	for (int i = 1; i < N; i++){
		fin >> per;
		g[i]=per-1;
	}
	for (int i = 0; i < N; i++){
		per = 0;
		int f = i;
		while (g[f] != f){
			per++;
			f=g[f];
		}
		d[i] = per;
	}
	int max = 0;
	int col = 0;
	for (int i = 0; i < N; i++){
		if (d[i]>max){
			max = d[i];
		}
	}
	for (int i = 0; i < N; i++){
		if (d[i] == max){
			col++;
		}
	}
	ofstream fout("rootdist.out");
	fout << max << "\n"<<col<<"\n";

	for(int i = 0; i < N; i++){
		if (d[i] == max)
			fout << i+1 << " ";
	}
	fout.close();

	return 0;
}