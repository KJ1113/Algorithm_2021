#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K;
int main() {
   //freopen("input.txt", "r", stdin);
   //중간값
   scanf("%d",&K);
   vector <int> list(K);
   for (int i = 0; i < K; i++) {
      scanf("%d", &list[i]);
   }
   sort(list.begin(), list.end());
   if (K==1 || K == 2) {
      printf("%d",list[0]);
   }
   else { // 3 이상일 경우
      if (K % 2 == 0) {
         printf("%d", list[K / 2 - 1]);
      }
      else {
         printf("%d", list[K / 2]);
      }
   }   
   return 0;
}