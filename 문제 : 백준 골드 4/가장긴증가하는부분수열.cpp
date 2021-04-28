#include <iostream>
#include <vector>
using namespace std;
int N , num[1001];
int maxSize = 1 ,maxIdx =  1 ;
vector <int> dp[1001];
int main(){
    cin >> N;

    for(int i = 1 ;i <= N ;i++){
        cin >> num[i];
        dp[i].push_back(num[i]);
    }
    for(int i = 1 ; i<= N ;i++){
        for(int j = 1; j < i ;j ++){
            if(num[j] < num[i] && dp[j].size() +1 > dp[i].size()){
                dp[i] = dp[j];
                dp[i].push_back(num[i]);
                int size = dp[i].size();

                if(maxSize < size ){
                    maxSize = dp[i].size();
                    maxIdx = i;
                }
            }
        }
    }
    
    cout << maxSize <<endl;
    for(int idx = 0 ; idx < dp[maxIdx].size() ;idx++){
        cout << dp[maxIdx][idx] <<" ";
    }
    return 0;
}