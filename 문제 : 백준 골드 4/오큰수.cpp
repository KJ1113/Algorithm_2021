#include <iostream>
#include <stack>
using namespace std;
int N ;
int Num[1000001];
int dp[1000001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<= N; i++){
        cin >> Num[i];
        dp[i] = -1;
    }
    stack<int> s; // 인텍스 저장
    for(int i = 1; i <= N ;i++){
        if(s.empty()){
            s.push(i);
        }else{
            if(Num[i] > Num[s.top()]){
                while (!s.empty()){
                    if(Num[i] > Num[s.top()]){
                        dp[s.top()] = Num[i];
                        s.pop();
                    }else{
                        break;
                    }
                }           
            }
            s.push(i);
        }
    }
    for(int i = 1; i < N ;i++){
        cout << dp[i] <<" ";
    }
    cout<< dp[N] <<endl;
    return 0;
}
