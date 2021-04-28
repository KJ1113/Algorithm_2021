#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> num;
int N ;
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        int a;
        cin >> a;
        num.push_back(a);
    }

    int left = 0 , right = N-1 , total = 2e9;
    pair < int, int > res;
    while (left < right){
        int a = num[left];
        int b = num[right];
        if(abs(a+b) < total){
            total = abs(a+b);
            res.first = a;
            res.second = b;
        }
        if(a + b < 0){
            left ++;
        }else{
            right --;
        }
    }
    cout << res.first << " " <<res.second ;
    return 0;
}