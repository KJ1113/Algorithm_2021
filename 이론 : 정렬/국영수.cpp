#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K;
struct Node {
   string name;
   int a, b, c;
};
bool cmp(Node A, Node B) {
   if (A.a == B.a) {
      if (A.b == B.b) {
         if (A.c == B.c) {
            return A.name < B.name;
         }
         else {
            return A.c > B.c;
         }
      }
      else {
         return A.b < B.b;
      }
   }
   else {
      return A.a > B.a;
   }
}
int main() {
   freopen("input.txt", "r", stdin);
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> K;
   vector <Node> list(K);
   for (int i = 0; i < K; i++) {
      cin >> list[i].name >> list[i].a >> list[i].b >> list[i].c;
   }
   sort(list.begin(), list.end(), cmp);
   for (int i = 0; i < list.size(); i++) {
      cout << list[i].name << "\n";
   }
   return 0;
}