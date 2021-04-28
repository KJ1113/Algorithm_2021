#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>list;
int N ,ans , dp[2001];
int maxCnt = 0;
int main(){
    cin >> N;
    for(int i  =0; i< N; i++){
        int input;
        cin >> input;
        list.push_back(input);
    }
    reverse(list.begin(),list.end());
    for(int i = 0 ; i < N;i++){
        dp[i] = 1;
    }
    for(int i = 1 ; i < N; i++){ // dp[i] :i인덱스가 list[i] 수열의 끝에 올때, 조건을 만족하는 수열의크기 5 4 3 2 1..
                                // 즉, 지금까지 list[i] 보다 작은 숫자들의 갯수를 찾는 과정
        for(int j =0; j<i; j++){
            if(list[j] < list[i]){ // 현재 보다 값이 작다면 
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        maxCnt = max(maxCnt, dp[i]);
    }
    cout << N - maxCnt;
    return 0;
}