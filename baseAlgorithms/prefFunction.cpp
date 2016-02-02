#include"iostream"
#include"vector"
#include"string"
#include"fstream"
using namespace std;
/* ПОИСК ПОДСТРОКИ
	Дано две строки, а и в. Требуется узнать, где в строке а можно найти строку в, 
	как подстроку и выписать все такие позиции
	
    Тест
	abacaba
	aba
	Ответ
	2
	1 5
	
	
*/


vector<int>prefecs_function(string s){
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++){
		int j = pi[i - 1];
		while (j>0 && s[i] != s[j]){
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}

	return pi;

}
int main(){
	string t;
	string s;
	ifstream fin("search.in");
	getline(fin, t);
	getline(fin, s);
	fin.close();
	ofstream fout("search.out");
	string f = s +"#"+ t;
	vector<int>d = prefecs_function(f);
	vector<int >ans;
	for (int i = s.length(); i < f.length(); i++){
		if (d[i] == s.length()){
			ans.push_back(i - 2 * s.length());
		}
	}
	fout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++){
		fout << ans[i]+1 << " ";
	}
	return 0;
}