#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int K , ans = 0;;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
   freopen("input.txt", "r", stdin);
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> K;
   vector <int> list(K);
   for (int i = 0; i < K; i++) {
      int input;
      cin >> input;
      q.push(input);
   }
   if (q.size() ==1 ) {
      ans = 0;
   }
   else {
      while (q.size() >= 2) {
         int tmp = q.top();
         q.pop();

         int tmp2 = q.top();
         q.pop();

         q.push(tmp + tmp2);
         ans += tmp + tmp2;
      }
   }
   cout << ans;
   return 0;
}

/* 퀵소트 
int a[100010], b[100010];
int top, n;

void quickSort(int left, int right) {
   int i = left, j = right;
   int pivot = a[(left + right) / 2];
   int temp;
   do {
      while (a[i] < pivot) i++;
      while (a[j] > pivot) j--;
      if (i <= j) {
         temp = a[i], a[i] = a[j], a[j] = temp;
         i++, j--;
      }
   } while (i <= j);

   if (left < j)
      quickSort(left, j);

   if (i < right)
      quickSort(i, right);
}
*/