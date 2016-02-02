#include "iostream"
#include"vector"
#include"string"
#include <algorithm>
#include"string"
#include"deque"
#include "fstream"
#include"queue"
using namespace std;
/*
Назовем компонентой связности в неориентированном графе произвольное множество вершин
такое, что из любой вершины этого множества существует путь в любою другую вершину этого множестваи
и не существует другого множества с аналогичным свойством содержащего это множество.
    Дан неориентированный граф. Найдите количество различных компонент связности в нем.
	
	Пример 
	3 2
	1 2 
	2 3
	Ответ 1
	
	Пример
	5 4
	3 1
	1 2
	2 3
	4 5
	Ответ 
	2
*/

vector<vector<int> > VVI;
vector<int> used;
queue<int> qu;
int main(){
    int n,m;
    ifstream fin("connect2.in");
    ofstream fout("connect2.out");
    
    fin >> n >> m;
    VVI.resize(n+1);
    used.resize(n+1);
    for (int i = 0; i <= n; i++){
        used[i] = -1;
    }
    int x, y;
    for (int i = 0; i < m; i++){
        fin >> x >> y;
        VVI[x].push_back(y);
        VVI[y].push_back(x);
    }
    int ans=0;
    for (int i = 1; i <= n; i++){
        if (used[i] == -1){
            
            ans++;
            qu.push(i);
            while (!qu.empty()){
                int t = qu.front();
                qu.pop();
                used[t] = 1;
                for (int i = 0; i < VVI[t].size(); i++){
                    if (used[VVI[t][i]] == -1)
                        qu.push(VVI[t][i]);
                }
            }
        }
    }

    fout << ans;

}