#include"fstream"
#include"iostream"
using namespace std;
/* Во входном файле задано число n(1<=n<=8). Выведите в выходной файле
в лексикографическом порядке все перестановки чисел от 1 до n.
Пример
3
Ответ
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
int a[8];
int n;
int check(){
	int z = -1;
	for (int i = 0; i < n-1; i++){
		if (a[i] < a[i + 1]){
			z = i;
		}
	}
	return z;
}
int main(){
	for (int i = 0; i < 8; i++){
		a[i] = i + 1;
	}
	ofstream fout("perm.out");
	ifstream fin("perm.in");
	fin >> n;

	int l,k;
	int loc;
	for (int i = 0; i < n; i++){
		fout << a[i] << " ";
	}
	fout << "\n";
	k = check();
	while (k != -1){
		
		l = n-1;
		while (a[l]<=a[k] ){
			l--;
		}
	
		loc = a[l];
		a[l] = a[k];
		a[k] = loc;
		int f = n;
		for (int i = k + 1; i < f; i++,f--){
			loc = a[i];
			a[i] = a[f-1];
			a[f  - 1] = loc;
		}
		k = check();
		for (int i = 0; i < n; i++){
			fout << a[i] << " ";
		}
		fout << "\n";
	}
	

	return 0;
}