#include"fstream"
#include"math.h"
using namespace std;
#define M_PI 3.14159265358979323846
/*
 Полярный угол точки
 
 Два числа  -- координаты точки, не совпадающей с началом координат.
 Найти полярный угол в радианах
 
 Тест
 2 3
 Ответ
 0.98279
	
	
*/

double polar_angle(int x,int y)
{
    double alpha = atan2(y,x);
    if (alpha < 0) alpha += 2 *M_PI;
    return alpha;
}
int main(){
    ifstream fin("angle1.in");
    ofstream fout("angle1.out");
    int x, y;
    fin >> x >> y;
    fout.precision(15);
    fout << polar_angle(x, y);
    return 0;

}

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