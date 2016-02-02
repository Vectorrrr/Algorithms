#include"iostream"
#include<vector>
#include"string"
using namespace std;
/*Ваня с другом Вовой играют в компьютерную игру, для прохождения уровня им нужно победить n
 монстров. Персонаж Вани наносит удары со скоростью x ударов за секунду, а персонаж Вовы — со скоростью 
 y ударов за секунду. Каждый из персонажей тратит фиксированное время на замах, после которого наносится удар 
 (время на замах составляет 1/x секунды для первого персонажа и 1/y секунды для второго). i-й монстр умирает после получения ai ударов.
Ване с Вовой стало интересно, кто нанесет последний удар каждому из монстров. Если Ваня с Вовой одновременно наносят последний удар, то 
считается, что последний удар нанесли оба из них.

Входные данные
В первой строке записано три целых числа n,x,y (1≤n≤10^5, 1≤x,y≤10^6) — количество монстров, скорость атаки Вани и Вовы соответственно.

В следующих n строках записаны целые числа ai (1≤ai≤10^9) — количество ударов, необходимое, чтобы победить i-го монстра.

Выходные данные
Выведите n строк. В i-й строке требуется вывести слово «Vanya», если последний удар по i-му монстру был нанесён Ваней, 
«Vova», если Вовой, либо «Both», если удар был нанесен ребятами одновременно.
ПРИМЕР 
4 3 2
1
2
3
4
ОТВЕТ
Vanya
Vova
Vanya
Both
*/


int main(){
    vector<string> vs;
    double n, x, y,last=0;

    cin >> n >> x >> y;
    double pox = 0, poy=0;
    long  mob;
    while (pox < x || poy < y){
        if ((pox + 1) / x < (poy + 1) / y){
            vs.push_back("Vanya");
            pox++;
        }
        else if ((pox + 1) / x>(poy + 1) / y){
            vs.push_back("Vova");
            poy++;
        }
        else{
            vs.push_back("Both");
            vs.push_back("Both");
            pox++;
            poy++;
        }
    }
    int f = (int)x;
    int l = (int)y;
    for (int i = 0; i < n; i++){
        cin >> mob;
        cout << vs[(mob - 1) % (f+l)]<<"\n";
    }
        
    }