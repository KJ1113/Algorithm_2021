#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
int K;
int main() {
   //freopen("input.txt", "r", stdin);
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> K;

   for (int i = 0; i<K;i++) {
      int input;
      cin >> input;
      // maxH 은 minH 보다 size가 같거나 하나더크다.
      // maxH 는 항상 minH 보다 작아야한다.

      if (maxH.size() ==0) {
         maxH.push(input);
      }
      else {
         if (maxH.size() > minH.size()) {
            minH.push(input);
         }
         else {
            maxH.push(input);
         }
         if (maxH.top() > minH.top()) {
            int maxtop = maxH.top();
            int mintop = minH.top();
            maxH.pop();
            minH.pop();
            maxH.push(mintop);
            minH.push(maxtop);
         }
      }
      cout << maxH.top() << '\n';
   }
   return 0;
}