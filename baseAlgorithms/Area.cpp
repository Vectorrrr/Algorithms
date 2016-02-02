#include"fstream"
#include"math.h"
using namespace std;
#define M_PI 3.14159265358979323846
/*
 Данны координаты точек многоугольника, в порядке их обхода по 
 или против часовой стрелки.
 Найти площадь многоугольника.
 
 Тест
 3
 1 0
 0 1
 1 1
 Ответ
 0.5
	
	
*/



int main(){
	ifstream fin("area.in");
	int x1, y1, x2, y2,k,firstX,firstY;
	fin >> k;
	double a=0;
	fin >> x1 >> y1;
	firstX = x1;
	firstY = y1;
	for (int i = 1; i < k; i++){
		fin >> x2>>y2;
		a = a+((x1 + x2)*(y1 - y2));
		x1 = x2;
		y1 = y2;
	}
	a += (x1 + firstX)*(y1 -firstY);
	a *= 0.5;
	a = abs(a);
	fin.close();
	ofstream fout("area.out");
	fout.precision(15);
	fout << a;
	return 0;

}
}