#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include"string"
#include<algorithm>
#include<map>
#include"queue"
#include"stdlib.h"
#include"stdio.h"
#include <iomanip> 
#include <stack> 
using namespace std;
/*В обороте находятся банкноты k  различных номиналов: 
a1, a2, ..., ak рублей. Банкомат должен выдать сумму в N рублей
при помощи минимального количества банкнот или сообщить, что 
запрашиваемую сумму выдать нельзя. Будем считать, что запасы
 банкнот каждого номинала неограничены.
 Пример 
 120 3
 10 
 60 
 100
 Ответ
 2
 */
 int main(){
 int n, m;
 int a[10000];
 cin>>n>>m;
 for(int i=0;i<m;i++){
	 scanf("%d",&a[i]);
 }
 const int INF=1000000000;  
 int TEMP[n+1]; 
 TEMP[0]=0; 
 int c, i; 
 for(c=1; c<=n; ++c)   
 {                      
   F[m]=INF;            
   for(i=0; i<k; ++i)   
   { 
     if(c>=a[i] && F[c-a[i]]+1<F[c]) 
       F[c] = F[c-a[i]]+1; 
   }                      
 } 
	cout<<F[n];
 }