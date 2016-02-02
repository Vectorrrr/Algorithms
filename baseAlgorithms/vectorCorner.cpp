#include"fstream"
#include"math.h"
using namespace std;
#define M_PI 3.14159265358979323846
/*
 Угол между векторами
 Дано четыре числа  координаты двух не нулевых векторов.
 Вывести величину неориентированного угла между ними с точностью до
 пятого знака после запятой из интервала [0,PI]
 
 Тест
 2 1 3 5
 Ответ
 0.56673
	
	
*/

int main(){
	ifstream fin("angle2.in");
	int x1, y1, x2, y2;
	fin >> x1 >> y1 >> x2 >> y2;
	int proiz = x1*x2 + y1*y2;
	double dlin1 = sqrt(x1*x1 + y1*y1);
	double dlin2 = sqrt(x2*x2 + y2*y2);
	double a = acos(proiz / (dlin1* dlin2));
	if (a < 0)a += M_PI;
	if (a>M_PI)a -= M_PI;
	fin.close();
	ofstream fout("angle2.out");
	fout.precision(15);
	fout << a;
	return 0;

}
