#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[110];
long long dp[110][30];
vector<int> num_list;
int main(){
    cin >> N;
    for(int i = 1 ;i <= N; i++){
        cin >> arr[i];
    }
    dp[1][arr[1]] = 1;

    for(int i = 2;  i <= N ; i++ ){
        for(int num = 0 ; num <= 20 ;num++){

            if(dp[i-1][num] >= 0){

                if(num + arr[i] <= 20 ){
                    dp[i][num+arr[i]]+=dp[i-1][num];
                }

                if(num - arr[i] >= 0 ){
                    dp[i][num-arr[i]]+=dp[i-1][num];
                }
            }
        }
    }

    cout<<dp[N-1][arr[N]];
    return 0;
}