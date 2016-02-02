/*http://codeforces.com/contest/492/problem/E*/
#include"iostream"
#include<vector>
#include"string"
using namespace std;
int a[10000000],  b[1000000],n,m,dx,dy,x,y;
int main(){
    cin >> n >> m >> dx >> dy;
    x = y  =a[0]= 0;
    for (int i = 0; i < n; i++){
        x = (x + dx) % n;
        y = (y + dy) % n;
        a[x] = y;
    }
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        b[(y - a[x] + 2*n) % n]++;
    }
    int m = -1;
    int rez = 0;
    for (int i = 0; i < n; i++){
        if (b[i]>m)
        {
            rez = i;
            m = b[i];
        }
    }
    cout << 0 << " " << rez;
    
}